#pragma once

#include "player.h"

#include <h3/player.h>
#include <h3/savefile.h>

#include <array>
#include <filesystem>
#include <string>
#include <vector>

namespace h3viewer::savefile_series
{
namespace fs = std::filesystem;

struct SaveFileSeries
{
    size_t size() const { return files.size(); }

    Players players;
    uint64_t numberOfTowns = 0;
    std::vector<h3::SaveFile> files;
};

SaveFileSeries read_savefiles(h3::SaveFile::Input input, const Players &players);
void draw();
} // namespace h3viewer::savefile_series

namespace h3viewer
{
using SaveFileSeries = h3viewer::savefile_series::SaveFileSeries;
} // namespace h3viewer
