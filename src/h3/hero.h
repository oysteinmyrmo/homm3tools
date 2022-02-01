#pragma once

#include <array>
#include <cstdint>
#include <span>

namespace h3::hero
{
// Total hero count as per https://heroes.thelazy.net/index.php/List_of_heroes_(HotA)
// A save file always contains all heroes.
static constexpr size_t heroCount = 179;

enum class Orientation : uint8_t
{
    N  = 0,
    NE = 1,
    E  = 2,
    SE = 3,
    S  = 4,
    SW = 5,
    W  = 6,
    NW = 7
};

struct Hero
{
    static constexpr size_t offsetFromNameToStart() { return offsetof(Hero, name); }

    // Offsets are relative to name.
    uint16_t x = -1;                // -196
    uint16_t y = -1;                // -194
    uint16_t z = -1;                // -192
    uint8_t _unused1[36];
    Orientation orientation;        // -154
    uint8_t _unused2[2];
    uint16_t dest_x = -1;           // -151
    uint8_t _unused3[2];
    uint16_t dest_y = -1;           // -147
    uint8_t _unused4[2];
    uint16_t dest_z = -1;           // -143
    uint8_t _unused5[141];
    uint8_t name[13];               // 0
    uint8_t _unused6[938];          // 13
} __attribute__((__packed__));

void readHero(const std::span<const char> data, size_t &idx, Hero &hero);
void readAllHeroes(const std::span<const char> data, size_t idx, std::span<Hero> output);
} // namespace h3::hero
