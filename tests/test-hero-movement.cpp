#include <h3/hero.h>
#include <h3/savefile.h>

#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;
using h3::savefile::SaveFile;
}

// Orrin moved from [2,2,0] to [3,2,0] (1E).
// Valeska moved from [2,4,0] to [1,4,0] (1W).
void test_day1(const SaveFile &start, const SaveFile &day1)
{
    const auto *orrin = &start.heroes[0];
    assert(orrin->x == 2);
    assert(orrin->y == 2);
    assert(orrin->z == 0);

    const auto *valeska = &start.heroes[1];
    assert(valeska->x == 2);
    assert(valeska->y == 4);
    assert(valeska->z == 0);

    orrin = &day1.heroes[0];
    assert(orrin->x == 3); // Moved 1E
    assert(orrin->y == 2);
    assert(orrin->z == 0);

    valeska = &day1.heroes[1];
    assert(valeska->x == 1); // Moved 1W
    assert(valeska->y == 4);
    assert(valeska->z == 0);
}

int main()
{
    // Test data is copied relative to executable in output/binary dir.
    fs::path testDataDir("../test_data");
    fs::path movementDir(testDataDir / "movement");

    h3::savefile::SaveFile start(movementDir / "start.GM2");
    h3::savefile::SaveFile day1(movementDir / "[hotseat] 111.GM2");
    h3::savefile::SaveFile day2(movementDir / "[hotseat] 112.GM2");
    h3::savefile::SaveFile day3(movementDir / "[hotseat] 113.GM2");
    h3::savefile::SaveFile day4(movementDir / "[hotseat] 114.GM2");
    h3::savefile::SaveFile day5(movementDir / "[hotseat] 115.GM2");
    h3::savefile::SaveFile day6(movementDir / "[hotseat] 116.GM2");
    h3::savefile::SaveFile day7(movementDir / "[hotseat] 117.GM2");

    assert(start.valid());
    assert(day1.valid());
    assert(day2.valid());
    assert(day3.valid());
    assert(day4.valid());
    assert(day5.valid());
    assert(day6.valid());
    assert(day7.valid());

    test_day1(start, day1);

    return 0;
}
