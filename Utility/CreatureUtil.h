#pragma once

#include "stdint.h"
#include <cmath>
#include <list>

#include "Utility/DnDUtil.h"

// different types of attacks
namespace eAttackType {
  enum Type : uint32_t {
    UNARMED = 0,
    WEAPON_MELEE = 1,
    WEAPON_RANGED = 2,
    SPELL = 3,
    MAX
  };
}

// different 5E damage types from here: https://www.reddit.com/r/DnD/comments/3v8btt/dd_5e_damage_type_explanations/
namespace eDamageType {
  enum Type : uint32_t {
    ACID = 0,
    BLUDGEONING,
    COLD,
    FIRE,
    FORCE,
    LIGHTNING,
    NECROTIC,
    PIERCING,
    POISON,
    PSYCHIC,
    RADIANT,
    SLASHING,
    THUNDER,
    MAX
  };
}

// class used to represent an amount of damage or healing
class Damage {
protected:
  // damage type (so the fire in "3d6 + 4 fire damage")
  eDamageType::Type type_;
  // amount of damage dice (so the 3 in "3d6 + 4 fire damage")
  uint32_t num_dice_;
  // damage dice type (so the d6 in "3d6 + 4 fire damage")
  eDice::Type dice_type_;
  // flat damage constant (so the +4 in "3d6 + 4 fire damage")
  int32_t damage_constant_;

public:
  Damage() {}
};

// the damage from an attack
class AttackDamageGroup {
  std::list<Damage> damages_;
};

// a class representing an attack
class Attack {
protected:
  // the type of attack
  eAttackType::Type type_;
  
  // the damage of the attack

public:
  Attack(eAttackType::Type type) : type_(type) {

  }
};