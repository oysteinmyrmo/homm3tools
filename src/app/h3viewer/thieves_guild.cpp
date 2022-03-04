#include "thieves_guild.h"
#include "kingdom_army_strength.h"

namespace h3viewer::thieves_guild
{
void reset(const savefile_series::SaveFileSeries &series)
{
    kingdom_army_strength::reset(series);
}

void draw()
{
    kingdom_army_strength::draw();
}
} // namespace h3viewer::thieves_guild
