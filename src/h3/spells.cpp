#include "spells.h"
#include "hero.h"

bool h3::spells::has_spell(const h3::hero::Hero &hero, const Spell spell)
{
    const uint8_t idx = static_cast<uint8_t>(spell);
    return bool(hero.spells[idx]); // Also true if spell in spellbook.
}

bool h3::spells::has_spell_in_spellbook(const h3::hero::Hero &hero, const Spell spell)
{
    const uint8_t idx = static_cast<uint8_t>(spell);
    return bool(hero.spellbook[idx]); // Only true if spell in spell book.
}
