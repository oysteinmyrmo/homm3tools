#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "spell_points");
} // namespace

TEST_CASE("spell-points-day1", "[hero][spell-points]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Sephinroth");
    REQUIRE(hero.spell_points == 360);

    hero = save.findHero("Sorsha");
    REQUIRE(hero.spell_points == 10);
}

TEST_CASE("spell-points-day2", "[hero][spell-points]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM2"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Sephinroth");
    REQUIRE(hero.spell_points == 344);

    hero = save.findHero("Sorsha");
    REQUIRE(hero.spell_points == 4);
}
