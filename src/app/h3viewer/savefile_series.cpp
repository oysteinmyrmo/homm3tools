#include "savefile_series.h"

#include "player.h"
#include "thieves_guild.h"

#include <h3/savefile.h>
#include <h3/town.h>

#include <imgui.h>

#include <algorithm>
#include <set>
#include <string>
#include <utility>

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(images::creatures::portraits);

namespace
{
h3viewer::SaveFileSeries gSaveFileSeries;

// Stolen from imgui_demo.cpp.
void HelpMarker(const char* desc)
{
    auto fs = cmrc::images::creatures::portraits::get_filesystem();
    auto bytes = fs.open("Cyclops_King_portrait.gif");

    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
} // namespace

namespace h3viewer::savefile_series
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

void draw()
{
    ImGui::Begin("Load Save File Series");

    static char path[256];
    ImGui::InputText("Path to folder", path, IM_ARRAYSIZE(path));
    ImGui::SameLine(); HelpMarker(
        "Path to folder containing automatic save files for a game. "
        "All the save files are read in alphabetical order, since the "
        "automatic saves are normally stored as 111.GM*, 112.GM*, ... "
        "or [hotseat] 111.GM*, [hotseat] 112.GM*, ... "
        "Any file that is not a homm3 save file is ignored."
    );

    static bool useAdvancedOptions = false;
    ImGui::Checkbox("Advanced Options", &useAdvancedOptions);
    ImGui::SameLine(); HelpMarker(
        "Advanced options must be used if either:\n\n"
        "- The name of the first hero (Orrin) has changed.\n"
        "- Any town uses a non-default name.\n\n"
        "For most campaign games and some skirmishes advanced options must be used. "
        "For random maps advanced options are normally not needed."
    );

    static char firstHeroName[16] = "Orrin"; // TODO: Refer to variable.
    static char firstTownName[16] = "";
    static int numberOfTowns = 0;

    if (useAdvancedOptions)
    {
        ImGui::BeginGroup();

        ImGui::InputTextWithHint("Name of first hero", h3::savefile::defaultFirstHeroName, firstHeroName, IM_ARRAYSIZE(firstHeroName));
        ImGui::SameLine(); HelpMarker(
            "The name of the first hero in the game, defaulting to Orrin. "
            "If his name is changed in the scenario this value must be updated accordingly."
        );

        ImGui::InputText("Name of first town", firstTownName, IM_ARRAYSIZE(firstTownName));
        ImGui::SameLine(); HelpMarker(
            "The name of the first town in the game, usually red player's start town. "
            "If red player is not in the game, or red player started without a town, "
            "this value must be the start town of the first player having an initial town, if any. "
            "Leave this field empty if only default town names are in use."
        );

        if (ImGui::InputInt("Number of towns", &numberOfTowns))
        {
            numberOfTowns = std::clamp(numberOfTowns, 0, int(h3::town::maxNumberOfTowns));
        }
        ImGui::SameLine(); HelpMarker(
            "The number of towns in the game. This is needed to read all the towns when "
            "custom town names are in use. If this value is 0 an attempt to read the towns "
            "using the default town names will be made."
        );

        ImGui::EndGroup();
    }

    static bool useCustomPlayerNames = false;
    constexpr size_t maxNameLength = 32;
    static std::array<char[maxNameLength], h3::player::maxPlayers> names;
    const auto &defaultNames = h3::player::playerColorsStr;

    ImGui::Checkbox("Custom Player Names", &useCustomPlayerNames);

    if (useCustomPlayerNames)
    {
        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            ImGui::InputTextWithHint(defaultNames[i], defaultNames[i], names[i], maxNameLength);
        }
    }

    if (ImGui::Button("Load"))
    {
        const bool pathOk = fs::is_directory(path);

        if (pathOk)
        {
            h3::SaveFile::Input input{path};

            if (useAdvancedOptions)
            {
                input.firstHeroName = firstHeroName;
                input.firstTownName = firstTownName;
                input.numberOfTowns = numberOfTowns;
            }

            Players players = defaultPlayers();
            for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
            {
                players[i].name = useCustomPlayerNames ? names[i] : defaultNames[i];
                if (players[i].name.empty())
                {
                    players[i].name = h3::player::playerColorsStr[i];
                }
            }

            gSaveFileSeries = read_savefiles(input, players);
            thieves_guild::reset(gSaveFileSeries);
        }
    }

    static bool showThievesGuild = true;
    ImGui::Checkbox("Show Thieves Guild", &showThievesGuild);
    if (showThievesGuild && gSaveFileSeries.valid())
    {
        thieves_guild::update(gSaveFileSeries);
        thieves_guild::draw();
    }

    // TODO: Add Stats for series:
    //   - Number of days/files
    //   - Number/colors of initial players
    //   - ...

    ImGui::End();
}
} // namespace h3viewer::savefile_series
