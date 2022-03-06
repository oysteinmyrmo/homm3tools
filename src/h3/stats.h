#pragma once

#include "creatures.h"

#include <cstdint>

namespace h3::hero
{
struct Hero;
} // namespace h3::hero

namespace h3::town
{
struct Town;
} // namespace h3::town

namespace h3::stats
{
uint64_t ai_value(const h3::Creature creature, const uint32_t count);
uint64_t ai_value(const h3::hero::Hero &hero);
uint64_t ai_value(const h3::town::Town &town);
uint64_t army_strength(const h3::hero::Hero &hero);
uint64_t army_strength(const h3::town::Town &town);
} // namespace h3::stats
