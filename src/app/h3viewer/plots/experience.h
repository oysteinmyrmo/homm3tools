#pragma once

#include <h3viewer/savefile_series.h>
#include <h3viewer/player.h>

#include <h3/player.h>

#include <array>
#include <cstdint>
#include <vector>

namespace h3viewer::experience
{
struct PlotData
{
    struct Settings
    {
        bool showVanquishedDay = false;
        bool includeHeroesInGarrison = false;
    };

    PlotData() = default;
    PlotData(const PlotData &) = default;
    explicit PlotData(const SaveFileSeries &series);

    size_t maxValue() const;

    Players players;
    std::array<std::vector<uint64_t>, h3::player::maxPlayers> experience;
    std::array<std::vector<uint64_t>, h3::player::maxPlayers> experienceAllHeroes;
    std::vector<uint64_t> x_vals;
    Settings settings;
};

void reset(const SaveFileSeries &series);
void drawTools();
void drawPlot();
} // namespace h3viewer::experience
