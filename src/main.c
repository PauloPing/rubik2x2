#include <stdio.h>

#include "rubik.c"
#include "rotation.c"

int main(void)
{
  Face *rubik[NB_FACE];
  creerRubik(rubik);
  rotation("B", rubik);
  rotation("B", rubik);
  printRubikCube(rubik);
  return 0;
}