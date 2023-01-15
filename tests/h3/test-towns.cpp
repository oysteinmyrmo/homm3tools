#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/creatures.h>
#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Creature;
using h3::Hero;
using h3::SaveFile;
using h3::Town;

void test_creature(const auto &owner, const uint8_t idx, const Creature creature, const uint32_t count)
{
    REQUIRE(owner.creatures[idx] == creature);
    REQUIRE(owner.creature_count[idx] == count);
}

std::filesystem::path testDataDir(h3::test::testDataDir / "towns");
} // namespace

void test_town_constants(const auto &towns)
{
    REQUIRE(towns.size() == 4);

    auto town = towns[0];
    REQUIRE(town.name == "RedsTown");
    REQUIRE(town.name.size() == town.nameSize);
    REQUIRE(town.x == 12);
    REQUIRE(town.y ==  7);
    REQUIRE(town.z ==  0);

    town = towns[1];
    REQUIRE(town.name == "BluesTown");
    REQUIRE(town.name.size() == town.nameSize);
    REQUIRE(town.x == 18);
    REQUIRE(town.y ==  7);
    REQUIRE(town.z ==  0);

    town = towns[2];
    REQUIRE(town.name == "BUUUUUUURN");
    REQUIRE(town.name.size() == town.nameSize);
    REQUIRE(town.x == 12);
    REQUIRE(town.y == 14);
    REQUIRE(town.z ==  0);

    town = towns[3];
    REQUIRE(town.name == "LOOKOUT");
    REQUIRE(town.name.size() == town.nameSize);
    REQUIRE(town.x == 18);
    REQUIRE(town.y == 14);
    REQUIRE(town.z ==  0);
}

TEST_CASE("towns-day1", "[hero][town][creature]")
{
    h3::SaveFile save({testDataDir / "[hotseat] 111.GM2", "RedsTown", 4});
    REQUIRE(save.valid());
    test_town_constants(save.towns);

    auto town = save.findTown("RedsTown");
    REQUIRE(town.owner == 0);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);

    town = save.findTown("BluesTown");
    REQUIRE(town.owner == 1);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);

    town = save.findTown("BUUUUUUURN");
    REQUIRE(town.owner == Town::noOwner);
    test_creature(town, 0, Creature::Magog, 1);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Magog, 2);

    town = save.findTown("LOOKOUT");
    REQUIRE(town.owner == Town::noOwner);
    test_creature(town, 0, Creature::Gremlin, 1);
    test_creature(town, 1, Creature::Gremlin, 2);
    test_creature(town, 2, Creature::Gremlin, 3);
    test_creature(town, 3, Creature::Gremlin, 4);
    test_creature(town, 4, Creature::Gremlin, 5);
    test_creature(town, 5, Creature::Gremlin, 6);
    test_creature(town, 6, Creature::Gremlin, 7);
}

// - Red takes BluesTown.
// - Leaves [griffin, centaur, dwarf, empty, dwarf, centaur, griffin]/[1,1,1,0,1,1,1] in garrison.
// - Edric stands in town with [pikeman, griffin,0,0,0,0]/[15,2,0,0,0,0,0]
TEST_CASE("towns-day2", "[hero][town][creature]")
{
    h3::SaveFile save({testDataDir / "[hotseat] 112.GM2", "RedsTown", 4});
    REQUIRE(save.valid());
    test_town_constants(save.towns);

    auto town = save.findTown("RedsTown");
    REQUIRE(town.owner == 0);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);

    town = save.findTown("BluesTown");
    REQUIRE(town.owner == 0); // Changed owner
    test_creature(town, 0, Creature::Griffin, 1);
    test_creature(town, 1, Creature::Centaur, 1);
    test_creature(town, 2, Creature::Dwarf,   1);
    test_creature(town, 3, Creature::Empty,   0);
    test_creature(town, 4, Creature::Dwarf,   1);
    test_creature(town, 5, Creature::Centaur, 1);
    test_creature(town, 6, Creature::Griffin, 1);

    // Edric stands in BluesTown.
    Hero hero = save.findHero("Edric");
    REQUIRE(hero.on_map == 1);
    REQUIRE(hero.x == town.x);
    REQUIRE(hero.y == town.y);
    REQUIRE(hero.z == town.z);
    test_creature(hero, 0, Creature::Pikeman, 15);
    test_creature(hero, 1, Creature::Griffin,  2);
    test_creature(hero, 2, Creature::Empty,    0);
    test_creature(hero, 3, Creature::Empty,    0);
    test_creature(hero, 4, Creature::Empty,    0);
    test_creature(hero, 5, Creature::Empty,    0);
    test_creature(hero, 6, Creature::Empty,    0);

    town = save.findTown("BUUUUUUURN");
    test_creature(town, 0, Creature::Magog, 1);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Magog, 2);

    town = save.findTown("LOOKOUT");
    test_creature(town, 0, Creature::Gremlin, 1);
    test_creature(town, 1, Creature::Gremlin, 2);
    test_creature(town, 2, Creature::Gremlin, 3);
    test_creature(town, 3, Creature::Gremlin, 4);
    test_creature(town, 4, Creature::Gremlin, 5);
    test_creature(town, 5, Creature::Gremlin, 6);
    test_creature(town, 6, Creature::Gremlin, 7);
}

