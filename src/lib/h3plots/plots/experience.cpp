#include "experience.h"

#include <h3/player.h>

namespace h3plots::plot
{
ExperiencePlot::ExperiencePlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart"},
        CheckBoxSetting{"Show Vanquish Lines"},
        CheckBoxSetting{"Include heroes in garrison"}
    };

    axisTexts = {
        {"Experience"},
        {"Day"},
        {"Accumulated Experience"},
    };
}

void ExperiencePlot::invalidate(const SaveFileSeries &series)
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
                    yVals[j][i] += hero.experience;
                }
            }
        }
    }

    alterDataToChartType();
}

bool ExperiencePlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool ExperiencePlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}

bool ExperiencePlot::includeHeroesInGarrison() const
{
    return std::get<CheckBoxSetting>(settings[2]).checked;
}
} // namespace h3plots::plot
