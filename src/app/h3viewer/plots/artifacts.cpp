#include "artifacts.h"

#include <h3/artifacts.h>
#include <h3/hero.h>
#include <h3/player.h>

#include <implot.h>

namespace h3viewer::plot
{
ArtifactsPlot::ArtifactsPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart##ArtifactsPlot"},
        CheckBoxSetting{"Show Vanquish Lines##ArtifactsPlot"},
        SettingSeparator{},
        RadioButtonSetting{
            {.text="Artifact Class##ArtifactsPlot"},
            {
                {"All##ArtifactsPlot", true},
                {"Treasure##ArtifactsPlot"},
                {"Minor##ArtifactsPlot"},
                {"Major##ArtifactsPlot", true},
                {"Relic##ArtifactsPlot"},
                {"Combo##ArtifactsPlot", true},
            }
        },
        SettingSeparator{},
        RadioButtonSetting{
            {.text="Customize##ArtifactsPlot"},
            {
                {"Count##ArtifactsPlot"},
                {"Value##ArtifactsPlot"},
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

void ArtifactsPlot::drawPlotSpecifics()
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
    return std::get<RadioButtonSetting>(settings[3]).selected == 0;
}

bool ArtifactsPlot::showTreasure() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 1;
}

bool ArtifactsPlot::showMinor() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 2;
}

bool ArtifactsPlot::showMajor() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 3;
}

bool ArtifactsPlot::showRelic() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 4;
}

bool ArtifactsPlot::showCombo() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 5;
}

bool ArtifactsPlot::showCount() const
{
    return std::get<RadioButtonSetting>(settings[5]).selected == 0;
}

bool ArtifactsPlot::showValue() const
{
    return std::get<RadioButtonSetting>(settings[5]).selected == 1;
}
} // namespace h3viewer::plot
