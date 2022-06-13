#pragma once

#include "artifacts.h"
#include "creatures.h"
#include "packed_structs.h"
#include "secondary_skills.h"
#include "spells.h"
#include "stats.h"

#include <algorithm>
#include <array>
#include <cstdint>
#include <span>

namespace h3::hero
{
// Total hero count as per https://heroes.thelazy.net/index.php/List_of_heroes_(HotA)
// A save file always contains all heroes.
static constexpr size_t heroCount = 179;

using creatures::maxStacks;
using artifacts::ArtifactEntry;
using artifacts::ArtifactSlotCount;

enum class Orientation : uint8_t
{
    N  = 0,
    NE = 1,
    E  = 2,
    SE = 3,
    S  = 4,
    SW = 5,
    W  = 6,
    NW = 7
};

// See also http://heroescommunity.com/viewthread.php3?TID=18817&PID=1366926#focus
PACKED_STRUCT(
struct Hero
{
    static constexpr size_t offsetFromNameToStart() { return offsetof(Hero, name); }
    static constexpr uint8_t maxPrimarySkillValue = 99;

    uint64_t armyStrength() const { return stats::army_strength(*this); }
    bool garrison() const { return (on_map == 0) && (player < 8); } // TODO: Read h3::player::maxPlayers instead.
    bool prison() const { return (on_map == 0) && (player == 0xFF); } // TODO: Read h3::player::maxPlayers instead.

    bool hasSpell(const Spell spell) const { return spells::has_spell(*this, spell); };
    bool hasSpellInSpellBook(const Spell spell) const { return spells::has_spell_in_spellbook(*this, spell); };

    // In-game primary values are clamped. Note that these values can overflow in the save files.
    uint8_t attackInGame() const { return std::min(attack, maxPrimarySkillValue); }
    uint8_t defenseInGame() const { return std::min(defense, maxPrimarySkillValue); }
    uint8_t powerInGame() const { return std::min(power, maxPrimarySkillValue); }
    uint8_t knowledgeInGame() const { return std::min(knowledge, maxPrimarySkillValue); }

    SkillSlots skills() const;

    // Offsets are relative to name.
    uint16_t x = 0xFFFF;                    // -195
    uint16_t y = 0XFFFF;                    // -193
    uint16_t z = 0xFFFF;                    // -191
    uint8_t on_map = 0;                     // -189 (1 = on the map, 0 = town garrison or in prison. Position is set when in prison.)
    uint8_t _unused1[19];
    uint8_t player = 0xFF;                  // -169
    uint8_t _unused2[14];
    Orientation orientation;                // -154
    uint8_t _unused3[3];
    uint32_t dest_x = 0xFFFFFFFF;           // -151
    uint32_t dest_y = 0xFFFFFFFF;           // -147
    uint32_t dest_z = 0xFFFFFFFF;           // -143
    uint8_t _unused4[4];
    uint16_t movement_remaining = 0xFFFF;   // -134
    uint8_t _unused5[2];
    uint32_t experience = 0;                // -130
    uint32_t skill_count = 0;               // -126 (Number of secondary skills)
    uint16_t spell_points = 0;              // -122
    uint8_t level = 0;                      // -120
    uint8_t _unused6[63];
    Creature creatures[maxStacks];          // -56
    uint32_t creature_count[maxStacks];     // -28
    uint8_t name[13];                       // 0
    SkillLevel skillLevels[SkillCount];     // +13
    uint8_t _unused7[27];                   // +42
    uint8_t attack = 0;                     // +69
    uint8_t defense = 0;                    // +70
    uint8_t power = 0;                      // +71
    uint8_t knowledge = 0;                  // +72
    uint8_t spellbook[SpellCount];          // +73  (Spells written to spell book. Permanent spells. 1 means spell is written, otherwise 0.)
    uint8_t spells[SpellCount];             // +143 (All available spells, spell book and artifacts. 1 means spell is available, otherwise 0.)
    ArtifactEntry artifacts[ArtifactSlotCount]; // +213
    uint8_t _unused8[46];                   // +877
    uint8_t skillSlots[SkillCount];         // +923
});

template <class Callback>
void forEachArtifact(const Hero &hero, const Callback callback)
{
    for (const auto &entry : hero.artifacts)
    {
        if (!entry.empty())
        {
            const Artifact artifact = static_cast<Artifact>(entry.artifactId);
            const auto &details = h3::artifacts::artifactDetails.at(artifact);
            callback(artifact, details);
        }
    }
}

void readHero(const std::span<const char> data, size_t idx, Hero &hero);
void readAllHeroes(const std::span<const char> data, size_t idx, std::span<Hero> output);
} // namespace h3::hero

namespace h3
{
using Hero = hero::Hero;
using Orientation = hero::Orientation;
}
