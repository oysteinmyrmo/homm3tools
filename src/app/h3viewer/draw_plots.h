#pragma once

#include <h3plots/plots.h>

#include <memory>

namespace h3viewer::draw
{
void settings(std::shared_ptr<h3plots::plot::Plot> &plot);
void plot(std::shared_ptr<h3plots::plot::Plot> &plot);
void plotAndSettings(std::shared_ptr<h3plots::plot::Plot> &plot);
} // namespace h3viewer::draw
