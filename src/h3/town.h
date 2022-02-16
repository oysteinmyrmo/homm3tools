#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

namespace h3::town
{
struct Town
{
    static constexpr size_t offsetFromNameToStart() { return offsetof(Town, name); }

    uint8_t name[13];
};

void readTown(const std::span<const char> data, size_t idx, Town &hero);
void readAllTowns(const std::span<const char> data, size_t idx, std::vector<Town> &output);
} // namespace h3::town
