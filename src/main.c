#include <stdio.h>
#include "rotation.c"
#include "rubik.c"

int main(void)
{
  Face *rubik[NB_FACE];
  creerRubik(rubik);
  printRubikCube(rubik);
  return 0;
}