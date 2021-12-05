#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "listeChainee.h"
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

void printRubikInFile(Face *rubik[NB_FACE], char *nomFichier)
{
  FILE *fichier = fopen(nomFichier, "w");
  int nbFaceMilieu = NB_FACE - 2;
  int i, j, k;
  int nbEspace = 8;
  for (j = 0; j < nbEspace; j++)
    fprintf(fichier, " ");
  fprintf(fichier, " ------ \n");
  for (i = 0; i < TAILLE_MATRICE; i++)
  {
    for (int j = 0; j < nbEspace; j++)
      fprintf(fichier, " ");
    fprintf(fichier, "|");
    for (j = 0; j < TAILLE_MATRICE; j++)
    {
      fprintf(fichier, " %d ", rubik[HAUT]->tab[i][j].value); //  + face->tab[i]->y * TAILLE_MATRICE
    }
    fprintf(fichier, "|\n");
  }
  for (j = 0; j < nbEspace; j++)
    fprintf(fichier, " ");
  fprintf(fichier, " ------ \n");
  for (i = 0; i < nbFaceMilieu; i++)
  {
    fprintf(fichier, " ------ ");
  }
  fprintf(fichier, "\n");
  for (i = 0; i < TAILLE_MATRICE; i++)
  {
    for (j = 1; j < nbFaceMilieu + 1; j++)
    {
      fprintf(fichier, "|");

      for (k = 0; k < TAILLE_MATRICE; k++)
      {
        fprintf(fichier, " %d ", rubik[j]->tab[i][k].value); //  + face->tab[i]->y * TAILLE_MATRICE
      }
      fprintf(fichier, "|");
    }
    fprintf(fichier, "\n");
  }
  for (i = 0; i < nbFaceMilieu; i++)
  {
    fprintf(fichier, " ------ ");
  }
  fprintf(fichier, "\n");
  for (j = 0; j < nbEspace; j++)
    fprintf(fichier, " ");
  fprintf(fichier, " ------ \n");
  for (i = 0; i < TAILLE_MATRICE; i++)
  {
    for (int j = 0; j < nbEspace; j++)
      fprintf(fichier, " ");
    fprintf(fichier, "|");
    for (j = 0; j < TAILLE_MATRICE; j++)
    {
      fprintf(fichier, " %d ", rubik[BAS]->tab[i][j].value); //  + face->tab[i]->y * TAILLE_MATRICE
    }
    fprintf(fichier, "|\n");
  }
  for (j = 0; j < nbEspace; j++)
    fprintf(fichier, " ");
  fprintf(fichier, " ------ \n");
  fclose(fichier);
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
  Nom : faceBlancheValide
  Description : dis si la face blanche est correct
  Paramètres : la face blanche
  Retour : 1 si valide, 0 sinon
*/
int faceBlancheValide(Face *face)
{
  return celluleCorrecte(face, 0, 0, BLANC, 0) && celluleCorrecte(face, 0, 1, BLANC, 1) && celluleCorrecte(face, 1, 0, BLANC, 2) && celluleCorrecte(face, 1, 1, BLANC, 3);
}

/*
  Nom : couleurCellule
  Description : Donne la couleur de la cellule sur la Face face à la position x/y dans la matrice
  Paramètres : la face et ses coordonnées
  Retour : La couleur de la cellule
*/
Color couleurCellule(Face *face, int x, int y)
{
  return face->tab[x][y].color;
}

/*
  Nom : faceValide
  Description : Dis si la Face face dispose uniquement de la Color color.
  Paramètres : la face et la couleur en question
  Retour : A si oui sinon 0
*/
int faceValide(Face *face, Color color)
{
  return couleurCellule(face, 0, 0) == color && couleurCellule(face, 0, 1) == color && couleurCellule(face, 1, 0) == color && couleurCellule(face, 1, 1) == color;
}

/*
  Nom : faireFaceBlanche
  Description : cette fonction fait la face blanche
  Paramètres : le rubik
  Retour : void
*/
void faireFaceBlanche(Face *rubik[NB_FACE], ListeChainee *liste)
{
  tourneRubikDevant(rubik, chercheCellule(rubik, BLANC, 0));
  monterRubik(rubik);

  int compteur = 0;
  while (!celluleCorrecte(returnFace(HAUT, rubik), 0, 0, BLANC, 0))
    rotation("Up", rubik, liste);
  if (celluleCorrecte(rubik[HAUT], 1, 0, BLANC, 1) || celluleCorrecte(rubik[GAUCHE], 0, 1, BLANC, 1) || celluleCorrecte(rubik[DEVANT], 0, 0, BLANC, 1))
    rotation("Dp", rubik, liste);
  while (!celluleCorrecte(rubik[HAUT], 0, 1, BLANC, 1))
  {
    rotation("Rp", rubik, liste);
    if (!celluleCorrecte(rubik[HAUT], 0, 1, BLANC, 1))
      rotation("Dp", rubik, liste);
    if (!celluleCorrecte(rubik[HAUT], 0, 1, BLANC, 1) && compteur % 4 == 0)
      rotation("F", rubik, liste);
    compteur++;
  }
  while (!celluleCorrecte(rubik[HAUT], 1, 0, BLANC, 2))
  {
    if (celluleCorrecte(rubik[DEVANT], 1, 1, BLANC, 2))
      rotation("Dp", rubik, liste);
    rotation("F", rubik, liste);
    if (!celluleCorrecte(rubik[HAUT], 1, 0, BLANC, 2))
      rotation("Dp", rubik, liste);
  }
  compteur = 0;
  if (celluleCorrecte(rubik[DEVANT], 1, 0, BLANC, 3) || celluleCorrecte(rubik[BAS], 0, 0, BLANC, 3))
  {
    rotation("D", rubik, liste);
    rotation("Rp", rubik, liste);
    rotation("Dp", rubik, liste);
    rotation("R", rubik, liste);
  }
  while (!celluleCorrecte(rubik[HAUT], 1, 1, BLANC, 3))
  {
    rotation("Rp", rubik, liste);
    for (int i = 0; i < 4 && !celluleCorrecte(rubik[DEVANT], 1, 1, BLANC, 3); i++)
    {
      rotation("Dp", rubik, liste);
    }
    rotation("R", rubik, liste);
    if (!celluleCorrecte(rubik[HAUT], 1, 1, BLANC, 3))
    {
      rotation("F", rubik, liste);
      for (int i = 0; i < 4 && !celluleCorrecte(rubik[DROITE], 1, 0, BLANC, 3); i++)
      {
        rotation("Dp", rubik, liste);
      }
      rotation("Fp", rubik, liste);
    }
    if (!celluleCorrecte(rubik[HAUT], 1, 1, BLANC, 3))
    {
      rotation("F", rubik, liste);
      rotation("Dp", rubik, liste);
      rotation("Fp", rubik, liste);
    }
  }
  if (!faceBlancheValide(rubik[HAUT]))
    printf("ERROR\n");
}

/*
  Nom : faireFaceJaune
  Description : cette fonction fait la face jaune
  Paramètres : le rubik
  Retour : void
*/
void faireFaceJaune(Face *rubik[NB_FACE], ListeChainee *liste)
{
  tourneRubikDevant(rubik, returnFace(BAS, rubik));
  monterRubik(rubik);
  int res = 0;

  while (!faceValide(rubik[HAUT], JAUNE))
  {
    if (cas1(rubik, liste) || cas2(rubik, liste) || cas3(rubik, liste) || cas4(rubik, liste) || cas5(rubik, liste) || cas6(rubik, liste) || cas7(rubik, liste))
      res = 1;
    else
      rotation("U", rubik, liste);
  }
  if (!faceValide(rubik[HAUT], JAUNE))
    printf("NONNONONN JAUNE JAUNE");
}

/*
  Nom : rubikValide
  Description : cette fonction vérifie que le rubik est correct.
  Paramètres : le rubik
  Retour : 1 si oui, sinon 0
*/
int rubikValide(Face *rubik[NB_FACE])
{
  for (int i = 0; i < NB_FACE; i++)
  {
    if (!faceValide(returnFace(i, rubik), couleurCellule(returnFace(i, rubik), 0, 0)))
    {
      return 0;
    }
  }
  return 1;
}

/*
  Nom : returnFaceJaune
  Description : cette fonction retourne la face JAUNE (ATTENTION : NOUS SAVONS QUE LA FACE JAUNE EST COMPLÈTE)
  Paramètres : le rubik
  Retour : La face jaune
*/
Face *returnFaceJaune(Face *rubik[NB_FACE])
{
  Face *res = malloc(sizeof(Face));
  for (int i = 0; i < NB_FACE; i++)
  {
    if (rubik[i]->tab[0][0].color == JAUNE)
    {
      res = rubik[i];
      break;
    }
  }
  return res;
}

/*
  Nom : faireFaceJaune
  Description : cette fonction permet de finir le rubik en terminant la face Jaune correctement pour obtebir le rubik
  Paramètres : le rubik
  Retour : void
*/
void terminerRubik(Face *rubik[NB_FACE], ListeChainee *liste)
{
  if (rubikValide(rubik))
    return;

  int valid = 0;
  for (int j = 0; j < 4; j++)
  {
    for (int i = 1; i < 5; i++)
    {
      if (faceValide(rubik[i], rubik[i]->tab[0][0].color))
      {
        tourneRubikDevant(rubik, rubik[i]);
        tourneRubikDevant(rubik, rubik[DERRIERE]);
        valid = 1;
        break;
      }
    }
    if (!valid)
      rotation("U", rubik, liste);
  }
  if (!valid && !rubikValide(rubik))
  {

    dernireRotation(rubik, 0, liste);
    tourneRubikDevant(rubik, returnFaceJaune(rubik));
    monterRubik(rubik);
    while (valid == 0)
    {
      for (int i = 1; i < 5; i++)
      {
        if (faceValide(rubik[i], rubik[i]->tab[0][0].color))
        {
          tourneRubikDevant(rubik, rubik[i]);
          tourneRubikDevant(rubik, rubik[DERRIERE]);
          valid = 1;
          break;
        }
      }
      if (!valid)
        rotation("U", rubik, liste);
    }
  }
  if (!rubikValide(rubik))
  {
    dernireRotation(rubik, 0, liste);
    rotation("Fp", rubik, liste);
  }
}