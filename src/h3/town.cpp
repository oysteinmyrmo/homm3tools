#include "town.h"
#include "value_reader.h"

namespace h3::town
{
static_assert(Town::offsetFromNameToStart() == 67, "Offset to Town::name must be 67.");

void readTown(const std::span<const char> data, size_t idx, Town &town)
{
    auto *foo = &data[idx];
    values::readVal(data, idx, town.x);
    values::readVal(data, idx, town.y);
    values::readVal(data, idx, town.z);
    values::skipVal(idx, town._unused0);
    values::readVal(data, idx, town.nameSize);
    values::readStr(data, idx, town.name, town.nameSize);
    // Intentionally stop reading more values here.
}

void readAllTowns(const std::span<const char> data, size_t idx, const size_t count, std::vector<Town> &towns)
{
    towns.resize(count);
    for (auto &town : towns)
    {
        readTown(data, idx, town);
        assert(town.nameSize == town.name.size());
        idx += town.sizeOfWithName();
    }
}
} // namespace h3::town
