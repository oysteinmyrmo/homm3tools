#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::Orientation;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "movement_gigantic");
} // namespace

// - Orrin starts at [245,246,0], facing E.
// - Valeska starts at [249,250,0], facing E.
TEST_CASE("hero-movement-gigantic-start", "[hero][movement]")
{
    SaveFile save({testDataDir / "start.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 246);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::E);
    REQUIRE(orrin.movement_remaining == 1560);

    // Note: For some reason, Valeska's position was not saved at this point.
    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 0xFFFF);
    REQUIRE(valeska.y == 0xFFFF);
    REQUIRE(valeska.z == 0xFFFF);
    REQUIRE(valeska.orientation == Orientation::E);
    REQUIRE(valeska.movement_remaining == 1630);
}

// - Orrin moved to [245,247,0], facing S.
// - Valeska moved to [248,249,0], facing NW.
TEST_CASE("hero-movement-gigantic-day1", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 247); // Moved 1S
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::S);
    REQUIRE(orrin.movement_remaining == 1385);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 248); // Moved 1NW
    REQUIRE(valeska.y == 249); // Moved 1NW
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::NW);
    REQUIRE(valeska.movement_remaining == 1383);
}

// - Orrin sets target position to [241,248,0].
// - Valeska sets target position to [249,250,0].
TEST_CASE("hero-movement-gigantic-day2", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 247);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::S);
    REQUIRE(orrin.dest_x == 241);
    REQUIRE(orrin.dest_y == 248);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 248);
    REQUIRE(valeska.y == 249);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::NW);
    REQUIRE(valeska.dest_x == 249);
    REQUIRE(valeska.dest_y == 250);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1630);
}

// - Orrin now faces W
// - Valeska now faces SW
TEST_CASE("hero-movement-gigantic-day3", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 247);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::W);
    REQUIRE(orrin.dest_x == 241);
    REQUIRE(orrin.dest_y == 248);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1210);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 248);
    REQUIRE(valeska.y == 249);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::SW);
    REQUIRE(valeska.dest_x == 249);
    REQUIRE(valeska.dest_y == 250);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1136);
}

// - Orrin spent all his movement, except 160 movement points.
// - Valeska spent all her movement, except 539 movement points.
TEST_CASE("hero-movement-gigantic-day4", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 114.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 247);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::W);
    REQUIRE(orrin.dest_x == 241);
    REQUIRE(orrin.dest_y == 248);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 160);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 248);
    REQUIRE(valeska.y == 249);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::SW);
    REQUIRE(valeska.dest_x == 249);
    REQUIRE(valeska.dest_y == 250);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 539);
}

// - Orrin sets target to Valeska at [248,249,0].
// - Valeska sets target to Orrin at [245,247,0].
TEST_CASE("hero-movement-gigantic-day5", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 115.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 247);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::W);
    REQUIRE(orrin.dest_x == 248);
    REQUIRE(orrin.dest_y == 249);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 248);
    REQUIRE(valeska.y == 249);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::SW);
    REQUIRE(valeska.dest_x == 245);
    REQUIRE(valeska.dest_y == 247);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1630);
}

// - Orrin now faces N.
// - Valeska now faces SE.
TEST_CASE("hero-movement-gigantic-day6", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 116.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 247);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::N);
    REQUIRE(orrin.dest_x == 248);
    REQUIRE(orrin.dest_y == 249);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1210);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 248);
    REQUIRE(valeska.y == 249);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::SE);
    REQUIRE(valeska.dest_x == 245);
    REQUIRE(valeska.dest_y == 247);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1136);
}

// - Orrin now faces E.
// - OrrinPlayer loses because he has no town (Valeska cannot move).
TEST_CASE("hero-movement-gigantic-day7", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 117.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 245);
    REQUIRE(orrin.y == 247);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::E);
    REQUIRE(orrin.dest_x == 248);
    REQUIRE(orrin.dest_y == 249);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1210);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 248);
    REQUIRE(valeska.y == 249);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::SE);
    REQUIRE(valeska.dest_x == 245);
    REQUIRE(valeska.dest_y == 247);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1136);
}
