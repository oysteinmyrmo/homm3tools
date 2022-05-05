#pragma once

#include <cstdint>

namespace h3::hero
{
struct Hero;
} // namespace h3::hero

namespace h3::spells
{
enum class Spell : uint8_t
{
    SummonBoat              =   0,
    ScuttleBoat             =   1,
    Visions                 =   2,
    ViewEarth               =   3,
    Disguise                =   4,
    ViewAir                 =   5,
    Fly                     =   6,
    WaterWalk               =   7,
    DimensionDoor           =   8,
    TownPortal              =   9,
    Quicksand               =  10,
    LandMine                =  11,
    ForceField              =  12,
    FireWall                =  13,
    Earthquake              =  14,
    MagicArrow              =  15,
    IceBolt                 =  16,
    LightningBolt           =  17,
    Implosion               =  18,
    ChainLightning          =  19,
    FrostRing               =  20,
    Fireball                =  21,
    Inferno                 =  22,
    MeteorShower            =  23,
    DeathRipple             =  24,
    DestroyUndead           =  25,
    Armageddon              =  26,
    Shield                  =  27,
    AirShield               =  28,
    FireShield              =  29,
    ProtectionFromAir       =  30,
    ProtectionFromFire      =  31,
    ProtectionFromWater     =  32,
    ProtectionFromEarth     =  33,
    AntiMagic               =  34,
    Dispel                  =  35,
    MagicMirror             =  36,
    Cure                    =  37,
    Resurrection            =  38,
    AnimateDead             =  39,
    Sacrifice               =  40,
    Bless                   =  41,
    Curse                   =  42,
    Bloodlust               =  43,
    Precision               =  44,
    Weakness                =  45,
    StoneSkin               =  46,
    DisruptingRay           =  47,
    Prayer                  =  48,
    Mirth                   =  49,
    Sorrow                  =  50,
    Fortune                 =  51,
    Misfortune              =  52,
    Haste                   =  53,
    Slow                    =  54,
    Slayer                  =  55,
    Frenzy                  =  56,
    TitansLightningBolt     =  57,
    Counterstrike           =  58,
    Berserk                 =  59,
    Hypnotize               =  60,
    Forgetfulness           =  61,
    Blind                   =  62,
    Teleport                =  63,
    RemoveObstacle          =  64,
    Clone                   =  65,
    SummonFireElemental     =  66,
    SummonEarthElemental    =  67,
    SummonWaterElemental    =  68,
    SummonAirElemental      =  69,
    COUNT                   =  70,
};

constexpr uint8_t SpellCount = static_cast<uint8_t>(Spell::COUNT);

bool has_spell(const h3::hero::Hero &hero, Spell spell);
bool has_spell_in_spellbook(const h3::hero::Hero &hero, Spell spell);
} // namespace h3::spells

namespace h3
{
using Spell = spells::Spell;
constexpr auto SpellCount = spells::SpellCount;
}
