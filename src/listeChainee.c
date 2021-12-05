#include <stdio.h>
#include <stdlib.h>

#include "listeChainee.h"
#include "rubik.h"

void ajoutElement(char *rotation, ListeChainee *liste)
{
  Maillon *m = malloc(sizeof(Maillon));
  m->rotation = rotation;
  m->suiv = NULL;
  if (*liste == NULL)
  {
    *liste = m;
  }
  else
  {
    ListeChainee current = *liste;
    while (current->suiv != NULL)
    {
      current = current->suiv;
    }
    current->suiv = m;
  }
}

void affichageListeChainee(ListeChainee *liste)
{
  ListeChainee current = *liste;
  printf("Rotation : \n");
  printf("[");
  while (current != NULL)
  {
    printf("%s", current->rotation);
    current = current->suiv;
    if (current != NULL)
      printf(",");
  }
  printf("]\n");
}

void viderListeChainee(ListeChainee *liste)
{
  *liste = NULL;
}