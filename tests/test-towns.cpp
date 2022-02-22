#include <h3/creatures.h>
#include <h3/hero.h>
#include <h3/savefile.h>
#include <h3/stats.h>

#include <test_data.h>

#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::hero::Hero;
using h3::savefile::SaveFile;
}

void test_town_constants(const auto &towns)
{
    assert(towns.size() == 4);

    auto town = towns[0];
    assert(town.name == "RedsTown");
    assert(town.name.size() == town.nameSize);
    assert(town.x == 12);
    assert(town.y ==  7);
    assert(town.z ==  0);

    town = towns[1];
    assert(town.name == "BluesTown");
    assert(town.name.size() == town.nameSize);
    assert(town.x == 18);
    assert(town.y ==  7);
    assert(town.z ==  0);

    town = towns[2];
    assert(town.name == "BUUUUUUURN");
    assert(town.name.size() == town.nameSize);
    assert(town.x == 12);
    assert(town.y == 14);
    assert(town.z ==  0);

    town = towns[3];
    assert(town.name == "LOOKOUT");
    assert(town.name.size() == town.nameSize);
    assert(town.x == 18);
    assert(town.y == 14);
    assert(town.z ==  0);
}

void test_day1(const SaveFile &save)
{
    assert(save.valid());
    test_town_constants(save.towns);
}

void test_day2(const SaveFile &save)
{
    assert(save.valid());
    test_town_constants(save.towns);
}

void test_day3(const SaveFile &save)
{
    assert(save.valid());
    test_town_constants(save.towns);
}

void test_day4(const SaveFile &save)
{
    assert(save.valid());
    test_town_constants(save.towns);
}

void test_day5(const SaveFile &save)
{
    assert(save.valid());
    test_town_constants(save.towns);
}

int main()
{
    fs::path dir(h3::test::testDataDir / "towns");

    h3::savefile::SaveFile day1({dir / "[hotseat] 111.GM2", "RedsTown", 4});
    h3::savefile::SaveFile day2({dir / "[hotseat] 112.GM2", "RedsTown", 4});
    h3::savefile::SaveFile day3({dir / "[hotseat] 113.GM2", "RedsTown", 4});
    h3::savefile::SaveFile day4({dir / "[hotseat] 114.GM2", "RedsTown", 4});
    h3::savefile::SaveFile day5({dir / "[hotseat] 115.GM2", "RedsTown", 4});

    test_day1(day1);
    test_day2(day2);
    test_day3(day3);
    test_day4(day4);
    test_day5(day5);

    return 0;
}
