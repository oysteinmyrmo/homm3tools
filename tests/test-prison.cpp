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

    Hero hero = save.findHero("Spint");
    assert(hero.x == 14);
    assert(hero.y == 13);
    assert(hero.z ==  1);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Solmyr");
    assert(hero.x == 19);
    assert(hero.y == 13);
    assert(hero.z ==  1);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    hero = save.findHero("Sandro");
    assert(hero.x == 13);
    assert(hero.y == 13);
    assert(hero.z ==  1);
    assert(hero.player == 0xFF);
    assert(hero.on_map == 0); // In prison = 0, but position is set!
}

void test_day2(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Spint");
    assert(hero.x == 14);
    assert(hero.y == 13);
    assert(hero.z ==  1);
    assert(hero.player == 0);
    assert(hero.on_map == 1);

    hero = save.findHero("Solmyr");
    assert(hero.x == 19);
    assert(hero.y == 13);
    assert(hero.z ==  1);
    assert(hero.player == 1);
    assert(hero.on_map == 1);

    // Sandro is released, same position, but now player and on_map is changed.
    hero = save.findHero("Sandro");
    assert(hero.x == 13);
    assert(hero.y == 13);
    assert(hero.z ==  1);
    assert(hero.player == 0); // Belongs to red player now.
    assert(hero.on_map == 1); // Is now on map.
}

int main()
{
    // Test data is copied relative to executable in output/binary dir.
    fs::path testDataDir("../test_data");
    fs::path dir(testDataDir / "prison");

    h3::savefile::SaveFile day1(dir / "[hotseat] 111.GM2");
    h3::savefile::SaveFile day2(dir / "[hotseat] 112.GM2");

    test_day1(day1);
    test_day2(day2);

    return 0;
}
