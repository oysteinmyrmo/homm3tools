#pragma once
#include "plots/plot.h"
#include "savefile_series.h"

#include <array>
#include <memory>

namespace h3plots
{
enum class PlotType : int
{
    KingdomArmyStrength = 0,
    BestCreature = 1,
    Heroes = 2,
    Artifacts = 3,
    Experience = 4,
    Gold = 5,
    Resources = 6,
    Towns = 7,

    COUNT = 8, // Must be last
};

class Plots
{
public:
    Plots();
    void invalidate(const SaveFileSeries &series);
    void update(const SaveFileSeries &series);

    std::shared_ptr<plot::Plot>& getPlot(PlotType plotType);

private:
    std::array<std::shared_ptr<plot::Plot>, static_cast<int>(PlotType::COUNT)> plots;
    SaveFileSeries saveFileSeries;
};
} // namespace h3plots
