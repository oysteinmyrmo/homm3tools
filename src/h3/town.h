#pragma once

#include "creatures.h"
#include "packed_structs.h"
#include "stats.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <vector>

namespace h3::town
{
using creatures::maxStacks;

// Note: The size of the Town struct in the save file is variable due to the size
// of the name being variable. sizeof(Town) is therefore 545 + name.size().
PACKED_STRUCT(
struct Town
{
    static constexpr size_t offsetFromNameToStart() { return offsetof(Town, name); }
    static constexpr size_t sizeOfWithoutName() { return 546; }
    static constexpr uint8_t noOwner = 0xFF;

    size_t sizeOfWithName() const { return sizeOfWithoutName() + name.size(); }
    uint64_t armyStrength() const { return stats::army_strength(*this); }

    uint8_t owner;                          // -71
    uint8_t _unused0[3];
    uint8_t x;                              // -67
    uint8_t y;                              // -66
    uint8_t z;                              // -65
    uint8_t _unused1[2];
    Creature creatures[maxStacks];          // -62
    uint32_t creature_count[maxStacks];     // -34
    uint8_t _unused2[4];
    uint16_t nameSize;                      // -2  <-- Note: The town name is of variable size.
    std::string name;                       // 0
    // Remaining bytes intentionally left out.
});

// Taken from http://heroes.thelazy.net/index.php/List_of_all_town_names
constexpr std::array townNames{

    // Castle
    "Alexandretta",
    "Armitage",
    "Brettonia",
    "Castellatus",
    "Claxton",
    "Cornerstone",
    "Dunwall",
    "Gateway",
    "Highcastle",
    "Kanan",
    "Kildare",
    "Middleheim",
    "Transom",
    "Whistledale",
    "Whitemoon",
    "Whitestone",

    // Rampart
    "Bath'iere",
    "Ceiliedgh",
    "Elfwind",
    "Emerald Moor",
    "Forest",
    "Forest Glen",
    "Fortune Keep",
    "Green Falls",
    "Gladeroot",
    "Marishen",
    "Rainhaven",
    "Serenity",
    "Still Water",
    "Strongglen",
    "Wild Willow",
    "Wise Oak",

    // Tower
    "Athenaeum",
    "Ayer",
    "Cloudfire",
    "Cloudspire",
    "Corona",
    "Equinox",
    "Facture",
    "Fallen Star",
    "Machina",
    "Manufactury",
    "Mystos",
    "Silverspire",
    "Silverwing",
    "Stronggale",
    "Tirith",
    "Valtara",

    // Inferno
    "Abaddon",
    "Acheron",
    "Ashcombe",
    "Ashden",
    "Blackburn",
    "Brimstone",
    "Candent",
    "Cinderspire",
    "Daemon Gate",
    "Enkindle",
    "Firebrand",
    "Gehenna",
    "Hellwind",
    "Stygius",
    "Styx",
    "Tartaros",

    // Necropolis
    "Agony",
    "Blackquarter",
    "Blight",
    "Cessacioun",
    "Coldreign",
    "Coldsoul",
    "Dark Cloud",
    "Dark Eternal",
    "Death's Gate",
    "Ghostwind",
    "Grave Raven",
    "Haunt's Wind",
    "Sanctum",
    "Shadow Keep",
    "Terminus",
    "Worm Warren",

    // Dungeon
    "Blindroot",
    "Castigare",
    "Chillwater",
    "Coldshadow",
    "Darkburrow",
    "Darkhold",
    "Deepshadow",
    "Dragonnade",
    "Evernight",
    "Lost Hold",
    "Malev",
    "Scar",
    "Shade",
    "Shadowden",
    "Sorrow Crown",
    "Veks",

    // Stronghold
    "Battlement",
    "Bocc",
    "Cragmoor",
    "Dolere",
    "Drago Breach",
    "Dragonspire",
    "Hartgrim",
    "Kragg",
    "Kruber",
    "Morganheim",
    "Rockwarren",
    "Rovener",
    "Sandflash",
    "Slau",
    "Strongglen",
    "Tormina",

    // Fortress
    "Backwater",
    "Coolmire",
    "Deadfall",
    "Deadwood",
    "Drakenmoor",
    "Edgewater",
    "Hermit Cove",
    "Lostmoor",
    "Marshank",
    "Marshchoke",
    "Marshwall",
    "Mossden",
    "Mosswood",
    "Mudshire",
    "Silt",
    "Stillbog",

    // Conflux
    "Ceald",
    "Electrising",
    "Elementon",
    "Fenderen",
    "Fleogan Mills",
    "Froisan",
    "Igne",
    "Lagumoor",
    "Lanting",
    "Magmetin",
    "Massein",
    "Solium",
    "Styriam",
    "Ventu",
    "Vluchton",
    "Wazzar",

    // Cove
    "Brown's Bay",
    "Downhaven",
    "Hitchgrove",
    "Jordanhall",
    "Lakenshire",
    "Lewindale",
    "Nithenes",
    "Noral",
    "Port Crowland",
    "Port Evendore",
    "Rotunda",
    "Sleepy Creek",
    "Tartaglia",
    "Walendale",
    "Watergate",
    "Westland Pier",
};

void readTown(const std::span<const char> data, size_t idx, Town &hero);
void readAllTowns(const std::span<const char> data, size_t idx, size_t count, std::vector<Town> &towns);

// Fleogan Mills is 13 characters long.
constexpr size_t longestTownName() { return 13; }
} // namespace h3::town

namespace h3
{
using Town = town::Town;
}
