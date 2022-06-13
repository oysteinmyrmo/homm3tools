#pragma once

#include <cstdint>
#include <limits>
#include <unordered_map>

namespace h3::hero
{
struct Hero;
} // namespace h3::hero

namespace h3::spells
{
enum class Spell : uint8_t;
} // namespace h3::spells

namespace h3::artifacts
{
enum class Artifact : uint32_t
{
    SpellBook                       =     0,
    SpellScroll                     =     1,
    Grail                           =     2,
    Catapult                        =     3,
    Ballista                        =     4,
    AmmoCart                        =     5,
    FirstAidTent                    =     6,
    CentaursAxe                     =     7,
    BlackshardOfTheDeadKnight       =     8,
    GreaterGnollsFlail              =     9,
    OgresClubOfHavoc                =    10,
    SwordOfHellfire                 =    11,
    TitansGladius                   =    12,
    ShieldOfTheDwarvenLords         =    13,
    ShieldOfTheYawningDead          =    14,
    BucklerOfTheGnollKing           =    15,
    TargOfTheRampagingOgre          =    16,
    ShieldOfTheDamned               =    17,
    SentinelsShield                 =    18,
    HelmOfTheAlabasterUnicorn       =    19,
    SkullHelmet                     =    20,
    HelmOfChaos                     =    21,
    CrownOfTheSupremeMagi           =    22,
    HellstormHelmet                 =    23,
    ThunderHelmet                   =    24,
    BreastplateOfPetrifiedWood      =    25,
    RibCage                         =    26,
    ScalesOfTheGreaterBasilisk      =    27,
    TunicOfTheCyclopsKing           =    28,
    BreastplateOfBrimstone          =    29,
    TitansCuirass                   =    30,
    ArmorOfWonder                   =    31,
    SandalsOfTheSaint               =    32,
    CelestialNecklaceOfBliss        =    33,
    LionsShieldOfCourage            =    34,
    SwordOfJudgement                =    35,
    HelmOfHeavenlyEnlightenment     =    36,
    QuietEyeOfTheDragon             =    37,
    RedDragonFlameTongue            =    38,
    DragonScaleShield               =    39,
    DragonScaleArmor                =    40,
    DragonboneGreaves               =    41,
    DragonWingTabard                =    42,
    NecklaceOfDragonteeth           =    43,
    CrownOfDragonTooth              =    44,
    StillEyeOfTheDragon             =    45,
    CloverOfFortune                 =    46,
    CardsOfProphecy                 =    47,
    LadybirdOfLuck                  =    48,
    BadgeOfCourage                  =    49,
    CrestOfValor                    =    50,
    GlyphOfGallantry                =    51,
    Speculum                        =    52,
    Spyglass                        =    53,
    AmuletOfTheUndertaker           =    54,
    VampiresCowl                    =    55,
    DeadMansBoots                   =    56,
    GarnitureOfInterference         =    57, // Resistance
    SurcoatOfCounterpoise           =    58, // Resistance
    BootsOfPolarity                 =    59, // Resistance
    BowOfElvenCherryWood            =    60,
    BowstringOfTheUnicornsMane      =    61,
    AngelFeatherArrows              =    62,
    BirdOfPerception                =    63,
    StoicWatchman                   =    64,
    EmblemOfCognizance              =    65,
    StatesmansMedal                 =    66,
    DiplomatsRing                   =    67,
    AmbassadorsSash                 =    68,
    RingOfTheWayfarer               =    69,
    EquestriansGloves               =    70,
    NecklaceOfOceanGuidance         =    71,
    AngelWings                      =    72,
    CharmOfMana                     =    73,
    TalismanOfMana                  =    74,
    MysticOrbOfMana                 =    75,
    CollarOfConjuring               =    76,
    RingOfConjuring                 =    77,
    CapeOfConjuring                 =    78,
    OrbOfFirmament                  =    79,
    OrbOfSilt                       =    80,
    OrbOfTempestuousFire            =    81,
    OrbOfDrivingRain                =    82,
    RecantersCloak                  =    83,
    SpiritOfOpression               =    84,
    HourglassOfTheEvilHour          =    85,
    TomeOfFireMagic                 =    86,
    TomeOfAirMagic                  =    87,
    TomeOfWaterMagic                =    88,
    TomeOfEarthMagic                =    89,
    BootsOfLevitation               =    90,
    GoldenBow                       =    91,
    SphereOfPermanence              =    92,
    OrbOfVulnerability              =    93,
    RingOfVitality                  =    94,
    RingOfLife                      =    95,
    VialOfLifeblooed                =    96,
    NecklaceOfSwiftness             =    97,
    BootsOfSpeed                    =    98,
    CapeOfVelocity                  =    99,
    PendantOfDispassion             =   100,
    PendantOfSecondSight            =   101,
    PendantOfHoliness               =   102,
    PendantOfLife                   =   103,
    PendantOfDeath                  =   104,
    PendantOfFreeWill               =   105,
    PendantOfNegativity             =   106,
    PendantOfTotalRecall            =   107,
    PendantOfCourage                =   108,
    EverflowingCrystalCloak         =   109,
    RingOfInfiniteGems              =   110,
    EverpouringVialOfMercury        =   111,
    InexhaustibleCartOfOre          =   112,
    EversmokingRingOfSulfur         =   113,
    InexhaustibleCartOfLumber       =   114,
    EndlessSackOfGold               =   115,
    EndlessBagOfGold                =   116,
    EndlessPurseOfGold              =   117,
    LegsOfLegion                    =   118,
    LoinsOfLegion                   =   119,
    TorsoOfLegion                   =   120,
    ArmsOfLegion                    =   121,
    HeadOfLegion                    =   122,
    SeaCaptainsHat                  =   123,
    SpellbindersHat                 =   124,
    ShacklesOfWar                   =   125,
    OrbOfInhibition                 =   126,

