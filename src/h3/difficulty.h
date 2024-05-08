#pragma once

#include <unordered_map>

namespace h3::difficulty
{
struct Income
{
    int gold = 0;
    int basic = 0;   // Wood and ore
    int magical = 0; // Mercury, sulfur, crystal and gems
};

enum class Difficulty
{
    Easy = 0,
    Normal = 1,
    Hard = 2,
    Expert = 4,
    Impossible = 5,
};

extern const std::unordered_map<Difficulty, Income> incomeForDifficulties;
}
