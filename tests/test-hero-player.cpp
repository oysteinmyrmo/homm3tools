#include <h3/creatures.h>
#include <h3/hero.h>
#include <h3/savefile.h>
#include <h3/stats.h>

#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::hero::Hero;
using h3::savefile::SaveFile;
}

void test_save01(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Orrin");
    assert(hero.player == 0);

    hero = save.findHero("Valeska");
    assert(hero.player == 1);

    hero = save.findHero("Edric");
    assert(hero.player == 2);

    hero = save.findHero("Sylvia");
    assert(hero.player == 3);

    hero = save.findHero("Lord Haart");
    assert(hero.player == 4);

    hero = save.findHero("Sorsha");
    assert(hero.player == 5);

    hero = save.findHero("Christian");
    assert(hero.player == 6);

    hero = save.findHero("Tyris");
    assert(hero.player == 7);
}

void test_save02(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Orrin");
    assert(hero.player == 7);

    hero = save.findHero("Valeska");
    assert(hero.player == 0);

    hero = save.findHero("Edric");
    assert(hero.player == 1);

    hero = save.findHero("Sylvia");
    assert(hero.player == 2);

    hero = save.findHero("Lord Haart");
    assert(hero.player == 3);

    hero = save.findHero("Sorsha");
    assert(hero.player == 4);

    hero = save.findHero("Christian");
    assert(hero.player == 5);

    hero = save.findHero("Tyris");
    assert(hero.player == 6);
}

int main()
{
    // Test data is copied relative to executable in output/binary dir.
    fs::path testDataDir("../test_data");
    fs::path dir(testDataDir / "hero_player");

    h3::savefile::SaveFile save01(dir / "[hotseat] 111.01.GM8");
    h3::savefile::SaveFile save02(dir / "[hotseat] 111.02.GM8");

    test_save01(save01);
    test_save02(save02);

    return 0;
}
