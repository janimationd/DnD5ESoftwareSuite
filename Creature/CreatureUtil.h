#pragma once

#include "stdint.h"
#include <cmath>





//class Abilities {
//private:
//  uint32_t str_score_, dex_score_, con_score_, int_score_, wis_score_, cha_score_;
//  int32_t str_mod_, dex_mod_, con_mod_, int_mod_, wis_mod_, cha_mod_;
//
//public:
//  Abilities(uint32_t str_score, uint32_t dex_score, uint32_t con_score, uint32_t int_score, uint32_t wis_score, uint32_t cha_score) :
//    str_score_(str_score), dex_score_(dex_score), con_score_(con_score), int_score_(int_score), wis_score_(wis_score), cha_score_(cha_score)
//  {
//    str_mod_ = DIV_ROUND_DOWN(str_score - 10, 2);
//    dex_mod_ = DIV_ROUND_DOWN(dex_score - 10, 2);
//    con_mod_ = DIV_ROUND_DOWN(con_score - 10, 2);
//    int_mod_ = DIV_ROUND_DOWN(int_score - 10, 2);
//    wis_mod_ = DIV_ROUND_DOWN(wis_score - 10, 2);
//    cha_mod_ = DIV_ROUND_DOWN(cha_score - 10, 2);
//  }
//
//  int TempChangeScore() {
//
//  }
//};