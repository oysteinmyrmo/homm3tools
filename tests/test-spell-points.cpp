#include <h3/creatures.h>
#include <h3/hero.h>
#include <h3/savefile.h>

#include <test_data.h>

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

    Hero hero = save.findHero("Sephinroth");
    assert(hero.spell_points == 360);

    hero = save.findHero("Sorsha");
    assert(hero.spell_points == 10);
}

void test_day2(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Sephinroth");
    assert(hero.spell_points == 344);

    hero = save.findHero("Sorsha");
    assert(hero.spell_points == 4);
}

int main()
{
    fs::path dir(h3::test::testDataDir / "spell_points");

    h3::savefile::SaveFile day1({dir / "[hotseat] 111.GM2"});
    h3::savefile::SaveFile day2({dir / "[hotseat] 112.GM2"});

    test_day1(day1);
    test_day2(day2);

    return 0;
}
