#include "plots.h"

#include "plots/artifacts.h"
#include "plots/best_creature.h"
#include "plots/experience.h"
#include "plots/gold.h"
#include "plots/hero_count.h"
#include "plots/kingdom_army_strength.h"
#include "plots/resources.h"
#include "plots/town_count.h"

#include "savefile_series.h"

namespace h3plots
{
Plots::Plots()
{
    // Army
    plots[static_cast<int>(PlotType::KingdomArmyStrength)] = std::make_shared<plot::KingdomArmyStrengthPlot>();
    plots[static_cast<int>(PlotType::BestCreature)] = std::make_shared<plot::BestCreaturePlot>();

    // Heroes
    plots[static_cast<int>(PlotType::Heroes)] = std::make_shared<plot::HeroesPlot>();
    plots[static_cast<int>(PlotType::Artifacts)] = std::make_shared<plot::ArtifactsPlot>();
    plots[static_cast<int>(PlotType::Experience)] = std::make_shared<plot::ExperiencePlot>();

    // Economy
    plots[static_cast<int>(PlotType::Gold)] = std::make_shared<plot::GoldPlot>();
    plots[static_cast<int>(PlotType::Resources)] = std::make_shared<plot::ResourcesPlot>();

    // Kingdom
    plots[static_cast<int>(PlotType::Towns)] = std::make_shared<plot::TownsPlot>();
}

void Plots::invalidate(const SaveFileSeries &series)
{
    for (auto &plot : plots)
    {
        plot->invalidate(series);
    }
}

void Plots::update(const SaveFileSeries &series)
{
    for (auto &plot : plots)
    {
        plot->update(series);
    }
}

std::shared_ptr<plot::Plot>& Plots::getPlot(const PlotType plotType)
{
    return plots[static_cast<int>(plotType)];
}
} // namespace h3plots
