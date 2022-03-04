#include <h3/creatures.h>
#include <h3/hero.h>
#include <h3/savefile.h>
#include <h3/stats.h>

#include <test_data.h>

#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::Hero;
using h3::SaveFile;
}

void test_day1(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Clavius");
    assert(hero.attack    == 1);
    assert(hero.defense   == 2);
    assert(hero.power     == 3);
    assert(hero.knowledge == 4);
    assert(hero.attackInGame()    == 1);
    assert(hero.defenseInGame()   == 2);
    assert(hero.powerInGame()     == 3);
    assert(hero.knowledgeInGame() == 4);

    hero = save.findHero("Nagash");
    assert(hero.attack    == 10);
    assert(hero.defense   == 20);
    assert(hero.power     == 30);
    assert(hero.knowledge == 40);
    assert(hero.attackInGame()    == 10);
    assert(hero.defenseInGame()   == 20);
    assert(hero.powerInGame()     == 30);
    assert(hero.knowledgeInGame() == 40);

    hero = save.findHero("Erdamon");
    assert(hero.attack    == 99);
    assert(hero.defense   == 99);
    assert(hero.power     == 99);
    assert(hero.knowledge == 99);
    assert(hero.attackInGame()    == 99);
    assert(hero.defenseInGame()   == 99);
    assert(hero.powerInGame()     == 99);
    assert(hero.knowledgeInGame() == 99);

    hero = save.findHero("Theodorus");
    assert(hero.attack    == 99);
    assert(hero.defense   == 99);
    assert(hero.power     == 99);
    assert(hero.knowledge == 99);
    assert(hero.attackInGame()    == 99);
    assert(hero.defenseInGame()   == 99);
    assert(hero.powerInGame()     == 99);
    assert(hero.knowledgeInGame() == 99);
}

void test_day2(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Clavius");
    assert(hero.attack    == 1);
    assert(hero.defense   == 2);
    assert(hero.power     == 12);
    assert(hero.knowledge == 4);
    assert(hero.attackInGame()    ==  1);
    assert(hero.defenseInGame()   ==  2);
    assert(hero.powerInGame()     == 12);
    assert(hero.knowledgeInGame() ==  4);

    hero = save.findHero("Nagash");
    assert(hero.attack    == 10);
    assert(hero.defense   == 20);
    assert(hero.power     == 30);
    assert(hero.knowledge == 49);
    assert(hero.attackInGame()    == 10);
    assert(hero.defenseInGame()   == 20);
    assert(hero.powerInGame()     == 30);
    assert(hero.knowledgeInGame() == 49);

    hero = save.findHero("Erdamon");
    assert(hero.attack    == 101);
    assert(hero.defense   == 105);
    assert(hero.power     ==  99);
    assert(hero.knowledge ==  99);
    assert(hero.attackInGame()    == 99);
    assert(hero.defenseInGame()   == 99);
    assert(hero.powerInGame()     == 99);
    assert(hero.knowledgeInGame() == 99);

    hero = save.findHero("Theodorus");
    assert(hero.attack    ==  99);
    assert(hero.defense   ==  99);
    assert(hero.power     ==  99);
    assert(hero.knowledge == 107);
    assert(hero.attackInGame()    == 99);
    assert(hero.defenseInGame()   == 99);
    assert(hero.powerInGame()     == 99);
    assert(hero.knowledgeInGame() == 99);
}

int main()
{
    fs::path dir(h3::test::testDataDir / "primary_skills");

    h3::SaveFile day1({dir / "[hotseat] 111.GM2"});
    h3::SaveFile day2({dir / "[hotseat] 112.GM2"});

    test_day1(day1);
    test_day2(day2);

    return 0;
}
