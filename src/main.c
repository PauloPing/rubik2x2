#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rubik.c"
#include "rotation.c"
#include "listeChainee.c"

void faireRubik(Face *rubik[NB_FACE], ListeChainee *liste)
{
  faireFaceBlanche(rubik, liste);
  printf("Face Blanche\n");
  affichageListeChainee(liste);
  printRubikCube(rubik);

  viderListeChainee(liste);

  faireFaceJaune(rubik, liste);
  printf("Face Jaune\n");
  affichageListeChainee(liste);
  printRubikCube(rubik);

  viderListeChainee(liste);

  terminerRubik(rubik, liste);
  printf("Rubik terminé\n");
  affichageListeChainee(liste);
  printRubikCube(rubik);

  // affichageListeChainee(liste);

  if (!rubikValide(rubik))
    printf("ERROR");
}

void param(void)
{
  printf("\n");
  printf("\n");
  printf("|------------MENU RUBIK------------|\n");
  printf("|       1. Afficher le rubik       |\n");
  printf("|      2. Enregistrer le rubik     |\n");
  printf("|       3. Mélanger le rubik       |\n");
  printf("|        4. Faire le rubik         |\n");
  printf("|           5. Quitter             |\n");
  printf("|----------------------------------|\n");
  printf("\n");
  printf("\n");
}
void menu(void)
{
  srand(time(NULL));
  Face *rubik[NB_FACE];
  creerRubik(rubik);
  ListeChainee liste = NULL;

  param();
  int reponse = 0;
  while (reponse != 5)
  {
    if (reponse != 0)
      param();
    do
    {
      printf("Que voulez-vous faire : ");
      scanf("%d", &reponse);
    } while (reponse < 0 || reponse > 6);
    switch (reponse)
    {
    case 1:
      printRubikCube(rubik);
      break;
    case 2:
      printf("Dans quel fichier voulez-vous enregistrer le rubik ? (MAX. 10 carac)\n");
      char c[10];
      scanf("%s", c);
      printRubikInFile(rubik, c);
      printf("Etat sauvegardé dans le fichier %s\n", c);
      break;
    case 3:
      melangerRubik(rubik);
      printf("Rubik mélangé.\n");
      break;
    case 4:
      faireRubik(rubik, &liste);
    default:
      break;
    }
  }
}

int main(void)
{
  menu();
  // srand(time(NULL));
  // Face *rubik[NB_FACE];
  // for (int i = 0; i < 10; i++)
  // {
  // creerRubik(rubik);
  // melangerRubik(rubik);
  // faireRubik(rubik, &liste);
  // }

  return 0;
}