#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/player.h>
#include <h3/savefile.h>

#include <algorithm>
#include <filesystem>

namespace
{
using h3::Hero;
using h3::Color;
using h3::SaveFile;
using h3::Town;

std::filesystem::path testDataDir(h3::test::testDataDir / "savefile");
} // namespace

TEST_CASE("savefile-S", "[hero][town][savefile]")
{
    SaveFile save({testDataDir / "S" / "[hotseat] 111.GM2", "RedsTown", 2});

    REQUIRE(save.valid());
    REQUIRE(save.heroCount == h3::hero::heroCount);
    REQUIRE(save.mapSize == h3::savefile::MapSize::S);
    REQUIRE(save.hasUnderground == 0);
    REQUIRE(save.mapNameSize == 20);
    REQUIRE(save.mapName == "SaveGameTester_Map_S");
    REQUIRE(save.descriptionSize == 0);
    REQUIRE(save.description == "");
    REQUIRE(save.towns.size() == 2);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    REQUIRE(red.color() == Color::Red);
    REQUIRE(red.towns().size() == 1);
    REQUIRE(red.heroes().size() == 1);

    Town town = red.towns()[0];
    REQUIRE(town.name == "RedsTown");
    REQUIRE(town.x == 2);
    REQUIRE(town.y == 3);
    REQUIRE(town.z == 0);

    Hero hero = red.heroes()[0];
    REQUIRE(memcmp(hero.name, "Orrin", 5) == 0);
    REQUIRE(hero.x == 2);
    REQUIRE(hero.y == 4);
    REQUIRE(hero.z == 0);

    const auto &blue = players[1];
    REQUIRE(blue.color() == Color::Blue);
    REQUIRE(blue.towns().size() == 1);
    REQUIRE(blue.heroes().size() == 1);

    town = blue.towns()[0];
    REQUIRE(town.name == "BluesTown");
    REQUIRE(town.x == 33);
    REQUIRE(town.y == 34);
    REQUIRE(town.z ==  0);

    hero = blue.heroes()[0];
    REQUIRE(memcmp(hero.name, "Mephala", 7) == 0);
    REQUIRE(hero.x == 33);
    REQUIRE(hero.y == 35);
    REQUIRE(hero.z ==  0);

    REQUIRE(players[2].color() == Color::Tan);
    REQUIRE(players[3].color() == Color::Green);
    REQUIRE(players[4].color() == Color::Orange);
    REQUIRE(players[5].color() == Color::Purple);
    REQUIRE(players[6].color() == Color::Teal);
    REQUIRE(players[7].color() == Color::Pink);

    REQUIRE(players[2].alive() == false);
    REQUIRE(players[3].alive() == false);
    REQUIRE(players[4].alive() == false);
    REQUIRE(players[5].alive() == false);
    REQUIRE(players[6].alive() == false);
    REQUIRE(players[7].alive() == false);
}

