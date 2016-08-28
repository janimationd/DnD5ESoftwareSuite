#include "stdio.h"
#include <cmath>

#include "Creature.h"

void main() {
  /*for (int i = 0; i < 22; i++) {
    printf("%d =   normal %d,  special %d\n", i, (i - 10) / 2, DIV_ROUND_DOWN(i - 10, 2));
  }*/

  Creature c = Creature(10, 10, 10, 10, 10, 10);
  c.ModifyAbility(STR, -5);
  c.ModifyAbility(CON, 7);
  printf("c: STR = %d\n", c.Str());
  printf("c: DEX = %d\n", c.Dex());
  printf("c: CON = %d\n", c.Con());
  printf("c: INT = %d\n", c.Int());
  printf("c: WIS = %d\n", c.Wis());
  printf("c: CHA = %d\n", c.Cha());
}