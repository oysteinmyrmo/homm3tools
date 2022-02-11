#include <h3/creatures.h>
#include <h3/hero.h>
#include <h3/savefile.h>
#include <h3/stats.h>

#include <cassert>
#include <filesystem>

namespace  {
namespace fs = std::filesystem;

using h3::creatures::Creature;
using h3::hero::Hero;
using h3::hero::Orientation;
using h3::savefile::SaveFile;

void test_creature(const Hero &hero, const uint8_t idx, const Creature creature, const uint32_t count)
{
    assert(hero.creatures[idx] == creature);
    assert(hero.creature_count[idx] == count);
}
}

void test_day1(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Lord Haart");
    test_creature(hero, 0, Creature::Pikeman,   1);
    test_creature(hero, 1, Creature::Archer,    2);
    test_creature(hero, 2, Creature::Griffin,   3);
    test_creature(hero, 3, Creature::Swordsman, 4);
    test_creature(hero, 4, Creature::Monk,      5);
    test_creature(hero, 5, Creature::Cavalier,  6);
    test_creature(hero, 6, Creature::Angel,     7);
    assert(h3::stats::ai_value(hero) == 52884);

    hero = save.findHero("Sanya");
    test_creature(hero, 0, Creature::Halberdier,   1);
    test_creature(hero, 1, Creature::Marksman,     2);
    test_creature(hero, 2, Creature::RoyalGriffin, 3);
    test_creature(hero, 3, Creature::Crusader,     4);
    test_creature(hero, 4, Creature::Zealot,       5);
    test_creature(hero, 5, Creature::Champion,     6);
    test_creature(hero, 6, Creature::ArchAngel,    7);
    assert(h3::stats::ai_value(hero) == 81961);

    hero = save.findHero("Kyrre");
    test_creature(hero, 0, Creature::Centaur,       1);
    test_creature(hero, 1, Creature::Dwarf,         2);
    test_creature(hero, 2, Creature::WoodElf,       3);
    test_creature(hero, 3, Creature::Pegasus,       4);
    test_creature(hero, 4, Creature::DendroidGuard, 5);
    test_creature(hero, 5, Creature::Unicorn,       6);
    test_creature(hero, 6, Creature::GreenDragon,   7);
    assert(h3::stats::ai_value(hero) == 50675);

    hero = save.findHero("Elleshar");
    test_creature(hero, 0, Creature::CentaurCaptain,  1);
    test_creature(hero, 1, Creature::BattleDwarf,     2);
    test_creature(hero, 2, Creature::GrandElf,        3);
    test_creature(hero, 3, Creature::SilverPegasus,   4);
    test_creature(hero, 4, Creature::DendroidSoldier, 5);
    test_creature(hero, 5, Creature::WarUnicorn,      6);
    test_creature(hero, 6, Creature::GoldDragon,      7);
    assert(h3::stats::ai_value(hero) == 80163);

    hero = save.findHero("Piquedram");
    test_creature(hero, 0, Creature::Gremlin,       1);
    test_creature(hero, 1, Creature::StoneGargoyle, 2);
    test_creature(hero, 2, Creature::StoneGolem,    3);
    test_creature(hero, 3, Creature::Mage,          4);
    test_creature(hero, 4, Creature::Genie,         5);
    test_creature(hero, 5, Creature::Naga,          6);
    test_creature(hero, 6, Creature::Giant,         7);
    assert(h3::stats::ai_value(hero) == 45946);

    hero = save.findHero("Halon");
    test_creature(hero, 0, Creature::MasterGremlin,    1);
    test_creature(hero, 1, Creature::ObsidianGargoyle, 2);
    test_creature(hero, 2, Creature::IronGolem,        3);
    test_creature(hero, 3, Creature::ArchMage,         4);
    test_creature(hero, 4, Creature::MasterGenie,      5);
    test_creature(hero, 5, Creature::NagaQueen,        6);
    test_creature(hero, 6, Creature::Titan,            7);
    assert(h3::stats::ai_value(hero) == 78674);

    hero = save.findHero("Pyre");
    test_creature(hero, 0, Creature::Imp,       1);
    test_creature(hero, 1, Creature::Gog,       2);
    test_creature(hero, 2, Creature::HellHound, 3);
    test_creature(hero, 3, Creature::Demon,     4);
    test_creature(hero, 4, Creature::PitFiend,  5);
    test_creature(hero, 5, Creature::Efreeti,   6);
    test_creature(hero, 6, Creature::Devil,     7);
    assert(h3::stats::ai_value(hero) == 52771);

    hero = save.findHero("Calid");
    test_creature(hero, 0, Creature::Familiar,     1);
    test_creature(hero, 1, Creature::Magog,        2);
    test_creature(hero, 2, Creature::Cerberus,     3);
    test_creature(hero, 3, Creature::HornedDemon,  4);
    test_creature(hero, 4, Creature::PitLord,      5);
    test_creature(hero, 5, Creature::EfreetSultan, 6);
    test_creature(hero, 6, Creature::ArchDevil,    7);
    assert(h3::stats::ai_value(hero) == 73619);

    hero = save.findHero("Isra");
    test_creature(hero, 0, Creature::Skeleton,    1);
    test_creature(hero, 1, Creature::WalkingDead, 2);
    test_creature(hero, 2, Creature::Wight,       3);
    test_creature(hero, 3, Creature::Vampire,     4);
    test_creature(hero, 4, Creature::Lich,        5);
    test_creature(hero, 5, Creature::BlackKnight, 6);
    test_creature(hero, 6, Creature::BoneDragon,  7);
    assert(h3::stats::ai_value(hero) == 43710);

    hero = save.findHero("Vidomina");
    test_creature(hero, 0, Creature::SkeletonWarrior, 1);
    test_creature(hero, 1, Creature::Zombie,          2);
    test_creature(hero, 2, Creature::Wraith,          3);
    test_creature(hero, 3, Creature::VampireLord,     4);
    test_creature(hero, 4, Creature::PowerLich,       5);
    test_creature(hero, 5, Creature::DreadKnight,     6);
    test_creature(hero, 6, Creature::GhostDragon,     7);
    assert(h3::stats::ai_value(hero) == 56977);

    hero = save.findHero("Dace");
    test_creature(hero, 0, Creature::Troglodyte, 1);
    test_creature(hero, 1, Creature::Harpy,      2);
    test_creature(hero, 2, Creature::Beholder,   3);
    test_creature(hero, 3, Creature::Medusa,     4);
    test_creature(hero, 4, Creature::Minotaur,   5);
    test_creature(hero, 5, Creature::Manticore,  6);
    test_creature(hero, 6, Creature::RedDragon,  7);
    assert(h3::stats::ai_value(hero) == 49814);

    hero = save.findHero("Deemer");
    test_creature(hero, 0, Creature::InfernalTroglodyte, 1);
    test_creature(hero, 1, Creature::HarpyHag,           2);
    test_creature(hero, 2, Creature::EvilEye,            3);
    test_creature(hero, 3, Creature::MedusaQueen,        4);
    test_creature(hero, 4, Creature::MinotaurKing,       5);
    test_creature(hero, 5, Creature::Scorpicore,         6);
    test_creature(hero, 6, Creature::BlackDragon,        7);
    assert(h3::stats::ai_value(hero) == 79890);

    hero = save.findHero("Yog");
    test_creature(hero, 0, Creature::Goblin,    1);
    test_creature(hero, 1, Creature::WolfRider, 2);
    test_creature(hero, 2, Creature::Orc,       3);
    test_creature(hero, 3, Creature::Ogre,      4);
    test_creature(hero, 4, Creature::Roc,       5);
    test_creature(hero, 5, Creature::Cyclops,   6);
    test_creature(hero, 6, Creature::Behemoth,  7);
    assert(h3::stats::ai_value(hero) == 37425);

    hero = save.findHero("Saurug");
    test_creature(hero, 0, Creature::Hobgoblin,       1);
    test_creature(hero, 1, Creature::WolfRaider,      2);
    test_creature(hero, 2, Creature::OrcChieftain,    3);
    test_creature(hero, 3, Creature::OgreMage,        4);
    test_creature(hero, 4, Creature::Thunderbird,     5);
    test_creature(hero, 5, Creature::CyclopsKing,     6);
    test_creature(hero, 6, Creature::AncientBehemoth, 7);
    assert(h3::stats::ai_value(hero) == 61256);

    hero = save.findHero("Gerwulf");
    test_creature(hero, 0, Creature::Gnoll,      1);
    test_creature(hero, 1, Creature::Lizardman,  2);
    test_creature(hero, 2, Creature::SerpentFly, 3);
    test_creature(hero, 3, Creature::Basilisk,   4);
    test_creature(hero, 4, Creature::Gorgon,     5);
    test_creature(hero, 5, Creature::Wyvern,     6);
    test_creature(hero, 6, Creature::Hydra,      7);
    assert(h3::stats::ai_value(hero) == 44710);

    hero = save.findHero("Merist");
    test_creature(hero, 0, Creature::GnollMarauder,   1);
    test_creature(hero, 1, Creature::LizardWarrior,   2);
    test_creature(hero, 2, Creature::DragonFly,       3);
    test_creature(hero, 3, Creature::GreaterBasilisk, 4);
    test_creature(hero, 4, Creature::MightyGorgon,    5);
    test_creature(hero, 5, Creature::WyvernMonarch,   6);
    test_creature(hero, 6, Creature::ChaosHydra,      7);
    assert(h3::stats::ai_value(hero) == 59959);

    hero = save.findHero("Thunar");
    test_creature(hero, 0, Creature::Pixie,            1);
    test_creature(hero, 1, Creature::AirElemental,     2);
    test_creature(hero, 2, Creature::WaterElemental,   3);
    test_creature(hero, 3, Creature::FireElemental,    4);
    test_creature(hero, 4, Creature::EarthElemental,   5);
    test_creature(hero, 5, Creature::PsychicElemental, 6);
    test_creature(hero, 6, Creature::Firebird,         7);
    assert(h3::stats::ai_value(hero) == 45108);

    hero = save.findHero("Inteus");
    test_creature(hero, 0, Creature::Sprite,          1);
    test_creature(hero, 1, Creature::StormElemental,  2);
    test_creature(hero, 2, Creature::IceElemental,    3);
    test_creature(hero, 3, Creature::EnergyElemental, 4);
    test_creature(hero, 4, Creature::MagmaElemental,  5);
    test_creature(hero, 5, Creature::MagicElemental,  6);
    test_creature(hero, 6, Creature::Phoenix,         7);
    assert(h3::stats::ai_value(hero) == 65656);

    hero = save.findHero("Jeremy");
    test_creature(hero, 0, Creature::Nymph,      1);
    test_creature(hero, 1, Creature::CrewMate,   2);
    test_creature(hero, 2, Creature::Pirate,     3);
    test_creature(hero, 3, Creature::Stormbird,  4);
    test_creature(hero, 4, Creature::SeaWitch,   5);
    test_creature(hero, 5, Creature::Nix,        6);
    test_creature(hero, 6, Creature::SeaSerpent, 7);
    assert(h3::stats::ai_value(hero) == 43422);

    hero = save.findHero("Astra");
    test_creature(hero, 0, Creature::Oceanid,    1);
    test_creature(hero, 1, Creature::Seaman,     2);
    test_creature(hero, 2, Creature::Corsair,    3);
    test_creature(hero, 3, Creature::Ayssid,     4);
    test_creature(hero, 4, Creature::Sorceress,  5);
    test_creature(hero, 5, Creature::NixWarrior, 6);
    test_creature(hero, 6, Creature::Haspid,     7);
    assert(h3::stats::ai_value(hero) == 71720);

    hero = save.findHero("Dargem");
    test_creature(hero, 0, Creature::SeaDog, 1234);
    test_creature(hero, 1, Creature::Empty,     0);
    test_creature(hero, 2, Creature::Empty,     0);
    test_creature(hero, 3, Creature::Empty,     0);
    test_creature(hero, 4, Creature::Empty,     0);
    test_creature(hero, 5, Creature::Empty,     0);
    test_creature(hero, 6, Creature::Empty,     0);
    assert(h3::stats::ai_value(hero) == 742868);

    hero = save.findHero("Corkes");
    test_creature(hero, 0, Creature::Halfling,   1);
    test_creature(hero, 1, Creature::Peasant,    2);
    test_creature(hero, 2, Creature::Boar,       3);
    test_creature(hero, 3, Creature::Rogue,      4);
    test_creature(hero, 4, Creature::Leprechaun, 5);
    test_creature(hero, 5, Creature::Mummy,      6);
    test_creature(hero, 6, Creature::Nomad,      7);
    assert(h3::stats::ai_value(hero) == 6155);

    hero = save.findHero("Zilare");
    test_creature(hero, 0, Creature::Sharpshooter, 1);
    test_creature(hero, 1, Creature::Satyr,        2);
    test_creature(hero, 2, Creature::SteelGolem,   3);
    test_creature(hero, 3, Creature::GoldGolem,    4);
    test_creature(hero, 4, Creature::Troll,        5);
    test_creature(hero, 5, Creature::Fangarm,      6);
    test_creature(hero, 6, Creature::DiamondGolem, 7);
    assert(h3::stats::ai_value(hero) == 21931);

    hero = save.findHero("Spint");
    test_creature(hero, 0, Creature::Enchanter,     1);
    test_creature(hero, 1, Creature::AzureDragon,   2);
    test_creature(hero, 2, Creature::CrystalDragon, 3);
    test_creature(hero, 3, Creature::FaerieDragon,  4);
    test_creature(hero, 4, Creature::RustDragon,    5);
    test_creature(hero, 5, Creature::Empty,         0);
    test_creature(hero, 6, Creature::Empty,         0);
    assert(h3::stats::ai_value(hero) == 531083);
}

