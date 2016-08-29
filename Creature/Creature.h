#pragma once

#include "stdint.h"
#include <list>

#include "Utility/DnDUtil.h"
#include "Utility\CreatureUtil.h"

// a class that represents a creature with hit points and other basic stats
class Creature {
protected:
  // 6 ability scores
  uint32_t abilities_[eAbility::MAX];

  // temporary modifiers to ability scores
  int32_t ability_temp_modifiers_[eAbility::MAX];

  // defense
  uint32_t max_hp_;
  uint32_t current_hp_;
  uint32_t ac_;

  // speed for round (6 seconds)
  uint32_t speed_, speed_fly_, speed_swim_, speed_climb_;

  // languages known (TODO: does not take into account can read vs. can speak)
  std::list<eLanguage::Type> languages_;

  // spellcasting
  eAbility::Type spellcasting_ability_; // if MAX, can't cast spells

  // Initialize all modifiers to 0
  void InitModifiers() {
    for (int i = 0; i < eAbility::MAX; i++) {
      ability_temp_modifiers_[i] = 0;
    }
  }


public:
  Creature(uint32_t str,
           uint32_t dex,
           uint32_t con,
           uint32_t intel,
           uint32_t wis,
           uint32_t cha,
           uint32_t speed,
           const std::list<eLanguage::Type> &languages,
           eAbility::Type spellcasting_ability)
      : languages_(languages), spellcasting_ability_(spellcasting_ability) {

    abilities_[eAbility::STR] = str;
    abilities_[eAbility::DEX] = dex;
    abilities_[eAbility::CON] = con;
    abilities_[eAbility::INT] = intel;
    abilities_[eAbility::WIS] = wis;
    abilities_[eAbility::CHA] = cha;

    InitModifiers();
    spellcasting_ability_ = eAbility::MAX;
  }

  // get strength modifier with all modifiers taken into account
  int32_t Str() {
    return DIV_ROUND_DOWN((int32_t)abilities_[eAbility::STR] + ability_temp_modifiers_[eAbility::STR] - 10, 2);
  }

  // get dexterity modifier with all modifiers taken into account
  int32_t Dex() {
    return DIV_ROUND_DOWN((int32_t)abilities_[eAbility::DEX] + ability_temp_modifiers_[eAbility::DEX] - 10, 2);
  }

  // get constitution modifier with all modifiers taken into account
  int32_t Con() {
    return DIV_ROUND_DOWN((int32_t)abilities_[eAbility::CON] + ability_temp_modifiers_[eAbility::CON] - 10, 2);
  }

  // get intelligence modifier with all modifiers taken into account
  int32_t Int() {
    return DIV_ROUND_DOWN((int32_t)abilities_[eAbility::INT] + ability_temp_modifiers_[eAbility::INT] - 10, 2);
  }

  // get wisdom modifier with all modifiers taken into account
  int32_t Wis() {
    return DIV_ROUND_DOWN((int32_t)abilities_[eAbility::WIS] + ability_temp_modifiers_[eAbility::WIS] - 10, 2);
  }

  // get charisma modifier with all modifiers taken into account
  int32_t Cha() {
    return DIV_ROUND_DOWN((int32_t)abilities_[eAbility::CHA] + ability_temp_modifiers_[eAbility::CHA] - 10, 2);
  }

  // add a temporary modification to an ability score, such as equipping belt of giant strength
  // if limit is not zero, then the ability will not be increased past limit
  void ModifyAbility(eAbility::Type a, int32_t delta, uint32_t limit = 0) {
    // no max
    if (limit == 0) {
      ability_temp_modifiers_[a] += delta;
    }
    else {
      ability_temp_modifiers_[a] = MIN(ability_temp_modifiers_[a] + delta, limit);
    }
  }

  // get saving throw modifier for the given ability
  // left as virtual because method for storing saving throws will be different for monsters and characters
  virtual int32_t SavingThrowMod(eAbility::Type a) {}

  // get the bonus to a specififc skill
  // left as virtual because method for storing skills will be different for monsters and characters
  virtual int32_t Skill(eSkill::Type s) {}

  // get the spell DC for this creature
  // left as virtual because method for calculating spell DC will be different for monsters and characters
  // if returns 0, can't cast spells
  virtual uint32_t SpellDC() {}

  // calculate this creature's armor class and return it
  // left as virtual because method will be different for monsters and characters
  virtual uint32_t AC() {}

  // make an attack on a target, returns whether it hits
  // left as virtual since this will be different for monsters and characters
  // @param attack_index: the index in the Creature's list of attacks that represents which attack they are making
  virtual bool Attack(uint32_t attack_index, Creature *target) {}
};