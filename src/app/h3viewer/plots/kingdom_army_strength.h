#pragma once

#include <h3viewer/savefile_series.h>
#include <h3viewer/player.h>

#include <h3/player.h>

#include <array>
#include <cstdint>
#include <vector>

namespace h3viewer::kingdom_army_strength
{
struct PlotData
{
    struct Settings
    {
        bool showVanquishedDay = false;
    };

    PlotData() = default;
    PlotData(const PlotData &) = default;
    explicit PlotData(const SaveFileSeries &series);

    Players players;
    std::array<std::vector<uint64_t>, h3::player::maxPlayers> kas;
    std::vector<uint64_t> x_vals;
    uint64_t max = 0;
    Settings settings;
};

void reset(const SaveFileSeries &series);
void drawTools();
void drawPlot();
} // namespace h3viewer::kingdom_army_strength
