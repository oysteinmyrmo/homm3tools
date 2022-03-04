#include "thieves_guild.h"

#include "plots/kingdom_army_strength.h"
#include "savefile_series.h"

namespace h3viewer::thieves_guild
{
void reset(const SaveFileSeries &series)
{
    kingdom_army_strength::reset(series);
}

void draw()
{
    ImGui::Begin("Thieves Guild");
    kingdom_army_strength::draw();
    ImGui::End();
}
} // namespace h3viewer::thieves_guild
