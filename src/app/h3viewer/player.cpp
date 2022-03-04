#include "player.h"

namespace h3viewer
{
Players defaultPlayers()
{
    Players players;

    const auto &colors = h3::player::playerColors;
    const auto &names = h3::player::playerColorsStr;
    for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
    {
        players[i].name = names[i];
        players[i].color = ImVec4{colors[i].r / 255.0f, colors[i].g / 255.0f, colors[i].b / 255.0f, 1.0f};
        players[i].active = false;
    }

    return players;
};
} // namespace h3viewer
