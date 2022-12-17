#pragma once
#include "player.h"

#include <h3/player.h>
#include <h3/savefile.h>

#include <array>
#include <filesystem>
#include <string>
#include <vector>

namespace h3plots
{
namespace fs = std::filesystem;

struct SaveFileSeries
{
    size_t size() const;
    bool hasActivePlayers() const;
    bool valid() const;

    Players players;
    std::vector<h3::SaveFile> files;
};

SaveFileSeries read_savefiles(h3::SaveFile::Input input, const Players &players);
void draw();
} // namespace h3plots