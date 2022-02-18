#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <vector>

namespace h3::town
{
// Note: The size of the Town struct in the save file is variable due to the size
// of the name being variable. sizeof(Town) is therefore 545 + name.size().
struct Town
{
    static constexpr size_t offsetFromNameToStart() { return offsetof(Town, name); }
    static constexpr size_t sizeOfWithoutName() { return 546; }

    size_t sizeOfWithName() const { return sizeOfWithoutName() + name.size(); }

    uint8_t x;                  // -67
    uint8_t y;                  // -66
    uint8_t z;                  // -65
    uint8_t _unused0[62];
    uint16_t nameSize;          // -2  <-- Note: The town name is of variable size.
    std::string name;           // 0
//    uint8_t _unused1[545];
} __attribute__((__packed__));

void readTown(const std::span<const char> data, size_t idx, Town &hero);
void readAllTowns(const std::span<const char> data, size_t idx, size_t count, std::vector<Town> &towns);
} // namespace h3::town
