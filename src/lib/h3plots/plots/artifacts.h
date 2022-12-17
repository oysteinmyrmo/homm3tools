#pragma once
#include "plot.h"

namespace h3plots::plot
{
class ArtifactsPlot : public Plot
{
public:
    ArtifactsPlot();

    std::string uniqueString() const override { return typeid(this).name(); };

    void invalidate(const SaveFileSeries &series) override;
    bool showAsPercentageStackedAreaChart() const override;
    bool showVanquishLines() const override;

    bool showAll() const;
    bool showTreasure() const;
    bool showMinor() const;
    bool showMajor() const;
    bool showRelic() const;
    bool showCombo() const;

    bool showCount() const;
    bool showValue() const;
};
} // namespace h3plots::plot
