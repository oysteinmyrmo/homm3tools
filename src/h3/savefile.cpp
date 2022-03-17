#include "savefile.h"
#include "value_reader.h"

#include <zlib.h>

#include <cstring>
#include <fstream>
#include <string>

namespace h3::savefile
{
std::vector<char> decompress(const fs::path &path)
{
    if (!fs::is_regular_file(path))
    {
        printf("Error: %s is not a regular file.\n", path.string().c_str());
        return {};
    }

    gzFile inFileZ = gzopen(path.string().c_str(), "rb");
    if (inFileZ == NULL)
    {
        printf("Error: gzopen() failed for file %s.\n", path.string().c_str());
        return {};
    }

    constexpr size_t bufSize = 8192;
    uint8_t unzipBuffer[bufSize];
    int unzippedBytes = bufSize;
    std::vector<char> unzippedData;
    unzippedData.reserve(bufSize * 200); // Semi-arbitrary

    while (unzippedBytes == bufSize)
    {
        unzippedBytes = gzread(inFileZ, unzipBuffer, bufSize);

        if (unzippedBytes == -1)
        {
            // TODO: Do anything when errors are hit? For multiplayer test games the following error is hit:
            // -3 / "/path/to/file.GM6: incorrect data check"
            // Everything seems to work fine though...
            int errnum;
            const char *err = gzerror(inFileZ, &errnum);
            printf(err, "%s\n");
            break;
        }

        if (unzippedBytes > 0)
        {
            unzippedData.insert(unzippedData.end(), unzipBuffer, unzipBuffer + unzippedBytes);
        }
    }

    gzclose(inFileZ);
    return unzippedData;
}

void write_decompressed(const fs::path &path, const std::span<const char> data)
{
    std::fstream file;
    file.open(path.c_str(), std::ios::app | std::ios::binary);
    file.write(data.data(), data.size());
}

void read_write_decompressed(const fs::path &path, const fs::path &outPath)
{
    const auto data = decompress(path);
    if (data.size())
    {
        write_decompressed(outPath, data);
    }
}

// The name of the first town in the file is always the name of red player's start town.s
size_t firstTownIndex(const std::span<const char> data, const std::string &firstTownName)
{
    if (firstTownName.size())
    {
        const auto it = std::search(data.begin(), data.end(), std::begin(firstTownName), std::end(firstTownName));
        if (it != data.end())
        {
            const size_t firstTownNameIdx = it - data.begin();
            return firstTownNameIdx - Town::offsetFromNameToStart();
        }
    }
    return 0;
}

// First hero is Orrin by default. If his name is changed, so must the name passed to this function
size_t firstHeroIndex(const std::span<const char> data, const std::string &firstHeroName)
{
    if (firstHeroName.size())
    {
        const auto it = std::search(data.begin(), data.end(), std::begin(firstHeroName), std::end(firstHeroName));
        if (it != data.end())
        {
            const size_t firstHeroNameIdx = it - data.begin();
            return firstHeroNameIdx - Hero::offsetFromNameToStart();
        }
    }
    return 0;
}

SaveFile::SaveFile(const Input &input)
{
    const auto data = decompress(input.path);
    if (data.empty())
    {
        return;
    }

    size_t idx = 0;
    values::readArr(data, idx, header);

    idx = 56;
    values::readVal(data, idx, heroCount);

    idx = 63;
    values::readEnum(data, idx, mapSize);

    idx = 67;
    values::readVal(data, idx, hasUnderground);

    idx = 68;
    values::readVal(data, idx, mapNameSize);

    idx = 70;
    values::readStr(data, idx, mapName, mapNameSize);

    idx = 70 + mapNameSize;
    values::readVal(data, idx, descriptionSize);

    idx = 72 + mapNameSize;
    values::readStr(data, idx, description, descriptionSize);

    idx = firstTownIndex(data, input.firstTownName);
    if (idx != 0)
    {
        town::readAllTowns(data, idx, input.townCount, towns);
    }

    idx = firstHeroIndex(data, input.firstHeroName);
    if (idx != 0)
    {
        readAllHeroes(data, idx, heroes);
    }
}

bool SaveFile::valid() const
{
    return memcmp(this->header, fileHeader, sizeof(fileHeader)) == 0;
}

Town SaveFile::findTown(const std::string &name) const
{
    for (const auto &town : towns)
    {
        if (town.name == name)
        {
            return town;
        }
    }
    return {};
}

Hero SaveFile::findHero(const std::string &name) const
{
    // TODO: This is silly.
    std::string nameHolder;
    nameHolder.reserve(sizeof(Hero::name));

    for (const auto &hero : heroes)
    {
        nameHolder = std::string(reinterpret_cast<const char*>(hero.name));
        if (name == nameHolder)
        {
            return hero;
        }
    }
    return {};
}
} // namespace h3::savefile
