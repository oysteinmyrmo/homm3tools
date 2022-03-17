#pragma once

#include "creatures.h"
#include "packed_structs.h"
#include "stats.h"

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <vector>

namespace h3::town
{
using creatures::maxStacks;

// Note: The size of the Town struct in the save file is variable due to the size
// of the name being variable. sizeof(Town) is therefore 545 + name.size().
PACKED_STRUCT(
struct Town
{
    static constexpr size_t offsetFromNameToStart() { return offsetof(Town, name); }
    static constexpr size_t sizeOfWithoutName() { return 546; }
    static constexpr uint8_t noOwner = 0xFF;

    size_t sizeOfWithName() const { return sizeOfWithoutName() + name.size(); }
    uint64_t armyStrength() const { return stats::army_strength(*this); }

    uint8_t owner;                          // -71
    uint8_t _unused0[3];
    uint8_t x;                              // -67
    uint8_t y;                              // -66
    uint8_t z;                              // -65
    uint8_t _unused1[2];
    Creature creatures[maxStacks];          // -62
    uint32_t creature_count[maxStacks];     // -34
    uint8_t _unused2[4];
    uint16_t nameSize;                      // -2  <-- Note: The town name is of variable size.
    std::string name;                       // 0
    // Remaining bytes intentionally left out.
});

void readTown(const std::span<const char> data, size_t idx, Town &hero);
void readAllTowns(const std::span<const char> data, size_t idx, size_t count, std::vector<Town> &towns);
} // namespace h3::town

namespace h3
{
using Town = town::Town;
}
