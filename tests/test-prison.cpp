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
    fs::path dir(h3::test::testDataDir / "prison");

    h3::SaveFile day1({dir / "[hotseat] 111.GM2"});
    h3::SaveFile day2({dir / "[hotseat] 112.GM2"});

    test_day1(day1);
    test_day2(day2);

    return 0;
}
