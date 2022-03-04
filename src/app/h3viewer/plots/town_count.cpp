#include "town_count.h"

#include <imgui.h>
#include <implot.h>

#include <algorithm>
#include <utility>

namespace
{
h3viewer::town_count::PlotData gPlotData;
bool gWasReset = false;
} // namespace

namespace h3viewer::town_count
{
PlotData::PlotData(const SaveFileSeries &series)
    : players(series.players)
    , max(series.numberOfTowns)
{
    const auto size = series.files.size();

    x_vals.resize(size, 0);
    for (uint64_t i = 0; i < size; ++i)
    {
        x_vals[i] = i; // The x-values are simply the day from 0 through N.
    }

    for (auto &item : towns)
    {
        item.resize(size, 0);
    }

    for (size_t i = 0; i < size; ++i)
    {
        const auto players{h3::player::players(series.files[i])};
        for (size_t j = 0; j < h3::player::maxPlayers; ++j)
        {
            for (const auto &town : players[j].towns())
            {
                ++towns[j][i];
            }
        }
    }
}

void reset(const SaveFileSeries &series)
{
    gPlotData = PlotData(series);
    gWasReset = true;
}

void draw()
{
    const auto &plotData = gPlotData;

    if (ImPlot::BeginPlot("Number of Towns"))
    {
        ImPlot::SetupAxes("Day", "Number of Towns");
        if (gWasReset)
        {
            gWasReset = false;
            ImPlot::SetupAxesLimits(0, plotData.x_vals.size(), 0, plotData.max, ImPlotCond_Always);
        }

        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            const auto &player = plotData.players[i];
            if (player.active)
            {
                const auto &name = player.name;
                const auto &color = player.color;
                const auto &x_vals = plotData.x_vals.data();
                const auto &size = plotData.x_vals.size();
                const auto &y_vals = plotData.towns[i].data();

                ImPlot::SetNextLineStyle(color);
                ImPlot::PlotLine(name.c_str(), x_vals, y_vals, size);
            }
        }

        ImPlot::EndPlot();
    }
}
} // namespace h3viewer::kingdom_army_strength

