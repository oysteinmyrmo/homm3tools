#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <algorithm>
#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;
using h3::Town;

bool townExists(const SaveFile &save, const std::string townName)
{
    return std::any_of(save.towns.begin(), save.towns.end(), [&townName](const Town &town)
    {
        return town.name == townName;
    });
}

std::filesystem::path testDataDir(h3::test::testDataDir / "town_names");
} // namespace

// All Castle, Rampart and Towner town names should be present once each.
TEST_CASE("towns-names-castle-rampart-tower", "[hero][town]")
{
    h3::SaveFile save({testDataDir / "01" / "[hotseat] 111.GM3"});
    REQUIRE(save.valid());

    // Castle
    for (int i = 0; i <= 15; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }

    // Rampart
    for (int i = 16; i <= 31; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }

    // Tower
    for (int i = 32; i <= 47; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }
}

// All Inferno, Necropolis and Dungeon town names should be present once each.
TEST_CASE("towns-names-inferno-necro-dungeon", "[hero][town]")
{
    h3::SaveFile save({testDataDir / "02" / "[hotseat] 111.GM3"});
    REQUIRE(save.valid());

    // Inferno
    for (int i = 48; i <= 63; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }

    // Necro
    for (int i = 64; i <= 79; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }

    // Dungeon
    for (int i = 80; i <= 95; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }
}

// All Stronghold and Fortress town names should be present once each.
TEST_CASE("towns-names-stronghold-fortress", "[hero][town]")
{
    h3::SaveFile save({testDataDir / "03" / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    // Stronghold
    for (int i = 96; i <= 111; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }

    // Fortress
    for (int i = 112; i <= 127; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }
}

// All Conflux and Cove town names should be present once each.
TEST_CASE("towns-names-conflux-cove", "[hero][town]")
{
    h3::SaveFile save({testDataDir / "04" / "[hotseat] 111.GM2"});
    REQUIRE(save.valid());

    // Conflux
    for (int i = 128; i <= 143; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }

    // Cove
    for (int i = 144; i <= 159; ++i)
    {
        REQUIRE(townExists(save, h3::town::townNames[i]));
    }
}
