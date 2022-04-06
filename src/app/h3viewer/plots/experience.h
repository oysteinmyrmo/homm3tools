#pragma once
#include "plot.h"

#include <h3viewer/savefile_series.h>

namespace h3viewer::plot
{
class ExperiencePlot : public Plot
{
public:
    ExperiencePlot();

    void invalidate(const SaveFileSeries &series) override;
    void drawPlotSpecifics() override;
    bool showAsPercentageStackedAreaChart() const override;

    bool showVanquishLines() const;
    bool includeHeroesInGarrison() const;
};
} // namespace h3viewer::plot
