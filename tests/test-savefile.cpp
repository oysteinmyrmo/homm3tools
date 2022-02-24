#include <h3/hero.h>
#include <h3/player.h>
#include <h3/savefile.h>

#include <test_data.h>

#include <algorithm>
#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::hero::Hero;
using h3::player::Color;
using h3::savefile::SaveFile;
using h3::town::Town;
} // namespace

void test_S()
{
    fs::path dir(h3::test::testDataDir / "savefile");
    SaveFile save({dir / "S" / "[hotseat] 111.GM2", "RedsTown", 2});

    assert(save.valid());
    assert(save.heroCount == h3::hero::heroCount);
    assert(save.mapSize == h3::savefile::MapSize::S);
    assert(save.hasUnderground == 0);
    assert(save.mapNameSize == 20);
    assert(save.mapName == "SaveGameTester_Map_S");
    assert(save.descriptionSize == 0);
    assert(save.description == "");
    assert(save.towns.size() == 2);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    assert(red.color() == Color::Red);
    assert(red.towns().size() == 1);
    assert(red.heroes().size() == 1);

    Town town = red.towns()[0];
    assert(town.name == "RedsTown");
    assert(town.x == 2);
    assert(town.y == 3);
    assert(town.z == 0);

    Hero hero = red.heroes()[0];
    assert(memcmp(hero.name, "Orrin", 5) == 0);
    assert(hero.x == 2);
    assert(hero.y == 4);
    assert(hero.z == 0);

    const auto &blue = players[1];
    assert(blue.color() == Color::Blue);
    assert(blue.towns().size() == 1);
    assert(blue.heroes().size() == 1);

    town = blue.towns()[0];
    assert(town.name == "BluesTown");
    assert(town.x == 33);
    assert(town.y == 34);
    assert(town.z ==  0);

    hero = blue.heroes()[0];
    assert(memcmp(hero.name, "Mephala", 7) == 0);
    assert(hero.x == 33);
    assert(hero.y == 35);
    assert(hero.z ==  0);

    assert(players[2].color() == Color::Tan);
    assert(players[3].color() == Color::Green);
    assert(players[4].color() == Color::Orange);
    assert(players[5].color() == Color::Purple);
    assert(players[6].color() == Color::Teal);
    assert(players[7].color() == Color::Pink);

    assert(players[2].alive() == false);
    assert(players[3].alive() == false);
    assert(players[4].alive() == false);
    assert(players[5].alive() == false);
    assert(players[6].alive() == false);
    assert(players[7].alive() == false);
}

void test_S_U()
{
    fs::path dir(h3::test::testDataDir / "savefile");
    SaveFile save({dir / "S_U" / "[hotseat] 111.GM2", "RedsTown", 4});

    assert(save.valid());
    assert(save.heroCount == h3::hero::heroCount);
    assert(save.mapSize == h3::savefile::MapSize::S);
    assert(save.hasUnderground == 1);
    assert(save.mapNameSize == 22);
    assert(save.mapName == "SaveGameTester_Map_S_U");
    assert(save.descriptionSize == 0);
    assert(save.description == "");
    assert(save.towns.size() == 4);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    assert(red.color() == Color::Red);
    assert(red.towns().size() == 2);
    assert(red.heroes().size() == 2);

    Town town = red.towns()[0];
    assert(town.name == "RedsTown");
    assert(town.x == 2);
    assert(town.y == 3);
    assert(town.z == 0);

    town = red.towns()[1];
    assert(town.name == "RedsTown_U");
    assert(town.x == 33);
    assert(town.y ==  3);
    assert(town.z ==  1);

    Hero hero = red.heroes()[0];
    assert(memcmp(hero.name, "Orrin", 5) == 0);
    assert(hero.x == 2);
    assert(hero.y == 4);
    assert(hero.z == 0);

    hero = red.heroes()[1];
    assert(memcmp(hero.name, "Rion", 4) == 0);
    assert(hero.x == 33);
    assert(hero.y ==  4);
    assert(hero.z ==  1);

    const auto &blue = players[1];
    assert(blue.color() == Color::Blue);
    assert(blue.towns().size() == 2);
    assert(blue.heroes().size() == 2);

    town = blue.towns()[0];
    assert(town.name == "BluesTown");
    assert(town.x == 33);
    assert(town.y == 34);
    assert(town.z ==  0);

    town = blue.towns()[1];
    assert(town.name == "BluesTown_U");
    assert(town.x ==  2);
    assert(town.y == 34);
    assert(town.z ==  1);

    hero = blue.heroes()[0];
    assert(memcmp(hero.name, "Mephala", 7) == 0);
    assert(hero.x == 33);
    assert(hero.y == 35);
    assert(hero.z ==  0);

    hero = blue.heroes()[1];
    assert(memcmp(hero.name, "Coronius", 8) == 0);
    assert(hero.x ==  2);
    assert(hero.y == 35);
    assert(hero.z ==  1);

    assert(players[2].color() == Color::Tan);
    assert(players[3].color() == Color::Green);
    assert(players[4].color() == Color::Orange);
    assert(players[5].color() == Color::Purple);
    assert(players[6].color() == Color::Teal);
    assert(players[7].color() == Color::Pink);

    assert(players[2].alive() == false);
    assert(players[3].alive() == false);
    assert(players[4].alive() == false);
    assert(players[5].alive() == false);
    assert(players[6].alive() == false);
    assert(players[7].alive() == false);
}