// - Blue takes RedsTown.
// - Leaves [centaur, empty, archer, dwarf, archer, dwarf, centaur]/[2,0,5,1,4,1,2] in garrison.
// - Kyrre stands in town with [woodelf, centaur, 0, 0, 0, 0, woodelf]/[1,19,0,0,0,0,1].
TEST_CASE("towns-day3", "[hero][town][creature]")
{
    h3::SaveFile save({testDataDir / "[hotseat] 113.GM2", "RedsTown", 4});
    REQUIRE(save.valid());
    test_town_constants(save.towns);

    auto town = save.findTown("RedsTown");
    REQUIRE(town.owner == 1); // Changed owner
    test_creature(town, 0, Creature::Centaur, 2);
    test_creature(town, 1, Creature::Empty,   0);
    test_creature(town, 2, Creature::Archer,  5);
    test_creature(town, 3, Creature::Dwarf,   1);
    test_creature(town, 4, Creature::Archer,  4);
    test_creature(town, 5, Creature::Dwarf,   1);
    test_creature(town, 6, Creature::Centaur, 2);

    // Kyrre stands in RedsTown.
    Hero hero = save.findHero("Kyrre");
    REQUIRE(hero.on_map == 1);
    REQUIRE(hero.x == town.x);
    REQUIRE(hero.y == town.y);
    REQUIRE(hero.z == town.z);
    test_creature(hero, 0, Creature::WoodElf,  1);
    test_creature(hero, 1, Creature::Centaur, 19);
    test_creature(hero, 2, Creature::Empty,    0);
    test_creature(hero, 3, Creature::Empty,    0);
    test_creature(hero, 4, Creature::Empty,    0);
    test_creature(hero, 5, Creature::Empty,    0);
    test_creature(hero, 6, Creature::WoodElf,  1);

    town = save.findTown("BluesTown");
    REQUIRE(town.owner == 0); // Changed owner
    test_creature(town, 0, Creature::Griffin, 1);
    test_creature(town, 1, Creature::Centaur, 1);
    test_creature(town, 2, Creature::Dwarf,   1);
    test_creature(town, 3, Creature::Empty,   0);
    test_creature(town, 4, Creature::Dwarf,   1);
    test_creature(town, 5, Creature::Centaur, 1);
    test_creature(town, 6, Creature::Griffin, 1);

    // Edric stands in BluesTown.
    hero = save.findHero("Edric");
    REQUIRE(hero.on_map == 1);
    REQUIRE(hero.x == town.x);
    REQUIRE(hero.y == town.y);
    REQUIRE(hero.z == town.z);
    test_creature(hero, 0, Creature::Pikeman, 15);
    test_creature(hero, 1, Creature::Griffin,  2);
    test_creature(hero, 2, Creature::Empty,    0);
    test_creature(hero, 3, Creature::Empty,    0);
    test_creature(hero, 4, Creature::Empty,    0);
    test_creature(hero, 5, Creature::Empty,    0);
    test_creature(hero, 6, Creature::Empty,    0);

    town = save.findTown("BUUUUUUURN");
    test_creature(town, 0, Creature::Magog, 1);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Magog, 2);

    town = save.findTown("LOOKOUT");
    test_creature(town, 0, Creature::Gremlin, 1);
    test_creature(town, 1, Creature::Gremlin, 2);
    test_creature(town, 2, Creature::Gremlin, 3);
    test_creature(town, 3, Creature::Gremlin, 4);
    test_creature(town, 4, Creature::Gremlin, 5);
    test_creature(town, 5, Creature::Gremlin, 6);
    test_creature(town, 6, Creature::Gremlin, 7);
}

