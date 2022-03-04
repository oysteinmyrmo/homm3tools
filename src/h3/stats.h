#pragma once

#include "hero.h"

#include <cstdint>

namespace h3::stats
{
uint64_t ai_value(const Creature creature, const uint32_t count);
uint64_t ai_value(const Hero &hero);
uint64_t army_strength(const Hero &hero);
} // namespace h3::stats
