#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "hero_town");
} // namespace

TEST_CASE("hero-town-day1", "[hero][town]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM3"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Orrin");
    REQUIRE(hero.x ==  9);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Valeska");
    REQUIRE(hero.x == 12);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Edric");
    REQUIRE(hero.x == 15);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Mephala");
    REQUIRE(hero.x == 18);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Ufretin");
    REQUIRE(hero.x == 21);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Jenova");
    REQUIRE(hero.x == 24);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    REQUIRE(hero.x == 27);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Thane");
    REQUIRE(hero.x == 30);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Josephine");
    REQUIRE(hero.x == 33);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1);
}

// - Second hero goes to town.
TEST_CASE("hero-town-day2", "[hero][town]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM3"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Orrin");
    REQUIRE(hero.x ==  9);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Valeska");
    REQUIRE(hero.x == 12);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Edric");
    REQUIRE(hero.x == 15);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Mephala");
    REQUIRE(hero.x == 18);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Ufretin");
    REQUIRE(hero.x == 21);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Jenova");
    REQUIRE(hero.x == 24);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    REQUIRE(hero.x == 27);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Thane");
    REQUIRE(hero.x == 30);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Josephine");
    REQUIRE(hero.x == 33);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1);
}

// - Hero in town swaps to visiting position.
// - First hero goes to town.
TEST_CASE("hero-town-day3", "[hero][town]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM3"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Orrin");
    REQUIRE(hero.x == 12);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Valeska");
    REQUIRE(hero.x == 12);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 0); // Visiting

    hero = save.findHero("Edric");
    REQUIRE(hero.x == 15);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Mephala");
    REQUIRE(hero.x == 21);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Ufretin");
    REQUIRE(hero.x == 21);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 0); // Visiting

    hero = save.findHero("Jenova");
    REQUIRE(hero.x == 24);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    REQUIRE(hero.x == 30);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Thane");
    REQUIRE(hero.x == 30);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 0); // Visiting

    hero = save.findHero("Josephine");
    REQUIRE(hero.x == 33);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1);
}

// - Swap visiting hero and hero in town.
TEST_CASE("hero-town-day4", "[hero][town]")
{
    SaveFile save({testDataDir / "[hotseat] 114.GM3"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Orrin");
    REQUIRE(hero.x == 12);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 0); // Visiting

    hero = save.findHero("Valeska");
    REQUIRE(hero.x == 12);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Edric");
    REQUIRE(hero.x == 15);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Mephala");
    REQUIRE(hero.x == 21);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 0); // Visiting

    hero = save.findHero("Ufretin");
    REQUIRE(hero.x == 21);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Jenova");
    REQUIRE(hero.x == 24);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    REQUIRE(hero.x == 30);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 0); // Visiting

    hero = save.findHero("Thane");
    REQUIRE(hero.x == 30);
    REQUIRE(hero.y ==  9);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1); // In town

    hero = save.findHero("Josephine");
    REQUIRE(hero.x == 33);
    REQUIRE(hero.y == 12);
    REQUIRE(hero.z ==  0);
    REQUIRE(hero.player == 2);
    REQUIRE(hero.on_map == 1);
}
