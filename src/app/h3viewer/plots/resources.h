#pragma once
#include "plot.h"

#include <h3viewer/savefile_series.h>

namespace h3viewer::plot
{
class ResourcesPlot : public Plot
{
public:
    ResourcesPlot();

    void invalidate(const SaveFileSeries &series) override;
    void drawPlotSpecifics() override;
    bool showAsPercentageStackedAreaChart() const override;

    bool showVanquishLines() const;

    bool showAll() const;
    bool showWoodOre() const;
    bool showMagical() const;
    bool showCustom() const;

    void checkNone();
    void checkAll();
    void checkWoodOre();
    void checkMagical();

    bool includeWood() const;
    bool includeOre() const;
    bool includeMercury() const;
    bool includeSulfur() const;
    bool includeCrystal() const;
    bool includeGems() const;
};
} // namespace h3viewer::plot
