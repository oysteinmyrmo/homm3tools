#include "thieves_guild.h"
#include "draw_plots.h"

#include <h3plots/plots.h>

#include <imgui.h>

#include <memory>

namespace
{
bool gInitialized = false;
h3plots::Plots allPlots;

std::unique_ptr<h3plots::plot::Plot>& getPlot(const h3plots::PlotType plotType)
{
    return allPlots.getPlot(plotType);
}

constexpr const char *plot_categories[] = {"Army", "Heroes", "Kingdom", "Economy"};
constexpr int plot_idx_army    = 0;
constexpr int plot_idx_heroes  = 1;
constexpr int plot_idx_kingdom = 2;
constexpr int plot_idx_economy = 3;

int current_plot_idx = 0;
} // namespace

namespace h3viewer::thieves_guild
{
void reset(const h3plots::SaveFileSeries &series)
{
    allPlots.invalidate(series);
    gInitialized = true;
}

void update(const h3plots::SaveFileSeries &series)
{
    allPlots.update(series);
}

void draw()
{
    if (!gInitialized)
    {
        return; // Simply not show the window before any data is loaded.
    }

    ImGui::Begin("Thieves Guild##Window");

    ImGui::PushItemWidth(100);
    ImGui::Combo("Select Category", &current_plot_idx, plot_categories, IM_ARRAYSIZE(plot_categories));
    ImGui::NewLine();

    constexpr ImGuiTableFlags tableFlags = ImGuiTableFlags_SizingFixedFit
                                         | ImGuiTableFlags_RowBg
                                         | ImGuiTableFlags_Borders
                                         | ImGuiTableFlags_Resizable
                                         | ImGuiTableFlags_Hideable;

    if (ImGui::BeginTable("Thieves Guild##Table", 2, tableFlags))
    {
        ImGui::TableSetupColumn("Settings", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Plots", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableHeadersRow();

        if (current_plot_idx == plot_idx_army)
        {
            draw::plotAndSettings(getPlot(h3plots::PlotType::KingdomArmyStrength));
            draw::plotAndSettings(getPlot(h3plots::PlotType::BestCreature));
        }
        else if (current_plot_idx == plot_idx_heroes)
        {
            draw::plotAndSettings(getPlot(h3plots::PlotType::Heroes));
            draw::plotAndSettings(getPlot(h3plots::PlotType::Artifacts));
            draw::plotAndSettings(getPlot(h3plots::PlotType::Experience));
        }
        else if (current_plot_idx == plot_idx_kingdom)
        {
            draw::plotAndSettings(getPlot(h3plots::PlotType::Towns));
        }
        else if (current_plot_idx == plot_idx_economy)
        {
            draw::plotAndSettings(getPlot(h3plots::PlotType::Gold));
            draw::plotAndSettings(getPlot(h3plots::PlotType::Resources));
        }

        ImGui::EndTable();
    }
    ImGui::End();
}
} // namespace h3viewer::thieves_guild
