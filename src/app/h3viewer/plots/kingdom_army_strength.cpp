#include "kingdom_army_strength.h"

#include <h3/player.h>

#include <implot.h>

#include <cmath>
#include <numeric>

namespace h3viewer::plot
{
KingdomArmyStrengthPlot::KingdomArmyStrengthPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart##KingdomArmyStrengthPlot"},
        CheckBoxSetting{"Show Vanquish Lines##KingdomArmyStrengthPlot"}
    };

    axisTexts = {
        {"Kingdom Army Strength"},
        {"Day"},
        {"Kingdom Army Strength"},
    };
}

void KingdomArmyStrengthPlot::invalidate(const SaveFileSeries &series)
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
            yVals[j][i] = players[j].kingdomArmyStrength();
        }
    }

    if (showAsPercentageStackedAreaChart())
    {
        setupPercentageStackedAreaChart();
    }
}

void KingdomArmyStrengthPlot::drawPlotSpecifics()
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

bool KingdomArmyStrengthPlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool KingdomArmyStrengthPlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}
} // namespace h3viewer::plot
