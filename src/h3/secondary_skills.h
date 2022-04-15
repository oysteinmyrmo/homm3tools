#pragma once

#include <array>
#include <cstdint>

namespace h3::secondary_skills
{
enum class Skill : uint8_t
{
    Pathfinding  =  0,
    Archery      =  1,
    Logistics    =  2,
    Scouting     =  3,
    Diplomacy    =  4,
    Navigation   =  5,
    Leadership   =  6,
    Wisdom       =  7,
    Mysticism    =  8,
    Luck         =  9,
    Ballistics   = 10,
    EagleEye     = 11,
    Necromancy   = 12,
    Estates      = 13,
    FireMagic    = 14,
    AirMagic     = 15,
    WaterMagic   = 16,
    EarthMagic   = 17,
    Scholar      = 18,
    Tactics      = 19,
    Artillery    = 20,
    Learning     = 21,
    Offense      = 22,
    Armorer      = 23,
    Intelligence = 24,
    Sorcery      = 25,
    Resistance   = 26, // Not used in HotA. (Not tested.)
    FirstAid     = 27,
    Interference = 28,
    COUNT        = 29, // Helper for Hero class.
    NONE         = 30, // Helper for Hero class.
};

constexpr uint8_t SkillCount = static_cast<uint8_t>(Skill::COUNT);

enum class SkillLevel : uint8_t
{
    None     = 0,
    Basic    = 1,
    Advanced = 2,
    Expert   = 3,
};

struct SkillSlot
{
    bool empty() const { return level == SkillLevel::None || skill == Skill::NONE; }
    bool operator==(const SkillSlot &other) const = default;

    Skill skill = Skill::NONE;
    SkillLevel level = SkillLevel::None;
};

constexpr uint8_t SkillSlotCount = 8;
using SkillSlots = std::array<SkillSlot, SkillSlotCount>;
} // namespace h3::secondary_skills

namespace h3
{
using Skill = secondary_skills::Skill;
using SkillLevel = secondary_skills::SkillLevel;
using SkillSlot = secondary_skills::SkillSlot;
using SkillSlots = secondary_skills::SkillSlots;
constexpr auto SkillCount = secondary_skills::SkillCount;
}
