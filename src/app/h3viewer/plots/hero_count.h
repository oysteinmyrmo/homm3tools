#pragma once

#include <h3viewer/savefile_series.h>
#include <h3viewer/player.h>

#include <h3/player.h>

#include <array>
#include <cstdint>
#include <vector>

namespace h3viewer::hero_count
{
struct PlotData
{
    struct Settings
    {
        bool showVanquishedDay = false;
        bool showHeroesInGarrison = false;
    };

    PlotData() = default;
    PlotData(const PlotData &) = default;
    explicit PlotData(const SaveFileSeries &series);

    size_t allHeroesMaxValue() const;

    Players players;
    std::array<std::vector<uint64_t>, h3::player::maxPlayers> allHeroes;   // All heroes, including those in garrison
    std::array<std::vector<uint64_t>, h3::player::maxPlayers> heroesOnMap; // Heroes on map (as in in-game thieves guild).
    std::vector<uint64_t> x_vals;
    Settings settings;
};

void reset(const SaveFileSeries &series);
void draw();
} // namespace h3viewer::hero_count
