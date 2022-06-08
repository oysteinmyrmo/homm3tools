#include "savefile.h"
#include "value_reader.h"

#include <zlib.h>

#include <array>
#include <cassert>
#include <cstring>
#include <fstream>
#include <span>
#include <string>

namespace
{
namespace fs = std::filesystem;
using h3::savefile::MapSize;
using h3::savefile::SaveFile;

struct MapProperties
{
    MapSize mapSize = MapSize::NA;
    bool hasUnderground = false;
};

int decompressBytes(std::span<unsigned char> compressed, std::span<unsigned char> decompressed)
{
    z_stream zStream;
    memset(&zStream, 0, sizeof(zStream));

    zStream.next_in = static_cast<Bytef*>(compressed.data());
    zStream.avail_in = static_cast<uInt>(compressed.size());

    zStream.next_out = static_cast<Bytef*>(decompressed.data());
    zStream.avail_out = static_cast<uInt>(decompressed.size());

    const int err = inflateInit2(&zStream, MAX_WBITS + 16); // + 16 --> decode gzip format
    return (err == Z_OK) ? inflate(&zStream, Z_FINISH) : err;
}

MapProperties readMapProperties(std::span<unsigned char> compressed)
{
    // We read data up to and including hasUnderground.
    constexpr size_t propsSize = offsetof(SaveFile, hasUnderground) + sizeof(SaveFile::hasUnderground);
    std::array<unsigned char, propsSize> decompressed;

    const int err = decompressBytes(compressed, decompressed);

    // When Z_FINISH is used, Z_BUF_ERROR is returned instead of Z_OK (by design).
    if (err == Z_BUF_ERROR)
    {
        constexpr size_t mapSizeIdx = offsetof(SaveFile, mapSize);
        constexpr size_t undergroundIdx = offsetof(SaveFile, hasUnderground);
        return MapProperties{ MapSize(decompressed[mapSizeIdx]), bool(decompressed[undergroundIdx]) };
    }

    return {};
}

std::string readFileHeader(std::span<unsigned char> compressed)
{
    // We read data up to and including hasUnderground.
    constexpr size_t headerSize = offsetof(SaveFile, header) + sizeof(SaveFile::header);
    std::array<unsigned char, headerSize> decompressed;

    const int err = decompressBytes(compressed, decompressed);

    // When Z_FINISH is used, Z_BUF_ERROR is returned instead of Z_OK (by design).
    if (err == Z_BUF_ERROR)
    {
        return std::string(decompressed.begin(), decompressed.end());
    }

    return {};
}

bool isCompressedSaveFile(std::span<unsigned char> compressed)
{
    const std::string header = readFileHeader(compressed);
    return SaveFile::valid(header);
}

// TODO: Find decent values by creating several random maps and view their decompressed size.
size_t approximateDecompressedSize(const MapProperties props)
{
    const size_t factor = props.hasUnderground ? 2 : 1;
    constexpr size_t MiB = 1048576;

    switch (props.mapSize)
    {
    case MapSize::S:
    case MapSize::M:
    case MapSize::L:
    case MapSize::XL:
    case MapSize::H:
    case MapSize::XH:
    case MapSize::G:
    case MapSize::NA:
        return MiB * factor;
    default:
        return 0;
    }
}
} // namespace

