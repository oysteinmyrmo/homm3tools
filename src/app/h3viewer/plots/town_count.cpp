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
        x_vals[i] = i + 1; // The x-values are simply the day from 1 through N.
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

void drawTools()
{
    ImGui::Checkbox("Show Vanquish Lines##Towns", &gPlotData.settings.showVanquishedDay);
}

void drawPlot()
{
    const auto &plot = gPlotData;

    if (ImPlot::BeginPlot("Number of Towns"))
    {
        ImPlot::SetupAxes("Day", "Number of Towns");
        if (gWasReset)
        {
            gWasReset = false;
            const double sizeX = double(plot.x_vals.size());
            const double sizeY = double(plot.max);
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
                const auto &y_vals = plot.towns[i].data();

                ImPlot::SetNextLineStyle(color);
                ImPlot::PlotLine(name.c_str(), x_vals, y_vals, size);

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
} // namespace h3viewer::kingdom_army_strength

