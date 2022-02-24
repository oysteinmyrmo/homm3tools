#pragma once

#include "hero.h"
#include "savefile.h"
#include "town.h"

#include <array>
#include <cstdint>
#include <vector>

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

class Player
{
public:
    Player();

    bool alive() const;
    Color color() const { return color_; };
    const auto& heroes() const { return heroes_; }
    const auto& towns() const { return towns_; }

    void addHero(const hero::Hero &hero);
    void addTown(const town::Town &town);
    void setColor(const Color color);

    uint64_t kingdomArmyStrength() const;

private:
    std::vector<hero::Hero> heroes_;
    std::vector<town::Town> towns_;
    Color color_{Color::Empty};
};

std::array<Player, maxPlayers> players(const savefile::SaveFile &save);
} // namespace h3::player
