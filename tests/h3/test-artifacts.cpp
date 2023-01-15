#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3/artifacts.h>
#include <h3/hero.h>
#include <h3/savefile.h>

#include <filesystem>

namespace
{
using h3::Artifact;
using h3::ArtifactSlot;
using h3::Hero;
using h3::SaveFile;

std::filesystem::path testDataDir(h3::test::testDataDir / "artifacts");

void verifyNoArtifacts(const Hero &hero)
{
    REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
    REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
    REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
    REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
    REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
    REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
    REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
    REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
    REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
    REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
    REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
    REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
    REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
    REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);
    REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
}

void verifyCatapultOnly(const Hero &hero)
{
    REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
    REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
    REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
    REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
    REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);
}

void verifyCatapultAndSpellBook(const Hero &hero)
{
    REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
    REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
    REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
    REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
    REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);
}
} // namespace

TEST_CASE("artifacts-day1", "[hero][artifact]")
{
    SaveFile save({testDataDir / "[hotseat] 111.GM8"});
    REQUIRE(save.valid());

    {
        const Hero hero = save.findHero("Orrin");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Mephala");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Piquedram");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Fiona");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Valeska");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Ufretin");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Thane");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Jeremy");
        verifyNoArtifacts(hero);
        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Cannon);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Edric");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Clancy");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Josephine");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Sylvia");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Jenova");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Neela");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Lord Haart");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Ryland");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        // NOTE! "Torosar" is saved as "Torosar " in the save file.
        const Hero hero = save.findHero("Torosar ");
        verifyNoArtifacts(hero);
        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);
    }

    {
        const Hero hero = save.findHero("Sorsha");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Ivor");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Fafner");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Tyris");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Kyrre");
        verifyNoArtifacts(hero);
        verifyCatapultOnly(hero);
    }

    {
        const Hero hero = save.findHero("Rissa");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Christian");
        verifyNoArtifacts(hero);
        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Iona");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Giselle");
        verifyNoArtifacts(hero);
        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);
    }
}

