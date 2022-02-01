#pragma once

#include "hero.h"

#include <array>
#include <filesystem>
#include <span>
#include <string_view>
#include <vector>

namespace h3::savefile
{
namespace fs = std::filesystem;
using hero::Hero;

// AppleClang does not have constexpr std::string at the time of writing.
constexpr uint8_t firstHeroName[] = "Orrin";
constexpr uint8_t fileHeader[] = "H3SVG";

std::vector<char> decompress(const fs::path &path);
void write_decompressed(const fs::path &path, const std::span<const char> data);
void read_write_decompressed(const fs::path &path, const fs::path &outPath);

size_t firstHeroPosition(const std::span<const char> data);

struct SaveFile
{
    explicit SaveFile(const fs::path &path);
    bool valid() const;

    uint8_t header[8];
    std::array<Hero, hero::heroCount> heroes;
};
} // namespace h3::savefile
