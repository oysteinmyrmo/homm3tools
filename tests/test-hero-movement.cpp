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

std::filesystem::path testDataDir(h3::test::testDataDir / "movement");
} // namespace

// - Orrin starts at [2,2,0], facing E.
// - Valeska starts at [2,4,0], facing E.
TEST_CASE("hero-movement-start", "[hero][movement]")
{
    SaveFile save({testDataDir / "start.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 2);
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::E);
    REQUIRE(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 2);
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::E);
    REQUIRE(valeska.movement_remaining == 1630);
}

// - Orrin moved to [3,2,0], facing E.
// - Valeska moved to [1,4,0], facing W.
TEST_CASE("hero-movement-day1", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 3); // Moved 1E
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::E);
    REQUIRE(orrin.movement_remaining == 1460);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 1); // Moved 1W
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::W);
    REQUIRE(valeska.movement_remaining == 1530);
}

// - Orrin sets destination to [5,4,0].
// - Valeska sets destination to [2,3,0].
TEST_CASE("hero-movement-day2", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 3);
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::E);
    REQUIRE(orrin.dest_x == 5);
    REQUIRE(orrin.dest_y == 4);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 1);
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::W);
    REQUIRE(valeska.dest_x == 2);
    REQUIRE(valeska.dest_y == 3);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1630);
}

// - Orrin sets destination to [5,0,0], facing NW.
// - Valeska sets destination to [0,1,0], facing S.
TEST_CASE("hero-movement-day3", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 3);
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::NW);
    REQUIRE(orrin.dest_x == 5);
    REQUIRE(orrin.dest_y == 0);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1078);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 1);
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::S);
    REQUIRE(valeska.dest_x == 0);
    REQUIRE(valeska.dest_y == 1);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1430);
}

// - Orrin spent all his movement, except 150 movement points.
// - Valeska spent all her movement, except 630 movement points.
TEST_CASE("hero-movement-day4", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 114.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 3);
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::NW);
    REQUIRE(orrin.dest_x == 5);
    REQUIRE(orrin.dest_y == 0);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 150);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 1);
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::S);
    REQUIRE(valeska.dest_x == 0);
    REQUIRE(valeska.dest_y == 1);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 630);
}

// - Orrin sets target to Valeska at [1,4,0].
// - Valeska sets target to Orrin at [3,2,0].
TEST_CASE("hero-movement-day5", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 115.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 3);
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::NW);
    REQUIRE(orrin.dest_x == 1);
    REQUIRE(orrin.dest_y == 4);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1560);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 1);
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::S);
    REQUIRE(valeska.dest_x == 3);
    REQUIRE(valeska.dest_y == 2);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1630);
}

// - Orrin now faces N.
// - Valeska now faces SE.
TEST_CASE("hero-movement-day6", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 116.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 3);
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::N);
    REQUIRE(orrin.dest_x == 1);
    REQUIRE(orrin.dest_y == 4);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1360);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 1);
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::SE);
    REQUIRE(valeska.dest_x == 3);
    REQUIRE(valeska.dest_y == 2);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1348);
}

// - Orrin now faces SW.
// - OrrinPlayer loses because he has no town (Valeska cannot move).
TEST_CASE("hero-movement-day7", "[hero][movement]")
{
    SaveFile save({testDataDir / "[hotseat] 117.GM2"});
    REQUIRE(save.valid());

    const Hero &orrin = save.heroes[0];
    REQUIRE(orrin.x == 3);
    REQUIRE(orrin.y == 2);
    REQUIRE(orrin.z == 0);
    REQUIRE(orrin.orientation == Orientation::SW);
    REQUIRE(orrin.dest_x == 1);
    REQUIRE(orrin.dest_y == 4);
    REQUIRE(orrin.dest_z == 0);
    REQUIRE(orrin.movement_remaining == 1219);

    const Hero &valeska = save.heroes[1];
    REQUIRE(valeska.x == 1);
    REQUIRE(valeska.y == 4);
    REQUIRE(valeska.z == 0);
    REQUIRE(valeska.orientation == Orientation::SE);
    REQUIRE(valeska.dest_x == 3);
    REQUIRE(valeska.dest_y == 2);
    REQUIRE(valeska.dest_z == 0);
    REQUIRE(valeska.movement_remaining == 1348);
}
