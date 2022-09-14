#include "best_creature.h"

#include <h3/player.h>

#include <implot.h>

#include <cmath>
#include <numeric>

namespace h3viewer::plot
{
BestCreaturePlot::BestCreaturePlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart##BestCreaturePlot"},
        CheckBoxSetting{"Show Vanquish Lines##BestCreaturePlot"}
    };

    axisTexts = {
        {"Best Creature (AI Value)"},
        {"Day"},
        {"Best Creature"},
    };
}

void BestCreaturePlot::invalidate(const SaveFileSeries &series)
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
            yVals[j][i] = players[j].bestCreatureAIValue();
        }
    }

    if (showAsPercentageStackedAreaChart())
    {
        setupPercentageStackedAreaChart();
    }
}

void BestCreaturePlot::drawPlotSpecifics()
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

bool BestCreaturePlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool BestCreaturePlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}
} // namespace h3viewer::plot