TEST_CASE("artifacts-day2", "[hero][artifact]")
{
    SaveFile save({testDataDir / "[hotseat] 112.GM8"});
    REQUIRE(save.valid());

    {
        const Hero hero = save.findHero("Orrin");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::AdmiralsHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Admiral's Hat
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::BowOfTheSharpshooter);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::Cornucopia);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::IronfistOfTheOgre);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::GoldenGoose);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::WizardsWell);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::RingOfTheMagi);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::DiplomatsCloak);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::PendantOfReflection);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory07) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Mephala");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::CrownOfTheSupremeMagi);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::CapeOfVelocity);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NecklaceOfSwiftness);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::OgresClubOfHavoc);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::TargOfTheRampagingOgre);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::TunicOfTheCyclopsKing);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfOblivion);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::BootsOfSpeed);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::CapeOfSilence);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Piquedram");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::AmbassadorsSash);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::StatesmansMedal);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::DiplomatsRing);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::RingOfTheWayfarer);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::EquestriansGloves);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Fiona");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::SurcoatOfCounterpoise);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::GarnitureOfInterference);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::BootsOfPolarity);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Valeska");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::CloakOfTheUndeadKing);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Cloak of the Undead King
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::ArmageddonsBlade);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Cloak of the Undead King
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::VialOfDragonBlood);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::HornOfTheAbyss);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::ElixirOfLife);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::StatueOfLegion);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::AngelicAlliance);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::ArmorOfTheDamned);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::PowerOfTheDragonFather);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::TitansThunder);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Ufretin");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HellstormHelmet);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfNegativity);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::SwordOfHellfire);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfTheDamned);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::BreastplateOfBrimstone);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfInfiniteGems);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::EversmokingRingOfSulfur);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::EverpouringVialOfMercury);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::InexhaustibleCartOfOre);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfDispassion);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Thane");
        verifyNoArtifacts(hero);
        verifyCatapultAndSpellBook(hero);
    }

    {
        const Hero hero = save.findHero("Jeremy");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Cannon);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::AmmoCart);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::FirstAidTent);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Edric");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::SpellbindersHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::CapeOfConjuring);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::CollarOfConjuring);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfConjuring);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::OrbOfFirmament);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::OrbOfSilt);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::OrbOfTempestuousFire);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::OrbOfDrivingRain);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Clancy");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::CrownOfTheFiveSeas);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfSecondSight);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::TridentOfDominion);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfNavalGlory);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::RoyalArmorOfNix);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::EndlessSackOfGold);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::EndlessBagOfGold);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::EndlessPurseOfGold);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfTotalRecall);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Josephine");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::SummonAirElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::AirShield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::AnimateDead);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::AntiMagic);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::Armageddon);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Berserk);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Bless);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::Blind);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Bloodlust);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::ChainLightning);
    }

    {
        const Hero hero = save.findHero("Sylvia");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::SeaCaptainsHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::AngelWings);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NecklaceOfOceanGuidance);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::PlateOfDyingLight);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::SealOfSunset);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::CharmOfMana);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::TalismanOfMana);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::MysticOrbOfMana);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ShacklesOfWar);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::CharmOfEclipse);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Jenova");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::ThunderHelmet);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfHoliness);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::TitansGladius);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::SentinelsShield);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::TitansCuirass);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::LegsOfLegion);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::LoinsOfLegion);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::TorsoOfLegion);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ArmsOfLegion);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfCourage);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Neela");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::Clone);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Counterstrike);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Cure);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Curse);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::DeathRipple);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::DestroyUndead);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::DimensionDoor);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::Disguise);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Dispel);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::DisruptingRay);
    }

    {
        const Hero hero = save.findHero("Lord Haart");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HelmOfTheAlabasterUnicorn);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::RecantersCloak);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::CentaursAxe);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfTheDwarvenLords);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::BreastplateOfPetrifiedWood);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpiritOfOpression);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::HourglassOfTheEvilHour);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Ryland");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HelmOfHeavenlyEnlightenment);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::CelestialNecklaceOfBliss);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::SwordOfJudgement);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::LionsShieldOfCourage);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::ArmorOfWonder);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::SandalsOfTheSaint);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::OrbOfInhibition);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::RunesOfImminency);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::DemonsHorseshoe);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ShamansPuppet);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // NOTE! "Torosar" is saved as "Torosar " in the save file.
        const Hero hero = save.findHero("Torosar ");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::SummonEarthElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Earthquake);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::SummonFireElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::FireShield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::FireWall);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Fireball);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Fly);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::ForceField);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Forgetfulness);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::Fortune);
    }

    {
        const Hero hero = save.findHero("Sorsha");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::SkullHelmet);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::BlackshardOfTheDeadKnight);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfTheYawningDead);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::RibCage);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::BootsOfLevitation);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::TomeOfFireMagic);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::TomeOfAirMagic);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::TomeOfWaterMagic);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::TomeOfEarthMagic);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Ivor");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::CrownOfDragonTooth);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::DragonWingTabard);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NecklaceOfDragonteeth);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::RedDragonFlameTongue);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::DragonScaleShield);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::DragonScaleArmor);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::QuietEyeOfTheDragon);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::StillEyeOfTheDragon);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::DragonboneGreaves);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Fafner");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::Frenzy);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::FrostRing);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Haste);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Hypnotize);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::IceBolt);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Implosion);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Inferno);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::LandMine);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::LightningBolt);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::MagicArrow);
    }

    {
        const Hero hero = save.findHero("Tyris");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::SummonBoat);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Teleport);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::TownPortal);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::ViewAir);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::ViewEarth);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Visions);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::SummonWaterElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::WaterWalk);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Weakness);
    }

    {
        const Hero hero = save.findHero("Kyrre");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfLife);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::CloverOfFortune);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::CardsOfProphecy);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::LadybirdOfLuck);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::BadgeOfCourage);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::CrestOfValor);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::GlyphOfGallantry);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::Speculum);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::Spyglass);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::PendantOfDeath);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::PendantOfFreeWill);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Rissa");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::MagicMirror);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::MeteorShower);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Mirth);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Misfortune);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::Prayer);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Precision);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::ProtectionFromEarth);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::ProtectionFromWater);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::ProtectionFromAir);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::ProtectionFromFire);
    }

    {
        const Hero hero = save.findHero("Christian");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HelmOfChaos);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::GreaterGnollsFlail);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::BucklerOfTheGnollKing);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::ScalesOfTheGreaterBasilisk);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfVitality);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::RingOfLife);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::GoldenBow);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SphereOfPermanence);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::OrbOfVulnerability);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::VialOfLifeblooed);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Iona");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::Quicksand);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::RemoveObstacle);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Resurrection);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Sacrifice);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::ScuttleBoat);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Shield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Slayer);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::Slow);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Sorrow);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::StoneSkin);
    }

    {
        const Hero hero = save.findHero("Giselle");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::VampiresCowl);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::AmuletOfTheUndertaker);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::DeadMansBoots);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::BowOfElvenCherryWood);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::BowstringOfTheUnicornsMane);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::AngelFeatherArrows);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::BirdOfPerception);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::StoicWatchman);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::EmblemOfCognizance);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }
}

