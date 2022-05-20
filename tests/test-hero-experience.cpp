#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "experience");
} // namespace

TEST_CASE("hero-experience-day1", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 2);
    REQUIRE(hero.experience == 1500);
    REQUIRE(hero.attack    == 1);
    REQUIRE(hero.defense   == 3);
    REQUIRE(hero.power     == 2);
    REQUIRE(hero.knowledge == 1);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 2);
    REQUIRE(hero.experience == 1800);
    REQUIRE(hero.attack    == 1);
    REQUIRE(hero.defense   == 0);
    REQUIRE(hero.power     == 2);
    REQUIRE(hero.knowledge == 3);
}

TEST_CASE("hero-experience-day2", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 7);
    REQUIRE(hero.experience == 9000);
    REQUIRE(hero.attack    == 4);
    REQUIRE(hero.defense   == 4);
    REQUIRE(hero.power     == 2);
    REQUIRE(hero.knowledge == 2);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 12);
    REQUIRE(hero.experience == 21800);
    REQUIRE(hero.attack    == 2);
    REQUIRE(hero.defense   == 2);
    REQUIRE(hero.power     == 5);
    REQUIRE(hero.knowledge == 7);
}

TEST_CASE("hero-experience-day3", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 9);
    REQUIRE(hero.experience == 13000);
    REQUIRE(hero.attack    == 4);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 3);
    REQUIRE(hero.knowledge == 2);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 18);
    REQUIRE(hero.experience == 61800);
    REQUIRE(hero.attack    == 3);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 6);
    REQUIRE(hero.knowledge == 8);
}

TEST_CASE("hero-experience-day4", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 114.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 10);
    REQUIRE(hero.experience == 17000);
    REQUIRE(hero.attack    == 4);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 4);
    REQUIRE(hero.knowledge == 2);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 20);
    REQUIRE(hero.experience == 91800);
    REQUIRE(hero.attack    == 4);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 7);
    REQUIRE(hero.knowledge == 8);
}

TEST_CASE("hero-experience-day5", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 115.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 13);
    REQUIRE(hero.experience == 26000);
    REQUIRE(hero.attack    == 5);
    REQUIRE(hero.defense   == 6);
    REQUIRE(hero.power     == 5);
    REQUIRE(hero.knowledge == 2);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 21);
    REQUIRE(hero.experience == 101800);
    REQUIRE(hero.attack    == 5);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 7);
    REQUIRE(hero.knowledge == 8);
}

TEST_CASE("hero-experience-day6", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 116.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 14);
    REQUIRE(hero.experience == 29750);
    REQUIRE(hero.attack    == 5);
    REQUIRE(hero.defense   == 6);
    REQUIRE(hero.power     == 5);
    REQUIRE(hero.knowledge == 3);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 21);
    REQUIRE(hero.experience == 107800);
    REQUIRE(hero.attack    == 5);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 7);
    REQUIRE(hero.knowledge == 8);
}

TEST_CASE("hero-experience-day7", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 117.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 16);
    REQUIRE(hero.experience == 41750);
    REQUIRE(hero.attack    == 6);
    REQUIRE(hero.defense   == 7);
    REQUIRE(hero.power     == 5);
    REQUIRE(hero.knowledge == 3);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 21);
    REQUIRE(hero.experience == 112800);
    REQUIRE(hero.attack    == 5);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 7);
    REQUIRE(hero.knowledge == 8);
}

TEST_CASE("hero-experience-day8", "[hero][experience][level][secondary-skill]")
{
    SaveFile save({testDataDir / "[hotseat] 121.GM2"});
    REQUIRE(save.valid());

    REQUIRE(save.towns.size() == 2);
    REQUIRE(save.towns[0].name == "Emerald Moor");
    REQUIRE(save.towns[1].name == "Cessacioun");

    Hero hero = save.findHero("Giselle");
    REQUIRE(hero.level == 18);
    REQUIRE(hero.experience == 62375);
    REQUIRE(hero.attack    == 7);
    REQUIRE(hero.defense   == 7);
    REQUIRE(hero.power     == 6);
    REQUIRE(hero.knowledge == 3);

    hero = save.findHero("Thant");
    REQUIRE(hero.level == 22);
    REQUIRE(hero.experience == 120720);
    REQUIRE(hero.attack    == 5);
    REQUIRE(hero.defense   == 5);
    REQUIRE(hero.power     == 7);
    REQUIRE(hero.knowledge == 9);
}
