#include "hero_count.h"

#include <h3/player.h>

#include <imgui.h>
#include <implot.h>

#include <algorithm>
#include <utility>

namespace
{
h3viewer::hero_count::PlotData gPlotData;
bool gWasReset = false;
} // namespace

namespace h3viewer::hero_count
{
PlotData::PlotData(const SaveFileSeries &series) : players(series.players)
{
    const auto size = series.files.size();

    x_vals.resize(size, 0);
    for (uint64_t i = 0; i < size; ++i)
    {
        x_vals[i] = i + 1; // The x-values are simply the day from 1 through N.
    }

    for (auto &item : allHeroes)
    {
        item.resize(size, 0);
    }

    for (auto &item : heroesOnMap)
    {
        item.resize(size, 0);
    }

    for (size_t i = 0; i < size; ++i)
    {
        const auto players{h3::player::players(series.files[i])};
        for (size_t j = 0; j < h3::player::maxPlayers; ++j)
        {
            for (const auto &hero : players[j].heroes())
            {
                ++allHeroes[j][i];
                if (hero.on_map)
                {
                    ++heroesOnMap[j][i];
                }
            }
        }
    }
}

size_t PlotData::allHeroesMaxValue() const
{
    uint64_t max = 0;
    for (const auto &h : allHeroes)
    {
        const auto maxElement = std::max_element(h.begin(), h.end());
        const auto idx = std::distance(h.begin(), maxElement);
        max = std::max(max, h[idx]);
    }
    return max;
}

void reset(const SaveFileSeries &series)
{
    gPlotData = PlotData(series);
    gWasReset = true;
}

void drawTools()
{
    ImGui::Checkbox("Show Vanquish Lines##Heroes", &gPlotData.settings.showVanquishedDay);
    if (ImGui::Checkbox("Include Heroes In Garrison##Heroes", &gPlotData.settings.includeHeroesInGarrison))
    {
        gWasReset = true;
    }
}

void drawPlot()
{
    const auto &plot = gPlotData;

    if (ImPlot::BeginPlot("Number of Heroes"))
    {
        ImPlot::SetupAxes("Day", "Number of Heroes");
        if (gWasReset)
        {
            gWasReset = false;
            const uint64_t maxY = plot.settings.includeHeroesInGarrison ? plot.allHeroesMaxValue() : h3::player::maxPlayers;
            const double sizeX = double(plot.x_vals.size() + 1);
            const double sizeY = double(maxY + 1);
            ImPlot::SetupAxesLimits(1, sizeX, 0, sizeY, ImPlotCond_Always);
        }

        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            const auto &player = plot.players[i];
            if (player.active)
            {
                const auto &name = player.name;
                const auto &color = player.color;
                const auto &x_vals = plot.x_vals.data();
                const auto size = int(plot.x_vals.size());

                ImPlot::SetNextLineStyle(color);

                if (plot.settings.includeHeroesInGarrison)
                {
                    const auto &y_vals = plot.allHeroes[i].data();
                    ImPlot::PlotLine(name.c_str(), x_vals, y_vals, size);
                }
                else
                {
                    const auto &y_vals = plot.heroesOnMap[i].data();
                    ImPlot::PlotLine(name.c_str(), x_vals, y_vals, size);
                }

                if (plot.settings.showVanquishedDay)
                {
                    ImPlot::SetNextLineStyle(color);
                    ImPlot::PlotVLines("", &player.vanquishedDay, 1);
                }
            }
        }

        ImPlot::EndPlot();
    }
}
} // namespace h3viewer::hero_count

