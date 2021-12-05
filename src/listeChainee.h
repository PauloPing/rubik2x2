#ifndef __LISTE__
#define __LISTE__

typedef struct maillon
{
  char *rotation;
  struct maillon *suiv;
} Maillon;

typedef Maillon *ListeChainee;
// TEST
void ajoutElement(char *, ListeChainee *);
void affichageListeChainee(ListeChainee *);
void viderListeChainee(ListeChainee *);

#endif