// - Red takes BUUUUUUURN.
// - Blue takes LOOKOUT.
// - Edric stands in BUUUUUUURN with [pikeman, griffin,0,0,0,0]/[15,2,0,0,0,0,0]
// - BUUUUUUURN has garrison [imp, imp, imp, gog, 0, gog, gog]/[2,2,2,2,0,1,1]
// - Kyrre stands in LOOKOUT with [woodelf, centaur, 0, 0, centaur, 0, woodelf]/[1,8,0,0,8,0,1].
// - LOOKOUT has garrison [gremlin, gremlin, 0, gremlin, gremlin, 0, stonegargoyle], [2,2,0,4,2,0,9].
TEST_CASE("towns-day4", "[hero][town][creature]")
{
    h3::SaveFile save({testDataDir / "[hotseat] 114.GM2", "RedsTown", 4});
    REQUIRE(save.valid());
    test_town_constants(save.towns);

    auto town = save.findTown("RedsTown");
    REQUIRE(town.owner == 1);
    test_creature(town, 0, Creature::Centaur, 2);
    test_creature(town, 1, Creature::Empty,   0);
    test_creature(town, 2, Creature::Archer,  5);
    test_creature(town, 3, Creature::Dwarf,   1);
    test_creature(town, 4, Creature::Archer,  4);
    test_creature(town, 5, Creature::Dwarf,   1);
    test_creature(town, 6, Creature::Centaur, 2);

    town = save.findTown("BluesTown");
    REQUIRE(town.owner == 0);
    test_creature(town, 0, Creature::Griffin, 1);
    test_creature(town, 1, Creature::Centaur, 1);
    test_creature(town, 2, Creature::Dwarf,   1);
    test_creature(town, 3, Creature::Empty,   0);
    test_creature(town, 4, Creature::Dwarf,   1);
    test_creature(town, 5, Creature::Centaur, 1);
    test_creature(town, 6, Creature::Griffin, 1);

    town = save.findTown("BUUUUUUURN");
    REQUIRE(town.owner == 0); // Changed owner
    test_creature(town, 0, Creature::Imp,   2);
    test_creature(town, 1, Creature::Imp,   2);
    test_creature(town, 2, Creature::Imp,   2);
    test_creature(town, 3, Creature::Gog,   2);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Gog,   1);
    test_creature(town, 6, Creature::Gog,   1);

    // Edric stands in BUUUUUUURN.
    Hero hero = save.findHero("Edric");
    REQUIRE(hero.on_map == 1);
    REQUIRE(hero.x == town.x);
    REQUIRE(hero.y == town.y);
    REQUIRE(hero.z == town.z);
    test_creature(hero, 0, Creature::Pikeman, 15);
    test_creature(hero, 1, Creature::Griffin,  2);
    test_creature(hero, 2, Creature::Empty,    0);
    test_creature(hero, 3, Creature::Empty,    0);
    test_creature(hero, 4, Creature::Empty,    0);
    test_creature(hero, 5, Creature::Empty,    0);
    test_creature(hero, 6, Creature::Empty,    0);

    town = save.findTown("LOOKOUT");
    REQUIRE(town.owner == 1); // Changed owner
    test_creature(town, 0, Creature::Gremlin,       2);
    test_creature(town, 1, Creature::Gremlin,       2);
    test_creature(town, 2, Creature::Empty,         0);
    test_creature(town, 3, Creature::Gremlin,       4);
    test_creature(town, 4, Creature::Gremlin,       2);
    test_creature(town, 5, Creature::Empty,         0);
    test_creature(town, 6, Creature::StoneGargoyle, 9);

    // Kyrre stands in LOOKOUT.
    hero = save.findHero("Kyrre");
    REQUIRE(hero.on_map == 1);
    REQUIRE(hero.x == town.x);
    REQUIRE(hero.y == town.y);
    REQUIRE(hero.z == town.z);
    test_creature(hero, 0, Creature::WoodElf,  1);
    test_creature(hero, 1, Creature::Centaur,  8);
    test_creature(hero, 2, Creature::Empty,    0);
    test_creature(hero, 3, Creature::Empty,    0);
    test_creature(hero, 4, Creature::Centaur,  8);
    test_creature(hero, 5, Creature::Empty,    0);
    test_creature(hero, 6, Creature::WoodElf,  1);
}

