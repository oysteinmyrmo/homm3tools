#include "experience.h"

#include <h3/player.h>

#include <implot.h>

namespace h3viewer::plot
{
ExperiencePlot::ExperiencePlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show Vanquish Lines##ExperiencePlot"},
        CheckBoxSetting{"Include heroes in garrison##ExperiencePlot"}
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
}

void ExperiencePlot::drawPlotSpecifics()
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

bool ExperiencePlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool ExperiencePlot::includeHeroesInGarrison() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}
} // namespace h3viewer::plot
