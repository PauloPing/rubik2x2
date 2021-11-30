#define NB_CELLULE 4
#define TAILLE_MATRICE 2

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

typedef struct
{
  int value;
  Color color;
} Cellule;

typedef struct
{
  Direction direction;
  Cellule **tab;
} Face;

void creerRubik(Face **);
Face *returnFace(Face **, Direction);
char *color(Cellule);