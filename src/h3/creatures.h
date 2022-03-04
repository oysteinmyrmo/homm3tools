#pragma once

#include <cstdint>
#include <unordered_map>

namespace h3::creatures
{
static constexpr size_t maxStacks = 7;

enum class Creature : uint32_t
{
    // Castle
    Pikeman             =   0,
    Halberdier          =   1,
    Archer              =   2,
    Marksman            =   3,
    Griffin             =   4,
    RoyalGriffin        =   5,
    Swordsman           =   6,
    Crusader            =   7,
    Monk                =   8,
    Zealot              =   9,
    Cavalier            =  10,
    Champion            =  11,
    Angel               =  12,
    ArchAngel           =  13,

    // Rampart
    Centaur             =  14,
    CentaurCaptain      =  15,
    Dwarf               =  16,
    BattleDwarf         =  17,
    WoodElf             =  18,
    GrandElf            =  19,
    Pegasus             =  20,
    SilverPegasus       =  21,
    DendroidGuard       =  22,
    DendroidSoldier     =  23,
    Unicorn             =  24,
    WarUnicorn          =  25,
    GreenDragon         =  26,
    GoldDragon          =  27,

    // Tower
    Gremlin             =  28,
    MasterGremlin       =  29,
    StoneGargoyle       =  30,
    ObsidianGargoyle    =  31,
    StoneGolem          =  32,
    IronGolem           =  33,
    Mage                =  34,
    ArchMage            =  35,
    Genie               =  36,
    MasterGenie         =  37,
    Naga                =  38,
    NagaQueen           =  39,
    Giant               =  40,
    Titan               =  41,

    // Inferno
    Imp                 =  42,
    Familiar            =  43,
    Gog                 =  44,
    Magog               =  45,
    HellHound           =  46,
    Cerberus            =  47,
    Demon               =  48,
    HornedDemon         =  49,
    PitFiend            =  50,
    PitLord             =  51,
    Efreeti             =  52,
    EfreetSultan        =  53,
    Devil               =  54,
    ArchDevil           =  55,

    // Necropolis
    Skeleton            =  56,
    SkeletonWarrior     =  57,
    WalkingDead         =  58,
    Zombie              =  59,
    Wight               =  60,
    Wraith              =  61,
    Vampire             =  62,
    VampireLord         =  63,
    Lich                =  64,
    PowerLich           =  65,
    BlackKnight         =  66,
    DreadKnight         =  67,
    BoneDragon          =  68,
    GhostDragon         =  69,

    // Dungeon
    Troglodyte          =  70,
    InfernalTroglodyte  =  71,
    Harpy               =  72,
    HarpyHag            =  73,
    Beholder            =  74,
    EvilEye             =  75,
    Medusa              =  76,
    MedusaQueen         =  77,
    Minotaur            =  78,
    MinotaurKing        =  79,
    Manticore           =  80,
    Scorpicore          =  81,
    RedDragon           =  82,
    BlackDragon         =  83,

    // Stronghold
    Goblin              =  84,
    Hobgoblin           =  85,
    WolfRider           =  86,
    WolfRaider          =  87,
    Orc                 =  88,
    OrcChieftain        =  89,
    Ogre                =  90,
    OgreMage            =  91,
    Roc                 =  92,
    Thunderbird         =  93,
    Cyclops             =  94,
    CyclopsKing         =  95,
    Behemoth            =  96,
    AncientBehemoth     =  97,

    // Fortress (Note: the order does not match the creature order in-game).
    Gnoll               =  98,
    GnollMarauder       =  99,
    Lizardman           = 100,
    LizardWarrior       = 101,
    Gorgon              = 102,
    MightyGorgon        = 103,
    SerpentFly          = 104,
    DragonFly           = 105,
    Basilisk            = 106,
    GreaterBasilisk     = 107,
    Wyvern              = 108,
    WyvernMonarch       = 109,
    Hydra               = 110,
    ChaosHydra          = 111,

    // Conflux (Note: the order does not match the creature order in-game).
    AirElemental        = 112,
    EarthElemental      = 113,
    FireElemental       = 114,
    WaterElemental      = 115,
    GoldGolem           = 116, // Neutral
    DiamondGolem        = 117, // Neutral
    Pixie               = 118,
    Sprite              = 119,
    PsychicElemental    = 120,
    MagicElemental      = 121,
    IceElemental        = 123,
    MagmaElemental      = 125,
    StormElemental      = 127,
    EnergyElemental     = 129,
    Firebird            = 130,
    Phoenix             = 131,

    // Neutrals
    AzureDragon         = 132,
    CrystalDragon       = 133,
    FaerieDragon        = 134,
    RustDragon          = 135,
    Enchanter           = 136,
    Sharpshooter        = 137,
    Halfling            = 138,
    Peasant             = 139,
    Boar                = 140,
    Mummy               = 141,
    Nomad               = 142,
    Rogue               = 143,
    Troll               = 144,

    // Cove
    SeaDog              = 151, // Out of in-game creature order.
    Nymph               = 153,
    Oceanid             = 154,
    CrewMate            = 155,
    Seaman              = 156,
    Pirate              = 157,
    Corsair             = 158,
    Stormbird           = 159,
    Ayssid              = 160,
    SeaWitch            = 161,
    Sorceress           = 162,
    Nix                 = 163,
    NixWarrior          = 164,
    SeaSerpent          = 165,
    Haspid              = 166,

    // Neturals
    Satyr               = 167,
    Fangarm             = 168,
    Leprechaun          = 169,
    SteelGolem          = 170,

    // Value for empty slot
    Empty               = uint32_t(-1)
};

extern const std::unordered_map<Creature, uint32_t> AIValues;
} // namespace h3::creatures

namespace h3
{
using Creature = creatures::Creature;
}