// Same as day 2, but with some minor differences.
TEST_CASE("artifacts-day3", "[hero][artifact]")
{
    SaveFile save({testDataDir / "[hotseat] 113.GM8"});
    REQUIRE(save.valid());

    {
        const Hero hero = save.findHero("Orrin");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::AdmiralsHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Admiral's Hat
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::BowOfTheSharpshooter);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::Cornucopia);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        // Diplomat's Cloak and Ring of the Magi are swapped. The inventory is also shuffled/scrolled
        // so that the artifact in the first slot is noe Wizards Well.
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::WizardsWell);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::DiplomatsCloak); // Swapped
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::RingOfTheMagi);  // Swapped
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::PendantOfReflection);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::IronfistOfTheOgre);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::GoldenGoose);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory07) == Artifact::NONE);
    }

    {
        // AssemblesIronfist of the Ogre.
        const Hero hero = save.findHero("Mephala");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Ironfist of the Ogre
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::CapeOfSilence); // Swapped
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NecklaceOfSwiftness);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::IronfistOfTheOgre);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Ironfist of the Ogre
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE); // Blocked by Ironfist of the Ogre
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfOblivion);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::BootsOfSpeed);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::CapeOfVelocity); // Swapped
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // Assemble Diplomat's Cloak.
        const Hero hero = save.findHero("Piquedram");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::DiplomatsCloak);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Diplomat's Cloak
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Diplomat's Cloak
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::RingOfTheWayfarer);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::EquestriansGloves);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Fiona");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Pendant of Reflection
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfReflection);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Pendant of Reflection
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Valeska");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::CloakOfTheUndeadKing);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Cloak of the Undead King
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::ArmageddonsBlade);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Cloak of the Undead King
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::VialOfDragonBlood);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::HornOfTheAbyss);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::ElixirOfLife);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        // Inventory01 was moved to Inventory05.
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::AngelicAlliance);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::ArmorOfTheDamned);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::PowerOfTheDragonFather);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::TitansThunder);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::StatueOfLegion); // Moved from Inventory01
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);
    }

    {
        // Swap neck slot item.
        const Hero hero = save.findHero("Ufretin");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HellstormHelmet);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfDispassion); // Swapped
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::SwordOfHellfire);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfTheDamned);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::BreastplateOfBrimstone);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfInfiniteGems);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::EversmokingRingOfSulfur);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::EverpouringVialOfMercury);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::InexhaustibleCartOfOre);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfNegativity); // Swapped
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // Thane now has the Grail.
        const Hero hero = save.findHero("Thane");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::Grail);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Jeremy");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Cannon);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::AmmoCart);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::FirstAidTent);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // Assemble Ring of the Magi.
        const Hero hero = save.findHero("Edric");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::SpellbindersHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Ring of the Magi
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Ring of the Magi
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfTheMagi);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::OrbOfFirmament);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::OrbOfSilt);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::OrbOfTempestuousFire);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::OrbOfDrivingRain);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // Assemble Golden Goose.
        const Hero hero = save.findHero("Clancy");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::CrownOfTheFiveSeas);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfSecondSight);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::TridentOfDominion);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfNavalGlory);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::RoyalArmorOfNix);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::GoldenGoose);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE); // Blocked by Golden Goose
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE); // Blocked by Golden Goose
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfTotalRecall);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // Swap Bless and Air Shield, put Air Shield in inventory04
        const Hero hero = save.findHero("Josephine");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::SummonAirElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Bless); // Swapped
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::AnimateDead);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::AntiMagic);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::Armageddon);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Berserk);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Blind);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::Bloodlust);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::AirShield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::ChainLightning);
    }

    {
        // Assemble Wizard's Well.
        const Hero hero = save.findHero("Sylvia");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::SeaCaptainsHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::AngelWings);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NecklaceOfOceanGuidance);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::PlateOfDyingLight);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::SealOfSunset);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::WizardsWell);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE); // Blocked by Wizard's Well
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE); // Blocked by Wizard's Well
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ShacklesOfWar);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::CharmOfEclipse);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // Add Head of Legion to Misc05
        // Add Wayfarer's Boots to Boots
        const Hero hero = save.findHero("Jenova");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::ThunderHelmet);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfHoliness);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::TitansGladius);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::SentinelsShield);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::TitansCuirass);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::WayfarersBoots);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::LegsOfLegion);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::LoinsOfLegion);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::TorsoOfLegion);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ArmsOfLegion);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::HeadOfLegion);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfCourage);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Neela");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::Clone);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Counterstrike);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Cure);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Curse);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::DeathRipple);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::DestroyUndead);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::DimensionDoor);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::Disguise);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Dispel);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::DisruptingRay);
    }

    {
        const Hero hero = save.findHero("Lord Haart");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HelmOfTheAlabasterUnicorn);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::RecantersCloak);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::CentaursAxe);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Moved shield to inventory.
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::BreastplateOfPetrifiedWood);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpiritOfOpression);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::HourglassOfTheEvilHour);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::ShieldOfTheDwarvenLords);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // Assemble Angelic Alliance.
        const Hero hero = save.findHero("Ryland");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::AngelicAlliance);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::OrbOfInhibition);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::RunesOfImminency);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::DemonsHorseshoe);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ShamansPuppet);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // NOTE! "Torosar" is saved as "Torosar " in the save file.
        // No changes.
        const Hero hero = save.findHero("Torosar ");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::SummonEarthElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Earthquake);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::SummonFireElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::FireShield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::FireWall);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Fireball);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Fly);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::ForceField);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Forgetfulness);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::Fortune);
    }

    {
        // Assemble Armor of the Damned.
        const Hero hero = save.findHero("Sorsha");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Armor of the Damned
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE); // Blocked by Armor of the Damned
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Armor of the Damned
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::ArmorOfTheDamned);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::BootsOfLevitation);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::TomeOfFireMagic);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::TomeOfAirMagic);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::TomeOfWaterMagic);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::TomeOfEarthMagic);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        const Hero hero = save.findHero("Ivor");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::PowerOfTheDragonFather);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Fafner");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::Frenzy);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::FrostRing);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Haste);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Hypnotize);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::IceBolt);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Implosion);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Inferno);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::LandMine);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::LightningBolt);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::MagicArrow);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Tyris");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::SummonBoat);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Teleport);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::TownPortal);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::ViewAir);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::ViewEarth);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Visions);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::SummonWaterElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::WaterWalk);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Weakness);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Kyrre");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfLife);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::CloverOfFortune);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::CardsOfProphecy);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::LadybirdOfLuck);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::BadgeOfCourage);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::CrestOfValor);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::GlyphOfGallantry);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::Speculum);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::Spyglass);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::PendantOfDeath);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::PendantOfFreeWill);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Rissa");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::MagicMirror);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::MeteorShower);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Mirth);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Misfortune);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::Prayer);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Precision);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::ProtectionFromEarth);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::ProtectionFromWater);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::ProtectionFromAir);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::ProtectionFromFire);
    }

    {
        // Asemble Elixir of Life.
        const Hero hero = save.findHero("Christian");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HelmOfChaos);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::GreaterGnollsFlail);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::BucklerOfTheGnollKing);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::ScalesOfTheGreaterBasilisk);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::GoldenBow);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SphereOfPermanence);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::OrbOfVulnerability);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ElixirOfLife);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Iona");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::Quicksand);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::RemoveObstacle);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Resurrection);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Sacrifice);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::ScuttleBoat);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::SpellScroll);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Shield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Slayer);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::Slow);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Sorrow);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::StoneSkin);
    }

    {
        // Assemble Bow of the Sharpshooter.
        const Hero hero = save.findHero("Giselle");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::VampiresCowl);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::AmuletOfTheUndertaker);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::DeadMansBoots);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::BowOfTheSharpshooter);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::BirdOfPerception);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::StoicWatchman);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::EmblemOfCognizance);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }
}