void test_M()
{
    fs::path dir(h3::test::testDataDir / "savefile");
    SaveFile save({dir / "M" / "[hotseat] 111.GM2", "RedsTown", 2});

    assert(save.valid());
    assert(save.heroCount == h3::hero::heroCount);
    assert(save.mapSize == h3::savefile::MapSize::M);
    assert(save.hasUnderground == 0);
    assert(save.mapNameSize == 20);
    assert(save.mapName == "SaveGameTester_Map_M");
    assert(save.descriptionSize == 0);
    assert(save.description == "");
    assert(save.towns.size() == 2);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    assert(red.color() == Color::Red);
    assert(red.towns().size() == 1);
    assert(red.heroes().size() == 1);

    Town town = red.towns()[0];
    assert(town.name == "RedsTown");
    assert(town.x == 2);
    assert(town.y == 3);
    assert(town.z == 0);

    Hero hero = red.heroes()[0];
    assert(memcmp(hero.name, "Orrin", 5) == 0);
    assert(hero.x == 2);
    assert(hero.y == 4);
    assert(hero.z == 0);

    const auto &blue = players[1];
    assert(blue.color() == Color::Blue);
    assert(blue.towns().size() == 1);
    assert(blue.heroes().size() == 1);

    town = blue.towns()[0];
    assert(town.name == "Bath'iere"); // Forgot to change to "BluesTown".
    assert(town.x == 69);
    assert(town.y == 70);
    assert(town.z ==  0);

    hero = blue.heroes()[0];
    assert(memcmp(hero.name, "Mephala", 7) == 0);
    assert(hero.x == 69);
    assert(hero.y == 71);
    assert(hero.z ==  0);

    assert(players[2].color() == Color::Tan);
    assert(players[3].color() == Color::Green);
    assert(players[4].color() == Color::Orange);
    assert(players[5].color() == Color::Purple);
    assert(players[6].color() == Color::Teal);
    assert(players[7].color() == Color::Pink);

    assert(players[2].alive() == false);
    assert(players[3].alive() == false);
    assert(players[4].alive() == false);
    assert(players[5].alive() == false);
    assert(players[6].alive() == false);
    assert(players[7].alive() == false);
}

void test_M_U()
{
    fs::path dir(h3::test::testDataDir / "savefile");
    SaveFile save({dir / "M_U" / "[hotseat] 111.GM2", "RedsTown", 4});

    assert(save.valid());
    assert(save.heroCount == h3::hero::heroCount);
    assert(save.mapSize == h3::savefile::MapSize::M);
    assert(save.hasUnderground == 1);
    assert(save.mapNameSize == 22);
    assert(save.mapName == "SaveGameTester_Map_M_U");
    assert(save.descriptionSize == 0);
    assert(save.description == "");
    assert(save.towns.size() == 4);

    const auto players = h3::player::players(save);

    const auto &red = players[0];
    assert(red.color() == Color::Red);
    assert(red.towns().size() == 2);
    assert(red.heroes().size() == 2);

    Town town = red.towns()[0];
    assert(town.name == "RedsTown");
    assert(town.x == 2);
    assert(town.y == 3);
    assert(town.z == 0);

    town = red.towns()[1];
    assert(town.name == "RedsTown_U");
    assert(town.x == 69);
    assert(town.y ==  3);
    assert(town.z ==  1);

    Hero hero = red.heroes()[0];
    assert(memcmp(hero.name, "Orrin", 5) == 0);
    assert(hero.x == 2);
    assert(hero.y == 4);
    assert(hero.z == 0);

    hero = red.heroes()[1];
    assert(memcmp(hero.name, "Rion", 4) == 0);
    assert(hero.x == 69);
    assert(hero.y ==  4);
    assert(hero.z ==  1);

    const auto &blue = players[1];
    assert(blue.color() == Color::Blue);
    assert(blue.towns().size() == 2);
    assert(blue.heroes().size() == 2);

    town = blue.towns()[0];
    assert(town.name == "Emerald Moor"); // Forgot to change to "BluesTown"
    assert(town.x == 69);
    assert(town.y == 70);
    assert(town.z ==  0);

    town = blue.towns()[1];
    assert(town.name == "BluesTown_U");
    assert(town.x ==  2);
    assert(town.y == 70);
    assert(town.z ==  1);

    hero = blue.heroes()[0];
    assert(memcmp(hero.name, "Mephala", 7) == 0);
    assert(hero.x == 69);
    assert(hero.y == 71);
    assert(hero.z ==  0);

    hero = blue.heroes()[1];
    assert(memcmp(hero.name, "Coronius", 8) == 0);
    assert(hero.x ==  2);
    assert(hero.y == 71);
    assert(hero.z ==  1);

    assert(players[2].color() == Color::Tan);
    assert(players[3].color() == Color::Green);
    assert(players[4].color() == Color::Orange);
    assert(players[5].color() == Color::Purple);
    assert(players[6].color() == Color::Teal);
    assert(players[7].color() == Color::Pink);

    assert(players[2].alive() == false);
    assert(players[3].alive() == false);
    assert(players[4].alive() == false);
    assert(players[5].alive() == false);
    assert(players[6].alive() == false);
    assert(players[7].alive() == false);
}

int main()
{
    test_S();
    test_S_U();
    test_M();
    test_M_U();

    return 0;
}
