#include "savefile.h"
#include "value_reader.h"

#include <zlib.h>

#include <array>
#include <cassert>
#include <cstring>
#include <fstream>
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

MapProperties readMapProperties(unsigned char *compressed, const size_t size)
{
    // We read data up to and including hasUnderground.
    constexpr size_t propsSize = offsetof(SaveFile, hasUnderground) + 1;
    std::array<unsigned char, propsSize> mapProperties;

    z_stream zStream;
    memset(&zStream, 0, sizeof(zStream));

    zStream.next_in = static_cast<Bytef*>(compressed);
    zStream.avail_in = static_cast<uInt>(size);

    zStream.next_out = static_cast<Bytef*>(mapProperties.data());
    zStream.avail_out = static_cast<uInt>(mapProperties.size());

    int err = inflateInit2(&zStream, MAX_WBITS + 16); // + 16 --> decode gzip format
    if (err == Z_OK)
    {
        err = inflate(&zStream, Z_FINISH);

        // When Z_FINISH is used, Z_BUF_ERROR is returned instead of Z_OK (by design).
        if (err == Z_BUF_ERROR)
        {
            constexpr size_t mapSizeIdx = offsetof(SaveFile, mapSize);
            constexpr size_t undergroundIdx = offsetof(SaveFile, hasUnderground);
            return MapProperties{ MapSize(mapProperties[mapSizeIdx]), bool(mapProperties[undergroundIdx]) };
        }
    }

    return {};
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
    if (fileStream)
    {
        compressed.resize(compressedSize, 0);
        char *output = reinterpret_cast<char*>(&compressed[0]);
        fileStream.read(output, compressedSize); // Read everything.
        fileStream.close();
    }

    MapProperties props = readMapProperties(compressed.data(), compressedSize);

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
