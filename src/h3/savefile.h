#pragma once

#include "hero.h"
#include "town.h"

#include <array>
#include <filesystem>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace h3::savefile
{
namespace fs = std::filesystem;

// Note: AppleClang does not have constexpr std::string at the time of writing.
constexpr char defaultFirstHeroName[] = "Orrin";
constexpr uint8_t fileHeaderNormal[] = "H3SVG";
constexpr uint8_t fileHeaderCampaign[] = "H3SVC";

std::vector<char> decompress(const fs::path &path);
void write_decompressed(const fs::path &path, const std::span<const char> data);
void read_write_decompressed(const fs::path &path, const fs::path &outPath);

size_t firstTownIndex(const std::span<const char> data, const std::string &firstTownName);
size_t firstHeroIndex(const std::span<const char> data, const std::string &firstHeroName);

// All map sizes are quadratic (and may have underground).
enum class MapSize : uint8_t
{
    NA  =    0,
    S   =   36,
    M   =   72,
    L   =  108,
    XL  =  144,
    H   =  180,
    XH  =  216,
    G   =  252
};

PACKED_STRUCT_BEGIN
struct SaveFile
{
    struct Input
    {
        // The path to the HotA save file to read.
        fs::path path;

        // The name of the start town for red player is used to read all the towns.
        // It is always the first in the list, but its position (and name) is always
        // in a different location in the file because the entire map is saved earlier.
        std::string firstTownName;

        // Number of towns is currently not known from the save file. Therefore it must
        // be part of the input to read all towns.
        size_t townCount = 0;

        // The name of the first hero is Orrin, if not changed in the map. This is
        // used to read all the heroes when opening the save file.
        std::string firstHeroName = defaultFirstHeroName;
    };

    explicit SaveFile(const Input &input);
    bool valid() const;
    bool normalSaveFile() const;
    bool campaignSaveFile() const;

    Town findTown(const std::string &name) const;
    Hero findHero(const std::string &name) const;

    uint8_t header[8];
    uint8_t _unused1[48];
    uint16_t heroCount;       // byte 56 <-- Has correct value, not sure if this is what it means.
    uint8_t _unused2[5];
    MapSize mapSize;          // byte 63
    uint8_t _unused3[3];
    uint8_t hasUnderground;   // byte 67
    uint16_t mapNameSize;     // byte 68
    std::string mapName;      // byte 70
    uint16_t descriptionSize; // byte 70 + mapNameSize
    std::string description;  // byte 72 + mapNameSize

    std::vector<Town> towns;
    std::array<Hero, hero::heroCount> heroes;
}
PACKED_STRUCT_END;
} // namespace h3::savefile

namespace h3
{
using SaveFile = savefile::SaveFile;
}
