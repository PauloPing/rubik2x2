#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/*
  Nom : melangerRubik
  Description : Cette fonction mélange le rubik
  Paramètres : Le rubik
  Retour : void 
*/
void melangerRubik(Face *rubik[NB_FACE])
{
  srand(time(NULL));
  int r, i = 0;
  for (i = 0; i < 300; i++)
  {
    r = rand() % (NB_ROTATION);
    void (*fun_ptr)(Face * rubik[]) = mouvement[r];
    (*fun_ptr)(rubik);
  }
}

/*
  Nom : estSurFace
  Description : Savoir si une cellule est sur une face en particulier
  Paramètres : La face, et la valeur et la couleur de la cellule que l'on cherche
  Retour : 1 => est sur la face et 0 sinon 
*/
int estSurFace(Face *face, int val, Color color)
{
  for (int i = 0; i < TAILLE_MATRICE; i++)
  {
    for (int j = 0; j < TAILLE_MATRICE; j++)
    {
      if (face->tab[i][j].color == color && face->tab[i][j].value == val)
      {
        return 1;
      }
    }
  }
  return 0;
}

/*
  Nom : celluleCorrecte
  Description : Savoir si la cellule est au bonne endroit
  Paramètres : La face, et la velur et la vouleur de la cellule en question
  Retour : void
*/
int celluleCorrecte(Face *face, int x, int y, Color color, int value)
{
  return face->tab[x][y].color == color && face->tab[x][y].value == value;
}

/*
  Nom : switchFace
  Description : Echange deux faces
  Paramètres : Les deux faces
  Retour : void
*/
void switchFace(Face *f1, Face *f2)
{
  Face tmp;
  tmp.tab = f1->tab;
  f1->tab = f2->tab;
  f2->tab = tmp.tab;
}

/*
  Nom : faceOppose
  Description : Donne la direction opposé de celle passé en param
  Paramètres : une direction
  Retour : la Direction opposé
*/
Direction faceOppose(Direction direction)
{
  if (direction == HAUT)
    return BAS;
  else if (direction == BAS)
    return HAUT;
  else if (direction == GAUCHE)
    return DROITE;
  else if (direction == DROITE)
    return GAUCHE;
  else if (direction == DEVANT)
    return DERRIERE;
  else
    return DEVANT;
}

/*
  Nom : tournerFace
  Description : Tourne les cellules de la fce dans une certaine direction
  Paramètres : une direction et la face
  Retour : void
*/
void tournerFace(Face *face, Direction direction)
{
  if (direction == GAUCHE)
  {
    permuteCellule(&face->tab[0][0], &face->tab[0][1]);
    permuteCellule(&face->tab[0][1], &face->tab[1][1]);
    permuteCellule(&face->tab[1][0], &face->tab[1][1]);
  }
  else if (direction == DROITE)
  {
    permuteCellule(&face->tab[0][0], &face->tab[0][1]);
    permuteCellule(&face->tab[0][0], &face->tab[1][1]);
    permuteCellule(&face->tab[0][0], &face->tab[1][0]);
  }
  else if (direction == HAUT)
  {
    permuteCellule(&face->tab[0][0], &face->tab[0][1]);
    permuteCellule(&face->tab[0][0], &face->tab[1][1]);
    permuteCellule(&face->tab[0][0], &face->tab[1][0]);
  }
}

/*
  Nom : tourneRubikDevant
  Description : Passer une face devant le rubik
  Paramètres : rubik et face
  Retour : void
*/
void tourneRubikDevant(Face *rubik[NB_FACE], Face *face)
{
  Direction direction = face->direction;
  if (direction != DERRIERE)
  {
    switchFace(returnFace(DEVANT, rubik), returnFace(direction, rubik));
    switchFace(returnFace(direction, rubik), returnFace(faceOppose(direction), rubik));
    switchFace(returnFace(direction, rubik), returnFace(faceOppose(DEVANT), rubik));
    if (direction != BAS && direction != HAUT) //  && direction != HAUT
    {
      tournerFace(returnFace(HAUT, rubik), direction);
      tournerFace(returnFace(BAS, rubik), faceOppose(direction));
    }
    else if (direction == HAUT)
    {
      tournerFace(returnFace(direction, rubik), DROITE);
      tournerFace(returnFace(direction, rubik), DROITE);
      tournerFace(returnFace(DROITE, rubik), GAUCHE);
      tournerFace(returnFace(GAUCHE, rubik), DROITE);
      tournerFace(returnFace(DERRIERE, rubik), GAUCHE);
      tournerFace(returnFace(DERRIERE, rubik), GAUCHE);
    }
    else if (direction == BAS)
    {
      tournerFace(returnFace(GAUCHE, rubik), GAUCHE);
      tournerFace(returnFace(DROITE, rubik), DROITE);
      tournerFace(returnFace(DERRIERE, rubik), DROITE);
      tournerFace(returnFace(DERRIERE, rubik), DROITE);
      tournerFace(returnFace(BAS, rubik), DROITE);
      tournerFace(returnFace(BAS, rubik), DROITE);
    }
  }
  else
  {
    switchFace(returnFace(DEVANT, rubik), returnFace(DERRIERE, rubik));
    switchFace(returnFace(GAUCHE, rubik), returnFace(DROITE, rubik));
    tournerFace(returnFace(HAUT, rubik), DROITE);
    tournerFace(returnFace(HAUT, rubik), DROITE);
    tournerFace(returnFace(BAS, rubik), DROITE);
    tournerFace(returnFace(BAS, rubik), DROITE);
  }
}

/*
  Nom : chercheCellule
  Description : retourne la face sur laquelle appartient la cellule.
  Paramètres : rubik et la valeur/coleur de cellule à trouver
  Retour : la face sur laquelle appartient la cellule
*/
Face *chercheCellule(Face *rubik[NB_FACE], Color color, int val)
{
  for (int i = 0; i < NB_FACE; i++)
  {
    if (estSurFace(rubik[i], val, color))
      return rubik[i];
  }
  return NULL;
}

/*
  Nom : monterRubik
  Description : Passe la face de devant en haut du rubik
  Paramètres : le rubik
  Retour : void
*/
void monterRubik(Face *rubik[NB_FACE])
{
  tourneRubikDevant(rubik, returnFace(BAS, rubik));
}

/*
  Nom : faireFaceBlanche
  Description : cette fonction fait la face blanche
  Paramètres : le rubik
  Retour : void
*/
void faireFaceBlanche(Face *rubik[NB_FACE])
{
  tourneRubikDevant(rubik, chercheCellule(rubik, BLANC, 0));
  monterRubik(rubik);
  while (!celluleCorrecte(returnFace(HAUT, rubik), 0, 0, BLANC, 0))
    rotation("Up", rubik);
}