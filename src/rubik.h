#ifndef __RUBIK__
#define __RUBIK__

#define NB_CELLULE 4
#define TAILLE_MATRICE 2
#define NB_FACE 6

typedef enum
{
  BLANC,
  VERT,
  ROUGE,
  BLEU,
  ORANGE,
  JAUNE,
} Color;

typedef enum
{
  HAUT,
  GAUCHE,
  DEVANT,
  DROITE,
  DERRIERE,
  BAS,
} Direction;

typedef struct face Face;
typedef struct
{
  int value;
  Color color;
  Face *face;
} Cellule;

struct face
{
  Direction direction;
  Cellule **tab;
} face;

char *color(Cellule);
Face *returnFace(Direction, Face **);
void printFace(Face *);
void printRubikCube(Face **);
void creerRubik(Face **);
void permuteCellule(Cellule *, Cellule *);
void melangerRubik(Face **);
int estSurFace(Face *, int, Color);
int celluleCorrecte(Face *, int, int, Color, int);
void switchFace(Face *, Face *);
Direction faceOppose(Direction);
void tournerFace(Face *, Direction);
void tourneRubikDevant(Face **, Face *);
Face *chercheCellule(Face **, Color, int);
void monterRubik(Face **);
Color couleurCellule(Face *, int, int);
int faceValide(Face *, Color);
void faireFaceBlanche(Face **);
void faireFaceJaune(Face **);
void terminerRubik(Face **);
void dernireRotation(Face **, int);
#endif