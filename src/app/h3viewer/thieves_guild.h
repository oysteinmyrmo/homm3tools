#pragma once

#include "savefile_series.h"

namespace h3viewer::thieves_guild
{
void reset(const SaveFileSeries &series);
void update(const SaveFileSeries &series);
void draw();
} // namespace h3viewer::thieves_guild
