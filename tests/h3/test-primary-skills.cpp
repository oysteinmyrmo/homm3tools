#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "primary_skills");
} // namespace

TEST_CASE("primary-skills-day1", "[hero][primary-skills]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Clavius");
    REQUIRE(hero.attack    == 1);
    REQUIRE(hero.defense   == 2);
    REQUIRE(hero.power     == 3);
    REQUIRE(hero.knowledge == 4);
    REQUIRE(hero.attackInGame()    == 1);
    REQUIRE(hero.defenseInGame()   == 2);
    REQUIRE(hero.powerInGame()     == 3);
    REQUIRE(hero.knowledgeInGame() == 4);

    hero = save.findHero("Nagash");
    REQUIRE(hero.attack    == 10);
    REQUIRE(hero.defense   == 20);
    REQUIRE(hero.power     == 30);
    REQUIRE(hero.knowledge == 40);
    REQUIRE(hero.attackInGame()    == 10);
    REQUIRE(hero.defenseInGame()   == 20);
    REQUIRE(hero.powerInGame()     == 30);
    REQUIRE(hero.knowledgeInGame() == 40);

    hero = save.findHero("Erdamon");
    REQUIRE(hero.attack    == 99);
    REQUIRE(hero.defense   == 99);
    REQUIRE(hero.power     == 99);
    REQUIRE(hero.knowledge == 99);
    REQUIRE(hero.attackInGame()    == 99);
    REQUIRE(hero.defenseInGame()   == 99);
    REQUIRE(hero.powerInGame()     == 99);
    REQUIRE(hero.knowledgeInGame() == 99);

    hero = save.findHero("Theodorus");
    REQUIRE(hero.attack    == 99);
    REQUIRE(hero.defense   == 99);
    REQUIRE(hero.power     == 99);
    REQUIRE(hero.knowledge == 99);
    REQUIRE(hero.attackInGame()    == 99);
    REQUIRE(hero.defenseInGame()   == 99);
    REQUIRE(hero.powerInGame()     == 99);
    REQUIRE(hero.knowledgeInGame() == 99);
}

TEST_CASE("primary-skills-day2", "[hero][primary-skills]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM2"});
    REQUIRE(save.valid());

    Hero hero = save.findHero("Clavius");
    REQUIRE(hero.attack    == 1);
    REQUIRE(hero.defense   == 2);
    REQUIRE(hero.power     == 12);
    REQUIRE(hero.knowledge == 4);
    REQUIRE(hero.attackInGame()    ==  1);
    REQUIRE(hero.defenseInGame()   ==  2);
    REQUIRE(hero.powerInGame()     == 12);
    REQUIRE(hero.knowledgeInGame() ==  4);

    hero = save.findHero("Nagash");
    REQUIRE(hero.attack    == 10);
    REQUIRE(hero.defense   == 20);
    REQUIRE(hero.power     == 30);
    REQUIRE(hero.knowledge == 49);
    REQUIRE(hero.attackInGame()    == 10);
    REQUIRE(hero.defenseInGame()   == 20);
    REQUIRE(hero.powerInGame()     == 30);
    REQUIRE(hero.knowledgeInGame() == 49);

    hero = save.findHero("Erdamon");
    REQUIRE(hero.attack    == 101);
    REQUIRE(hero.defense   == 105);
    REQUIRE(hero.power     ==  99);
    REQUIRE(hero.knowledge ==  99);
    REQUIRE(hero.attackInGame()    == 99);
    REQUIRE(hero.defenseInGame()   == 99);
    REQUIRE(hero.powerInGame()     == 99);
    REQUIRE(hero.knowledgeInGame() == 99);

    hero = save.findHero("Theodorus");
    REQUIRE(hero.attack    ==  99);
    REQUIRE(hero.defense   ==  99);
    REQUIRE(hero.power     ==  99);
    REQUIRE(hero.knowledge == 107);
    REQUIRE(hero.attackInGame()    == 99);
    REQUIRE(hero.defenseInGame()   == 99);
    REQUIRE(hero.powerInGame()     == 99);
    REQUIRE(hero.knowledgeInGame() == 99);
}
