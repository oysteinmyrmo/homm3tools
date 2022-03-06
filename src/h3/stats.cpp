#include "stats.h"
#include "creatures.h"
#include "hero.h"
#include "town.h"

#include <cmath>

namespace
{
uint64_t AIValue(const h3::Creature creature, const uint32_t count)
{
    return h3::creatures::AIValues.at(creature) * count;
}

uint64_t sumAIValues(const auto &creatures, const auto &creature_count)
{
    uint64_t strength = 0;
    for (size_t i = 0; i < h3::creatures::maxStacks; ++i)
    {
        strength += AIValue(creatures[i], creature_count[i]);
    }
    return strength;
}
} // namespace

namespace h3::stats
{
uint64_t ai_value(const Creature creature, const uint32_t count)
{
    return AIValue(creature, count);
}

uint64_t ai_value(const Hero &hero)
{
    return sumAIValues(hero.creatures, hero.creature_count);
}

uint64_t army_strength(const Hero &hero)
{
    const uint64_t aiValue = ai_value(hero);
    if (hero.on_map)
    {
        // Formula taken from https://heroes.thelazy.net/index.php/Army_strength
        const double heroFactor = std::sqrt((hero.attackInGame() * 0.05 + 1.0) * (hero.defenseInGame() * 0.05 + 1.0));
        return uint64_t(aiValue * heroFactor);
    }
    return aiValue;
}

uint64_t army_strength(const Town &town)
{
    return sumAIValues(town.creatures, town.creature_count);
}
} //namespace h3::stats
