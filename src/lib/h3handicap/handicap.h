#pragma once
#include <array>
#include <cstdint>

#include <h3/difficulty.h>
#include <h3/player.h>

namespace h3handicap
{
struct PlayerHandicap
{
    double handicap = 0.0;
    bool enabled = false;
};

using PlayerHandicaps = std::array<PlayerHandicap, h3::player::maxPlayers>;

struct GameInput
{
    PlayerHandicaps handicaps;
    h3::difficulty::Difficulty difficulty;
};

//struct Debt
//{
//    double normalizedDebt = 0.0;
//    uint8_t player = uint8_t(-1);
//};

//using PlayerDebts = std::array<Debt, h3::player::maxPlayers>;

void calculateDebt(const GameInput &input);
} // namespace h3handicap