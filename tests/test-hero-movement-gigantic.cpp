#include <h3/hero.h>
#include <h3/savefile.h>

#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::hero::Hero;
using h3::hero::Orientation;
using h3::savefile::SaveFile;
}

// - Orrin starts at [245,246,0], facing E.
// - Valeska starts at [249,250,0], facing E.
void test_start(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 246);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::E);
    assert(orrin.movement_remaining == 1560);

    // Note: For some reason, Valeska's position was not saved at this point.
    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 0xFFFF);
    assert(valeska.y == 0xFFFF);
    assert(valeska.z == 0xFFFF);
    assert(valeska.orientation == Orientation::E);
    assert(valeska.movement_remaining == 1630);
}

// - Orrin moved to [245,247,0], facing S.
// - Valeska moved to [248,249,0], facing NW.
void test_day1(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 247); // Moved 1S
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::S);
    assert(orrin.movement_remaining == 1385);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 248); // Moved 1NW
    assert(valeska.y == 249); // Moved 1NW
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::NW);
    assert(valeska.movement_remaining == 1383);
}

// - Orrin sets target position to [241,248,0].
// - Valeska sets target position to [249,250,0].
void test_day2(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 247);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::S);
    assert(orrin.dest_x == 241);
    assert(orrin.dest_y == 248);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 248);
    assert(valeska.y == 249);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::NW);
    assert(valeska.dest_x == 249);
    assert(valeska.dest_y == 250);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1630);
}

// - Orrin now faces W
// - Valeska now faces SW
void test_day3(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 247);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::W);
    assert(orrin.dest_x == 241);
    assert(orrin.dest_y == 248);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1210);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 248);
    assert(valeska.y == 249);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::SW);
    assert(valeska.dest_x == 249);
    assert(valeska.dest_y == 250);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1136);
}

// - Orrin spent all his movement, except 160 movement points.
// - Valeska spent all her movement, except 539 movement points.
void test_day4(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 247);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::W);
    assert(orrin.dest_x == 241);
    assert(orrin.dest_y == 248);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 160);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 248);
    assert(valeska.y == 249);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::SW);
    assert(valeska.dest_x == 249);
    assert(valeska.dest_y == 250);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 539);
}

// - Orrin sets target to Valeska at [248,249,0].
// - Valeska sets target to Orrin at [245,247,0].
void test_day5(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 247);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::W);
    assert(orrin.dest_x == 248);
    assert(orrin.dest_y == 249);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 248);
    assert(valeska.y == 249);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::SW);
    assert(valeska.dest_x == 245);
    assert(valeska.dest_y == 247);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1630);
}

// - Orrin now faces N.
// - Valeska now faces SE.
void test_day6(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 247);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::N);
    assert(orrin.dest_x == 248);
    assert(orrin.dest_y == 249);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1210);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 248);
    assert(valeska.y == 249);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::SE);
    assert(valeska.dest_x == 245);
    assert(valeska.dest_y == 247);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1136);
}

// - Orrin now faces E.
// - OrrinPlayer loses because he has no town (Valeska cannot move).
void test_day7(const SaveFile &save)
{
    assert(save.valid());

    const Hero &orrin = save.heroes[0];
    assert(orrin.x == 245);
    assert(orrin.y == 247);
    assert(orrin.z == 0);
    assert(orrin.orientation == Orientation::E);
    assert(orrin.dest_x == 248);
    assert(orrin.dest_y == 249);
    assert(orrin.dest_z == 0);
    assert(orrin.movement_remaining == 1210);

    const Hero &valeska = save.heroes[1];
    assert(valeska.x == 248);
    assert(valeska.y == 249);
    assert(valeska.z == 0);
    assert(valeska.orientation == Orientation::SE);
    assert(valeska.dest_x == 245);
    assert(valeska.dest_y == 247);
    assert(valeska.dest_z == 0);
    assert(valeska.movement_remaining == 1136);
}

int main()
{
    // Test data is copied relative to executable in output/binary dir.
    fs::path testDataDir("../test_data");
    fs::path dir(testDataDir / "movement_gigantic");

    h3::savefile::SaveFile start(dir / "start.GM2");
    h3::savefile::SaveFile day1(dir / "[hotseat] 111.GM2");
    h3::savefile::SaveFile day2(dir / "[hotseat] 112.GM2");
    h3::savefile::SaveFile day3(dir / "[hotseat] 113.GM2");
    h3::savefile::SaveFile day4(dir / "[hotseat] 114.GM2");
    h3::savefile::SaveFile day5(dir / "[hotseat] 115.GM2");
    h3::savefile::SaveFile day6(dir / "[hotseat] 116.GM2");
    h3::savefile::SaveFile day7(dir / "[hotseat] 117.GM2");

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
