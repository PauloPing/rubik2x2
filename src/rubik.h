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

void creerRubik(Face **);
Face *returnFace(Direction, Face **);
char *color(Cellule);
void printRubikCube(Face **);
void permuteCellule(Cellule *, Cellule *);
#endif