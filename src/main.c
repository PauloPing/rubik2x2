#include <stdio.h>

#include "rubik.c"
#include "rotation.c"

int main(void)
{
  Face *rubik[NB_FACE];
  creerRubik(rubik);
  melangerRubik(rubik);
  printRubikCube(rubik);
  faireFaceBlanche(rubik);
  printRubikCube(rubik);

  // REVOIR ROTATION DU RUBIK PROBLEME / ROTATION CLASSIQUE CORRECT
  return 0;
}