// Same as day 3, but with some minor differences.
TEST_CASE("artifacts-day4", "[hero][artifact]")
{
    SaveFile save({testDataDir / "[hotseat] 114.GM8"});
    REQUIRE(save.valid());

    {
        // No changes.
        const Hero hero = save.findHero("Orrin");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::AdmiralsHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Admiral's Hat
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Cornucopia
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::BowOfTheSharpshooter);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::Cornucopia);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        // Diplomat's Cloak and Ring of the Magi are swapped. The inventory is also shuffled/scrolled
        // so that the artifact in the first slot is noe Wizards Well.
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::WizardsWell);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::DiplomatsCloak); // Swapped
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::RingOfTheMagi);  // Swapped
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::PendantOfReflection);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::IronfistOfTheOgre);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::GoldenGoose);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory07) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Mephala");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Ironfist of the Ogre
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::CapeOfSilence); // Swapped
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NecklaceOfSwiftness);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::IronfistOfTheOgre);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Ironfist of the Ogre
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE); // Blocked by Ironfist of the Ogre
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfOblivion);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::BootsOfSpeed);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::CapeOfVelocity); // Swapped
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Piquedram");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::DiplomatsCloak);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Diplomat's Cloak
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Diplomat's Cloak
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::RingOfTheWayfarer);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::EquestriansGloves);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Fiona");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Pendant of Reflection
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfReflection);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Pendant of Reflection
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Valeska");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::CloakOfTheUndeadKing);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Cloak of the Undead King
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::ArmageddonsBlade);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Cloak of the Undead King
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::VialOfDragonBlood);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::HornOfTheAbyss);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::ElixirOfLife);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        // Inventory01 was moved to Inventory05.
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::AngelicAlliance);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::ArmorOfTheDamned);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::PowerOfTheDragonFather);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::TitansThunder);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::StatueOfLegion); // Moved from Inventory01
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);
    }

    {
        // Pick up two more artifacts.
        const Hero hero = save.findHero("Ufretin");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HellstormHelmet);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::EverflowingCrystalCloak); // Added
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfDispassion);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::SwordOfHellfire);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfTheDamned);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::BreastplateOfBrimstone);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfInfiniteGems);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::EversmokingRingOfSulfur);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::EverpouringVialOfMercury);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::InexhaustibleCartOfOre);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::InexhaustibleCartOfLumber); // Added
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfNegativity);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Thane");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::Grail);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Jeremy");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Cannon);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::AmmoCart);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::FirstAidTent);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Edric");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::SpellbindersHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Ring of the Magi
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Ring of the Magi
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfTheMagi);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::OrbOfFirmament);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::OrbOfSilt);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::OrbOfTempestuousFire);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::OrbOfDrivingRain);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Clancy");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::CrownOfTheFiveSeas);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfSecondSight);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::TridentOfDominion);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::ShieldOfNavalGlory);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::RoyalArmorOfNix);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::GoldenGoose);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE); // Blocked by Golden Goose
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE); // Blocked by Golden Goose
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfTotalRecall);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // Josephine was defeated.
        const Hero hero = save.findHero("Josephine");
        REQUIRE(hero.player == 0xFF);
        REQUIRE(hero.on_map == 0);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Sylvia");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::SeaCaptainsHat);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::AngelWings);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NecklaceOfOceanGuidance);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::PlateOfDyingLight);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::SealOfSunset);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::WizardsWell);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE); // Blocked by Wizard's Well
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE); // Blocked by Wizard's Well
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ShacklesOfWar);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::CharmOfEclipse);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // - Assemble Statue of Legion
        // - Assemble Titan's Thunder. This gives Jenova a spell book (!).
        // - Gives Pendant of Courage to Neela, who is now full of scrolls. The pendant disappears!
        const Hero hero = save.findHero("Jenova");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Titan's Thunder
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfHoliness);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::TitansThunder);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Titan's Thunder
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE); // Blocked by Titan's Thunder
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::WayfarersBoots);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::StatueOfLegion);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE); // Blocked by Statue of Legion
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE); // Blocked by Statue of Legion
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE); // Blocked by Statue of Legion
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE); // Blocked by Statue of Legion

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook); // Spell Book gained by assembling Titan's Thunder!

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // Neela used her Armorer skill to kill off all other heroes with scrolls.
        // She now posesses all 69 scrolls, filling up the entire inventory.
        // Any artifacts gained after this is therefore lost.
        const Hero hero = save.findHero("Neela");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::SpellScroll);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::SpellScroll);

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc01) == h3::Spell::Clone);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc02) == h3::Spell::Counterstrike);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc03) == h3::Spell::Cure);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc04) == h3::Spell::Curse);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Misc05) == h3::Spell::DeathRipple);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::SpellBook);

        // Loop through all inventory items and verify that they are scrolls.
        const uint8_t start = static_cast<uint8_t>(ArtifactSlot::Inventory01);
        for (uint8_t i = start; i < start + 64; ++i)
        {
            REQUIRE(h3::artifacts::artifact(hero, i) == Artifact::SpellScroll);
        }

        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory01) == h3::Spell::Blind);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory02) == h3::Spell::Berserk);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory03) == h3::Spell::SummonEarthElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory04) == h3::Spell::Earthquake);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory05) == h3::Spell::SummonFireElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory06) == h3::Spell::FireShield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory07) == h3::Spell::FireWall);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory08) == h3::Spell::Fortune);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory09) == h3::Spell::Forgetfulness);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory10) == h3::Spell::ForceField);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory11) == h3::Spell::Fly);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory12) == h3::Spell::Fireball);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory13) == h3::Spell::Frenzy);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory14) == h3::Spell::FrostRing);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory15) == h3::Spell::Haste);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory16) == h3::Spell::Hypnotize);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory17) == h3::Spell::IceBolt);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory18) == h3::Spell::MagicArrow);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory19) == h3::Spell::LightningBolt);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory20) == h3::Spell::LandMine);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory21) == h3::Spell::Inferno);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory22) == h3::Spell::Implosion);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory23) == h3::Spell::MagicMirror);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory24) == h3::Spell::MeteorShower);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory25) == h3::Spell::Mirth);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory26) == h3::Spell::Misfortune);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory27) == h3::Spell::Prayer);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory28) == h3::Spell::ProtectionFromFire);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory29) == h3::Spell::ProtectionFromAir);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory30) == h3::Spell::ProtectionFromWater);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory31) == h3::Spell::ProtectionFromEarth);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory32) == h3::Spell::Precision);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory33) == h3::Spell::Quicksand);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory34) == h3::Spell::RemoveObstacle);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory35) == h3::Spell::Resurrection);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory36) == h3::Spell::Sacrifice);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory37) == h3::Spell::ScuttleBoat);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory38) == h3::Spell::StoneSkin);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory39) == h3::Spell::Sorrow);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory40) == h3::Spell::Slow);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory41) == h3::Spell::Slayer);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory42) == h3::Spell::Shield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory43) == h3::Spell::SummonBoat);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory44) == h3::Spell::Teleport);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory45) == h3::Spell::TownPortal);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory46) == h3::Spell::ViewAir);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory47) == h3::Spell::ViewEarth);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory48) == h3::Spell::Weakness);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory49) == h3::Spell::WaterWalk);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory50) == h3::Spell::SummonWaterElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory51) == h3::Spell::Visions);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory52) == h3::Spell::DestroyUndead);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory53) == h3::Spell::DimensionDoor);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory54) == h3::Spell::Disguise);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory55) == h3::Spell::Dispel);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory56) == h3::Spell::DisruptingRay);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory57) == h3::Spell::SummonAirElemental);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory58) == h3::Spell::Bless);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory59) == h3::Spell::AnimateDead);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory60) == h3::Spell::AntiMagic);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory61) == h3::Spell::Armageddon);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory62) == h3::Spell::ChainLightning);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory63) == h3::Spell::AirShield);
        REQUIRE(h3::artifacts::spellFromScroll(hero, ArtifactSlot::Inventory64) == h3::Spell::Bloodlust);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Lord Haart");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HelmOfTheAlabasterUnicorn);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::RecantersCloak);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::CentaursAxe);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Moved shield to inventory.
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::BreastplateOfPetrifiedWood);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::SpiritOfOpression);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::HourglassOfTheEvilHour);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::ShieldOfTheDwarvenLords);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // - Adds Left ring: Ring of Suppression
        // - Adds Misc05: Hideous Mask
        // - Adds inventory01: Pendant of Downfall
        const Hero hero = save.findHero("Ryland");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::AngelicAlliance);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::RingOfSuppression);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Angelic Alliance
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::OrbOfInhibition);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::RunesOfImminency);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::DemonsHorseshoe);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ShamansPuppet);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::HideousMask);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::PendantOfDownfall);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }

    {
        // NOTE! "Torosar" is saved as "Torosar " in the save file.
        // Torosar was defeated.
        const Hero hero = save.findHero("Torosar ");
        REQUIRE(hero.player == 0xFF);
        REQUIRE(hero.on_map == 0);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Sorsha");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Armor of the Damned
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE); // Blocked by Armor of the Damned
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Armor of the Damned
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::ArmorOfTheDamned);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::BootsOfLevitation);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::TomeOfFireMagic);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::TomeOfAirMagic);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::TomeOfWaterMagic);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::TomeOfEarthMagic);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Ivor");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::PowerOfTheDragonFather);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE); // Blocked by Power of the Dragon Father
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // Fafner was defeated.
        const Hero hero = save.findHero("Fafner");
        REQUIRE(hero.player == 0xFF);
        REQUIRE(hero.on_map == 0);
    }

    {
        // Tyris was defeated.
        const Hero hero = save.findHero("Tyris");
        REQUIRE(hero.player == 0xFF);
        REQUIRE(hero.on_map == 0);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Kyrre");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::PendantOfLife);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::CloverOfFortune);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::CardsOfProphecy);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::LadybirdOfLuck);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::BadgeOfCourage);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::CrestOfValor);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::GlyphOfGallantry);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::Speculum);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory03) == Artifact::Spyglass);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory04) == Artifact::PendantOfDeath);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory05) == Artifact::PendantOfFreeWill);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory06) == Artifact::NONE);
    }

    {
        // Rissa was defeated.
        const Hero hero = save.findHero("Rissa");
        REQUIRE(hero.player == 0xFF);
        REQUIRE(hero.on_map == 0);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Christian");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::HelmOfChaos);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::GreaterGnollsFlail);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::BucklerOfTheGnollKing);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::ScalesOfTheGreaterBasilisk);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE); // Blocked by Elixir of Life
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::GoldenBow);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::SphereOfPermanence);
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::OrbOfVulnerability);
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::ElixirOfLife);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::NONE);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::Ballista);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::NONE);
    }

    {
        // Iona was defeated.
        const Hero hero = save.findHero("Iona");
        REQUIRE(hero.player == 0xFF);
        REQUIRE(hero.on_map == 0);
    }

    {
        // No changes.
        const Hero hero = save.findHero("Giselle");
        REQUIRE(h3::artifacts::helm(hero)           ==  Artifact::NONE);
        REQUIRE(h3::artifacts::cloak(hero)          ==  Artifact::VampiresCowl);
        REQUIRE(h3::artifacts::neck(hero)           ==  Artifact::AmuletOfTheUndertaker);
        REQUIRE(h3::artifacts::weapon(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::shield(hero)         ==  Artifact::NONE);
        REQUIRE(h3::artifacts::armor(hero)          ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringLeft(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ringRight(hero)      ==  Artifact::NONE);
        REQUIRE(h3::artifacts::boots(hero)          ==  Artifact::DeadMansBoots);
        REQUIRE(h3::artifacts::misc01(hero)         ==  Artifact::BowOfTheSharpshooter);
        REQUIRE(h3::artifacts::misc02(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter
        REQUIRE(h3::artifacts::misc03(hero)         ==  Artifact::NONE); // Blocked by Bow of the Sharpshooter
        REQUIRE(h3::artifacts::misc04(hero)         ==  Artifact::BirdOfPerception);
        REQUIRE(h3::artifacts::misc05(hero)         ==  Artifact::StoicWatchman);

        REQUIRE(h3::artifacts::ballista(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::ammoCart(hero)       ==  Artifact::NONE);
        REQUIRE(h3::artifacts::firstAidTent(hero)   ==  Artifact::NONE);
        REQUIRE(h3::artifacts::catapult(hero)       ==  Artifact::Catapult);
        REQUIRE(h3::artifacts::spellBook(hero)      ==  Artifact::NONE);

        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory01) == Artifact::EmblemOfCognizance);
        REQUIRE(h3::artifacts::artifact(hero, ArtifactSlot::Inventory02) == Artifact::NONE);
    }
}
