#pragma once

#include "hero.h"
#include "packed_structs.h"
#include "town.h"

#include <array>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace h3::savefile
{
struct SaveFile;
} // namespace h3::savefile

namespace h3::player
{
constexpr size_t maxPlayers = 8;

enum class Color : uint8_t
{
    Red     =   0x00,
    Blue    =   0x01,
    Tan     =   0x02,
    Green   =   0x03,
    Orange  =   0x04,
    Purple  =   0x05,
    Teal    =   0x06,
    Pink    =   0x07,
    Empty   =   0xFF
};

struct ColorRGB
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

static constexpr std::array<ColorRGB, maxPlayers> playerColors = {
    ColorRGB{248,   0,   0}, // Red
    ColorRGB{ 48,  80, 248}, // Blue
    ColorRGB{160, 128,  80}, // Tan
    ColorRGB{ 32, 148,   0}, // Green
    ColorRGB{248, 132,   0}, // Orange
    ColorRGB{136,  40, 160}, // Purple
    ColorRGB{  8, 156, 160}, // Teal
    ColorRGB{192, 120, 136}, // Pink
};

static constexpr std::array<const char*, maxPlayers> playerColorsStr = {
    "Red",
    "Blue",
    "Tan",
    "Green",
    "Orange",
    "Purple",
    "Teal",
    "Pink",
};

PACKED_STRUCT(
struct PlayerData
{
    uint8_t _unused01[96];
    uint32_t wood = 0;
    uint32_t mercury = 0;
    uint32_t ore = 0;
    uint32_t sulfur = 0;
    uint32_t crystal = 0;
    uint32_t gems = 0;
    uint32_t gold = 0;
    uint8_t _unused02[25];
});

class Player
{
public:
    Player();

    bool alive() const;
    Color color() const { return color_; };
    const auto& heroes() const { return heroes_; }
    const auto& towns() const { return towns_; }

    void addHero(const Hero &hero);
    void addTown(const Town &town);
    void setColor(const Color color);
    void setPlayerData(const PlayerData &playerData);

    uint64_t kingdomArmyStrength() const;

    uint32_t wood()    const { return playerData_.wood;    }
    uint32_t mercury() const { return playerData_.mercury; }
    uint32_t ore()     const { return playerData_.ore;     }
    uint32_t sulfur()  const { return playerData_.sulfur;  }
    uint32_t crystal() const { return playerData_.crystal; }
    uint32_t gems()    const { return playerData_.gems;    }
    uint32_t gold()    const { return playerData_.gold;    }

private:
    PlayerData playerData_;
    std::vector<Hero> heroes_;
    std::vector<Town> towns_;
    Color color_{Color::Empty};
};

std::array<Player, maxPlayers> players(const savefile::SaveFile &save);
void readAllPlayers(const std::span<const char> data, size_t idx, std::array<PlayerData, maxPlayers> &playerData);
} // namespace h3::player

namespace h3
{
using Player = player::Player;
using Color = player::Color;
using ColorRGB = player::ColorRGB;
}
