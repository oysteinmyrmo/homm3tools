#pragma once
#include "plot.h"

#include <h3viewer/savefile_series.h>

namespace h3viewer::plot
{
class GoldPlot : public Plot
{
public:
    GoldPlot();

    void invalidate(const SaveFileSeries &series) override;
    void drawPlotSpecifics() override;
    bool showAsPercentageStackedAreaChart() const override;

    bool showVanquishLines() const;
};
} // namespace h3viewer::plot
