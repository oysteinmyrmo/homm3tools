#include "savefile.h"
#include "value_reader.h"

#include <zlib.h>

#include <cstring>
#include <fstream>

namespace h3::savefile
{
std::vector<char> decompress(const fs::path &path)
{
    if (!fs::is_regular_file(path))
    {
        printf("Error: %s is not a regular file.\n", path.c_str());
        return {};
    }

    gzFile inFileZ = gzopen(path.c_str(), "rb");
    if (inFileZ == NULL)
    {
        printf("Error: gzopen() failed for file %s.\n", path.c_str());
        return {};
    }

    std::vector<char> unzippedData;
    uint8_t unzipBuffer[8192];
    int unzippedBytes = 0;

    while (unzippedBytes >= 0)
    {
        unzippedBytes = gzread(inFileZ, unzipBuffer, 8192);
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

// First hero is always Orrin, unless he is renamed. If so, the current code fails.
size_t firstHeroPosition(const std::span<const char> data)
{
    const auto it = std::search(data.begin(), data.end(), std::begin(firstHeroName), std::end(firstHeroName));
    if (it != data.end())
    {
        const size_t firstHeroNamePos = it - data.begin();
        return firstHeroNamePos - Hero::offsetFromNameToStart();
    }
    return 0;
}

SaveFile::SaveFile(const fs::path &path)
{
    const auto data = decompress(path);
    if (data.empty())
    {
        return;
    }

    size_t idx = 0;
    values::readArr(data, idx, header);

    idx = firstHeroPosition(data);
    hero::readAllHeroes(data, idx, heroes);
}

bool SaveFile::valid() const
{
    return memcmp(this->header, fileHeader, sizeof(fileHeader)) == 0;
}
} // namespace h3::savefile
