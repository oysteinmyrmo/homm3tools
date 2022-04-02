#pragma once
#include "plot.h"

#include <h3viewer/savefile_series.h>

namespace h3viewer::plot
{
class KingdomArmyStrengthPlot : public Plot
{
public:
    KingdomArmyStrengthPlot();

    void invalidate(const SaveFileSeries &series) override;
    void drawPlotSpecifics() override;

    bool showVanquishLines() const;
};
} // namespace h3viewer::plot
