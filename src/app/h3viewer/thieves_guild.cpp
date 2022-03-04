#include "thieves_guild.h"

#include "kingdom_army_strength.h"
#include "savefile_series.h"

namespace h3viewer::thieves_guild
{
void reset(const SaveFileSeries &series)
{
    kingdom_army_strength::reset(series);
}

void draw()
{
    kingdom_army_strength::draw();
}
} // namespace h3viewer::thieves_guild
