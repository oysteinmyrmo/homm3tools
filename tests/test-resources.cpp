#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/savefile.h>
#include <h3/player.h>

#include <filesystem>

namespace
{
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "resources");
} // namespace

TEST_CASE("resources-day1", "[player][resources]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM8"});
    const auto players = h3::player::players(save);

    {
        // Red
        const auto &player = players[0];
        const auto &playerData = save.players[0];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    5);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 2500);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    5);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 2500);
    }

    {
        // Blue
        const auto &player = players[1];
        const auto &playerData = save.players[1];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    0);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 3400);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    0);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 3400);
    }

    {
        // Tan
        const auto &player = players[2];
        const auto &playerData = save.players[2];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    5);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 2500);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    5);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 2500);
    }

    {
        // Green
        const auto &player = players[3];
        const auto &playerData = save.players[3];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    0);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 3400);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    0);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 3400);
    }

    {
        // Orange
        const auto &player = players[4];
        const auto &playerData = save.players[4];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    3);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 2500);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    3);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 2500);
    }

    {
        // Purple
        const auto &player = players[5];
        const auto &playerData = save.players[5];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    0);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 3300);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    0);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 3300);
    }

    {
        // Teal
        const auto &player = players[6];
        const auto &playerData = save.players[6];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    6);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 2500);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    6);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 2500);
    }

    {
        // Pink
        const auto &player = players[7];
        const auto &playerData = save.players[7];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    0);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 3500);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    0);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 3500);
    }
}

TEST_CASE("resources-day2", "[player][resources]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM8"});
    const auto players = h3::player::players(save);

    {
        // Red
        const auto &player = players[0];
        const auto &playerData = save.players[0];

        REQUIRE(player.wood()      ==   15);
        REQUIRE(player.mercury()   ==   17);
        REQUIRE(player.ore()       ==   16);
        REQUIRE(player.sulfur()    ==    5);
        REQUIRE(player.crystal()   ==    5);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 6700);

        REQUIRE(playerData.wood    ==   15);
        REQUIRE(playerData.mercury ==   17);
        REQUIRE(playerData.ore     ==   16);
        REQUIRE(playerData.sulfur  ==    5);
        REQUIRE(playerData.crystal ==    5);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 6700);
    }

    {
        // Blue
        const auto &player = players[1];
        const auto &playerData = save.players[1];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==   12);
        REQUIRE(player.ore()       ==   23);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    8);
        REQUIRE(player.gems()      ==   11);
        REQUIRE(player.gold()      == 6700);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==   12);
        REQUIRE(playerData.ore     ==   23);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    8);
        REQUIRE(playerData.gems    ==   11);
        REQUIRE(playerData.gold    == 6700);
    }

    {
        // Tan
        const auto &player = players[2];
        const auto &playerData = save.players[2];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    5);
        REQUIRE(player.ore()       ==   15);
        REQUIRE(player.sulfur()    ==   18);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 3100);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    5);
        REQUIRE(playerData.ore     ==   15);
        REQUIRE(playerData.sulfur  ==   18);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 3100);
    }

    {
        // Green
        const auto &player = players[3];
        const auto &playerData = save.players[3];

        REQUIRE(player.wood()      ==    5);
        REQUIRE(player.mercury()   ==   10);
        REQUIRE(player.ore()       ==   10);
        REQUIRE(player.sulfur()    ==   14);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 6800);

        REQUIRE(playerData.wood    ==    5);
        REQUIRE(playerData.mercury ==   10);
        REQUIRE(playerData.ore     ==   10);
        REQUIRE(playerData.sulfur  ==   14);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 6800);
    }

    {
        // Orange
        const auto &player = players[4];
        const auto &playerData = save.players[4];

        REQUIRE(player.wood()      ==    5);
        REQUIRE(player.mercury()   ==    3);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   12);
        REQUIRE(player.gold()      == 7250);

        REQUIRE(playerData.wood    ==    5);
        REQUIRE(playerData.mercury ==    3);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   12);
        REQUIRE(playerData.gold    == 7250);
    }

    {
        // Purple
        const auto &player = players[5];
        const auto &playerData = save.players[5];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    0);
        REQUIRE(player.ore()       ==   20);
        REQUIRE(player.sulfur()    ==    5);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   10);
        REQUIRE(player.gold()      == 6900);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    0);
        REQUIRE(playerData.ore     ==   20);
        REQUIRE(playerData.sulfur  ==    5);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   10);
        REQUIRE(playerData.gold    == 6900);
    }

    {
        // Teal
        const auto &player = players[6];
        const auto &playerData = save.players[6];

        REQUIRE(player.wood()      ==    6);
        REQUIRE(player.mercury()   ==    6);
        REQUIRE(player.ore()       ==   11);
        REQUIRE(player.sulfur()    ==    4);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   10);
        REQUIRE(player.gold()      == 5950);

        REQUIRE(playerData.wood    ==    6);
        REQUIRE(playerData.mercury ==    6);
        REQUIRE(playerData.ore     ==   11);
        REQUIRE(playerData.sulfur  ==    4);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   10);
        REQUIRE(playerData.gold    == 5950);
    }

    {
        // Pink
        const auto &player = players[7];
        const auto &playerData = save.players[7];

        REQUIRE(player.wood()      ==    6);
        REQUIRE(player.mercury()   ==    6);
        REQUIRE(player.ore()       ==   11);
        REQUIRE(player.sulfur()    ==   17);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   10);
        REQUIRE(player.gold()      == 5000);

        REQUIRE(playerData.wood    ==    6);
        REQUIRE(playerData.mercury ==    6);
        REQUIRE(playerData.ore     ==   11);
        REQUIRE(playerData.sulfur  ==   17);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   10);
        REQUIRE(playerData.gold    == 5000);
    }
}

