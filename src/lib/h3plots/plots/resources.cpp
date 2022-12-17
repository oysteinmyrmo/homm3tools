#include "resources.h"

#include <h3/player.h>

namespace h3plots::plot
{
ResourcesPlot::ResourcesPlot() : Plot()
{
    settings = {
        CheckBoxSetting{{.text="Show as Percentage Stacked Area Chart"}},
        CheckBoxSetting{{.text="Show Vanquish Lines"}},
        RadioButtonSetting{
            {.text="Customize"},
            {
                {.text="All"},
                {.text="Wood/Ore"},
                {.text="Magic"},
                {.text="Custom"}
            }
        },
        CheckBoxSetting{{"Wood"}, true},
        CheckBoxSetting{{"Ore"}, true},
        CheckBoxSetting{{"Mercury"}, true},
        CheckBoxSetting{{"Sulfur"}, true},
        CheckBoxSetting{{"Crystal"}, true},
        CheckBoxSetting{{"Gems"}, true},
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
    return std::get<RadioButtonSetting>(settings[2]).selected == 0;
}

bool ResourcesPlot::showWoodOre() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 1;
}

bool ResourcesPlot::showMagical() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 2;
}

bool ResourcesPlot::showCustom() const
{
    return std::get<RadioButtonSetting>(settings[2]).selected == 3;
}

void ResourcesPlot::checkNone()
{
    std::get<CheckBoxSetting>(settings[3]).checked = false;
    std::get<CheckBoxSetting>(settings[4]).checked = false;
    std::get<CheckBoxSetting>(settings[5]).checked = false;
    std::get<CheckBoxSetting>(settings[6]).checked = false;
    std::get<CheckBoxSetting>(settings[7]).checked = false;
    std::get<CheckBoxSetting>(settings[8]).checked = false;
}

void ResourcesPlot::checkAll()
{
    std::get<CheckBoxSetting>(settings[3]).checked = true;
    std::get<CheckBoxSetting>(settings[4]).checked = true;
    std::get<CheckBoxSetting>(settings[5]).checked = true;
    std::get<CheckBoxSetting>(settings[6]).checked = true;
    std::get<CheckBoxSetting>(settings[7]).checked = true;
    std::get<CheckBoxSetting>(settings[8]).checked = true;
}

void ResourcesPlot::checkWoodOre()
{
    std::get<CheckBoxSetting>(settings[3]).checked = true;
    std::get<CheckBoxSetting>(settings[4]).checked = true;
}

void ResourcesPlot::checkMagical()
{
    std::get<CheckBoxSetting>(settings[5]).checked = true;
    std::get<CheckBoxSetting>(settings[6]).checked = true;
    std::get<CheckBoxSetting>(settings[7]).checked = true;
    std::get<CheckBoxSetting>(settings[8]).checked = true;
}

bool ResourcesPlot::includeWood() const
{
    return std::get<CheckBoxSetting>(settings[3]).checked;
}

bool ResourcesPlot::includeOre() const
{
    return std::get<CheckBoxSetting>(settings[4]).checked;
}

bool ResourcesPlot::includeMercury() const
{
    return std::get<CheckBoxSetting>(settings[5]).checked;
}

bool ResourcesPlot::includeSulfur() const
{
    return std::get<CheckBoxSetting>(settings[6]).checked;
}

bool ResourcesPlot::includeCrystal() const
{
    return std::get<CheckBoxSetting>(settings[7]).checked;
}

bool ResourcesPlot::includeGems() const
{
    return std::get<CheckBoxSetting>(settings[8]).checked;
}
} // namespace h1viewer::plot
