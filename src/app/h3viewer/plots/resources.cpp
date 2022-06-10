#include "resources.h"

#include <h3/player.h>

#include <implot.h>

namespace h3viewer::plot
{
ResourcesPlot::ResourcesPlot() : Plot()
{
    settings = {
        CheckBoxSetting{"Show as Percentage Stacked Area Chart##ResourcesPlot"},
        CheckBoxSetting{"Show Vanquish Lines##ResourcesPlot"},
        SettingSeparator{},
        RadioButtonSetting{
            {.text="Customize##ResourcesPlot"},
            .settings = {
                {"All##ResourcesPlot", .newline=true},
                {"Wood/Ore##ResourcesPlot"},
                {"Magic##ResourcesPlot", .newline=true},
                {"Custom##ResourcesPlot", .newline=true}
            }
        },
        SettingSeparator{},
        CheckBoxSetting{{"Wood##ResourcesPlot"}, .checked=true},
        CheckBoxSetting{{"Ore##ResourcesPlot"}, .checked=true},
        CheckBoxSetting{{"Mercury##ResourcesPlot"}, .checked=true},
        CheckBoxSetting{{"Sulfur##ResourcesPlot"}, .checked=true},
        CheckBoxSetting{{"Crystal##ResourcesPlot"}, .checked=true},
        CheckBoxSetting{{"Gems##ResourcesPlot"}, .checked=true},
    };

    axisTexts = {
        {"Resources"},
        {"Day"},
        {"Resource Amount at end of Day"},
    };
}

void ResourcesPlot::invalidate(const SaveFileSeries &series)
{
    Plot::invalidate(series);

    for (auto &item : yVals)
    {
        item.resize(size(), 0);
    }

    if (!showCustom())
    {
        checkNone();
        if (showAll())
        {
            checkAll();
        }
        else if (showWoodOre())
        {
            checkWoodOre();
        }
        else if (showMagical())
        {
            checkMagical();
        }
    }

    for (size_t i = 0; i < size(); ++i)
    {
        const auto players{h3::player::players(series.files[i])};
        for (size_t j = 0; j < h3::player::maxPlayers; ++j)
        {
            if (players[j].alive())
            {
                if (includeWood())    { yVals[j][i] += players[j].wood();    }
                if (includeOre())     { yVals[j][i] += players[j].ore();     }
                if (includeMercury()) { yVals[j][i] += players[j].mercury(); }
                if (includeSulfur())  { yVals[j][i] += players[j].sulfur();  }
                if (includeCrystal()) { yVals[j][i] += players[j].crystal(); }
                if (includeGems())    { yVals[j][i] += players[j].gems();    }
            }
        }
    }

    alterDataToChartType();
}

void ResourcesPlot::drawPlotSpecifics()
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

bool ResourcesPlot::showAsPercentageStackedAreaChart() const
{
    return std::get<CheckBoxSetting>(settings[0]).checked;
}

bool ResourcesPlot::showVanquishLines() const
{
    return std::get<CheckBoxSetting>(settings[1]).checked;
}

bool ResourcesPlot::showAll() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 0;
}

bool ResourcesPlot::showWoodOre() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 1;
}

bool ResourcesPlot::showMagical() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 2;
}

bool ResourcesPlot::showCustom() const
{
    return std::get<RadioButtonSetting>(settings[3]).selected == 3;
}

void ResourcesPlot::checkNone()
{
    std::get<CheckBoxSetting>(settings[5]).checked = false;
    std::get<CheckBoxSetting>(settings[6]).checked = false;
    std::get<CheckBoxSetting>(settings[7]).checked = false;
    std::get<CheckBoxSetting>(settings[8]).checked = false;
    std::get<CheckBoxSetting>(settings[9]).checked = false;
    std::get<CheckBoxSetting>(settings[10]).checked = false;
}

void ResourcesPlot::checkAll()
{
    std::get<CheckBoxSetting>(settings[5]).checked = true;
    std::get<CheckBoxSetting>(settings[6]).checked = true;
    std::get<CheckBoxSetting>(settings[7]).checked = true;
    std::get<CheckBoxSetting>(settings[8]).checked = true;
    std::get<CheckBoxSetting>(settings[9]).checked = true;
    std::get<CheckBoxSetting>(settings[10]).checked = true;
}

void ResourcesPlot::checkWoodOre()
{
    std::get<CheckBoxSetting>(settings[5]).checked = true;
    std::get<CheckBoxSetting>(settings[6]).checked = true;
}

void ResourcesPlot::checkMagical()
{
    std::get<CheckBoxSetting>(settings[7]).checked = true;
    std::get<CheckBoxSetting>(settings[8]).checked = true;
    std::get<CheckBoxSetting>(settings[9]).checked = true;
    std::get<CheckBoxSetting>(settings[10]).checked = true;
}

bool ResourcesPlot::includeWood() const
{
    return std::get<CheckBoxSetting>(settings[5]).checked;
}

bool ResourcesPlot::includeOre() const
{
    return std::get<CheckBoxSetting>(settings[6]).checked;
}

bool ResourcesPlot::includeMercury() const
{
    return std::get<CheckBoxSetting>(settings[7]).checked;
}

bool ResourcesPlot::includeSulfur() const
{
    return std::get<CheckBoxSetting>(settings[8]).checked;
}

bool ResourcesPlot::includeCrystal() const
{
    return std::get<CheckBoxSetting>(settings[9]).checked;
}

bool ResourcesPlot::includeGems() const
{
    return std::get<CheckBoxSetting>(settings[10]).checked;
}
} // namespace h3viewer::plot