namespace h3::savefile
{
std::vector<char> decompress(const fs::path& path)
{
    if (!fs::is_regular_file(path))
    {
        printf("Error: %s is not a regular file.\n", path.string().c_str());
        return {};
    }

    const size_t compressedSize = std::filesystem::file_size(path);
    std::vector<unsigned char> compressed;
    std::ifstream fileStream(path, std::ios::binary);
    if (compressedSize == 0 || !fileStream)
    {
        return {};
    }

    compressed.resize(compressedSize);
    char *output = reinterpret_cast<char*>(&compressed[0]);
    fileStream.read(output, compressedSize); // Read everything.
    fileStream.close();

    if (!isCompressedSaveFile(compressed))
    {
        return {};
    }

    const MapProperties props = readMapProperties(compressed);

    std::vector<unsigned char> buf;
    buf.resize(262144); // 256 kiB, as recommended by Zlib.

    z_stream zStream;
    memset(&zStream, 0, sizeof(zStream));

    zStream.next_in = static_cast<Bytef*>(compressed.data());
    zStream.avail_in = static_cast<uInt>(compressed.size());

    zStream.next_out = static_cast<Bytef*>(buf.data());
    zStream.avail_out = static_cast<uInt>(buf.size());

    int err = inflateInit2(&zStream, MAX_WBITS + 16); // + 16 --> decode gzip format
    if (err == Z_OK)
    {
        std::vector<char> decompressed;
        decompressed.reserve(approximateDecompressedSize(props));
        uLong prev_total = 0;

        while (err == Z_OK)
        {
            err = inflate(&zStream, Z_SYNC_FLUSH);
            if (err == Z_OK || err == Z_STREAM_END)
            {
                const uLong bytes = zStream.total_out - prev_total;
                prev_total = zStream.total_out;

                decompressed.insert(decompressed.end(), buf.data(), buf.data() + bytes);

                zStream.next_in = static_cast<Bytef*>(compressed.data() + zStream.total_in);
                zStream.avail_in = static_cast<uInt>(compressed.size() - zStream.total_in);

                zStream.next_out = static_cast<Bytef*>(buf.data());
                zStream.avail_out = static_cast<uInt>(buf.size());
            }
            else if (err == Z_DATA_ERROR)
            {
                // There is something wrong at the end of all the save files.
                // The last 4 bytes cannot be read properly and the error message
                // is "incorrect" data check. It is currently not known why or
                // what this is, and the error is simply ignored.
                assert(zStream.avail_in == 4);

                const uLong bytes = zStream.total_out - prev_total;
                decompressed.insert(decompressed.end(), buf.data(), buf.data() + bytes);
                return decompressed; // Early return because of the special case.
            }
        }

        if (err == Z_STREAM_END)
        {
            return decompressed;
        }
    }
    else
    {
        printf("Error %d when decompressing save file: %s\n", err, zStream.msg);
    }

    return {};
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

// Note: firstTownIdx is identical to firstHeroIdx if the map has no towns.
size_t firstPlayerIndex(const size_t firstTownIdx)
{
    return firstTownIdx - (player::maxPlayers * sizeof(player::PlayerData));
}

// Returns index of first town and town count.
std::pair<size_t, size_t> firstTownIndexAndCount(const std::span<const char> data, const size_t firstHeroIdx)
{
    size_t townEndIdx = firstHeroIdx - 1;
    size_t townCount = 0;
    bool townFound = true;

    while(townFound)
    {
        townFound = false;

        // Note: This is an approximation since the length of the town name is unknown.
        const size_t townStartIdx = townEndIdx - Town::sizeOfWithoutName() - town::longestTownName();
        std::span searchData{data.data() + townStartIdx, townEndIdx - townStartIdx};

        for (const char *town : town::townNames)
        {
            const auto townNameIt = std::search(searchData.begin(), searchData.end(), town, town + strlen(town));

            // Found a legit town name, continue searching backwards in the save file data.
            if (townNameIt != searchData.end())
            {
                ++townCount;
                townFound = true;

                // Reset the index referring to the end of the next possible town.
                const size_t townNameIdx = townNameIt - data.begin();
                townEndIdx = townNameIdx - Town::offsetFromNameToStart() - 1;
                break;
            }
        }
    }

    // Note: This weirdness stems from the fact that the save file is slightly differenct
    // in the case where there are no towns. The "townEndIdx + 2" part should be wrong, but
    // it needs to be like that when no towns are present in the save file. It is not clear
    // at the time of writing why it is so, but this makes the plots and tests work for both
    // cases. This might come and bite at a later time...
    const size_t firstTownIdx = (townCount == 0) ? townEndIdx + 2 : townEndIdx + 1;
    return std::make_pair(firstTownIdx, townCount);
}

// The name of the first town in the file is always the name of red player's start town.
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
    values::skipVal(idx, _unused1);
    values::readVal(data, idx, heroCount);
    values::skipVal(idx, _unused2);
    values::readEnum(data, idx, mapSize);
    values::skipVal(idx, _unused3);
    values::readVal(data, idx, hasUnderground);
    values::readVal(data, idx, mapNameSize);
    values::readStr(data, idx, mapName, mapNameSize);
    values::readVal(data, idx, descriptionSize);
    values::readStr(data, idx, description, descriptionSize);

    const size_t firstHeroIdx = firstHeroIndex(data, input.firstHeroName);
    const auto [firstTownIdx, townCount] = [&data, &input, firstHeroIdx]()
    {
        return input.readAllTownsAutomatically()
            ? firstTownIndexAndCount(data, firstHeroIdx)
            : std::make_pair(firstTownIndex(data, input.firstTownName), input.numberOfTowns);
    }();
    const auto firstPlayerIdx = firstPlayerIndex(firstTownIdx);

    idx = firstPlayerIdx;
    if (idx > 0)
    {
        player::readAllPlayers(data, idx, players);
    }
    else
    {
        // TODO: Show a warning that "firstPlayerIndex" could not be found.
    }

    idx = firstTownIdx;
    if (idx > 0)
    {
        town::readAllTowns(data, idx, townCount, towns);
    }
    else
    {
        // TODO: Show a warning that "firstTownName" could not be found.
    }

    idx = firstHeroIdx;
    if (idx > 0)
    {
        hero::readAllHeroes(data, idx, heroes);
    }
    else
    {
        // TODO: Show a warning that "firstHeroName" could not be found.
    }
}

bool SaveFile::valid() const
{
    return normalSaveFile() || campaignSaveFile();
}

bool SaveFile::normalSaveFile() const
{
    return normalSaveFile({std::begin(this->header), std::end(this->header)});
}

bool SaveFile::campaignSaveFile() const
{
    return campaignSaveFile({std::begin(this->header), std::end(this->header)});
}

bool SaveFile::valid(const std::string &header)
{
    return normalSaveFile(header) || campaignSaveFile(header);
}

bool SaveFile::normalSaveFile(const std::string &header)
{
    return memcmp(header.data(), fileHeaderNormal, sizeof(fileHeaderNormal)) == 0;
}

bool SaveFile::campaignSaveFile(const std::string &header)
{
    return memcmp(header.data(), fileHeaderCampaign, sizeof(fileHeaderCampaign)) == 0;
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