// - Edric changes to visiting hero.
// - Kyrre changes to visiting hero.
TEST_CASE("towns-day5", "[hero][town][creature]")
{
    h3::SaveFile save({testDataDir / "[hotseat] 115.GM2", "RedsTown", 4});
    REQUIRE(save.valid());
    test_town_constants(save.towns);

    auto town = save.findTown("RedsTown");
    REQUIRE(town.owner == 1);
    test_creature(town, 0, Creature::Centaur, 2);
    test_creature(town, 1, Creature::Empty,   0);
    test_creature(town, 2, Creature::Archer,  5);
    test_creature(town, 3, Creature::Dwarf,   1);
    test_creature(town, 4, Creature::Archer,  4);
    test_creature(town, 5, Creature::Dwarf,   1);
    test_creature(town, 6, Creature::Centaur, 2);

    town = save.findTown("BluesTown");
    REQUIRE(town.owner == 0);
    test_creature(town, 0, Creature::Griffin, 1);
    test_creature(town, 1, Creature::Centaur, 1);
    test_creature(town, 2, Creature::Dwarf,   1);
    test_creature(town, 3, Creature::Empty,   0);
    test_creature(town, 4, Creature::Dwarf,   1);
    test_creature(town, 5, Creature::Centaur, 1);
    test_creature(town, 6, Creature::Griffin, 1);

    // BUUUUUUURN has no creatures in garrison since Edric is visiting.
    town = save.findTown("BUUUUUUURN");
    REQUIRE(town.owner == 0);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);

    // Edric is visiting BUUUUUUURN.
    Hero hero = save.findHero("Edric");
    REQUIRE(hero.on_map == 0);
    REQUIRE(hero.x == town.x);
    REQUIRE(hero.y == town.y);
    REQUIRE(hero.z == town.z);
    test_creature(hero, 0, Creature::Pikeman, 8);
    test_creature(hero, 1, Creature::Griffin, 2);
    test_creature(hero, 2, Creature::Empty,   0);
    test_creature(hero, 3, Creature::Gog,     4);
    test_creature(hero, 4, Creature::Imp,     6);
    test_creature(hero, 5, Creature::Pikeman, 7);
    test_creature(hero, 6, Creature::Empty,   0);

    // LOOKOUT has no creatures in garrison since Edric is visiting.
    town = save.findTown("LOOKOUT");
    REQUIRE(town.owner == 1);
    test_creature(town, 0, Creature::Empty, 0);
    test_creature(town, 1, Creature::Empty, 0);
    test_creature(town, 2, Creature::Empty, 0);
    test_creature(town, 3, Creature::Empty, 0);
    test_creature(town, 4, Creature::Empty, 0);
    test_creature(town, 5, Creature::Empty, 0);
    test_creature(town, 6, Creature::Empty, 0);

    // Kyrre is visiting LOOKOUT.
    hero = save.findHero("Kyrre");
    REQUIRE(hero.on_map == 0);
    REQUIRE(hero.x == town.x);
    REQUIRE(hero.y == town.y);
    REQUIRE(hero.z == town.z);
    test_creature(hero, 0, Creature::WoodElf,        1);
    test_creature(hero, 1, Creature::Centaur,        8);
    test_creature(hero, 2, Creature::Gremlin,       10);
    test_creature(hero, 3, Creature::StoneGargoyle,  9);
    test_creature(hero, 4, Creature::Centaur,        8);
    test_creature(hero, 5, Creature::Empty,          0);
    test_creature(hero, 6, Creature::WoodElf,        1);
}
