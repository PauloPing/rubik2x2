#include <stdio.h>

#include "rubik.c"
#include "rotation.c"

int main(void)
{
  srand(time(NULL));
  Face *rubik[NB_FACE];
  for (int i = 0; i < 10000; i++)
  {
    creerRubik(rubik);
    melangerRubik(rubik);
    faireFaceBlanche(rubik);
    faireFaceJaune(rubik);
    terminerRubik(rubik);
    if (!rubikValide(rubik))
      printf("ERROR A DEMAIN");
  }

  return 0;
}