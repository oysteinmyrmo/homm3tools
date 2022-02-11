#pragma once

#include "hero.h"

#include <cstdint>

namespace h3::stats
{
uint64_t ai_value(const creatures::Creature creature, const uint32_t count);
uint64_t ai_value(const hero::Hero &hero);
uint64_t army_strength(const hero::Hero &hero);
} // namespace h3::stats