    // Combination artifacts and special artifacts.
    VialOfDragonBlood               =   127,
    ArmageddonsBlade                =   128,
    AngelicAlliance                 =   129,
    CloakOfTheUndeadKing            =   130,
    ElixirOfLife                    =   131,
    ArmorOfTheDamned                =   132,
    StatueOfLegion                  =   133,
    PowerOfTheDragonFather          =   134,
    TitansThunder                   =   135,
    AdmiralsHat                     =   136,
    BowOfTheSharpshooter            =   137,
    WizardsWell                     =   138,
    RingOfTheMagi                   =   139,
    Cornucopia                      =   140,

    // Note: HotA artifacts from here on.

    DiplomatsCloak                  =   141,
    PendantOfReflection             =   142,
    IronfistOfTheOgre               =   143,

    // Note: Artifacts 144 and 145 do not exist.

    Cannon                          =   146,

    TridentOfDominion               =   147,
    ShieldOfNavalGlory              =   148,
    RoyalArmorOfNix                 =   149,
    CrownOfTheFiveSeas              =   150,
    WayfarersBoots                  =   151,
    RunesOfImminency                =   152,
    DemonsHorseshoe                 =   153,
    ShamansPuppet                   =   154,
    HideousMask                     =   155,
    RingOfSuppression               =   156,
    PendantOfDownfall               =   157,
    RingOfOblivion                  =   158,
    CapeOfSilence                   =   159,
    GoldenGoose                     =   160, // Combination artifact
    HornOfTheAbyss                  =   161,
    CharmOfEclipse                  =   162,
    SealOfSunset                    =   163,
    PlateOfDyingLight               =   164,
    NONE                            =   std::numeric_limits<uint32_t>::max() // As in the save files
};

// Note: Artifacts 144 and 145 do not exist.
constexpr uint8_t ArtifactCount = 163;

// A single artifact entry in a save file.
struct ArtifactEntry
{
    bool empty() const { return artifactId == std::numeric_limits<uint32_t>::max(); }