void test_day2(const SaveFile &save)
{
    assert(save.valid());

    Hero hero = save.findHero("Lord Haart");
    test_creature(hero, 0, Creature::Angel,     7);
    test_creature(hero, 1, Creature::Cavalier,  6);
    test_creature(hero, 2, Creature::Monk,      5);
    test_creature(hero, 3, Creature::Swordsman, 4);
    test_creature(hero, 4, Creature::Griffin,   3);
    test_creature(hero, 5, Creature::Archer,    2);
    test_creature(hero, 6, Creature::Pikeman,   1);
    assert(h3::stats::ai_value(hero) == 52884);

    hero = save.findHero("Sanya");
    test_creature(hero, 0, Creature::ArchAngel,    7);
    test_creature(hero, 1, Creature::Champion,     6);
    test_creature(hero, 2, Creature::Zealot,       5);
    test_creature(hero, 3, Creature::Crusader,     4);
    test_creature(hero, 4, Creature::RoyalGriffin, 3);
    test_creature(hero, 5, Creature::Marksman,     2);
    test_creature(hero, 6, Creature::Halberdier,   1);
    assert(h3::stats::ai_value(hero) == 81961);

    hero = save.findHero("Kyrre");
    test_creature(hero, 0, Creature::GreenDragon,   7);
    test_creature(hero, 1, Creature::Unicorn,       6);
    test_creature(hero, 2, Creature::DendroidGuard, 5);
    test_creature(hero, 3, Creature::Pegasus,       4);
    test_creature(hero, 4, Creature::WoodElf,       3);
    test_creature(hero, 5, Creature::Dwarf,         2);
    test_creature(hero, 6, Creature::Centaur,       1);
    assert(h3::stats::ai_value(hero) == 50675);

    hero = save.findHero("Elleshar");
    test_creature(hero, 0, Creature::GoldDragon,      7);
    test_creature(hero, 1, Creature::WarUnicorn,      6);
    test_creature(hero, 2, Creature::DendroidSoldier, 5);
    test_creature(hero, 3, Creature::SilverPegasus,   4);
    test_creature(hero, 4, Creature::GrandElf,        3);
    test_creature(hero, 5, Creature::BattleDwarf,     2);
    test_creature(hero, 6, Creature::CentaurCaptain,  1);
    assert(h3::stats::ai_value(hero) == 80163);

    hero = save.findHero("Piquedram");
    test_creature(hero, 0, Creature::Giant,         7);
    test_creature(hero, 1, Creature::Naga,          6);
    test_creature(hero, 2, Creature::Genie,         5);
    test_creature(hero, 3, Creature::Mage,          4);
    test_creature(hero, 4, Creature::StoneGolem,    3);
    test_creature(hero, 5, Creature::StoneGargoyle, 2);
    test_creature(hero, 6, Creature::Gremlin,       1);

    hero = save.findHero("Halon");
    test_creature(hero, 0, Creature::Titan,            7);
    test_creature(hero, 1, Creature::NagaQueen,        6);
    test_creature(hero, 2, Creature::MasterGenie,      5);
    test_creature(hero, 3, Creature::ArchMage,         4);
    test_creature(hero, 4, Creature::IronGolem,        3);
    test_creature(hero, 5, Creature::ObsidianGargoyle, 2);
    test_creature(hero, 6, Creature::MasterGremlin,    1);
    assert(h3::stats::ai_value(hero) == 78674);

    hero = save.findHero("Pyre");
    test_creature(hero, 0, Creature::Devil,     7);
    test_creature(hero, 1, Creature::Efreeti,   6);
    test_creature(hero, 2, Creature::PitFiend,  5);
    test_creature(hero, 3, Creature::Demon,     4);
    test_creature(hero, 4, Creature::HellHound, 3);
    test_creature(hero, 5, Creature::Gog,       2);
    test_creature(hero, 6, Creature::Imp,       1);
    assert(h3::stats::ai_value(hero) == 52771);

    hero = save.findHero("Calid");
    test_creature(hero, 0, Creature::ArchDevil,    7);
    test_creature(hero, 1, Creature::EfreetSultan, 6);
    test_creature(hero, 2, Creature::PitLord,      5);
    test_creature(hero, 3, Creature::HornedDemon,  4);
    test_creature(hero, 4, Creature::Cerberus,     3);
    test_creature(hero, 5, Creature::Magog,        2);
    test_creature(hero, 6, Creature::Familiar,     1);
    assert(h3::stats::ai_value(hero) == 73619);

    hero = save.findHero("Isra");
    test_creature(hero, 0, Creature::BoneDragon,  7);
    test_creature(hero, 1, Creature::BlackKnight, 6);
    test_creature(hero, 2, Creature::Lich,        5);
    test_creature(hero, 3, Creature::Vampire,     4);
    test_creature(hero, 4, Creature::Wight,       3);
    test_creature(hero, 5, Creature::WalkingDead, 2);
    test_creature(hero, 6, Creature::Skeleton,    1);
    assert(h3::stats::ai_value(hero) == 43710);

    hero = save.findHero("Vidomina");
    test_creature(hero, 0, Creature::GhostDragon,     7);
    test_creature(hero, 1, Creature::DreadKnight,     6);
    test_creature(hero, 2, Creature::PowerLich,       5);
    test_creature(hero, 3, Creature::VampireLord,     4);
    test_creature(hero, 4, Creature::Wraith,          3);
    test_creature(hero, 5, Creature::Zombie,          2);
    test_creature(hero, 6, Creature::SkeletonWarrior, 1);
    assert(h3::stats::ai_value(hero) == 56977);

    hero = save.findHero("Dace");
    test_creature(hero, 0, Creature::RedDragon,  7);
    test_creature(hero, 1, Creature::Manticore,  6);
    test_creature(hero, 2, Creature::Minotaur,   5);
    test_creature(hero, 3, Creature::Medusa,     4);
    test_creature(hero, 4, Creature::Beholder,   3);
    test_creature(hero, 5, Creature::Harpy,      2);
    test_creature(hero, 6, Creature::Troglodyte, 1);
    assert(h3::stats::ai_value(hero) == 49814);

    hero = save.findHero("Deemer");
    test_creature(hero, 0, Creature::BlackDragon,        7);
    test_creature(hero, 1, Creature::Scorpicore,         6);
    test_creature(hero, 2, Creature::MinotaurKing,       5);
    test_creature(hero, 3, Creature::MedusaQueen,        4);
    test_creature(hero, 4, Creature::EvilEye,            3);
    test_creature(hero, 5, Creature::HarpyHag,           2);
    test_creature(hero, 6, Creature::InfernalTroglodyte, 1);
    assert(h3::stats::ai_value(hero) == 79890);

    hero = save.findHero("Yog");
    test_creature(hero, 0, Creature::Behemoth,  7);
    test_creature(hero, 1, Creature::Cyclops,   6);
    test_creature(hero, 2, Creature::Roc,       5);
    test_creature(hero, 3, Creature::Ogre,      4);
    test_creature(hero, 4, Creature::Orc,       3);
    test_creature(hero, 5, Creature::WolfRider, 2);
    test_creature(hero, 6, Creature::Goblin,    1);
    assert(h3::stats::ai_value(hero) == 37425);

    hero = save.findHero("Saurug");
    test_creature(hero, 0, Creature::AncientBehemoth, 7);
    test_creature(hero, 1, Creature::CyclopsKing,     6);
    test_creature(hero, 2, Creature::Thunderbird,     5);
    test_creature(hero, 3, Creature::OgreMage,        4);
    test_creature(hero, 4, Creature::OrcChieftain,    3);
    test_creature(hero, 5, Creature::WolfRaider,      2);
    test_creature(hero, 6, Creature::Hobgoblin,       1);
    assert(h3::stats::ai_value(hero) == 61256);

    hero = save.findHero("Gerwulf");
    test_creature(hero, 0, Creature::Hydra,      7);
    test_creature(hero, 1, Creature::Wyvern,     6);
    test_creature(hero, 2, Creature::Gorgon,     5);
    test_creature(hero, 3, Creature::Basilisk,   4);
    test_creature(hero, 4, Creature::SerpentFly, 3);
    test_creature(hero, 5, Creature::Lizardman,  2);
    test_creature(hero, 6, Creature::Gnoll,      1);
    assert(h3::stats::ai_value(hero) == 44710);

    hero = save.findHero("Merist");
    test_creature(hero, 0, Creature::ChaosHydra,      7);
    test_creature(hero, 1, Creature::WyvernMonarch,   6);
    test_creature(hero, 2, Creature::MightyGorgon,    5);
    test_creature(hero, 3, Creature::GreaterBasilisk, 4);
    test_creature(hero, 4, Creature::DragonFly,       3);
    test_creature(hero, 5, Creature::LizardWarrior,   2);
    test_creature(hero, 6, Creature::GnollMarauder,   1);
    assert(h3::stats::ai_value(hero) == 59959);

    hero = save.findHero("Thunar");
    test_creature(hero, 0, Creature::Firebird,         7);
    test_creature(hero, 1, Creature::PsychicElemental, 6);
    test_creature(hero, 2, Creature::EarthElemental,   5);
    test_creature(hero, 3, Creature::FireElemental,    4);
    test_creature(hero, 4, Creature::WaterElemental,   3);
    test_creature(hero, 5, Creature::AirElemental,     2);
    test_creature(hero, 6, Creature::Pixie,            1);
    assert(h3::stats::ai_value(hero) == 45108);

    hero = save.findHero("Inteus");
    test_creature(hero, 0, Creature::Phoenix,         7);
    test_creature(hero, 1, Creature::MagicElemental,  6);
    test_creature(hero, 2, Creature::MagmaElemental,  5);
    test_creature(hero, 3, Creature::EnergyElemental, 4);
    test_creature(hero, 4, Creature::IceElemental,    3);
    test_creature(hero, 5, Creature::StormElemental,  2);
    test_creature(hero, 6, Creature::Sprite,          1);
    assert(h3::stats::ai_value(hero) == 65656);

    hero = save.findHero("Jeremy");
    test_creature(hero, 0, Creature::SeaSerpent, 7);
    test_creature(hero, 1, Creature::Nix,        6);
    test_creature(hero, 2, Creature::SeaWitch,   5);
    test_creature(hero, 3, Creature::Stormbird,  4);
    test_creature(hero, 4, Creature::Pirate,     3);
    test_creature(hero, 5, Creature::CrewMate,   2);
    test_creature(hero, 6, Creature::Nymph,      1);
    assert(h3::stats::ai_value(hero) == 43422);

    hero = save.findHero("Astra");
    test_creature(hero, 0, Creature::Haspid,     7);
    test_creature(hero, 1, Creature::NixWarrior, 6);
    test_creature(hero, 2, Creature::Sorceress,  5);
    test_creature(hero, 3, Creature::Ayssid,     4);
    test_creature(hero, 4, Creature::Corsair,    3);
    test_creature(hero, 5, Creature::Seaman,     2);
    test_creature(hero, 6, Creature::Oceanid,    1);
    assert(h3::stats::ai_value(hero) == 71720);

    hero = save.findHero("Dargem");
    test_creature(hero, 0, Creature::SeaDog, 617);
    test_creature(hero, 1, Creature::SeaDog, 617);
    test_creature(hero, 2, Creature::Empty,    0);
    test_creature(hero, 3, Creature::Empty,    0);
    test_creature(hero, 4, Creature::Empty,    0);
    test_creature(hero, 5, Creature::Empty,    0);
    test_creature(hero, 6, Creature::Empty,    0);
    assert(h3::stats::ai_value(hero) == 742868);

    hero = save.findHero("Corkes");
    test_creature(hero, 0, Creature::Nomad,      7);
    test_creature(hero, 1, Creature::Mummy,      6);
    test_creature(hero, 2, Creature::Leprechaun, 5);
    test_creature(hero, 3, Creature::Rogue,      4);
    test_creature(hero, 4, Creature::Boar,       3);
    test_creature(hero, 5, Creature::Peasant,    2);
    test_creature(hero, 6, Creature::Halfling,   1);
    assert(h3::stats::ai_value(hero) == 6155);

    hero = save.findHero("Zilare");
    test_creature(hero, 0, Creature::DiamondGolem, 7);
    test_creature(hero, 1, Creature::Fangarm,      6);
    test_creature(hero, 2, Creature::Troll,        5);
    test_creature(hero, 3, Creature::GoldGolem,    4);
    test_creature(hero, 4, Creature::SteelGolem,   3);
    test_creature(hero, 5, Creature::Satyr,        2);
    test_creature(hero, 6, Creature::Sharpshooter, 1);
    assert(h3::stats::ai_value(hero) == 21931);

    hero = save.findHero("Spint");
    test_creature(hero, 0, Creature::RustDragon,    5);
    test_creature(hero, 1, Creature::FaerieDragon,  4);
    test_creature(hero, 2, Creature::CrystalDragon, 3);
    test_creature(hero, 3, Creature::AzureDragon,   2);
    test_creature(hero, 4, Creature::Enchanter,     1);
    test_creature(hero, 5, Creature::Empty,         0);
    test_creature(hero, 6, Creature::Empty,         0);
    assert(h3::stats::ai_value(hero) == 531083);
}

int main()
{
    // Test data is copied relative to executable in output/binary dir.
    fs::path testDataDir("../test_data");
    fs::path dir(testDataDir / "creatures");

    h3::savefile::SaveFile day1(dir / "[hotseat] 111.GM8");
    h3::savefile::SaveFile day2(dir / "[hotseat] 112.GM8");

    test_day1(day1);
    test_day2(day2);

    return 0;
}
