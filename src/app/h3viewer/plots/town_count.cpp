#include "town_count.h"

#include <h3/player.h>

#include <implot.h>

namespace h3viewer::plot
{
TownsPlot::TownsPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart##TownsPlot"},
        CheckBoxSetting{"Show Vanquish Lines##TownsPlot"}
        // TODO: Add setting to split on towns/forts/citadels/castles.
    };

    axisTexts = {
        {"Towns"},
        {"Day"},
        {"Number of Towns"},
    };
}

void TownsPlot::invalidate(const SaveFileSeries &series)
{
    Plot::invalidate(series);

    for (auto &item : yVals)
    {
        item.resize(size(), 0);
    }

    for (size_t i = 0; i < size(); ++i)
    {
        const auto players{h3::player::players(series.files[i])};
        for (size_t j = 0; j < h3::player::maxPlayers; ++j)
        {
            for (const auto &town : players[j].towns())
            {
                ++yVals[j][i];
            }
        }
    }

    alterDataToChartType();
}

void TownsPlot::drawPlotSpecifics()
{
    if (showVanquishLines())
    {
        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            const auto &player = players[i];
            if (player.active)
            {
                const auto &name = player.name;
                const auto &color = player.color;

                ImPlot::SetNextLineStyle(color);
                ImPlot::PlotVLines("", &player.vanquishedDay, 1);
            }
        }
    }
}

bool TownsPlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool TownsPlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}
} // namespace h3viewer::plot
