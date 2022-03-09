#include "kingdom_army_strength.h"

#include <imgui.h>
#include <implot.h>

namespace
{
h3viewer::kingdom_army_strength::PlotData gPlotData;
bool gWasReset = false;
} // namespace

namespace h3viewer::kingdom_army_strength
{
PlotData::PlotData(const SaveFileSeries &series) : players(series.players)
{
    const auto size = series.files.size();

    x_vals.resize(size, 0);
    for (uint64_t i = 0; i < size; ++i)
    {
        x_vals[i] = i + 1; // The x-values are simply the day from 1 through N.
    }

    for (auto &item : kas)
    {
        item.resize(size, 0);
    }

    for (size_t i = 0; i < size; ++i)
    {
        const auto players{h3::player::players(series.files[i])};
        for (size_t j = 0; j < h3::player::maxPlayers; ++j)
        {
            const uint64_t strength = players[j].kingdomArmyStrength();
            max = std::max(max, strength);
            kas[j][i] = strength;
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
    ImGui::Checkbox("Show Vanquish Lines##KAS", &gPlotData.settings.showVanquishedDay);
}

void drawPlot()
{
    const auto &plot = gPlotData;

    if (ImPlot::BeginPlot("Kingdom Army Strength"))
    {
        ImPlot::SetupAxes("Day","Kingdom Army Strength");
        if (gWasReset)
        {
            gWasReset = false;
            ImPlot::SetupAxesLimits(1, plot.x_vals.size(), 0, plot.max, ImPlotCond_Always);
        }

        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            const auto &player = plot.players[i];
            if (player.active)
            {
                const auto &name = player.name;
                const auto &color = player.color;
                const auto &x_vals = plot.x_vals.data();
                const auto &y_vals = plot.kas[i].data();
                const auto &size = plot.x_vals.size();

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
