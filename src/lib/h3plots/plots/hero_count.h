#pragma once
#include "plot.h"

namespace h3plots::plot
{
class HeroesPlot : public Plot
{
public:
    HeroesPlot();

    std::string uniqueString() const override { return typeid(this).name(); };

    void invalidate(const SaveFileSeries &series) override;
    bool showAsPercentageStackedAreaChart() const override;
    bool showVanquishLines() const override;

    bool includeHeroesInGarrison() const;
};
} // namespace h3viewer::hero_count
