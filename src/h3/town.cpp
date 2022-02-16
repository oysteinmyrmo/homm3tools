#include "town.h"
#include "value_reader.h"

namespace h3::town
{
//static_assert(sizeof(Town) == 666, "sizeof(Town) must be 666.");
//static_assert(Town::offsetFromNameToStart() == 666, "Offset to Town::name must be 666.");

void readTown(const std::span<const char> data, size_t idx, Town &hero)
{
    
}

void readAllTowns(const std::span<const char> data, size_t idx, std::vector<Town> &output)
{
    output.reserve(32);
}
} // namespace h3::town
