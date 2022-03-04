#include "savefile_series.h"

#include "player.h"
#include "thieves_guild.h"

#include <h3/savefile.h>

#include <imgui.h>

#include <set>
#include <string>
#include <utility>

namespace
{
h3viewer::SaveFileSeries gSaveFileSeries;

// Stolen from imgui_demo.cpp.
void HelpMarker(const char* desc)
{
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
SaveFileSeries read_savefiles(h3::SaveFile::Input input, const Players &players)
{
    SaveFileSeries series{players, input.townCount};

    // Use a set to ensure that savefiles are ordered by name (i.e. by in-game day).
    std::set<fs::path> savefiles;

    for (const auto &entry : fs::directory_iterator{input.path})
    {
        if (fs::is_regular_file(entry))
        {
            savefiles.insert(entry);
        }
    }

    series.files.reserve(savefiles.size());
    for (const auto &s : savefiles)
    {
        input.path = s;
        auto savefile = h3::SaveFile(input);
        if (savefile.valid())
        {
            series.files.push_back(std::move(savefile));
        }
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
        "Path to folder containing automatic save files for a game.\n"
        "All the save files are read in alphabetical order, since the\n"
        "automatic saves are normally stored as 111.GM*, 112.GM*, ...\n"
        "or [hotseat] 111.GM*, [hotseat] 112.GM*, ...\n"
        "Any file that is not a homm3 save file is ignored."
    );

    static char firstTownName[256];
    ImGui::InputText("Name of first town", firstTownName, IM_ARRAYSIZE(firstTownName));
    ImGui::SameLine(); HelpMarker(
        "The name of the first town in the game. This is usually red\n"
        "player's start town. This information is needed because it is\n"
        "currently not known how to find this information from the\n"
        "binary data in the save file itself.\n"
    );

    static char townCount[256];
    ImGui::InputText("Number of towns", townCount, IM_ARRAYSIZE(townCount), ImGuiInputTextFlags_CharsDecimal);
    ImGui::SameLine(); HelpMarker(
        "The number of towns in the game. This is needed to read all the\n"
        "towns and who owns them during the game. This information is needed\n"
        "because it is currently not known how to find this information from\n"
        "the binary data in the save file itself.\n"
    );

    static char firstHeroName[256] = "Orrin"; // TODO: Refer to variable.
    ImGui::InputTextWithHint("Name of first hero", h3::savefile::defaultFirstHeroName, firstHeroName, IM_ARRAYSIZE(firstHeroName));
    ImGui::SameLine(); HelpMarker(
        "The name of the first hero in the game. The default first hero is Orrin.\n"
        "If his name is not changed or he is banned from the game this must be changed.\n"
    );

    constexpr size_t maxNameLength = 32;
    const auto &defaultNames = h3::player::playerColorsStr;
    static std::array<char[maxNameLength], h3::player::maxPlayers> names;
    ImGui::Text("Player Names:");
    for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
    {
        ImGui::InputTextWithHint(defaultNames[i], defaultNames[i], names[i], maxNameLength);
    }

    if (ImGui::Button("Load"))
    {
        size_t count = std::stoull({townCount});
        h3::SaveFile::Input input{path, firstTownName, count, firstHeroName};

        Players players = defaultPlayers();
        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            players[i].name = names[i];
            if (players[i].name.empty())
            {
                players[i].name = h3::player::playerColorsStr[i];
            }
        }

        gSaveFileSeries = read_savefiles(input, players);
        thieves_guild::reset(gSaveFileSeries);
    }

    static bool showThievesGuild = true;
    ImGui::Checkbox("Show Thieves Guild", &showThievesGuild);
    if (showThievesGuild)
    {
        thieves_guild::draw();
    }

    // TODO: Add Stats for series:
    //   - Number of days/files
    //   - Number/colors of initial players
    //   - ...

    ImGui::End();
}
} // namespace h3viewer::savefile_series
