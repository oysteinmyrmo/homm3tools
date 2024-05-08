#include "difficulty.h"

namespace h3::difficulty
{
// See https://heroes.thelazy.net/index.php/Difficulty_level
const std::unordered_map<Difficulty, Income> incomeForDifficulties = {
    {Difficulty::Easy,       {.gold = 30000, .basic = 60, .magical = 60}},
    {Difficulty::Normal,     {.gold = 20000, .basic = 40, .magical = 40}},
    {Difficulty::Hard,       {.gold = 15000, .basic = 30, .magical = 28}},
    {Difficulty::Expert,     {.gold = 10000, .basic = 20, .magical = 16}},
    {Difficulty::Impossible, {.gold =     0, .basic =  0, .magical =  0}},
};
} // namespace difficulty