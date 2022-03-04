#pragma once

#include <h3/player.h>

#include <imgui.h>

#include <array>
#include <string>

namespace h3viewer
{
struct Player
{
    std::string name;
    ImVec4 color;
    bool active = false; // Whether or not the player is part of the game.
};

using Players = std::array<Player, h3::player::maxPlayers>;
Players defaultPlayers();
} // namespace h3viewer
