#include "artifacts.h"
#include "hero.h"
#include "spells.h"

namespace h3::artifacts
{
spells::Spell spellFromScroll(const hero::Hero &hero, const uint8_t slot)
{
    const ArtifactEntry entry = hero.artifacts[slot];
    return static_cast<spells::Spell>(entry.scrollSpellId);
}

spells::Spell spellFromScroll(const hero::Hero &hero, const ArtifactSlot artifactSlot)
{
    const uint8_t slot = static_cast<uint8_t>(artifactSlot);
    return spellFromScroll(hero, slot);
}

Artifact artifact(const hero::Hero &hero, const uint8_t slot)
{
    const ArtifactEntry entry = hero.artifacts[slot];
    return static_cast<Artifact>(entry.artifactId);
}

Artifact artifact(const hero::Hero &hero, const ArtifactSlot artifactSlot)
{
    const uint8_t slot = static_cast<uint8_t>(artifactSlot);
    return artifact(hero, slot);
}

Artifact helm(const hero::Hero &hero)           { return artifact(hero, ArtifactSlot::Helm);         }
Artifact cloak(const hero::Hero &hero)          { return artifact(hero, ArtifactSlot::Cloak);        }
Artifact neck(const hero::Hero &hero)           { return artifact(hero, ArtifactSlot::Neck);         }
Artifact weapon(const hero::Hero &hero)         { return artifact(hero, ArtifactSlot::Weapon);       }
Artifact shield(const hero::Hero &hero)         { return artifact(hero, ArtifactSlot::Shield);       }
Artifact armor(const hero::Hero &hero)          { return artifact(hero, ArtifactSlot::Armor);        }
Artifact ringLeft(const hero::Hero &hero)       { return artifact(hero, ArtifactSlot::RingLeft);     }
Artifact ringRight(const hero::Hero &hero)      { return artifact(hero, ArtifactSlot::RingRight);    }
Artifact boots(const hero::Hero &hero)          { return artifact(hero, ArtifactSlot::Boots);        }
Artifact misc01(const hero::Hero &hero)         { return artifact(hero, ArtifactSlot::Misc01);       }
Artifact misc02(const hero::Hero &hero)         { return artifact(hero, ArtifactSlot::Misc02);       }
Artifact misc03(const hero::Hero &hero)         { return artifact(hero, ArtifactSlot::Misc03);       }
Artifact misc04(const hero::Hero &hero)         { return artifact(hero, ArtifactSlot::Misc04);       }
Artifact misc05(const hero::Hero &hero)         { return artifact(hero, ArtifactSlot::Misc05);       }
Artifact ballista(const hero::Hero &hero)       { return artifact(hero, ArtifactSlot::Ballista);     }
Artifact ammoCart(const hero::Hero &hero)       { return artifact(hero, ArtifactSlot::AmmoCart);     }
Artifact firstAidTent(const hero::Hero &hero)   { return artifact(hero, ArtifactSlot::FirstAidTent); }
Artifact catapult(const hero::Hero &hero)       { return artifact(hero, ArtifactSlot::Catapult);     }
Artifact spellBook(const hero::Hero &hero)      { return artifact(hero, ArtifactSlot::SpellBook);    }

Artifact inventory(const hero::Hero &hero, const uint8_t slot)
{
    return artifact(hero, slot);
}

// Values taken from https://heroes.thelazy.net/index.php/List_of_artifacts_(HotA)
const std::unordered_map<Artifact, ArtifactDetails> artifactDetails = {

    // Cloaks
    {Artifact::CapeOfConjuring,             {ArtifactClass::Treasure,    ArtifactSlotType::Cloak,        1500}},
    {Artifact::DragonWingTabard,            {ArtifactClass::Minor,       ArtifactSlotType::Cloak,        4000}},
    {Artifact::VampiresCowl,                {ArtifactClass::Minor,       ArtifactSlotType::Cloak,        4000}},
    {Artifact::SurcoatOfCounterpoise,       {ArtifactClass::Major,       ArtifactSlotType::Cloak,        4000}},
    {Artifact::AmbassadorsSash,             {ArtifactClass::Major,       ArtifactSlotType::Cloak,        5000}},
    {Artifact::EverflowingCrystalCloak,     {ArtifactClass::Major,       ArtifactSlotType::Cloak,        5000}},
    {Artifact::RecantersCloak,              {ArtifactClass::Major,       ArtifactSlotType::Cloak,        8000}},
    {Artifact::CapeOfVelocity,              {ArtifactClass::Major,       ArtifactSlotType::Cloak,       10000}},
    {Artifact::AngelWings,                  {ArtifactClass::Relic,       ArtifactSlotType::Cloak,       20000}},
    {Artifact::CapeOfSilence,               {ArtifactClass::Relic,       ArtifactSlotType::Cloak,        7500}},

    // Boots
    {Artifact::DragonboneGreaves,           {ArtifactClass::Treasure,    ArtifactSlotType::Boots,        2000}},
    {Artifact::BootsOfSpeed,                {ArtifactClass::Minor,       ArtifactSlotType::Boots,        6000}},
    {Artifact::DeadMansBoots,               {ArtifactClass::Major,       ArtifactSlotType::Boots,        6000}},
    {Artifact::BootsOfPolarity,             {ArtifactClass::Relic,       ArtifactSlotType::Boots,        6000}},
    {Artifact::SandalsOfTheSaint,           {ArtifactClass::Relic,       ArtifactSlotType::Boots,        8000}},
    {Artifact::BootsOfLevitation,           {ArtifactClass::Relic,       ArtifactSlotType::Boots,       10000}},
    {Artifact::WayfarersBoots,              {ArtifactClass::Major,       ArtifactSlotType::Boots,        5000}},

    // Helms
    {Artifact::HelmOfTheAlabasterUnicorn,   {ArtifactClass::Treasure,    ArtifactSlotType::Helm,         1000}},
    {Artifact::SkullHelmet,                 {ArtifactClass::Treasure,    ArtifactSlotType::Helm,         3000}},
    {Artifact::HelmOfChaos,                 {ArtifactClass::Minor,       ArtifactSlotType::Helm,         4000}},
    {Artifact::CrownOfTheSupremeMagi,       {ArtifactClass::Minor,       ArtifactSlotType::Helm,         5000}},
    {Artifact::HellstormHelmet,             {ArtifactClass::Major,       ArtifactSlotType::Helm,         6000}},
    {Artifact::CrownOfDragonTooth,          {ArtifactClass::Relic,       ArtifactSlotType::Helm,         8000}},
    {Artifact::ThunderHelmet,               {ArtifactClass::Relic,       ArtifactSlotType::Helm,        10000}},
    {Artifact::SeaCaptainsHat,              {ArtifactClass::Relic,       ArtifactSlotType::Helm,        15000}},
    {Artifact::HelmOfHeavenlyEnlightenment, {ArtifactClass::Relic,       ArtifactSlotType::Helm,        24000}},
    {Artifact::SpellbindersHat,             {ArtifactClass::Relic,       ArtifactSlotType::Helm,        30000}},
    {Artifact::AdmiralsHat,                 {ArtifactClass::Relic,       ArtifactSlotType::Helm,        25000}},
    {Artifact::CrownOfTheFiveSeas,          {ArtifactClass::Major,       ArtifactSlotType::Helm,         7000}},

    // Shields
    {Artifact::ShieldOfTheDwarvenLords,     {ArtifactClass::Treasure,    ArtifactSlotType::Shield,       2000}},
    {Artifact::ShieldOfTheYawningDead,      {ArtifactClass::Minor,       ArtifactSlotType::Shield,       3000}},
    {Artifact::BucklerOfTheGnollKing,       {ArtifactClass::Minor,       ArtifactSlotType::Shield,       4000}},
    {Artifact::TargOfTheRampagingOgre,      {ArtifactClass::Major,       ArtifactSlotType::Shield,       5000}},
    {Artifact::ShieldOfTheDamned,           {ArtifactClass::Major,       ArtifactSlotType::Shield,       6000}},
    {Artifact::DragonScaleShield,           {ArtifactClass::Major,       ArtifactSlotType::Shield,       6000}},
    {Artifact::LionsShieldOfCourage,        {ArtifactClass::Relic,       ArtifactSlotType::Shield,      16000}},
    {Artifact::SentinelsShield,             {ArtifactClass::Relic,       ArtifactSlotType::Shield,      10000}},
    {Artifact::ShieldOfNavalGlory,          {ArtifactClass::Major,       ArtifactSlotType::Shield,       7000}},

    // Misc
    {Artifact::CharmOfMana,                 {ArtifactClass::Treasure,    ArtifactSlotType::Misc,          500}},
    {Artifact::TalismanOfMana,              {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::MysticOrbOfMana,             {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1500}},
    {Artifact::OrbOfSilt,                   {ArtifactClass::Major,       ArtifactSlotType::Misc,         6000}},
    {Artifact::OrbOfFirmament,              {ArtifactClass::Major,       ArtifactSlotType::Misc,         6000}},
    {Artifact::OrbOfDrivingRain,            {ArtifactClass::Major,       ArtifactSlotType::Misc,         6000}},
    {Artifact::OrbOfTempestuousFire,        {ArtifactClass::Major,       ArtifactSlotType::Misc,         6000}},
    {Artifact::TomeOfEarthMagic,            {ArtifactClass::Relic,       ArtifactSlotType::Misc,        20000}},
    {Artifact::TomeOfAirMagic,              {ArtifactClass::Relic,       ArtifactSlotType::Misc,        20000}},
    {Artifact::TomeOfWaterMagic,            {ArtifactClass::Relic,       ArtifactSlotType::Misc,        20000}},
    {Artifact::TomeOfFireMagic,             {ArtifactClass::Relic,       ArtifactSlotType::Misc,        20000}},
    {Artifact::SphereOfPermanence,          {ArtifactClass::Major,       ArtifactSlotType::Misc,         7500}},
    {Artifact::OrbOfInhibition,             {ArtifactClass::Relic,       ArtifactSlotType::Misc,        20000}},
    {Artifact::OrbOfVulnerability,          {ArtifactClass::Relic,       ArtifactSlotType::Misc,        25000}},
    {Artifact::BirdOfPerception,            {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::StoicWatchman,               {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         2000}},
    {Artifact::EmblemOfCognizance,          {ArtifactClass::Minor,       ArtifactSlotType::Misc,         3000}},
    {Artifact::CloverOfFortune,             {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::LadybirdOfLuck,              {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::CardsOfProphecy,             {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::HourglassOfTheEvilHour,      {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         2000}},
    {Artifact::GlyphOfGallantry,            {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::CrestOfValor,                {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::BadgeOfCourage,              {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::SpiritOfOpression,           {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         2000}},
    {Artifact::Spyglass,                    {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::Speculum,                    {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         1000}},
    {Artifact::GoldenBow,                   {ArtifactClass::Major,       ArtifactSlotType::Misc,         8000}},
    {Artifact::BowOfElvenCherryWood,        {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         2000}},
    {Artifact::BowstringOfTheUnicornsMane,  {ArtifactClass::Minor,       ArtifactSlotType::Misc,         4000}},
    {Artifact::AngelFeatherArrows,          {ArtifactClass::Major,       ArtifactSlotType::Misc,         6000}},
    {Artifact::VialOfLifeblooed,            {ArtifactClass::Major,       ArtifactSlotType::Misc,        10000}},
    {Artifact::EndlessPurseOfGold,          {ArtifactClass::Major,       ArtifactSlotType::Misc,         5000}},
    {Artifact::EndlessBagOfGold,            {ArtifactClass::Major,       ArtifactSlotType::Misc,         7500}},
    {Artifact::EndlessSackOfGold,           {ArtifactClass::Relic,       ArtifactSlotType::Misc,        10000}},
    {Artifact::InexhaustibleCartOfLumber,   {ArtifactClass::Minor,       ArtifactSlotType::Misc,         5000}},
    {Artifact::InexhaustibleCartOfOre,      {ArtifactClass::Minor,       ArtifactSlotType::Misc,         5000}},
    {Artifact::EverpouringVialOfMercury,    {ArtifactClass::Major,       ArtifactSlotType::Misc,         5000}},
    {Artifact::LegsOfLegion,                {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         5000}},
    {Artifact::LoinsOfLegion,               {ArtifactClass::Minor,       ArtifactSlotType::Misc,         5000}},
    {Artifact::TorsoOfLegion,               {ArtifactClass::Minor,       ArtifactSlotType::Misc,         5000}},
    {Artifact::ArmsOfLegion,                {ArtifactClass::Major,       ArtifactSlotType::Misc,         5000}},
    {Artifact::HeadOfLegion,                {ArtifactClass::Major,       ArtifactSlotType::Misc,         5000}},
    {Artifact::ShacklesOfWar,               {ArtifactClass::Major,       ArtifactSlotType::Misc,         5000}},
    {Artifact::VialOfDragonBlood,           {ArtifactClass::Relic,       ArtifactSlotType::Misc,        20000}},
    {Artifact::HideousMask,                 {ArtifactClass::Minor,       ArtifactSlotType::Misc,         4000}},
    {Artifact::RunesOfImminency,            {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         2000}},
    {Artifact::DemonsHorseshoe,             {ArtifactClass::Treasure,    ArtifactSlotType::Misc,         2000}},
    {Artifact::ShamansPuppet,               {ArtifactClass::Minor,       ArtifactSlotType::Misc,         4000}},
    {Artifact::CharmOfEclipse,              {ArtifactClass::Minor,       ArtifactSlotType::Misc,         5000}},
    {Artifact::HornOfTheAbyss,              {ArtifactClass::Relic,       ArtifactSlotType::Misc,        50000}},

    // Necklace
    {Artifact::PendantOfDispassion,         {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         1000}},
    {Artifact::PendantOfFreeWill,           {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         1000}},
    {Artifact::PendantOfLife,               {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         2500}},
    {Artifact::PendantOfDeath,              {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         2500}},
    {Artifact::PendantOfTotalRecall,        {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         3000}},
    {Artifact::PendantOfHoliness,           {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         5000}},
    {Artifact::PendantOfSecondSight,        {ArtifactClass::Major,       ArtifactSlotType::Neck,         5000}},
    {Artifact::PendantOfNegativity,         {ArtifactClass::Major,       ArtifactSlotType::Neck,         5000}},
    {Artifact::CollarOfConjuring,           {ArtifactClass::Treasure,    ArtifactSlotType::Neck,          500}},
    {Artifact::AmuletOfTheUndertaker,       {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         2000}},
    {Artifact::GarnitureOfInterference,     {ArtifactClass::Major,       ArtifactSlotType::Neck,         2000}},
    {Artifact::StatesmansMedal,             {ArtifactClass::Major,       ArtifactSlotType::Neck,         5000}},
    {Artifact::NecklaceOfSwiftness,         {ArtifactClass::Treasure,    ArtifactSlotType::Neck,         5000}},
    {Artifact::PendantOfCourage,            {ArtifactClass::Major,       ArtifactSlotType::Neck,         7000}},
    {Artifact::NecklaceOfDragonteeth,       {ArtifactClass::Major,       ArtifactSlotType::Neck,         6000}},
    {Artifact::NecklaceOfOceanGuidance,     {ArtifactClass::Major,       ArtifactSlotType::Neck,        10000}},
    {Artifact::CelestialNecklaceOfBliss,    {ArtifactClass::Relic,       ArtifactSlotType::Neck,        12000}},
    {Artifact::PendantOfDownfall,           {ArtifactClass::Major,       ArtifactSlotType::Neck,         7000}},

    // Weapons
    {Artifact::CentaursAxe,                 {ArtifactClass::Treasure,    ArtifactSlotType::Weapon,       2000}},
    {Artifact::BlackshardOfTheDeadKnight,   {ArtifactClass::Minor,       ArtifactSlotType::Weapon,       3000}},
    {Artifact::GreaterGnollsFlail,          {ArtifactClass::Minor,       ArtifactSlotType::Weapon,       4000}},
    {Artifact::OgresClubOfHavoc,            {ArtifactClass::Major,       ArtifactSlotType::Weapon,       5000}},
    {Artifact::SwordOfHellfire,             {ArtifactClass::Major,       ArtifactSlotType::Weapon,       6000}},
    {Artifact::RedDragonFlameTongue,        {ArtifactClass::Minor,       ArtifactSlotType::Weapon,       4000}},
    {Artifact::TitansGladius,               {ArtifactClass::Relic,       ArtifactSlotType::Weapon,      10000}},
    {Artifact::SwordOfJudgement,            {ArtifactClass::Relic,       ArtifactSlotType::Weapon,      20000}},
    {Artifact::ArmageddonsBlade,            {ArtifactClass::Relic,       ArtifactSlotType::Weapon,      50000}},
    {Artifact::TridentOfDominion,           {ArtifactClass::Major,       ArtifactSlotType::Weapon,       7000}},

    // Rings
    {Artifact::RingOfConjuring,             {ArtifactClass::Treasure,    ArtifactSlotType::Ring,         1000}},
    {Artifact::StillEyeOfTheDragon,         {ArtifactClass::Treasure,    ArtifactSlotType::Ring,         2000}},
    {Artifact::QuietEyeOfTheDragon,         {ArtifactClass::Treasure,    ArtifactSlotType::Ring,         2000}},
    {Artifact::EquestriansGloves,           {ArtifactClass::Minor,       ArtifactSlotType::Ring,         3000}},
    {Artifact::DiplomatsRing,               {ArtifactClass::Minor,       ArtifactSlotType::Ring,         5000}},
    {Artifact::RingOfTheWayfarer,           {ArtifactClass::Major,       ArtifactSlotType::Ring,         5000}},
    {Artifact::RingOfVitality,              {ArtifactClass::Treasure,    ArtifactSlotType::Ring,         5000}},
    {Artifact::RingOfLife,                  {ArtifactClass::Minor,       ArtifactSlotType::Ring,         5000}},
    {Artifact::RingOfInfiniteGems,          {ArtifactClass::Major,       ArtifactSlotType::Ring,         5000}},
    {Artifact::EversmokingRingOfSulfur,     {ArtifactClass::Major,       ArtifactSlotType::Ring,         5000}},
    {Artifact::RingOfSuppression,           {ArtifactClass::Treasure,    ArtifactSlotType::Ring,         4000}},
    {Artifact::RingOfOblivion,              {ArtifactClass::Major,       ArtifactSlotType::Ring,         7500}},
    {Artifact::SealOfSunset,                {ArtifactClass::Minor,       ArtifactSlotType::Ring,         5000}},

    // Armor
    {Artifact::BreastplateOfPetrifiedWood,  {ArtifactClass::Treasure,    ArtifactSlotType::Armor,        1000}},
    {Artifact::RibCage,                     {ArtifactClass::Minor,       ArtifactSlotType::Armor,        3000}},
    {Artifact::ScalesOfTheGreaterBasilisk,  {ArtifactClass::Minor,       ArtifactSlotType::Armor,        4000}},
    {Artifact::TunicOfTheCyclopsKing,       {ArtifactClass::Major,       ArtifactSlotType::Armor,        5000}},
    {Artifact::BreastplateOfBrimstone,      {ArtifactClass::Major,       ArtifactSlotType::Armor,        6000}},
    {Artifact::ArmorOfWonder,               {ArtifactClass::Minor,       ArtifactSlotType::Armor,        4000}},
    {Artifact::DragonScaleArmor,            {ArtifactClass::Relic,       ArtifactSlotType::Armor,        8000}},
    {Artifact::TitansCuirass,               {ArtifactClass::Relic,       ArtifactSlotType::Armor,       10000}},
    {Artifact::RoyalArmorOfNix,             {ArtifactClass::Major,       ArtifactSlotType::Armor,        7000}},
    {Artifact::PlateOfDyingLight,           {ArtifactClass::Relic,       ArtifactSlotType::Armor,       10000}},

    // Combination Artifacts
    {Artifact::CloakOfTheUndeadKing,        {ArtifactClass::Combination, ArtifactSlotType::Combination, 12000}},
    {Artifact::DiplomatsCloak,              {ArtifactClass::Combination, ArtifactSlotType::Combination, 15000}},
    {Artifact::AdmiralsHat,                 {ArtifactClass::Combination, ArtifactSlotType::Combination, 25000}},
    {Artifact::WizardsWell,                 {ArtifactClass::Combination, ArtifactSlotType::Combination,  3000}},
    {Artifact::BowOfTheSharpshooter,        {ArtifactClass::Combination, ArtifactSlotType::Combination, 12000}},
    {Artifact::ElixirOfLife,                {ArtifactClass::Combination, ArtifactSlotType::Combination, 20000}},
    {Artifact::Cornucopia,                  {ArtifactClass::Combination, ArtifactSlotType::Combination, 20000}},
    {Artifact::StatueOfLegion,              {ArtifactClass::Combination, ArtifactSlotType::Combination, 25000}},
    {Artifact::GoldenGoose,                 {ArtifactClass::Combination, ArtifactSlotType::Combination, 22500}},
    {Artifact::PendantOfReflection,         {ArtifactClass::Combination, ArtifactSlotType::Combination, 12000}},
    {Artifact::TitansThunder,               {ArtifactClass::Combination, ArtifactSlotType::Combination, 40000}},
    {Artifact::AngelicAlliance,             {ArtifactClass::Combination, ArtifactSlotType::Combination, 84000}},
    {Artifact::IronfistOfTheOgre,           {ArtifactClass::Combination, ArtifactSlotType::Combination, 20000}},
    {Artifact::RingOfTheMagi,               {ArtifactClass::Combination, ArtifactSlotType::Combination,  3000}},
    {Artifact::ArmorOfTheDamned,            {ArtifactClass::Combination, ArtifactSlotType::Combination, 12000}},
    {Artifact::PowerOfTheDragonFather,      {ArtifactClass::Combination, ArtifactSlotType::Combination, 42000}},

    // Scrolls
    // TODO: Update values based on spell? See https://heroes.thelazy.net//index.php/Spell_scroll
    {Artifact::SpellScroll,                 {ArtifactClass::Other,       ArtifactSlotType::Misc,         2500}},

    // Dummies
    {Artifact::Catapult,                    {ArtifactClass::Other,       ArtifactSlotType::Catapult,        0}},
    {Artifact::Ballista,                    {ArtifactClass::Other,       ArtifactSlotType::Ballista,        0}},
    {Artifact::Cannon,                      {ArtifactClass::Other,       ArtifactSlotType::Ballista,        0}},
    {Artifact::FirstAidTent,                {ArtifactClass::Other,       ArtifactSlotType::FirstAidTent,    0}},
    {Artifact::AmmoCart,                    {ArtifactClass::Other,       ArtifactSlotType::AmmoCart,        0}},
    {Artifact::SpellBook,                   {ArtifactClass::Other,       ArtifactSlotType::SpellBook,       0}},
    {Artifact::Grail,                       {ArtifactClass::Other,       ArtifactSlotType::Misc,            0}},
};
} // namespace h3::artifacts
