#pragma once

#include "hero.h"
#include "player.h"
#include "town.h"

#include <array>
#include <filesystem>
#include <span>
#include <string>
#include <string_view>
#include <utility>
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

size_t firstPlayerIndex(size_t firstTownIdx);
std::pair<size_t, size_t> firstTownIndexAndCount(const std::span<const char> data, size_t firstHeroIdx);
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

struct SaveFile
{
    struct Input
    {
        // Attempt to read all the towns automatically, bacwards from the first hero.
        // The towns are stored right before the heroes, but with varying length. The
        // default town names must be used to read the towns.
        bool readAllTownsAutomatically() const { return firstTownName.empty() || numberOfTowns == 0; }

        // The path to the HotA save file to read.
        fs::path path;

        // The name of the start town for red player is used to read all the towns.
        // Note: If not provided an attempt will be made to find all towns, read backwards
        // from the first Hero, using the default town names. This means that if any town
        // name is not default in the map, the name of the first town must be provided.
        std::string firstTownName;

        // Number of towns in the save file must be provided if any town uses a
        // non-default name. If all town names are default, this can be left as 0,
        // making an attempt to read all the towns automatically backwards.
        size_t numberOfTowns = 0;

        // The name of the first hero is Orrin, if not changed in the map. This is
        // used to read all the heroes when opening the save file.
        std::string firstHeroName = defaultFirstHeroName;
    };

    static constexpr size_t offsetofHeader() { return 0; }
    static constexpr size_t offsetofMapSize() { return 63; }
    static constexpr size_t offsetofHasUnderground() { return 67; }
    static constexpr size_t offsetofMapNameSizeInSaveFile() { return 68; }

    explicit SaveFile(const Input &input);

    bool valid() const;
    bool normalSaveFile() const;
    bool campaignSaveFile() const;

    static bool valid(const std::string &header);
    static bool normalSaveFile(const std::string &header);
    static bool campaignSaveFile(const std::string &header);

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

    std::array<player::PlayerData, player::maxPlayers> players;
    std::vector<Town> towns;
    std::array<Hero, hero::heroCount> heroes;
};
} // namespace h3::savefile

namespace h3
{
using SaveFile = savefile::SaveFile;
}
