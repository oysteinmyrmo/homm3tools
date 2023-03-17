#include "hero.h"
#include "value_reader.h"

#include <cassert>

namespace h3::hero
{
Creature Hero::bestCreature() const
{
    Creature bestCreature = Creature::Empty;
    uint32_t bestAIValue = 0;
    for (uint8_t i = 0; i < creatures::maxStacks; ++i)
    {
        const Creature creature = creatures[i];
        const uint32_t aiValue = creatures::AIValues.at(creature);
        if (aiValue > bestAIValue)
        {
            bestAIValue = aiValue;
            bestCreature = creature;
        }
    }
    return bestCreature;
}

SkillSlots Hero::skills() const
{
    SkillSlots skills;

    for (uint8_t i = 0; i < SkillCount; ++i)
    {
        if (skillLevels[i] != SkillLevel::None)
        {
            const uint8_t slot = skillSlots[i];
            assert(slot > 0 && slot <= 8);

            Skill skill = static_cast<Skill>(i);
            skills[slot - 1].level = skillLevels[i];
            skills[slot - 1].skill = skill;
        }
    }

    return skills;
}

void readHero(const std::span<const char> data, size_t idx, Hero &hero)
{
    values::readVal(data, idx, hero.x);
    values::readVal(data, idx, hero.y);
    values::readVal(data, idx, hero.z);
    values::readVal(data, idx, hero.on_map);
    values::skipVal(idx, hero._unused1);
    values::readVal(data, idx, hero.player);
    values::skipVal(idx, hero._unused2);
    values::readEnum(data, idx, hero.orientation);
    values::skipVal(idx, hero._unused3);
    values::readVal(data, idx, hero.dest_x);
    values::readVal(data, idx, hero.dest_y);
    values::readVal(data, idx, hero.dest_z);
    values::skipVal(idx, hero._unused4);
    values::readVal(data, idx, hero.movement_remaining);
    values::skipVal(idx, hero._unused5);
    values::readVal(data, idx, hero.experience);
    values::readVal(data, idx, hero.skill_count);
    values::readVal(data, idx, hero.spell_points);
    values::readVal(data, idx, hero.level);
    values::skipVal(idx, hero._unused6);
    values::readEnumArr(data, idx, hero.creatures);
    values::readArr(data, idx, hero.creature_count);
    values::readArr(data, idx, hero.name);
    values::readArr(data, idx, hero.skillLevels);
    values::skipVal(idx, hero._unused7);
    values::readVal(data, idx, hero.attack);
    values::readVal(data, idx, hero.defense);
    values::readVal(data, idx, hero.power);
    values::readVal(data, idx, hero.knowledge);
    values::readArr(data, idx, hero.spellbook);
    values::readArr(data, idx, hero.spells);
    values::readStructArr(data, idx, hero.artifacts,
                          &artifacts::ArtifactEntry::artifactId,
                          &artifacts::ArtifactEntry::scrollSpellId);
    values::skipVal(idx, hero._unused8);
    values::readArr(data, idx, hero.skillSlots);
}

void readAllHeroes(const std::span<const char> data, size_t idx, std::span<Hero> heroes)
{
    for (auto &hero : heroes)
    {
        readHero(data, idx, hero);
        idx += Hero::sizeofInSaveFile();
    }
}
} // namespace h3::hero