TEST_CASE("savefile-S_U", "[hero][town][savefile]")
{
    SaveFile save({testDataDir / "S_U" / "[hotseat] 111.GM2", "RedsTown", 4});

    REQUIRE(save.valid());
    REQUIRE(save.heroCount == h3::hero::heroCount);
    REQUIRE(save.mapSize == h3::savefile::MapSize::S);
    REQUIRE(save.hasUnderground == 1);
    REQUIRE(save.mapNameSize == 22);
    REQUIRE(save.mapName == "SaveGameTester_Map_S_U");
    REQUIRE(save.descriptionSize == 0);
    REQUIRE(save.description == "");
    REQUIRE(save.towns.size() == 4);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    REQUIRE(red.color() == Color::Red);
    REQUIRE(red.towns().size() == 2);
    REQUIRE(red.heroes().size() == 2);

    Town town = red.towns()[0];
    REQUIRE(town.name == "RedsTown");
    REQUIRE(town.x == 2);
    REQUIRE(town.y == 3);
    REQUIRE(town.z == 0);

    town = red.towns()[1];
    REQUIRE(town.name == "RedsTown_U");
    REQUIRE(town.x == 33);
    REQUIRE(town.y ==  3);
    REQUIRE(town.z ==  1);

    Hero hero = red.heroes()[0];
    REQUIRE(memcmp(hero.name, "Orrin", 5) == 0);
    REQUIRE(hero.x == 2);
    REQUIRE(hero.y == 4);
    REQUIRE(hero.z == 0);

    hero = red.heroes()[1];
    REQUIRE(memcmp(hero.name, "Rion", 4) == 0);
    REQUIRE(hero.x == 33);
    REQUIRE(hero.y ==  4);
    REQUIRE(hero.z ==  1);

    const auto &blue = players[1];
    REQUIRE(blue.color() == Color::Blue);
    REQUIRE(blue.towns().size() == 2);
    REQUIRE(blue.heroes().size() == 2);

    town = blue.towns()[0];
    REQUIRE(town.name == "BluesTown");
    REQUIRE(town.x == 33);
    REQUIRE(town.y == 34);
    REQUIRE(town.z ==  0);

    town = blue.towns()[1];
    REQUIRE(town.name == "BluesTown_U");
    REQUIRE(town.x ==  2);
    REQUIRE(town.y == 34);
    REQUIRE(town.z ==  1);

    hero = blue.heroes()[0];
    REQUIRE(memcmp(hero.name, "Mephala", 7) == 0);
    REQUIRE(hero.x == 33);
    REQUIRE(hero.y == 35);
    REQUIRE(hero.z ==  0);

    hero = blue.heroes()[1];
    REQUIRE(memcmp(hero.name, "Coronius", 8) == 0);
    REQUIRE(hero.x ==  2);
    REQUIRE(hero.y == 35);
    REQUIRE(hero.z ==  1);

    REQUIRE(players[2].color() == Color::Tan);
    REQUIRE(players[3].color() == Color::Green);
    REQUIRE(players[4].color() == Color::Orange);
    REQUIRE(players[5].color() == Color::Purple);
    REQUIRE(players[6].color() == Color::Teal);
    REQUIRE(players[7].color() == Color::Pink);

    REQUIRE(players[2].alive() == false);
    REQUIRE(players[3].alive() == false);
    REQUIRE(players[4].alive() == false);
    REQUIRE(players[5].alive() == false);
    REQUIRE(players[6].alive() == false);
    REQUIRE(players[7].alive() == false);
}

TEST_CASE("savefile-M", "[hero][town][savefile]")
{
    SaveFile save({testDataDir / "M" / "[hotseat] 111.GM2", "RedsTown", 2});

    REQUIRE(save.valid());
    REQUIRE(save.heroCount == h3::hero::heroCount);
    REQUIRE(save.mapSize == h3::savefile::MapSize::M);
    REQUIRE(save.hasUnderground == 0);
    REQUIRE(save.mapNameSize == 20);
    REQUIRE(save.mapName == "SaveGameTester_Map_M");
    REQUIRE(save.descriptionSize == 0);
    REQUIRE(save.description == "");
    REQUIRE(save.towns.size() == 2);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    REQUIRE(red.color() == Color::Red);
    REQUIRE(red.towns().size() == 1);
    REQUIRE(red.heroes().size() == 1);

    Town town = red.towns()[0];
    REQUIRE(town.name == "RedsTown");
    REQUIRE(town.x == 2);
    REQUIRE(town.y == 3);
    REQUIRE(town.z == 0);

    Hero hero = red.heroes()[0];
    REQUIRE(memcmp(hero.name, "Orrin", 5) == 0);
    REQUIRE(hero.x == 2);
    REQUIRE(hero.y == 4);
    REQUIRE(hero.z == 0);

    const auto &blue = players[1];
    REQUIRE(blue.color() == Color::Blue);
    REQUIRE(blue.towns().size() == 1);
    REQUIRE(blue.heroes().size() == 1);

    town = blue.towns()[0];
    REQUIRE(town.name == "Bath'iere"); // Forgot to change to "BluesTown".
    REQUIRE(town.x == 69);
    REQUIRE(town.y == 70);
    REQUIRE(town.z ==  0);

    hero = blue.heroes()[0];
    REQUIRE(memcmp(hero.name, "Mephala", 7) == 0);
    REQUIRE(hero.x == 69);
    REQUIRE(hero.y == 71);
    REQUIRE(hero.z ==  0);

    REQUIRE(players[2].color() == Color::Tan);
    REQUIRE(players[3].color() == Color::Green);
    REQUIRE(players[4].color() == Color::Orange);
    REQUIRE(players[5].color() == Color::Purple);
    REQUIRE(players[6].color() == Color::Teal);
    REQUIRE(players[7].color() == Color::Pink);

    REQUIRE(players[2].alive() == false);
    REQUIRE(players[3].alive() == false);
    REQUIRE(players[4].alive() == false);
    REQUIRE(players[5].alive() == false);
    REQUIRE(players[6].alive() == false);
    REQUIRE(players[7].alive() == false);
}