    uint32_t artifactId = std::numeric_limits<uint32_t>::max();
    uint32_t scrollSpellId = std::numeric_limits<uint32_t>::max(); // Spell ID if artifact is a spell scroll.
};

enum class ArtifactClass : uint8_t
{
    Other         =   0, // Catapult, ballista, spell book, etc.
    Treasure      =   1,
    Minor         =   2,
    Major         =   3,
    Relic         =   4,
    Combination   =   5,
};

// Where on a Hero an artifact resides.
enum class ArtifactSlot : uint8_t
{
    Helm          =    0,
    Cloak         =    1,
    Neck          =    2,
    Weapon        =    3,
    Shield        =    4,
    Armor         =    5,
    RingLeft      =    6, // Left on the Hero screen (right hand).
    RingRight     =    7, // Right on the Hero screem (left hand).
    Boots         =    8,
    Misc01        =    9,
    Misc02        =   10,
    Misc03        =   11,
    Misc04        =   12,
    Ballista      =   13,
    AmmoCart      =   14,
    FirstAidTent  =   15,
    Catapult      =   16,
    SpellBook     =   17,
    Misc05        =   18,
    Inventory01   =   19,
    Inventory02   =   20,
    Inventory03   =   21,
    Inventory04   =   22,
    Inventory05   =   23,
    Inventory06   =   24,
    Inventory07   =   25,
    Inventory08   =   26,
    Inventory09   =   27,
    Inventory10   =   28,
    Inventory11   =   29,
    Inventory12   =   30,
    Inventory13   =   31,
    Inventory14   =   32,
    Inventory15   =   33,
    Inventory16   =   34,
    Inventory17   =   35,
    Inventory18   =   36,
    Inventory19   =   37,
    Inventory20   =   38,
    Inventory21   =   39,
    Inventory22   =   40,
    Inventory23   =   41,
    Inventory24   =   42,
    Inventory25   =   43,
    Inventory26   =   44,
    Inventory27   =   45,
    Inventory28   =   46,
    Inventory29   =   47,
    Inventory30   =   48,
    Inventory31   =   49,
    Inventory32   =   50,
    Inventory33   =   51,
    Inventory34   =   52,
    Inventory35   =   53,
    Inventory36   =   54,
    Inventory37   =   55,
    Inventory38   =   56,
    Inventory39   =   57,
    Inventory40   =   58,
    Inventory41   =   59,
    Inventory42   =   60,
    Inventory43   =   61,
    Inventory44   =   62,
    Inventory45   =   63,
    Inventory46   =   64,
    Inventory47   =   65,
    Inventory48   =   66,
    Inventory49   =   67,
    Inventory50   =   68,
    Inventory51   =   69,
    Inventory52   =   70,
    Inventory53   =   71,
    Inventory54   =   72,
    Inventory55   =   73,
    Inventory56   =   74,
    Inventory57   =   75,
    Inventory58   =   76,
    Inventory59   =   77,
    Inventory60   =   78,
    Inventory61   =   79,
    Inventory62   =   80,
    Inventory63   =   81,
    Inventory64   =   82,
    COUNT         =   83,
};

// Not the actual slots, but the type of slots.
enum class ArtifactSlotType : uint8_t
{
    Helm         =  0,
    Cloak        =  1,
    Neck         =  2,
    Weapon       =  3,
    Shield       =  4,
    Armor        =  5,
    Ring         =  6,
    Boots        =  7,
    Misc         =  8,
    Combination  =  9,
    Ballista     = 10,
    AmmoCart     = 11,
    FirstAidTent = 12,
    Catapult     = 13,
    SpellBook    = 14,
    Backpack     = 15,
};

constexpr uint8_t ArtifactSlotCount = static_cast<uint8_t>(ArtifactSlot::COUNT);

spells::Spell spellFromScroll(const hero::Hero &hero, uint8_t slot);
spells::Spell spellFromScroll(const hero::Hero &hero, ArtifactSlot artifactSlot);

Artifact artifact(const hero::Hero &hero, uint8_t slot);
Artifact artifact(const hero::Hero &hero, ArtifactSlot artifactSlot);

// Convenience free functions to make code easier elsewhere.
Artifact helm(const hero::Hero &hero);
Artifact cloak(const hero::Hero &hero);
Artifact neck(const hero::Hero &hero);
Artifact weapon(const hero::Hero &hero);
Artifact shield(const hero::Hero &hero);
Artifact armor(const hero::Hero &hero);
Artifact ringLeft(const hero::Hero &hero);
Artifact ringRight(const hero::Hero &hero);
Artifact boots(const hero::Hero &hero);
Artifact misc01(const hero::Hero &hero);
Artifact misc02(const hero::Hero &hero);
Artifact misc03(const hero::Hero &hero);
Artifact misc04(const hero::Hero &hero);
Artifact misc05(const hero::Hero &hero);
Artifact ballista(const hero::Hero &hero);
Artifact ammoCart(const hero::Hero &hero);
Artifact firstAidTent(const hero::Hero &hero);
Artifact catapult(const hero::Hero &hero);
Artifact spellBook(const hero::Hero &hero);
Artifact inventory(const hero::Hero &hero, uint8_t slot);

struct ArtifactDetails
{
    bool isTreasure() const { return artifactClass == ArtifactClass::Treasure; }
    bool isMinor() const { return artifactClass == ArtifactClass::Minor; }
    bool isMajor() const { return artifactClass == ArtifactClass::Major; }
    bool isRelic() const { return artifactClass == ArtifactClass::Relic; }
    bool isCombo() const { return artifactClass == ArtifactClass::Combination; }

    ArtifactClass artifactClass;
    ArtifactSlotType slotType;
    uint32_t cost = 0;
};

extern const std::unordered_map<Artifact, ArtifactDetails> artifactDetails;
} // namespace h3::artifacts

namespace h3
{
using Artifact = artifacts::Artifact;
using ArtifactSlot = artifacts::ArtifactSlot;
constexpr auto ArtifactCount = artifacts::ArtifactCount;
constexpr auto ArtifactSlotCount = artifacts::ArtifactSlotCount;
}
