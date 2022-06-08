#include "gold.h"

#include <h3/player.h>

#include <implot.h>

namespace h3viewer::plot
{
GoldPlot::GoldPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart##GoldPlot"},
        CheckBoxSetting{"Show Vanquish Lines##GoldPlot"},
    };

    axisTexts = {
        {"Gold"},
        {"Day"},
        {"Gold Amount at end of Day"},
    };
}

void GoldPlot::invalidate(const SaveFileSeries &series)
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
            if (players[j].alive())
            {
                yVals[j][i] += players[j].gold();
            }
        }
    }

    alterDataToChartType();
}

void GoldPlot::drawPlotSpecifics()
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

bool GoldPlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool GoldPlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}
} // namespace h3viewer::plot