TEST_CASE("savefile-M_U", "[hero][town][savefile]")
{
    SaveFile save({testDataDir / "M_U" / "[hotseat] 111.GM2", "RedsTown", 4});

    REQUIRE(save.valid());
    REQUIRE(save.heroCount == h3::hero::heroCount);
    REQUIRE(save.mapSize == h3::savefile::MapSize::M);
    REQUIRE(save.hasUnderground == 1);
    REQUIRE(save.mapNameSize == 22);
    REQUIRE(save.mapName == "SaveGameTester_Map_M_U");
    REQUIRE(save.descriptionSize == 0);
    REQUIRE(save.description == "");
    REQUIRE(save.towns.size() == 4);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    REQUIRE(red.color() == Color::Red);
    REQUIRE(red.towns().size() == 2);
    REQUIRE(red.heroes().size() == 2);

    Town town = red.towns()[0];
    REQUIRE(town.name == "RedsTown");
    REQUIRE(town.x == 2);
    REQUIRE(town.y == 3);
    REQUIRE(town.z == 0);

    town = red.towns()[1];
    REQUIRE(town.name == "RedsTown_U");
    REQUIRE(town.x == 69);
    REQUIRE(town.y ==  3);
    REQUIRE(town.z ==  1);

    Hero hero = red.heroes()[0];
    REQUIRE(memcmp(hero.name, "Orrin", 5) == 0);
    REQUIRE(hero.x == 2);
    REQUIRE(hero.y == 4);
    REQUIRE(hero.z == 0);

    hero = red.heroes()[1];
    REQUIRE(memcmp(hero.name, "Rion", 4) == 0);
    REQUIRE(hero.x == 69);
    REQUIRE(hero.y ==  4);
    REQUIRE(hero.z ==  1);

    const auto &blue = players[1];
    REQUIRE(blue.color() == Color::Blue);
    REQUIRE(blue.towns().size() == 2);
    REQUIRE(blue.heroes().size() == 2);

    town = blue.towns()[0];
    REQUIRE(town.name == "Emerald Moor"); // Forgot to change to "BluesTown"
    REQUIRE(town.x == 69);
    REQUIRE(town.y == 70);
    REQUIRE(town.z ==  0);

    town = blue.towns()[1];
    REQUIRE(town.name == "BluesTown_U");
    REQUIRE(town.x ==  2);
    REQUIRE(town.y == 70);
    REQUIRE(town.z ==  1);

    hero = blue.heroes()[0];
    REQUIRE(memcmp(hero.name, "Mephala", 7) == 0);
    REQUIRE(hero.x == 69);
    REQUIRE(hero.y == 71);
    REQUIRE(hero.z ==  0);

    hero = blue.heroes()[1];
    REQUIRE(memcmp(hero.name, "Coronius", 8) == 0);
    REQUIRE(hero.x ==  2);
    REQUIRE(hero.y == 71);
    REQUIRE(hero.z ==  1);

    REQUIRE(players[2].color() == Color::Tan);
    REQUIRE(players[3].color() == Color::Green);
    REQUIRE(players[4].color() == Color::Orange);
    REQUIRE(players[5].color() == Color::Purple);
    REQUIRE(players[6].color() == Color::Teal);
    REQUIRE(players[7].color() == Color::Pink);

    REQUIRE(players[2].alive() == false);
    REQUIRE(players[3].alive() == false);
    REQUIRE(players[4].alive() == false);
    REQUIRE(players[5].alive() == false);
    REQUIRE(players[6].alive() == false);
    REQUIRE(players[7].alive() == false);
}
