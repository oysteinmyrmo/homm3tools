#include "hero.h"
#include "value_reader.h"

namespace h3::hero
{
void readHero(const std::span<const char> data, size_t &idx, Hero &hero)
{
    values::readVal(data, idx, hero.x);
    values::readVal(data, idx, hero.y);
    values::readVal(data, idx, hero.z);
    values::skipVal(idx, hero.unused1);
    values::readArr(data, idx, hero.name);
    values::skipVal(idx, hero.unused2);
}

void readAllHeroes(const std::span<const char> data, size_t idx, std::span<Hero> heroes)
{
    for (auto &hero : heroes)
    {
        readHero(data, idx, hero);
    }
}
} // namespace h3::hero
