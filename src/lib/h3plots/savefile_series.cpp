#include "savefile_series.h"

#include "player.h"

#include <h3/savefile.h>
#include <h3/town.h>

#include <algorithm>
#include <set>
#include <string>
#include <utility>

namespace h3plots
{
size_t SaveFileSeries::size() const
{
    return files.size();
}

bool SaveFileSeries::hasActivePlayers() const
{
    return std::any_of(players.begin(), players.end(), [](const Player &player)
    {
        return player.active;
    });
};

bool SaveFileSeries::valid() const
{
    return size() && hasActivePlayers();
}

SaveFileSeries read_savefiles(h3::SaveFile::Input input, const Players &players)
{
    SaveFileSeries series{players};

    // Use a set to ensure that savefiles are ordered by name (i.e. by in-game day).
    std::set<fs::path> savefiles;

    for (const auto &entry : fs::directory_iterator{input.path})
    {
        if (fs::is_regular_file(entry))
        {
            savefiles.insert(entry);
        }
    }

    uint64_t day = 1;
    series.files.reserve(savefiles.size());
    for (const auto &s : savefiles)
    {
        input.path = s;
        auto savefile = h3::SaveFile(input);
        if (savefile.valid())
        {
            const auto playersInSavefile = h3::player::players(savefile);
            for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
            {
                if (playersInSavefile[i].alive())
                {
                    // Almost dead yesterday, maybe dead tomorrow, but alive, gloriously alive, today!
                    series.players[i].vanquishedDay = day + 1;
                }
            }

            series.files.emplace_back(std::move(savefile));
        }
        ++day;
    }

    if (series.files.size())
    {
        // If the first save is not day 1, some players might be left out if already vanquished.
        const auto playersFirstDay = h3::player::players(series.files[0]);

        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            series.players[i].active = playersFirstDay[i].alive();
        }
    }

    return series;
}
} // namespace h3plots::savefile_series
