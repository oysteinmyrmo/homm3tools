#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "hero_player");
} // namespace

TEST_CASE("hero-player-01", "[hero][player]")
{
    SaveFile save({testDataDir / "[hotseat] 111.01.GM8"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Orrin");
    REQUIRE(hero.player == 0);

    hero = save.findHero("Valeska");
    REQUIRE(hero.player == 1);

    hero = save.findHero("Edric");
    REQUIRE(hero.player == 2);

    hero = save.findHero("Sylvia");
    REQUIRE(hero.player == 3);

    hero = save.findHero("Lord Haart");
    REQUIRE(hero.player == 4);

    hero = save.findHero("Sorsha");
    REQUIRE(hero.player == 5);

    hero = save.findHero("Christian");
    REQUIRE(hero.player == 6);

    hero = save.findHero("Tyris");
    REQUIRE(hero.player == 7);
}

TEST_CASE("hero-player-02", "[hero][player]")
{
    SaveFile save({testDataDir / "[hotseat] 111.02.GM8"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Orrin");
    REQUIRE(hero.player == 7);

    hero = save.findHero("Valeska");
    REQUIRE(hero.player == 0);

    hero = save.findHero("Edric");
    REQUIRE(hero.player == 1);

    hero = save.findHero("Sylvia");
    REQUIRE(hero.player == 2);

    hero = save.findHero("Lord Haart");
    REQUIRE(hero.player == 3);

    hero = save.findHero("Sorsha");
    REQUIRE(hero.player == 4);

    hero = save.findHero("Christian");
    REQUIRE(hero.player == 5);

    hero = save.findHero("Tyris");
    REQUIRE(hero.player == 6);
}
