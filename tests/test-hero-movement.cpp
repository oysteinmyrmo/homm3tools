#include <h3/hero.h>
#include <h3/savefile.h>

#include <test_data.h>

#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::hero::Hero;
using h3::hero::Orientation;
using h3::savefile::SaveFile;
}

// - Orrin starts at [2,2,0], facing E.
// - Valeska starts at [2,4,0], facing E.
void test_start(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 2);
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::E);
    assert(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 2);
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::E);
    assert(valeska.movement_remaining == 1630);
}

// - Orrin moved to [3,2,0], facing E.
// - Valeska moved to [1,4,0], facing W.
void test_day1(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 3); // Moved 1E
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::E);
    assert(orrin.movement_remaining == 1460);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 1); // Moved 1W
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::W);
    assert(valeska.movement_remaining == 1530);
}

// - Orrin sets destination to [5,4,0].
// - Valeska sets destination to [2,3,0].
void test_day2(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 3);
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::E);
    assert(orrin.dest_x == 5);
    assert(orrin.dest_y == 4);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 1);
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::W);
    assert(valeska.dest_x == 2);
    assert(valeska.dest_y == 3);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1630);
}

// - Orrin sets destination to [5,0,0], facing NW.
// - Valeska sets destination to [0,1,0], facing S.
void test_day3(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 3);
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::NW);
    assert(orrin.dest_x == 5);
    assert(orrin.dest_y == 0);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1078);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 1);
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::S);
    assert(valeska.dest_x == 0);
    assert(valeska.dest_y == 1);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1430);
}

// TODO: Movement points are not read into Hero struct!
// - Orrin spent all his movement, except 150 movement points.
// - Valeska spent all her movement, except 630 movement points.
void test_day4(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 3);
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::NW);
    assert(orrin.dest_x == 5);
    assert(orrin.dest_y == 0);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 150);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 1);
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::S);
    assert(valeska.dest_x == 0);
    assert(valeska.dest_y == 1);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 630);
}

// - Orrin sets target to Valeska at [1,4,0].
// - Valeska sets target to Orrin at [3,2,0].
void test_day5(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 3);
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::NW);
    assert(orrin.dest_x == 1);
    assert(orrin.dest_y == 4);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 1);
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::S);
    assert(valeska.dest_x == 3);
    assert(valeska.dest_y == 2);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1630);
}

// - Orrin now faces N.
// - Valeska now faces SE.
void test_day6(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 3);
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::N);
    assert(orrin.dest_x == 1);
    assert(orrin.dest_y == 4);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1360);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 1);
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::SE);
    assert(valeska.dest_x == 3);
    assert(valeska.dest_y == 2);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1348);
}

// - Orrin now faces SW.
// - OrrinPlayer loses because he has no town (Valeska cannot move).
void test_day7(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 3);
    assert(orrin.y == 2);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::SW);
    assert(orrin.dest_x == 1);
    assert(orrin.dest_y == 4);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1219);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 1);
    assert(valeska.y == 4);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::SE);
    assert(valeska.dest_x == 3);
    assert(valeska.dest_y == 2);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1348);
}

int main()
{
    fs::path dir(h3::test::testDataDir / "movement");

    h3::savefile::SaveFile start({dir / "start.GM2"});
    h3::savefile::SaveFile day1({dir / "[hotseat] 111.GM2"});
    h3::savefile::SaveFile day2({dir / "[hotseat] 112.GM2"});
    h3::savefile::SaveFile day3({dir / "[hotseat] 113.GM2"});
    h3::savefile::SaveFile day4({dir / "[hotseat] 114.GM2"});
    h3::savefile::SaveFile day5({dir / "[hotseat] 115.GM2"});
    h3::savefile::SaveFile day6({dir / "[hotseat] 116.GM2"});
    h3::savefile::SaveFile day7({dir / "[hotseat] 117.GM2"});

    test_start(start);
    test_day1(day1);
    test_day2(day2);
    test_day3(day3);
    test_day4(day4);
    test_day5(day5);
    test_day6(day6);
    test_day7(day7);

    return 0;
}
