#include "thieves_guild.h"

#include "plots/hero_count.h"
#include "plots/kingdom_army_strength.h"
#include "savefile_series.h"

namespace h3viewer::thieves_guild
{
void reset(const SaveFileSeries &series)
{
    hero_count::reset(series);
    kingdom_army_strength::reset(series);
}

void draw()
{
    ImGui::Begin("Thieves Guild");
    hero_count::draw();
    kingdom_army_strength::draw();
    ImGui::End();
}
} // namespace h3viewer::thieves_guild
