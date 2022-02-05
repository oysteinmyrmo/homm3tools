#include "hero.h"
#include "value_reader.h"

namespace h3::hero
{
static_assert(sizeof(Hero) == 1147, "sizeof(Hero) must be 1147.");
static_assert(Hero::offsetFromNameToStart() == 196, "Offset to Hero::name must be 196.");

void readHero(const std::span<const char> data, size_t idx, Hero &hero)
{
    values::readVal(data, idx, hero.x);
    values::readVal(data, idx, hero.y);
    values::readVal(data, idx, hero.z);
    values::skipVal(idx, hero._unused1);
    values::readEnum(data, idx, hero.orientation);
    values::skipVal(idx, hero._unused2);
    values::readVal(data, idx, hero.dest_x);
    values::skipVal(idx, hero._unused3);
    values::readVal(data, idx, hero.dest_y);
    values::skipVal(idx, hero._unused4);
    values::readVal(data, idx, hero.dest_z);
    values::skipVal(idx, hero._unused5);
    values::readArr(data, idx, hero.name);
    values::skipVal(idx, hero._unused6);
}

void readAllHeroes(const std::span<const char> data, size_t idx, std::span<Hero> heroes)
{
    for (auto &hero : heroes)
    {
        readHero(data, idx, hero);
        idx += sizeof(Hero);
    }
}
} // namespace h3::hero
