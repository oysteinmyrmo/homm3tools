#pragma once

#include <h3plots/savefile_series.h>

namespace h3viewer::thieves_guild
{
void reset(const h3plots::SaveFileSeries &series);
void update(const h3plots::SaveFileSeries &series);
void draw();
} // namespace h3viewer::thieves_guild
