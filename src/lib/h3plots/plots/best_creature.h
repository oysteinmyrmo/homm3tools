#pragma once
#include "plot.h"

namespace h3plots::plot
{
class BestCreaturePlot : public Plot
{
public:
    BestCreaturePlot();

    std::string uniqueString() const override { return typeid(this).name(); };

    void invalidate(const SaveFileSeries &series) override;
    bool showAsPercentageStackedAreaChart() const override;
    bool showVanquishLines() const override;
};
} // namespace h3plots::plot
