#include "player.h"

#include "creatures.h"
#include "savefile.h"
#include "stats.h"
#include "value_reader.h"

#include <algorithm>

namespace h3::player
{
static_assert(sizeof(PlayerData) == 149, "sizeof(PlayerData) must be 149.");

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

void Player::setPlayerData(const PlayerData &playerData)
{
    playerData_ = playerData;
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

uint32_t Player::bestCreatureAIValue() const
{
    uint32_t bestCreature = 0;
    for (const auto &hero : heroes_)
    {
        const auto creature = hero.bestCreature();
        const uint32_t aiValue = creatures::AIValues.at(creature);
        bestCreature = std::max(bestCreature, aiValue);
    }
    for (const auto &town : towns_)
    {
        const auto creature = town.bestCreature();
        const uint32_t aiValue = creatures::AIValues.at(creature);
        bestCreature = std::max(bestCreature, aiValue);
    }
    return bestCreature;
}

std::array<Player, maxPlayers> players(const SaveFile &save)
{
    std::array<Player, maxPlayers> players;

    for (uint8_t i = 0; i < maxPlayers; ++i)
    {
        players[i].setColor(static_cast<Color>(i));
        players[i].setPlayerData(save.players[i]);
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

void readAllPlayers(const std::span<const char> data, size_t idx, std::array<PlayerData, maxPlayers> &playerData)
{
    for (auto &p : playerData)
    {
        values::skipVal(idx, p._unused01);
        values::readVal(data, idx, p.wood);
        values::readVal(data, idx, p.mercury);
        values::readVal(data, idx, p.ore);
        values::readVal(data, idx, p.sulfur);
        values::readVal(data, idx, p.crystal);
        values::readVal(data, idx, p.gems);
        values::readVal(data, idx, p.gold);
        values::skipVal(idx, p._unused02);
    }
}
} // namespace h3::player
