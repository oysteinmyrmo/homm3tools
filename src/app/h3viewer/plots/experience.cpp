#include "experience.h"

#include <h3/player.h>

#include <imgui.h>
#include <implot.h>

#include <algorithm>
#include <utility>

namespace
{
h3viewer::experience::PlotData gPlotData;
bool gWasReset = false;
} // namespace

namespace h3viewer::experience
{
PlotData::PlotData(const SaveFileSeries &series) : players(series.players)
{
    const auto size = series.files.size();

    x_vals.resize(size, 0);
    for (uint64_t i = 0; i < size; ++i)
    {
        x_vals[i] = i + 1; // The x-values are simply the day from 1 through N.
    }

    for (auto &item : experience)
    {
        item.resize(size, 0);
    }

    for (auto &item : experienceAllHeroes)
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
                experienceAllHeroes[j][i] += hero.experience;
                if (hero.on_map)
                {
                    experience[j][i] += hero.experience;
                }
            }
        }
    }
}

size_t PlotData::maxValue() const
{
    uint64_t max = 0;
    const auto &data = settings.includeHeroesInGarrison ? experienceAllHeroes : experience;
    for (const auto &d : data)
    {
        const auto maxElement = std::max_element(d.begin(), d.end());
        const auto idx = std::distance(d.begin(), maxElement);
        max = std::max(max, d[idx]);
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
    ImGui::Checkbox("Show Vanquish Lines##Experience", &gPlotData.settings.showVanquishedDay);
    if (ImGui::Checkbox("Include Heroes In Garrison##Experience", &gPlotData.settings.includeHeroesInGarrison))
    {
        gWasReset = true;
    }
}

void drawPlot()
{
    const auto &plot = gPlotData;

    if (ImPlot::BeginPlot("Accumulated Experience"))
    {
        ImPlot::SetupAxes("Day", "Accumulated Experience");
        if (gWasReset)
        {
            gWasReset = false;
            const double sizeX = double(plot.x_vals.size() + 1);
            const double sizeY = double(plot.maxValue() + 1);
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
                    const auto &y_vals = plot.experienceAllHeroes[i].data();
                    ImPlot::PlotLine(name.c_str(), x_vals, y_vals, size);
                }
                else
                {
                    const auto &y_vals = plot.experience[i].data();
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
} // namespace h3viewer::experience

