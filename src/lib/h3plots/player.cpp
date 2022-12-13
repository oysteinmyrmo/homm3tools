#include "player.h"

namespace h3plots
{
Players defaultPlayers()
{
    Players players;

    const auto &colors = h3::player::playerColors;
    const auto &names = h3::player::playerColorsStr;
    for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
    {
        players[i].name = names[i];
        players[i].color[0] = colors[i].r;
        players[i].color[1] = colors[i].g;
        players[i].color[2] = colors[i].b;
        players[i].active = false;
    }

    return players;
};
} // namespace h3plots
