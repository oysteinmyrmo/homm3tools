#include "thieves_guild.h"

#include "plots/experience.h"
#include "plots/hero_count.h"
#include "plots/kingdom_army_strength.h"
#include "plots/town_count.h"
#include "savefile_series.h"

namespace
{
bool gInitialized = false;
h3viewer::plot::ExperiencePlot experiencePlot;
h3viewer::plot::HeroesPlot heroesPlot;
h3viewer::plot::KingdomArmyStrengthPlot kasPlot;
h3viewer::plot::TownsPlot townsPlot;
} // namespace

namespace h3viewer::thieves_guild
{
void reset(const SaveFileSeries &series)
{
    experiencePlot.invalidate(series);
    heroesPlot.invalidate(series);
    kasPlot.invalidate(series);
    townsPlot.invalidate(series);

    gInitialized = true;
}

void update(const SaveFileSeries &series)
{
    experiencePlot.update(series);
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

    static ImGuiTableFlags flags = ImGuiTableFlags_SizingFixedFit
                                 | ImGuiTableFlags_RowBg
                                 | ImGuiTableFlags_Borders
                                 | ImGuiTableFlags_Resizable
                                 | ImGuiTableFlags_Hideable;

    ImGui::Begin("Thieves Guild##Window");
    if (ImGui::BeginTable("Thieves Guild##Table", 2, flags))
    {
        ImGui::TableSetupColumn("Settings", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Plots", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        heroesPlot.drawSettings();
        ImGui::TableNextColumn();
        heroesPlot.drawPlot();

        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        townsPlot.drawSettings();
        ImGui::TableNextColumn();
        townsPlot.drawPlot();

        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        kasPlot.drawSettings();
        ImGui::TableNextColumn();
        kasPlot.drawPlot();

        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        experiencePlot.drawSettings();
        ImGui::TableNextColumn();
        experiencePlot.drawPlot();

        ImGui::EndTable();
    }
    ImGui::End();
}
} // namespace h3viewer::thieves_guild
