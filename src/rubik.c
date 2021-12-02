#include <stdio.h>
#include <stdlib.h>

#include "rubik.h"
#include "rotation.h"

/*
  Nom : color
  Description : Cette fonction retourne le code couleur de la cellule  
  Paramètres : La cellule en question
  Retour : le code couleur sous forme de chaine de caractère
*/
char *color(Cellule c)
{
  Color color = c.color;
  switch (color)
  {
  case ROUGE:
    return "\x1b[31m";
    break;
  case BLEU:
    return "\x1b[34m";
    break;
  case JAUNE:
    return "\x1b[35m";
    break;
  case ORANGE:
    return "\x1b[33m";
    break;
  case BLANC:
    return "\x1b[37m";
    break;
  case VERT:
    return "\x1b[32m";
    break;
  }
}

/*
  Nom : returnFace
  Description : Cette fonction retourne la face dans la direction donnée en paramètre
  Paramètres : Le rubik et la direction de la face qu'on cherche
  Retour : la face
*/
Face *returnFace(Direction direction, Face *rubik[NB_FACE])
{
  int i;
  for (i = 0; i < NB_FACE; i++)
  {
    if (rubik[i] != NULL)
    {
      if (rubik[i]->direction == direction)
      {
        return rubik[i];
      }
    }
  }
  return NULL;
}

/*
  Nom : printFace
  Description : Cette fonction affiche une face (utile pour la face du haut et du bas)
  Paramètres : La face en question
  Retour : void (affichage)
*/
void printFace(Face *face)
{
  int nbEspace = 9;
  for (int j = 0; j < nbEspace; j++)
    printf(" ");
  printf("\x1b[30m ------  \n");
  int i, j;
  for (i = 0; i < TAILLE_MATRICE; i++)
  {
    for (int j = 0; j < nbEspace; j++)
      printf(" ");
    printf("|");
    for (j = 0; j < TAILLE_MATRICE; j++)
    {
      printf("%s %d \x1b[0m", color(face->tab[i][j]), face->tab[i][j].value); //  + face->tab[i]->y * TAILLE_MATRICE
    }
    printf("\x1b[30m|\n");
  }
  for (int j = 0; j < nbEspace; j++)
    printf(" ");
  printf("\x1b[30m ------  \n");
}

/*
  Nom : printRubikCube
  Description : Cette fonction affiche le rubik (les 6 faces)
  Paramètres : Le rubik
  Retour : void (affichage)
*/
void printRubikCube(Face *rubik[NB_FACE])
{
  int nbFaceMilieu = NB_FACE - 2;
  int i, j, k;
  printFace(returnFace(HAUT, rubik));
  for (i = 0; i < nbFaceMilieu; i++)
  {
    printf("\x1b[30m ------  ");
  }
  printf("\n");
  for (i = 0; i < TAILLE_MATRICE; i++)
  {
    for (j = 1; j < nbFaceMilieu + 1; j++)
    {
      printf("\x1b[30m|");

      for (k = 0; k < TAILLE_MATRICE; k++)
      {
        printf("%s %d ", color(rubik[j]->tab[i][k]), rubik[j]->tab[i][k].value); //  + face->tab[i]->y * TAILLE_MATRICE
      }
      printf("\x1b[30m| ");
    }
    printf("\n");
  }
  for (i = 0; i < nbFaceMilieu; i++)
  {
    printf("\x1b[30m ------  ");
  }
  printf("\n");
  printFace(returnFace(BAS, rubik));
  printf("\x1b[0m");
}

/*
  Nom : creerRubik
  Description : Cette fonction crée le rubik (les 6 faces)
  Paramètres : Le tableau où va être stocké les 6 faces
  Retour : void 
*/
void creerRubik(Face *rubik[NB_FACE])
{
  int i = 0, j = 0, k = 0;
  for (i = 0; i < NB_FACE; i++)
  {
    Face *face = malloc(sizeof(Face));
    face->direction = i;
    Cellule **tab = malloc(sizeof(Cellule) * NB_CELLULE);
    for (j = 0; j < NB_CELLULE; j++)
    {
      tab[j] = malloc(sizeof(Cellule) * TAILLE_MATRICE);
    }

    for (j = 0; j < TAILLE_MATRICE; j++)
    {
      for (k = 0; k < TAILLE_MATRICE; k++)
      {
        Cellule c;
        c.color = i;
        c.face = face;
        c.value = (j * TAILLE_MATRICE) + k;
        tab[j][k] = c;
      }
    }
    face->tab = tab;
    rubik[i] = face;
  }
}

/*
  Nom : permuteCellule
  Description : Cette fonction permute deux cellules 
  Paramètres : Les deux cellules
  Retour : void 
*/
void permuteCellule(Cellule *c1, Cellule *c2)
{
  Cellule c3;
  c3.color = c1->color;
  c3.face = c1->face;
  c3.value = c1->value;
  c1->color = c2->color;
  c1->value = c2->value;
  c1->face = c2->face;
  c2->color = c3.color;
  c2->face = c3.face;
  c2->value = c3.value;
}