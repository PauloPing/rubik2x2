#include <stdio.h>

#include "rubik.c"
#include "rotation.c"

int main(void)
{
  srand(time(NULL));
  Face *rubik[NB_FACE];
  for (int i = 0; i < 100; i++)
  {
    creerRubik(rubik);
    melangerRubik(rubik);
    faireFaceBlanche(rubik);
    faireFaceJaune(rubik);
    printRubikCube(rubik);

    // RESTE JUSTE LA DERNIÈRE METHODE POUR INIR LE RUBIK APRÈS LA FACE JAUNE
  }

  return 0;
}