#include "hero_count.h"

#include <h3/player.h>

namespace h3plots::plot
{
HeroesPlot::HeroesPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart"},
        CheckBoxSetting{"Show Vanquish Lines"},
        CheckBoxSetting{"Include heroes in garrison"}
    };

    axisTexts = {
        {"Heroes"},
        {"Day"},
        {"Number of Heroes"},
    };
}

void HeroesPlot::invalidate(const SaveFileSeries &series)
{
    Plot::invalidate(series);

    const bool includeGarrison = includeHeroesInGarrison();

    for (auto &item : yVals)
    {
        item.resize(size(), 0);
    }

    for (size_t i = 0; i < size(); ++i)
    {
        const auto players{h3::player::players(series.files[i])};
        for (size_t j = 0; j < h3::player::maxPlayers; ++j)
        {
            for (const auto &hero : players[j].heroes())
            {
                if (hero.on_map || includeGarrison)
                {
                    ++yVals[j][i];
                }
            }
        }
    }

    alterDataToChartType();

    if (showAsPercentageStackedAreaChart())
    {
        axisTexts.yText = "Number of Heroes (%)";
    }
    else
    {
        axisTexts.yText = "Number of Heroes";
    }
}

bool HeroesPlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool HeroesPlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}

bool HeroesPlot::includeHeroesInGarrison() const
{
    return std::get<CheckBoxSetting>(settings[2]).checked;
}
} // namespace h3plots::plot

