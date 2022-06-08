#include "thieves_guild.h"

#include "plots/experience.h"
#include "plots/gold.h"
#include "plots/hero_count.h"
#include "plots/kingdom_army_strength.h"
#include "plots/town_count.h"
#include "savefile_series.h"

namespace
{
bool gInitialized = false;
h3viewer::plot::ExperiencePlot experiencePlot;
h3viewer::plot::GoldPlot goldPlot;
h3viewer::plot::HeroesPlot heroesPlot;
h3viewer::plot::KingdomArmyStrengthPlot kasPlot;
h3viewer::plot::TownsPlot townsPlot;

constexpr const char *plot_categories[] = {"Army", "Heroes", "Kingdom", "Economy"};
constexpr int plot_idx_army    = 0;
constexpr int plot_idx_heroes  = 1;
constexpr int plot_idx_kingdom = 2;
constexpr int plot_idx_economy = 3;

int current_plot_idx = 0;
} // namespace

namespace h3viewer::thieves_guild
{
void reset(const SaveFileSeries &series)
{
    experiencePlot.invalidate(series);
    goldPlot.invalidate(series);
    heroesPlot.invalidate(series);
    kasPlot.invalidate(series);
    townsPlot.invalidate(series);

    gInitialized = true;
}

void update(const SaveFileSeries &series)
{
    experiencePlot.update(series);
    goldPlot.update(series);
    heroesPlot.update(series);
    kasPlot.update(series);
    townsPlot.update(series);
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
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            kasPlot.drawSettings();
            ImGui::TableNextColumn();
            kasPlot.drawPlot();
        }
        else if (current_plot_idx == plot_idx_heroes)
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            heroesPlot.drawSettings();
            ImGui::TableNextColumn();
            heroesPlot.drawPlot();

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            experiencePlot.drawSettings();
            ImGui::TableNextColumn();
            experiencePlot.drawPlot();
        }
        else if (current_plot_idx == plot_idx_kingdom)
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            townsPlot.drawSettings();
            ImGui::TableNextColumn();
            townsPlot.drawPlot();
        }
        else if (current_plot_idx == plot_idx_economy)
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            goldPlot.drawSettings();
            ImGui::TableNextColumn();
            goldPlot.drawPlot();
        }

        ImGui::EndTable();
    }
    ImGui::End();
}
} // namespace h3viewer::thieves_guild
