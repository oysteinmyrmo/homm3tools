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

void test_day1(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Orrin");
    assert(hero.x ==  9);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Valeska");
    assert(hero.x == 12);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Edric");
    assert(hero.x == 15);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Mephala");
    assert(hero.x == 18);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Ufretin");
    assert(hero.x == 21);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Jenova");
    assert(hero.x == 24);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    assert(hero.x == 27);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1);

    hero = save.findHero("Thane");
    assert(hero.x == 30);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1);

    hero = save.findHero("Josephine");
    assert(hero.x == 33);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1);
}

// - Second hero goes to town.
void test_day2(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Orrin");
    assert(hero.x ==  9);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Valeska");
    assert(hero.x == 12);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Edric");
    assert(hero.x == 15);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Mephala");
    assert(hero.x == 18);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Ufretin");
    assert(hero.x == 21);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Jenova");
    assert(hero.x == 24);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    assert(hero.x == 27);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1);

    hero = save.findHero("Thane");
    assert(hero.x == 30);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Josephine");
    assert(hero.x == 33);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1);
}

// - Hero in town swaps to visiting position.
// - First hero goes to town.
void test_day3(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Orrin");
    assert(hero.x == 12);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Valeska");
    assert(hero.x == 12);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 0); // Visiting

    hero = save.findHero("Edric");
    assert(hero.x == 15);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Mephala");
    assert(hero.x == 21);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Ufretin");
    assert(hero.x == 21);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 0); // Visiting

    hero = save.findHero("Jenova");
    assert(hero.x == 24);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    assert(hero.x == 30);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Thane");
    assert(hero.x == 30);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 0); // Visiting

    hero = save.findHero("Josephine");
    assert(hero.x == 33);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1);
}

// - Swap visiting hero and hero in town.
void test_day4(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Orrin");
    assert(hero.x == 12);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 0); // Visiting

    hero = save.findHero("Valeska");
    assert(hero.x == 12);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Edric");
    assert(hero.x == 15);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Mephala");
    assert(hero.x == 21);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 0); // Visiting

    hero = save.findHero("Ufretin");
    assert(hero.x == 21);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Jenova");
    assert(hero.x == 24);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Piquedram");
    assert(hero.x == 30);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 0); // Visiting

    hero = save.findHero("Thane");
    assert(hero.x == 30);
    assert(hero.y ==  9);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1); // In town

    hero = save.findHero("Josephine");
    assert(hero.x == 33);
    assert(hero.y == 12);
    assert(hero.z ==  0);
    assert(hero.player == 2);
    assert(hero.on_map == 1);
}

int main()
{
    // Test data is copied relative to executable in output/binary dir.
    fs::path testDataDir("../test_data");
    fs::path dir(testDataDir / "hero_town");

    h3::savefile::SaveFile day1(dir / "[hotseat] 111.GM3");
    h3::savefile::SaveFile day2(dir / "[hotseat] 112.GM3");
    h3::savefile::SaveFile day3(dir / "[hotseat] 113.GM3");

    test_day1(day1);
    test_day2(day2);
    test_day3(day3);

    return 0;
}
