#pragma once
#include "plot.h"

namespace h3plots::plot
{
class ExperiencePlot : public Plot
{
public:
    ExperiencePlot();

    std::string uniqueString() const override { return typeid(this).name(); };

    void invalidate(const SaveFileSeries &series) override;
    bool showAsPercentageStackedAreaChart() const override;
    bool showVanquishLines() const override;

    bool includeHeroesInGarrison() const;
};
} // namespace h3plots::plot
