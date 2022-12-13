#include "gold.h"

#include <h3/player.h>

namespace h3plots::plot
{
GoldPlot::GoldPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart"},
        CheckBoxSetting{"Show Vanquish Lines"},
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

bool GoldPlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool GoldPlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}
} // namespace h3plots::plot
