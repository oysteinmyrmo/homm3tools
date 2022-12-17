#pragma once
#include "plot.h"

namespace h3plots::plot
{
class TownsPlot : public Plot
{
public:
    TownsPlot();

    std::string uniqueString() const override { return typeid(this).name(); };

    void invalidate(const SaveFileSeries &series) override;
    bool showAsPercentageStackedAreaChart() const override;
    bool showVanquishLines() const override;
};
} // namespace h3plots::plot
