#pragma once
#include "plot.h"

#include <h3viewer/savefile_series.h>

namespace h3viewer::plot
{
class HeroesPlot : public Plot
{
public:
    HeroesPlot();

    void invalidate(const SaveFileSeries &series) override;
    void drawPlotSpecifics() override;

    bool showVanquishLines() const;
    bool includeHeroesInGarrison() const;
};
} // namespace h3viewer::hero_count
