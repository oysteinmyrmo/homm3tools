#include "artifacts.h"

#include <h3/artifacts.h>
#include <h3/hero.h>
#include <h3/player.h>

namespace h3plots::plot
{
ArtifactsPlot::ArtifactsPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart"},
        CheckBoxSetting{"Show Vanquish Lines"},
        RadioButtonSetting{
            {.text="Artifact Class"},
            {
                {"All"},
                {"Treasure"},
                {"Minor"},
                {"Major"},
                {"Relic"},
                {"Combo"},
            }
        },
        RadioButtonSetting{
            {.text="Customize"},
            {
                {"Count"},
                {"Value"},
            }
        },
    };

    axisTexts = {
        {"Artifacts"},
        {"Day"},
        {"Artifacts"},
    };
}

void ArtifactsPlot::invalidate(const SaveFileSeries &series)
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
            const auto &player = players[j];
            if (player.alive())
            {
                h3::player::forEachHero(player, [&](const h3::Hero &hero)
                {
                    h3::hero::forEachArtifact(hero, [&](const h3::artifacts::Artifact &artifact,
                                                        const h3::artifacts::ArtifactDetails &details)
                    {
                        const bool add = showAll()
                                      || (showTreasure() && details.isTreasure())
                                      || (showMinor() && details.isMinor())
                                      || (showMajor() && details.isMajor())
                                      || (showRelic() && details.isRelic())
                                      || (showCombo() && details.isCombo());

                        if (add && showCount())
                        {
                            ++yVals[j][i];
                        }
                        else if (add && showValue())
                        {
                            yVals[j][i] += details.cost;
                        }
                    });
                });
            }
        }
    }

    alterDataToChartType();
}

bool ArtifactsPlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool ArtifactsPlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}

bool ArtifactsPlot::showAll() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 0;
}

bool ArtifactsPlot::showTreasure() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 1;
}

bool ArtifactsPlot::showMinor() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 2;
}

bool ArtifactsPlot::showMajor() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 3;
}

bool ArtifactsPlot::showRelic() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 4;
}

bool ArtifactsPlot::showCombo() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 5;
}

bool ArtifactsPlot::showCount() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 0;
}

bool ArtifactsPlot::showValue() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 1;
}
} // namespace h3plots::plot
