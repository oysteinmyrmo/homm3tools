#pragma once

#include <h3plots/plots.h>

#include <memory>

namespace h3viewer::draw
{
void settings(std::unique_ptr<h3plots::plot::Plot> &plot);
void plot(std::unique_ptr<h3plots::plot::Plot> &plot);
void plotAndSettings(std::unique_ptr<h3plots::plot::Plot> &plot);
} // namespace h3viewer::draw
