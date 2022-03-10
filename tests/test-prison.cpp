#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "prison");
} // namespace

TEST_CASE("prison-day1", "[hero][prison]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Spint");
    REQUIRE(hero.x == 14);
    REQUIRE(hero.y == 13);
    REQUIRE(hero.z ==  1);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);
    REQUIRE(!hero.prison());
    REQUIRE(!hero.garrison());

    hero = save.findHero("Solmyr");
    REQUIRE(hero.x == 19);
    REQUIRE(hero.y == 13);
    REQUIRE(hero.z ==  1);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);
    REQUIRE(!hero.prison());
    REQUIRE(!hero.garrison());

    hero = save.findHero("Sandro");
    REQUIRE(hero.x == 13);
    REQUIRE(hero.y == 13);
    REQUIRE(hero.z ==  1);
    REQUIRE(hero.player == 0xFF);
    REQUIRE(hero.on_map == 0); // In prison = 0, but position is set!
    REQUIRE(hero.prison());
    REQUIRE(!hero.garrison());
}

TEST_CASE("prison-day2", "[hero][prison]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM2"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Spint");
    REQUIRE(hero.x == 14);
    REQUIRE(hero.y == 13);
    REQUIRE(hero.z ==  1);
    REQUIRE(hero.player == 0);
    REQUIRE(hero.on_map == 1);
    REQUIRE(!hero.prison());
    REQUIRE(!hero.garrison());

    hero = save.findHero("Solmyr");
    REQUIRE(hero.x == 19);
    REQUIRE(hero.y == 13);
    REQUIRE(hero.z ==  1);
    REQUIRE(hero.player == 1);
    REQUIRE(hero.on_map == 1);
    REQUIRE(!hero.prison());
    REQUIRE(!hero.garrison());

    // Sandro is released, same position, but now player and on_map is changed.
    hero = save.findHero("Sandro");
    REQUIRE(hero.x == 13);
    REQUIRE(hero.y == 13);
    REQUIRE(hero.z ==  1);
    REQUIRE(hero.player == 0); // Belongs to red player now.
    REQUIRE(hero.on_map == 1); // Is now on map.
    REQUIRE(!hero.prison());
    REQUIRE(!hero.garrison());
}
