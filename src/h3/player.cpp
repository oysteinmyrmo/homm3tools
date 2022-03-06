#include "player.h"
#include "stats.h"

namespace h3::player
{
Player::Player()
{
    heroes_.reserve(16);
}

bool Player::alive() const
{
    return heroes_.size() || towns_.size();
}

void Player::addHero(const Hero &hero)
{
    heroes_.push_back(hero);
}

void Player::addTown(const Town &town)
{
    towns_.push_back(town);
}

void Player::setColor(const Color color)
{
    color_ = color;
}

uint64_t Player::kingdomArmyStrength() const
{
    uint64_t kas = 0;
    for (const auto &hero : heroes_)
    {
        kas += hero.armyStrength();
    }
    for (const auto &town : towns_)
    {
        kas += town.armyStrength();
    }
    return kas;
}

std::array<Player, maxPlayers> players(const SaveFile &save)
{
    std::array<Player, maxPlayers> players;

    for (uint8_t idx = 0; idx < maxPlayers; ++idx)
    {
        players[idx].setColor(static_cast<Color>(idx));
    }

    for (const auto &hero : save.heroes)
    {
        if (hero.player < maxPlayers)
        {
            players[hero.player].addHero(hero);
        }
    }

    for (const auto &town : save.towns)
    {
        if (town.owner < maxPlayers)
        {
            players[town.owner].addTown(town);
        }
    }

    return players;
}
} // namespace h3::player