TEST_CASE("resources-day3", "[player][resources]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM8"});
    const auto players = h3::player::players(save);

    {
        // Red
        const auto &player = players[0];
        const auto &playerData = save.players[0];

        REQUIRE(player.wood()      ==    19);
        REQUIRE(player.mercury()   ==    32);
        REQUIRE(player.ore()       ==    21);
        REQUIRE(player.sulfur()    ==     5);
        REQUIRE(player.crystal()   ==    21);
        REQUIRE(player.gems()      ==     0);
        REQUIRE(player.gold()      == 10700);

        REQUIRE(playerData.wood    ==    19);
        REQUIRE(playerData.mercury ==    32);
        REQUIRE(playerData.ore     ==    21);
        REQUIRE(playerData.sulfur  ==     5);
        REQUIRE(playerData.crystal ==    21);
        REQUIRE(playerData.gems    ==     0);
        REQUIRE(playerData.gold    == 10700);
    }

    {
        // Blue is vanquished, resource data remains fixed in the save file.
        const auto &player = players[1];
        const auto &playerData = save.players[1];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==   12);
        REQUIRE(player.ore()       ==   23);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    8);
        REQUIRE(player.gems()      ==   11);
        REQUIRE(player.gold()      == 6700);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==   12);
        REQUIRE(playerData.ore     ==   23);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    8);
        REQUIRE(playerData.gems    ==   11);
        REQUIRE(playerData.gold    == 6700);
    }

    {
        // Tan is vanquished, resource data remains fixed in the save file.
        const auto &player = players[2];
        const auto &playerData = save.players[2];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    5);
        REQUIRE(player.ore()       ==   21); // Picked up some ore before vanquished.
        REQUIRE(player.sulfur()    ==   18);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 3700); // Picked up some gold before vanquished.

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    5);
        REQUIRE(playerData.ore     ==   21); // Picked up some ore before vanquished.
        REQUIRE(playerData.sulfur  ==   18);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 3700); // Picked up some gold before vanquished.
    }

    {
        // Green
        const auto &player = players[3];
        const auto &playerData = save.players[3];

        REQUIRE(player.wood()      ==    5);
        REQUIRE(player.mercury()   ==   10);
        REQUIRE(player.ore()       ==   10);
        REQUIRE(player.sulfur()    ==   14);
        REQUIRE(player.crystal()   ==    0);
        REQUIRE(player.gems()      ==    0);
        REQUIRE(player.gold()      == 6800);

        REQUIRE(playerData.wood    ==    5);
        REQUIRE(playerData.mercury ==   10);
        REQUIRE(playerData.ore     ==   10);
        REQUIRE(playerData.sulfur  ==   14);
        REQUIRE(playerData.crystal ==    0);
        REQUIRE(playerData.gems    ==    0);
        REQUIRE(playerData.gold    == 6800);
    }

    {
        // Orange is vanquished, resource data remains fixed in the save file.
        const auto &player = players[4];
        const auto &playerData = save.players[4];

        REQUIRE(player.wood()      ==    5);
        REQUIRE(player.mercury()   ==    3);
        REQUIRE(player.ore()       ==    5);
        REQUIRE(player.sulfur()    ==    0);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   12);
        REQUIRE(player.gold()      == 7500); // Basic estates (Erdamon) increased gold by 250.

        REQUIRE(playerData.wood    ==    5);
        REQUIRE(playerData.mercury ==    3);
        REQUIRE(playerData.ore     ==    5);
        REQUIRE(playerData.sulfur  ==    0);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   12);
        REQUIRE(playerData.gold    == 7500);; // Basic estates (Erdamon) increased gold by 250.
    }

    {
        // Purple
        const auto &player = players[5];
        const auto &playerData = save.players[5];

        REQUIRE(player.wood()      ==    0);
        REQUIRE(player.mercury()   ==    0);
        REQUIRE(player.ore()       ==   20);
        REQUIRE(player.sulfur()    ==    5);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   10);
        REQUIRE(player.gold()      == 6900);

        REQUIRE(playerData.wood    ==    0);
        REQUIRE(playerData.mercury ==    0);
        REQUIRE(playerData.ore     ==   20);
        REQUIRE(playerData.sulfur  ==    5);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   10);
        REQUIRE(playerData.gold    == 6900);
    }

    {
        // Teal
        const auto &player = players[6];
        const auto &playerData = save.players[6];

        REQUIRE(player.wood()      ==    6);
        REQUIRE(player.mercury()   ==    6);
        REQUIRE(player.ore()       ==   11);
        REQUIRE(player.sulfur()    ==    4);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   10);
        REQUIRE(player.gold()      == 6200); // Basic estates (Thunar) increased gold by 250.

        REQUIRE(playerData.wood    ==    6);
        REQUIRE(playerData.mercury ==    6);
        REQUIRE(playerData.ore     ==   11);
        REQUIRE(playerData.sulfur  ==    4);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   10);
        REQUIRE(playerData.gold    == 6200); // Basic estates (Thunar) increased gold by 250.
    }

    {
        // Pink
        const auto &player = players[7];
        const auto &playerData = save.players[7];

        REQUIRE(player.wood()      ==    6);
        REQUIRE(player.mercury()   ==    6);
        REQUIRE(player.ore()       ==   11);
        REQUIRE(player.sulfur()    ==   17);
        REQUIRE(player.crystal()   ==    6);
        REQUIRE(player.gems()      ==   10);
        REQUIRE(player.gold()      == 5000);

        REQUIRE(playerData.wood    ==    6);
        REQUIRE(playerData.mercury ==    6);
        REQUIRE(playerData.ore     ==   11);
        REQUIRE(playerData.sulfur  ==   17);
        REQUIRE(playerData.crystal ==    6);
        REQUIRE(playerData.gems    ==   10);
        REQUIRE(playerData.gold    == 5000);
    }
}
