#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;
using h3::SkillSlots;
using h3::Skill;
using h3::SkillLevel;
using h3::SkillSlot;

std::filesystem::path testDataDir(h3::test::testDataDir / "secondary_skills");

void testSkills(const Hero &hero, const SkillSlots &required)
{
    const auto skills = hero.skills();
    for (uint8_t i = 0; i < skills.size(); ++i)
    {
        REQUIRE(skills[i] == required[i]);
    }
}
} // namespace

TEST_CASE("secondary-skills-day1", "[hero][secondary-skills]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM5"});
    REQUIRE(save.valid());

    auto hero = save.findHero("Edric");
    REQUIRE(hero.skill_count == 2);
    testSkills(hero, {
        SkillSlot{Skill::Leadership, SkillLevel::Basic},
        SkillSlot{Skill::Armorer,    SkillLevel::Basic},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Axsis");
    REQUIRE(hero.skill_count == 2);
    testSkills(hero, {
        SkillSlot{Skill::Wisdom,    SkillLevel::Basic},
        SkillSlot{Skill::Mysticism, SkillLevel::Basic},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Leena");
    REQUIRE(hero.skill_count == 2);
    testSkills(hero, {
        SkillSlot{Skill::Estates,     SkillLevel::Basic},
        SkillSlot{Skill::Pathfinding, SkillLevel::Basic},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Lacus");
    REQUIRE(hero.skill_count == 1);
    testSkills(hero, {
        SkillSlot{Skill::Tactics, SkillLevel::Advanced},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Septienna");
    REQUIRE(hero.skill_count == 2);
    testSkills(hero, {
        SkillSlot{Skill::Necromancy, SkillLevel::Basic},
        SkillSlot{Skill::Scholar,    SkillLevel::Basic},
        // Remaining skill slots are unused
    });
}

TEST_CASE("secondary-skills-day2", "[hero][secondary-skills]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM5"});
    REQUIRE(save.valid());

    auto hero = save.findHero("Edric");
    REQUIRE(hero.skill_count == 5);
    testSkills(hero, {
        SkillSlot{Skill::Leadership, SkillLevel::Basic},
        SkillSlot{Skill::Armorer,    SkillLevel::Basic},
        SkillSlot{Skill::AirMagic,   SkillLevel::Basic},
        SkillSlot{Skill::Archery,    SkillLevel::Basic},
        SkillSlot{Skill::Artillery,  SkillLevel::Basic},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Axsis");
    REQUIRE(hero.skill_count == 5);
    testSkills(hero, {
        SkillSlot{Skill::Wisdom,     SkillLevel::Basic},
        SkillSlot{Skill::Mysticism,  SkillLevel::Basic},
        SkillSlot{Skill::EagleEye,   SkillLevel::Basic},
        SkillSlot{Skill::EarthMagic, SkillLevel::Basic},
        SkillSlot{Skill::Estates,    SkillLevel::Basic},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Leena");
    REQUIRE(hero.skill_count == 5);
    testSkills(hero, {
        SkillSlot{Skill::Estates,      SkillLevel::Basic},
        SkillSlot{Skill::Pathfinding,  SkillLevel::Basic},
        SkillSlot{Skill::Interference, SkillLevel::Basic},
        SkillSlot{Skill::Leadership,   SkillLevel::Basic},
        SkillSlot{Skill::Learning,     SkillLevel::Basic},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Lacus");
    REQUIRE(hero.skill_count == 4);
    testSkills(hero, {
        SkillSlot{Skill::Tactics,    SkillLevel::Advanced},
        SkillSlot{Skill::Navigation, SkillLevel::Basic},
        SkillSlot{Skill::Necromancy, SkillLevel::Basic},
        SkillSlot{Skill::Offense,    SkillLevel::Basic},
        // Remaining skill slots are unused
    });

    hero = save.findHero("Septienna");
    REQUIRE(hero.skill_count == 5);
    testSkills(hero, {
        SkillSlot{Skill::Necromancy, SkillLevel::Basic},
        SkillSlot{Skill::Scholar,    SkillLevel::Basic},
        SkillSlot{Skill::Scouting,   SkillLevel::Basic},
        SkillSlot{Skill::Sorcery,    SkillLevel::Basic},
        SkillSlot{Skill::Tactics,    SkillLevel::Basic},
        // Remaining skill slots are unused
    });
}

TEST_CASE("secondary-skills-day3", "[hero][secondary-skills]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM5"});
    REQUIRE(save.valid());

    auto hero = save.findHero("Edric");
    REQUIRE(hero.skill_count == 8);
    testSkills(hero, {
        SkillSlot{Skill::Leadership, SkillLevel::Expert},
        SkillSlot{Skill::Armorer,    SkillLevel::Advanced},
        SkillSlot{Skill::AirMagic,   SkillLevel::Expert},
        SkillSlot{Skill::Archery,    SkillLevel::Expert},
        SkillSlot{Skill::Artillery,  SkillLevel::Expert},
        SkillSlot{Skill::Ballistics, SkillLevel::Expert},
        SkillSlot{Skill::Diplomacy,  SkillLevel::Expert},
        SkillSlot{Skill::Offense,    SkillLevel::Expert},
    });

    hero = save.findHero("Axsis");
    REQUIRE(hero.skill_count == 8);
    testSkills(hero, {
        SkillSlot{Skill::Wisdom,       SkillLevel::Expert},
        SkillSlot{Skill::Mysticism,    SkillLevel::Advanced},
        SkillSlot{Skill::EagleEye,     SkillLevel::Basic},
        SkillSlot{Skill::EarthMagic,   SkillLevel::Expert},
        SkillSlot{Skill::Estates,      SkillLevel::Expert},
        SkillSlot{Skill::FireMagic,    SkillLevel::Expert},
        SkillSlot{Skill::FirstAid,     SkillLevel::Expert},
        SkillSlot{Skill::Intelligence, SkillLevel::Expert},
    });

    hero = save.findHero("Leena");
    REQUIRE(hero.skill_count == 8);
    testSkills(hero, {
        SkillSlot{Skill::Estates,      SkillLevel::Expert},
        SkillSlot{Skill::Pathfinding,  SkillLevel::Expert},
        SkillSlot{Skill::Interference, SkillLevel::Expert},
        SkillSlot{Skill::Leadership,   SkillLevel::Expert},
        SkillSlot{Skill::Learning,     SkillLevel::Basic},
        SkillSlot{Skill::Logistics,    SkillLevel::Expert},
        SkillSlot{Skill::Luck,         SkillLevel::Expert},
        SkillSlot{Skill::Mysticism,    SkillLevel::Advanced},
    });

    hero = save.findHero("Lacus");
    REQUIRE(hero.skill_count == 7);
    testSkills(hero, {
        SkillSlot{Skill::Tactics,     SkillLevel::Expert},
        SkillSlot{Skill::Navigation,  SkillLevel::Expert},
        SkillSlot{Skill::Necromancy,  SkillLevel::Expert},
        SkillSlot{Skill::Offense,     SkillLevel::Expert},
        SkillSlot{Skill::Pathfinding, SkillLevel::Expert},
        SkillSlot{Skill::Scholar,     SkillLevel::Expert},
        SkillSlot{Skill::Archery,     SkillLevel::Advanced},
        SkillSlot{Skill::NONE,        SkillLevel::None},
    });

    hero = save.findHero("Septienna");
    REQUIRE(hero.skill_count == 8);
    testSkills(hero, {
        SkillSlot{Skill::Necromancy, SkillLevel::Basic},
        SkillSlot{Skill::Scholar,    SkillLevel::Expert},
        SkillSlot{Skill::Scouting,   SkillLevel::Expert},
        SkillSlot{Skill::Sorcery,    SkillLevel::Expert},
        SkillSlot{Skill::Tactics,    SkillLevel::Advanced},
        SkillSlot{Skill::WaterMagic, SkillLevel::Expert},
        SkillSlot{Skill::Wisdom,     SkillLevel::Expert},
        SkillSlot{Skill::Logistics,  SkillLevel::Advanced},
    });
}
