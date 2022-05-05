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
}
