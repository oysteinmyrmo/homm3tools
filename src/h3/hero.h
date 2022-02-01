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

    uint16_t x = -1;
    uint16_t y = -1;
    uint16_t z = -1;
    uint8_t _unused1[36];
    Orientation orientation;
    uint8_t _unused2[153];
    uint8_t name[13];
    uint8_t _unused3[938];
};

void readHero(const std::span<const char> data, size_t &idx, Hero &hero);
void readAllHeroes(const std::span<const char> data, size_t idx, std::span<Hero> output);
} // namespace h3::hero
