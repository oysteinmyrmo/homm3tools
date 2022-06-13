#pragma once
#include "plot.h"

#include <h3viewer/savefile_series.h>

namespace h3viewer::plot
{
class ArtifactsPlot : public Plot
{
public:
    ArtifactsPlot();

    void invalidate(const SaveFileSeries &series) override;
    void drawPlotSpecifics() override;
    bool showAsPercentageStackedAreaChart() const override;

    bool showVanquishLines() const;

    bool showAll() const;
    bool showTreasure() const;
    bool showMinor() const;
    bool showMajor() const;
    bool showRelic() const;
    bool showCombo() const;

    bool showCount() const;
    bool showValue() const;
};
} // namespace h3viewer::plot
