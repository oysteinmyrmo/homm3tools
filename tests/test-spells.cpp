#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/hero.h>
#include <h3/savefile.h>
#include <h3/spells.h>

#include <algorithm>
#include <array>
#include <cassert>
#include <filesystem>

namespace
{
using h3::Hero;
using h3::SaveFile;
using h3::Spell;
using h3::SpellCount;

std::filesystem::path testDataDir(h3::test::testDataDir / "spells");

template<size_t Count>
bool contains(const std::array<Spell, Count> spells, const Spell arg)
{
    return std::find(spells.begin(), spells.end(), arg) != spells.end();
}

// Verify spells in spell book (not artifacts).
template<size_t Count>
void verifySpellBook(const Hero &hero, const std::array<Spell, Count> expectedSpells)
{
    for (uint8_t i = 0; i < SpellCount; ++i)
    {
        const Spell spell = static_cast<Spell>(i);
        const bool exists = bool(hero.spellbook[i]);
        const bool expected = contains(expectedSpells, spell);
        assert(expected == exists);
        REQUIRE(expected == exists);
        REQUIRE(hero.hasSpellInSpellBook(spell) == expected);
    }
}

// Verify all spells, both in spell book and from artifacts.
template<size_t Count>
void verifySpells(const Hero &hero, const std::array<Spell, Count> expectedSpells)
{
    for (uint8_t i = 0; i < SpellCount; ++i)
    {
        const Spell spell = static_cast<Spell>(i);
        const bool exists = bool(hero.spells[i]);
        const bool expected = contains(expectedSpells, spell);
        REQUIRE(expected == exists);
        REQUIRE(hero.hasSpell(spell) == expected);
    }
}

// Verify spells from artifacts. Expects spells that are not in the spell book.
template<size_t Count>
void verifySpellsFromArtifacts(const Hero &hero, const std::array<Spell, Count> expectedSpells, const Spell speciality)
{
    for (uint8_t i = 0; i < SpellCount; ++i)
    {
        const Spell spell = static_cast<Spell>(i);
        const bool exists = bool(hero.spells[i]);
        const bool expected = contains(expectedSpells, spell);
        REQUIRE(expected == exists);
        REQUIRE(hero.hasSpell(spell) == expected);

        // Speciality adds the spell to spell book by default (e.g. curse for Ingham).
        if (spell != speciality)
        {
            REQUIRE(!hero.hasSpellInSpellBook(spell)); // This function verifies spells from artifacts only.
        }
    }
}

// Verify spells from artifacts. Expects spells that are not in the spell book.
template<size_t Count>
void verifySpellsFromArtifacts(const Hero &hero, const std::array<Spell, Count> expectedSpells)
{
    for (uint8_t i = 0; i < SpellCount; ++i)
    {
        const Spell spell = static_cast<Spell>(i);
        const bool exists = bool(hero.spells[i]);
        const bool expected = contains(expectedSpells, spell);
        REQUIRE(expected == exists);
        REQUIRE(hero.hasSpell(spell) == expected);
        REQUIRE(!hero.hasSpellInSpellBook(spell)); // This function verifies spells from artifacts only.
    }
}
} // namespace

// Only heroes with spell speciality have spells on day 1.
TEST_CASE("spells-day1", "[hero][spells]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM3"});
    REQUIRE(save.valid());

    const std::array<Spell, 0> noSpells{};

    {
        const Hero hero = save.findHero("Sanya");
        verifySpellBook(hero, noSpells);
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Rion");
        verifySpellBook(hero, noSpells);
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Cuthbert");
        verifySpellBook(hero, noSpells);
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Loynis");
        const std::array spells {
            Spell::Prayer, // Speciality
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Adela");
        const std::array spells {
            Spell::Bless, // Speciality
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Ingham");
        const std::array spells {
            Spell::Curse,
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Adelaide");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Caitlin");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Elleshar");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Coronius");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Alagar");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Gem");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Aeris");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Malcom");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Uland");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Melodia");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Theodorus");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Halon");
        verifySpells(hero, noSpells);
    }

    {
        const Hero hero = save.findHero("Daremyth");
        verifySpells(hero, noSpells);
    }

    {
        // Solmyr had his precious Chain Lightning stripped from the game!
        const Hero hero = save.findHero("Solmyr");
        verifySpells(hero, noSpells);
    }
}

