#pragma once


#define FLAG 5555555555u

#ifndef MAX
  #define MAX(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
  #define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif

#define DIV_ROUND_DOWN(n, d) (int(floorf(float(n) / (d))))



namespace eAbility {
  enum Type : uint32_t {
    STR = 0, DEX, CON, INT, WIS, CHA, MAX
  };
}

namespace eSkill {
  enum Type : uint32_t {
    ACROBATICS = 0,
    ANIMAL_HANDLING,
    ARCANA,
    ATHLETICS,
    DECEPTION,
    HISTORY,
    INSIGHT,
    INTIMIDATION,
    INVESTIGATION,
    MEDICINE,
    NATURE,
    PERCEPTION,
    PERFORMANCE,
    PERSUASION,
    RELIGION,
    SLEIGHT_OF_HAND,
    STEALTH,
    SURVIVAL,
    MAX
  };
}

// all lnaguages in 5th edition, copied from here: https://olddungeonmaster.wordpress.com/2012/06/27/dd-languages/
namespace eLanguage {
  enum Type : uint32_t {
    ABYSSAL = 0,
    AQUAN,
    AURAN,
    CELESTIAL,
    COMMON,
    DEEP_SPEECH,
    DRACONIC,
    DRUIDIC,
    DWARVISH,
    ELVISH,
    GIANT,
    GNOMISH,
    GOBLIN,
    GNOLL,
    HALFLING,
    IGNAN,
    INFERNAL,
    ORC,
    PRIMORDIAL,
    SYLVAN,
    TERRAN,
    UNDERCOMMON,
    MAX
  };
};