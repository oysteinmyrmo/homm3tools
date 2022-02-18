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
using hero::Hero;
using town::Town;

// Note: AppleClang does not have constexpr std::string at the time of writing.
const std::string defaultFirstHeroName{"Orrin"};
constexpr uint8_t fileHeader[] = "H3SVG";

std::vector<char> decompress(const fs::path &path);
void write_decompressed(const fs::path &path, const std::span<const char> data);
void read_write_decompressed(const fs::path &path, const fs::path &outPath);

size_t firstTownIndex(const std::span<const char> data, const std::string &firstTownName);
size_t firstHeroIndex(const std::span<const char> data, const std::string &firstHeroName);

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

    const Town findTown(const std::string &name) const;
    const Hero findHero(const std::string &name) const;

    uint8_t header[8];
    MapSize mapSize; // byte 63
    std::vector<Town> towns;
    std::array<Hero, hero::heroCount> heroes;
};
} // namespace h3::savefile
