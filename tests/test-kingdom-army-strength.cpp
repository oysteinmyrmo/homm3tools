#include <h3/player.h>
#include <h3/savefile.h>
#include <h3/stats.h>

#include <test_data.h>

#include <cassert>
#include <cstdint>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::Creature;
using h3::Hero;
using h3::SaveFile;

constexpr uint8_t Green = 3;
constexpr uint8_t Orange = 4;
constexpr uint8_t Purple = 5;

void test_creature(const auto &item, const uint8_t idx, const Creature creature, const uint32_t count)
{
    assert(item.creatures[idx] == creature);
    assert(item.creature_count[idx] == count);
}
} // namespace

void test_day1(const SaveFile &save)
{
    assert(save.valid());
    const auto players = h3::player::players(save);

    auto player = players[Green];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5019);

    auto hero = save.findHero("Rion");
    assert(hero.player == Green);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5019);

    auto town = save.findTown("GreensTown");
    assert(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Orange];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5019);

    hero = save.findHero("Adelaide");
    assert(hero.player == Orange);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5019);

    town = save.findTown("OrangesTown");
    assert(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Purple];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5019);

    hero = save.findHero("Ingham");
    assert(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5019);

    town = save.findTown("PurplesTown");
    assert(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);
}

// Rion +1 attack.
// Adelaide +1 defense.
void test_day2(const SaveFile &save)
{
    assert(save.valid());
    const auto players = h3::player::players(save);

    auto player = players[Green];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5142);

    auto hero = save.findHero("Rion");
    assert(hero.player == Green);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 1); // +1 attack
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5142);

    auto town = save.findTown("GreensTown");
    assert(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Orange];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5142);

    hero = save.findHero("Adelaide");
    assert(hero.player == Orange);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 1); // +1 defense
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5142);

    town = save.findTown("OrangesTown");
    assert(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Purple];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5019);

    hero = save.findHero("Ingham");
    assert(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5019);

    town = save.findTown("PurplesTown");
    assert(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);
}

// Ingham +1 attack, +1 defense.
void test_day3(const SaveFile &save)
{
    assert(save.valid());
    const auto players = h3::player::players(save);

    auto player = players[Green];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5142);

    auto hero = save.findHero("Rion");
    assert(hero.player == Green);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 1); // +1 attack
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5142);

    auto town = save.findTown("GreensTown");
    assert(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Orange];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5142);

    hero = save.findHero("Adelaide");
    assert(hero.player == Orange);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 1); // +1 defense
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5142);

    town = save.findTown("OrangesTown");
    assert(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Purple];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5269);

    hero = save.findHero("Ingham");
    assert(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 1);  // +1 attack
    assert(hero.defense == 1); // +1 defense
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5269);

    town = save.findTown("PurplesTown");
    assert(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);
}

// Green recruits 14 halberdiers in town. Rion is visiting.
// Orange recruits 14 halberdiers in town. Adelaide is visiting.
void test_day4(const SaveFile &save)
{
    assert(save.valid());
    const auto players = h3::player::players(save);

    auto player = players[Green];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 6752);

    auto hero = save.findHero("Rion");
    assert(hero.player == Green);
    assert(hero.on_map == 1); // Visiting means that the hero is on the map.
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 1);
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5142);

    auto town = save.findTown("GreensTown");
    assert(town.owner == Green);
    test_creature(town, 0, Creature::Halberdier, 14);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 1610);

    player = players[Orange];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 6752);

    hero = save.findHero("Adelaide");
    assert(hero.player == Orange);
    assert(hero.on_map == 1); // Visiting means that the hero is on the map.
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 1);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5142);

    town = save.findTown("OrangesTown");
    assert(town.owner == Orange);
    test_creature(town, 0, Creature::Halberdier, 14);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 1610);

    player = players[Purple];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == 5269);

    hero = save.findHero("Ingham");
    assert(hero.player == Purple);
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Empty, 0);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 1);
    assert(hero.defense == 1);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == 5269);

    town = save.findTown("PurplesTown");
    assert(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);
}

// Green moves Rion to garrison.
// Orange moves Adelaide to garrison.
// Purple recruits 14 halberdiers in town. Moves Ingham to garrison.
void test_day5(const SaveFile &save)
{
    assert(save.valid());
    const auto players = h3::player::players(save);

    const uint64_t expectedKAS = h3::stats::ai_value(Creature::Angel, 1)
                               + h3::stats::ai_value(Creature::Halberdier, 14);
    assert(expectedKAS == 6629);

    auto player = players[Green];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == expectedKAS);

    auto hero = save.findHero("Rion");
    assert(hero.player == Green);
    assert(hero.on_map == 0);
    assert(hero.garrison());
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Halberdier, 14);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 1);
    assert(hero.defense == 0);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == expectedKAS); // When in garrison, attack/defense does not modify army strength.

    auto town = save.findTown("GreensTown");
    assert(town.owner == Green);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Orange];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == expectedKAS);

    hero = save.findHero("Adelaide");
    assert(hero.player == Orange);
    assert(hero.on_map == 0);
    assert(hero.garrison());
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Halberdier, 14);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 0);
    assert(hero.defense == 1);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == expectedKAS); // When in garrison, attack/defense does not modify army strength.

    town = save.findTown("OrangesTown");
    assert(town.owner == Orange);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);

    player = players[Purple];
    assert(player.alive());
    assert(player.heroes().size() == 1);
    assert(player.towns().size() == 1);
    assert(player.kingdomArmyStrength() == expectedKAS);

    hero = save.findHero("Ingham");
    assert(hero.player == Purple);
    assert(hero.on_map == 0);
    assert(hero.garrison());
    test_creature(hero, 0, Creature::Angel, 1);
    test_creature(hero, 1, Creature::Halberdier, 14);
    test_creature(hero, 2, Creature::Empty, 0);
    test_creature(hero, 3, Creature::Empty, 0);
    test_creature(hero, 4, Creature::Empty, 0);
    test_creature(hero, 5, Creature::Empty, 0);
    test_creature(hero, 6, Creature::Empty, 0);
    assert(hero.attack == 1);
    assert(hero.defense == 1);
    assert(hero.power == 1);
    assert(hero.knowledge == 1);
    assert(hero.armyStrength() == expectedKAS); // When in garrison, attack/defense does not modify army strength.

    town = save.findTown("PurplesTown");
    assert(town.owner == Purple);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);
    assert(town.armyStrength() == 0);
}

int main()
{
    fs::path dir(h3::test::testDataDir / "kingdom_army_strength");

    h3::SaveFile day1({dir / "[hotseat] 111.GM3", "GreensTown", 3});
    h3::SaveFile day2({dir / "[hotseat] 112.GM3", "GreensTown", 3});
    h3::SaveFile day3({dir / "[hotseat] 113.GM3", "GreensTown", 3});
    h3::SaveFile day4({dir / "[hotseat] 114.GM3", "GreensTown", 3});
    h3::SaveFile day5({dir / "[hotseat] 115.GM3", "GreensTown", 3});

    test_day1(day1);
    test_day2(day2);
    test_day3(day3);
    test_day4(day4);
    test_day5(day5);

    return 0;
}
