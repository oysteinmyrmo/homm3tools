#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/player.h>
#include <h3/savefile.h>
#include <h3/stats.h>

#include <cstdint>
#include <filesystem>

namespace
{
using h3::Creature;
using h3::Hero;
using h3::SaveFile;

constexpr uint8_t Green = 3;
constexpr uint8_t Orange = 4;
constexpr uint8_t Purple = 5;

void test_creature(const auto &item, const uint8_t idx, const Creature creature, const uint32_t count)
{
    REQUIRE(item.creatures[idx] == creature);
    REQUIRE(item.creature_count[idx] == count);
}

std::filesystem::path testDataDir(h3::test::testDataDir / "kingdom_army_strength");
} // namespace

TEST_CASE("kingdom-army-strength-day1", "[hero][creature][town][army-strength][ai-value][kingdom-army-strength]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM3", "GreensTown", 3});
    REQUIRE(save.valid());

    const auto players = h3::player::players(save);

    auto player = players[Green];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5019);

    auto hero = save.findHero("Rion");
    REQUIRE(hero.player == Green);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5019);

    auto town = save.findTown("GreensTown");
    REQUIRE(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Orange];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5019);

    hero = save.findHero("Adelaide");
    REQUIRE(hero.player == Orange);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5019);

    town = save.findTown("OrangesTown");
    REQUIRE(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Purple];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5019);

    hero = save.findHero("Ingham");
    REQUIRE(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5019);

    town = save.findTown("PurplesTown");
    REQUIRE(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);
}

// Rion +1 attack.
// Adelaide +1 defense.
TEST_CASE("kingdom-army-strength-day2", "[hero][creature][town][army-strength][ai-value][kingdom-army-strength]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM3", "GreensTown", 3});
    REQUIRE(save.valid());

    const auto players = h3::player::players(save);

    auto player = players[Green];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5142);

    auto hero = save.findHero("Rion");
    REQUIRE(hero.player == Green);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 1); // +1 attack
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5142);

    auto town = save.findTown("GreensTown");
    REQUIRE(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Orange];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5142);

    hero = save.findHero("Adelaide");
    REQUIRE(hero.player == Orange);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 1); // +1 defense
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5142);

    town = save.findTown("OrangesTown");
    REQUIRE(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Purple];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5019);

    hero = save.findHero("Ingham");
    REQUIRE(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5019);

    town = save.findTown("PurplesTown");
    REQUIRE(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);
}

// Ingham +1 attack, +1 defense.
TEST_CASE("kingdom-army-strength-day3", "[hero][creature][town][army-strength][ai-value][kingdom-army-strength]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM3", "GreensTown", 3});
    REQUIRE(save.valid());

    const auto players = h3::player::players(save);

    auto player = players[Green];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5142);

    auto hero = save.findHero("Rion");
    REQUIRE(hero.player == Green);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 1); // +1 attack
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5142);

    auto town = save.findTown("GreensTown");
    REQUIRE(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Orange];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5142);

    hero = save.findHero("Adelaide");
    REQUIRE(hero.player == Orange);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 1); // +1 defense
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5142);

    town = save.findTown("OrangesTown");
    REQUIRE(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Purple];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5269);

    hero = save.findHero("Ingham");
    REQUIRE(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 1);  // +1 attack
    REQUIRE(hero.defense == 1); // +1 defense
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5269);

    town = save.findTown("PurplesTown");
    REQUIRE(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);
}

// Green recruits 14 halberdiers in town. Rion is visiting.
// Orange recruits 14 halberdiers in town. Adelaide is visiting.
TEST_CASE("kingdom-army-strength-day4", "[hero][creature][town][army-strength][ai-value][kingdom-army-strength]")
{
    SaveFile save({testDataDir / "[hotseat] 114.GM3", "GreensTown", 3});
    REQUIRE(save.valid());

    const auto players = h3::player::players(save);

    auto player = players[Green];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 6752);

    auto hero = save.findHero("Rion");
    REQUIRE(hero.player == Green);
    REQUIRE(hero.on_map == 1); // Visiting means that the hero is on the map.
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 1);
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5142);

    auto town = save.findTown("GreensTown");
    REQUIRE(town.owner == Green);
    test_creature(town, 0, Creature::Halberdier, 14);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 1610);

    player = players[Orange];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 6752);

    hero = save.findHero("Adelaide");
    REQUIRE(hero.player == Orange);
    REQUIRE(hero.on_map == 1); // Visiting means that the hero is on the map.
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 1);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5142);

    town = save.findTown("OrangesTown");
    REQUIRE(town.owner == Orange);
    test_creature(town, 0, Creature::Halberdier, 14);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 1610);

    player = players[Purple];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == 5269);

    hero = save.findHero("Ingham");
    REQUIRE(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 1);
    REQUIRE(hero.defense == 1);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == 5269);

    town = save.findTown("PurplesTown");
    REQUIRE(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);
}

// Green moves Rion to garrison.
// Orange moves Adelaide to garrison.
// Purple recruits 14 halberdiers in town. Moves Ingham to garrison.
TEST_CASE("kingdom-army-strength-day5", "[hero][creature][town][army-strength][ai-value][kingdom-army-strength]")
{
    SaveFile save({testDataDir / "[hotseat] 115.GM3", "GreensTown", 3});
    REQUIRE(save.valid());

    const auto players = h3::player::players(save);

    const uint64_t expectedKAS = h3::stats::ai_value(Creature::Angel, 1)
                               + h3::stats::ai_value(Creature::Halberdier, 14);
    REQUIRE(expectedKAS == 6629);

    auto player = players[Green];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == expectedKAS);

    auto hero = save.findHero("Rion");
    REQUIRE(hero.player == Green);
    REQUIRE(hero.on_map == 0);
    REQUIRE(hero.garrison());
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Halberdier, 14);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 1);
    REQUIRE(hero.defense == 0);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == expectedKAS); // When in garrison, attack/defense does not modify army strength.

    auto town = save.findTown("GreensTown");
    REQUIRE(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Orange];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == expectedKAS);

    hero = save.findHero("Adelaide");
    REQUIRE(hero.player == Orange);
    REQUIRE(hero.on_map == 0);
    REQUIRE(hero.garrison());
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Halberdier, 14);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 0);
    REQUIRE(hero.defense == 1);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == expectedKAS); // When in garrison, attack/defense does not modify army strength.

    town = save.findTown("OrangesTown");
    REQUIRE(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);

    player = players[Purple];
    REQUIRE(player.alive());
    REQUIRE(player.heroes().size() == 1);
    REQUIRE(player.towns().size() == 1);
    REQUIRE(player.kingdomArmyStrength() == expectedKAS);

    hero = save.findHero("Ingham");
    REQUIRE(hero.player == Purple);
    REQUIRE(hero.on_map == 0);
    REQUIRE(hero.garrison());
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Halberdier, 14);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    REQUIRE(hero.attack == 1);
    REQUIRE(hero.defense == 1);
    REQUIRE(hero.power == 1);
    REQUIRE(hero.knowledge == 1);
    REQUIRE(hero.armyStrength() == expectedKAS); // When in garrison, attack/defense does not modify army strength.

    town = save.findTown("PurplesTown");
    REQUIRE(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    REQUIRE(town.armyStrength() == 0);
}
