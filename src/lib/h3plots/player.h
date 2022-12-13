#pragma once
#include <h3/player.h>

#include <array>
#include <cstdint>
#include <string>

namespace h3plots
{
struct Player
{
    std::string name;
    std::array<uint8_t, 3> color{0, 0, 0};
    uint64_t vanquishedDay = 0;
    bool active = false; // Whether or not the player is part of the game.
};

using Players = std::array<Player, h3::player::maxPlayers>;
Players defaultPlayers();
} // namespace h3plots
