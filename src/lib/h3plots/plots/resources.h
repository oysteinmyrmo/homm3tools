#pragma once
#include "plot.h"

namespace h3plots::plot
{
class ResourcesPlot : public Plot
{
public:
    ResourcesPlot();

    std::string uniqueString() const override { return typeid(this).name(); };

    void invalidate(const SaveFileSeries &series) override;
    bool showAsPercentageStackedAreaChart() const override;
    bool showVanquishLines() const override;

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
} // namespace h3plots::plot