TEST_CASE("spells-day2-sanya", "[hero][spells]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM3"});
    REQUIRE(save.valid());

    {
        const Hero hero = save.findHero("Sanya");
        const std::array spells{
            Spell::Bless,
            Spell::Bloodlust,
            Spell::Cure,
            Spell::Curse,
            Spell::Dispel,
            Spell::Haste,
            Spell::MagicArrow,
            Spell::ProtectionFromWater,
            Spell::ProtectionFromFire,
            Spell::Shield,
            Spell::Slow,
            Spell::StoneSkin,
            Spell::SummonBoat,
            Spell::ViewAir,
            Spell::ViewEarth,
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Rion");
        const std::array spells {
            Spell::Blind,
            Spell::DeathRipple,
            Spell::Disguise,
            Spell::DisruptingRay,
            Spell::FireWall,
            Spell::Fortune,
            Spell::IceBolt,
            Spell::LightningBolt,
            Spell::Precision,
            Spell::ProtectionFromAir,
            Spell::Quicksand,
            Spell::RemoveObstacle,
            Spell::ScuttleBoat,
            Spell::Visions,
            Spell::Weakness,
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Cuthbert");
        const std::array spells {
            Spell::AirShield,
            Spell::AnimateDead,
            Spell::AntiMagic,
            Spell::DestroyUndead,
            Spell::Earthquake,
            Spell::Fireball,
            Spell::ForceField,
            Spell::Forgetfulness,
            Spell::FrostRing,
            Spell::Hypnotize,
            Spell::LandMine,
            Spell::Mirth,
            Spell::Misfortune,
            Spell::ProtectionFromEarth,
            Spell::Teleport,
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Loynis");
        const std::array spells {
            Spell::Prayer,
            Spell::Armageddon,
            Spell::Berserk,
            Spell::ChainLightning,
            Spell::Clone,
            Spell::Counterstrike,
            Spell::FireShield,
            Spell::Frenzy,
            Spell::Inferno,
            Spell::MeteorShower,
            Spell::Resurrection,
            Spell::Slayer,
            Spell::Sorrow,
            Spell::TownPortal,
            Spell::WaterWalk,
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Adela");
        const std::array spells {
            Spell::DimensionDoor,
            Spell::Fly,
            Spell::Implosion,
            Spell::MagicMirror,
            Spell::Sacrifice,
            Spell::SummonAirElemental,
            Spell::SummonEarthElemental,
            Spell::SummonFireElemental,
            Spell::SummonWaterElemental,
            Spell::Bless, // From speciality.
        };
        verifySpellBook(hero, spells);
        verifySpells(hero, spells);
    }

    {
        // All spells, provided by artifacts only.
        const Hero hero = save.findHero("Ingham");
        const Spell speciality = Spell::Curse;
        const std::array spells {
            Spell::AirShield,
            Spell::AnimateDead,
            Spell::AntiMagic,
            Spell::Armageddon,
            Spell::Berserk,
            Spell::Bless,
            Spell::Blind,
            Spell::Bloodlust,
            Spell::ChainLightning,
            Spell::Clone,
            Spell::Counterstrike,
            Spell::Cure,
            Spell::Curse,
            Spell::DeathRipple,
            Spell::DestroyUndead,
            Spell::DimensionDoor,
            Spell::Disguise,
            Spell::Dispel,
            Spell::DisruptingRay,
            Spell::Earthquake,
            Spell::FireShield,
            Spell::FireWall,
            Spell::Fireball,
            Spell::Fly,
            Spell::ForceField,
            Spell::Forgetfulness,
            Spell::Fortune,
            Spell::Frenzy,
            Spell::FrostRing,
            Spell::Haste,
            Spell::Hypnotize,
            Spell::IceBolt,
            Spell::Implosion,
            Spell::Inferno,
            Spell::LandMine,
            Spell::LightningBolt,
            Spell::MagicArrow,
            Spell::MagicMirror,
            Spell::MeteorShower,
            Spell::Mirth,
            Spell::Misfortune,
            Spell::Prayer,
            Spell::Precision,
            Spell::ProtectionFromAir,
            Spell::ProtectionFromEarth,
            Spell::ProtectionFromFire,
            Spell::ProtectionFromWater,
            Spell::Quicksand,
            Spell::RemoveObstacle,
            Spell::Resurrection,
            Spell::Sacrifice,
            Spell::ScuttleBoat,
            Spell::Shield,
            Spell::Slayer,
            Spell::Slow,
            Spell::Sorrow,
            Spell::StoneSkin,
            Spell::SummonAirElemental,
            Spell::SummonBoat,
            Spell::SummonEarthElemental,
            Spell::SummonFireElemental,
            Spell::SummonWaterElemental,
            Spell::Teleport,
            Spell::TitansLightningBolt,
            Spell::TownPortal,
            Spell::ViewAir,
            Spell::ViewEarth,
            Spell::Visions,
            Spell::WaterWalk,
            Spell::Weakness,
        };
        verifySpellsFromArtifacts(hero, spells, speciality);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Adelaide");
        const std::array spells {
            Spell::SummonAirElemental,
            Spell::AirShield,
            Spell::AnimateDead,
            Spell::AntiMagic,
            Spell::Armageddon,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Caitlin");
        const std::array spells {
            Spell::Berserk,
            Spell::Bless,
            Spell::Blind,
            Spell::Bloodlust,
            Spell::ChainLightning,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Elleshar");
        const std::array spells {
            Spell::Clone,
            Spell::Counterstrike,
            Spell::Cure,
            Spell::Curse,
            Spell::DeathRipple,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Coronius");
        const std::array spells {
            Spell::DestroyUndead,
            Spell::DimensionDoor,
            Spell::Disguise,
            Spell::Dispel,
            Spell::DisruptingRay,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Alagar");
        const std::array spells {
            Spell::SummonEarthElemental,
            Spell::Earthquake,
            Spell::SummonFireElemental,
            Spell::FireShield,
            Spell::FireWall,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Gem");
        const std::array spells {
            Spell::Fireball,
            Spell::Fly,
            Spell::ForceField,
            Spell::Forgetfulness,
            Spell::Fortune,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Aeris");
        const std::array spells {
            Spell::Frenzy,
            Spell::FrostRing,
            Spell::Haste,
            Spell::Hypnotize,
            Spell::IceBolt,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Malcom");
        const std::array spells {
            Spell::Implosion,
            Spell::Inferno,
            Spell::LandMine,
            Spell::LightningBolt,
            Spell::MagicArrow,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Uland");
        const std::array spells {
            Spell::MagicMirror,
            Spell::MeteorShower,
            Spell::Mirth,
            Spell::Misfortune,
            Spell::Prayer,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Melodia");
        const std::array spells {
            Spell::Precision,
            Spell::ProtectionFromEarth,
            Spell::ProtectionFromWater,
            Spell::ProtectionFromAir,
            Spell::ProtectionFromFire,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Theodorus");
        const std::array spells {
            Spell::Quicksand,
            Spell::RemoveObstacle,
            Spell::Resurrection,
            Spell::Sacrifice,
            Spell::ScuttleBoat,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Halon");
        const std::array spells {
            Spell::Shield,
            Spell::Slayer,
            Spell::Slow,
            Spell::Sorrow,
            Spell::StoneSkin,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        const Hero hero = save.findHero("Daremyth");
        const std::array spells {
            Spell::SummonBoat,
            Spell::Teleport,
            Spell::TownPortal,
            Spell::ViewAir,
            Spell::ViewEarth,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }

    {
        // Solmyr had his precious Chain Lightning stripped from the game!
        const Hero hero = save.findHero("Solmyr");
        const std::array spells {
            Spell::Visions,
            Spell::SummonWaterElemental,
            Spell::WaterWalk,
            Spell::Weakness,
        };
        verifySpellsFromArtifacts(hero, spells);
        verifySpells(hero, spells);
    }
}
