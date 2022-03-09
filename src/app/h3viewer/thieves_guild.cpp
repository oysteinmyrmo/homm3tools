#include "thieves_guild.h"

#include "plots/hero_count.h"
#include "plots/kingdom_army_strength.h"
#include "plots/town_count.h"
#include "savefile_series.h"

namespace
{
bool gInitialized = false;
} // namespace

namespace h3viewer::thieves_guild
{
void reset(const SaveFileSeries &series)
{
    hero_count::reset(series);
    town_count::reset(series);
    kingdom_army_strength::reset(series);

    gInitialized = true;
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
        ImGui::TableSetupColumn("Tools", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Plots", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        hero_count::drawTools();
        ImGui::TableNextColumn();
        hero_count::drawPlot();

        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        town_count::drawTools();
        ImGui::TableNextColumn();
        town_count::drawPlot();

        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        kingdom_army_strength::drawTools();
        ImGui::TableNextColumn();
        kingdom_army_strength::drawPlot();

        ImGui::EndTable();
    }
    ImGui::End();
}
} // namespace h3viewer::thieves_guild
