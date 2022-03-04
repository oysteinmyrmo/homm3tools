#pragma once

#include "savefile_series.h"
#include "player.h"

#include <h3/player.h>

#include <array>
#include <cstdint>
#include <vector>

namespace h3viewer::kingdom_army_strength
{
struct PlotData
{
    PlotData() = default;
    PlotData(const PlotData &) = default;
    explicit PlotData(const savefile_series::SaveFileSeries &series);

    Players players;
    std::array<std::vector<uint64_t>, h3::player::maxPlayers> kas;
    std::vector<uint64_t> x_vals;
    uint64_t max = 0;
};

void reset(const savefile_series::SaveFileSeries &series);
void draw();
} // namespace h3viewer::kingdom_army_strength
