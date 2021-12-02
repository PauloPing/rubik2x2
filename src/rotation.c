#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rubik.h"
#include "rotation.h"

void rotation(char *rotation, Face *rubik[NB_FACE])
{
  if (!strcmp(rotation, "L"))
    rotationL(rubik);
  else if (!strcmp(rotation, "Lp"))
    rotationLPrime(rubik);
  else if (!strcmp(rotation, "R"))
    rotationR(rubik);
  else if (!strcmp(rotation, "Rp"))
    rotationRPrime(rubik);
  else if (!strcmp(rotation, "U"))
    rotationU(rubik);
  else if (!strcmp(rotation, "Up"))
    rotationUPrime(rubik);
  else if (!strcmp(rotation, "D"))
    rotationD(rubik);
  else if (!strcmp(rotation, "Dp"))
    rotationDPrime(rubik);
  else if (!strcmp(rotation, "F"))
    rotationF(rubik);
  else if (!strcmp(rotation, "Fp"))
    rotationFPrime(rubik);

  else if (!strcmp(rotation, "B"))
    rotationB(rubik);
  else if (!strcmp(rotation, "Bp"))
    rotationBPrime(rubik);
}

void rotationL(Face *rubik[NB_FACE])
{
  // Face AVANT -> Face BAS
  Face *bas = returnFace(BAS, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&avant->tab[0][0], &bas->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &bas->tab[1][0]);
  // Face BAS -> Face DERRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[0][0], &derriere->tab[1][1]);
  permuteCellule(&avant->tab[1][0], &derriere->tab[0][1]);
  // Face DERRIERE -> Face BAS
  Face *haut = returnFace(HAUT, rubik);
  permuteCellule(&avant->tab[0][0], &haut->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &haut->tab[1][0]);
  // Rotation face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[0][1]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[1][1]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[1][0]);
}

void rotationLPrime(Face *rubik[NB_FACE])
{
  // Face AVANT -> Face HAUT
  Face *haut = returnFace(HAUT, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&avant->tab[0][0], &haut->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &haut->tab[1][0]);
  // Face HAUT -> Face DERRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[0][0], &derriere->tab[1][1]);
  permuteCellule(&avant->tab[1][0], &derriere->tab[0][1]);
  // Face DERRIERE -> Face BAS
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&avant->tab[0][0], &bas->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &bas->tab[1][0]);
  // Rotation face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[1][0]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[1][1]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[0][1]);
}

void rotationR(Face *rubik[NB_FACE])
{
  Face *haut = returnFace(HAUT, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&avant->tab[0][1], &haut->tab[0][1]);
  permuteCellule(&avant->tab[1][1], &haut->tab[1][1]);
  // Face HAUT -> Face DERRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[0][1], &derriere->tab[1][0]);
  permuteCellule(&avant->tab[1][1], &derriere->tab[0][0]);
  // Face DERRIERE -> Face BAS
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&avant->tab[0][1], &bas->tab[0][1]);
  permuteCellule(&avant->tab[1][1], &bas->tab[1][1]);
  // Rotation face DROITE
  Face *droite = returnFace(DROITE, rubik);
  permuteCellule(&droite->tab[0][0], &droite->tab[0][1]);
  permuteCellule(&droite->tab[0][0], &droite->tab[1][1]);
  permuteCellule(&droite->tab[0][0], &droite->tab[1][0]);
}

void rotationRPrime(Face *rubik[NB_FACE])
{
  Face *bas = returnFace(BAS, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&avant->tab[0][1], &bas->tab[0][1]);
  permuteCellule(&avant->tab[1][1], &bas->tab[1][1]);
  // Face HAUT -> Face DERRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[0][1], &derriere->tab[1][0]);
  permuteCellule(&avant->tab[1][1], &derriere->tab[0][0]);
  // Face DERRIERE -> Face BAS
  Face *haut = returnFace(HAUT, rubik);
  permuteCellule(&avant->tab[0][1], &haut->tab[0][1]);
  permuteCellule(&avant->tab[1][1], &haut->tab[1][1]);
  // Rotation face DROITE
  Face *droite = returnFace(DROITE, rubik);
  permuteCellule(&droite->tab[0][0], &droite->tab[1][0]);
  permuteCellule(&droite->tab[0][0], &droite->tab[1][1]);
  permuteCellule(&droite->tab[0][0], &droite->tab[0][1]);
}

void rotationU(Face *rubik[NB_FACE])
{
  // Face AVANT -> Face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&gauche->tab[0][0], &avant->tab[0][0]);
  permuteCellule(&gauche->tab[0][1], &avant->tab[0][1]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[0][0], &derriere->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &derriere->tab[0][1]);
  // Face ARRIERE -> Face DROITE
  Face *droite = returnFace(DROITE, rubik);
  permuteCellule(&avant->tab[0][0], &droite->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &droite->tab[0][1]);
  // Modification de la face HAUT
  Face *haut = returnFace(HAUT, rubik);
  permuteCellule(&haut->tab[0][0], &haut->tab[0][1]);
  permuteCellule(&haut->tab[0][0], &haut->tab[1][1]);
  permuteCellule(&haut->tab[0][0], &haut->tab[1][0]);
}

void rotationUPrime(Face *rubik[NB_FACE])
{
  // Face AVANT -> Face DROITE
  Face *droite = returnFace(DROITE, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&droite->tab[0][0], &avant->tab[0][0]);
  permuteCellule(&droite->tab[0][1], &avant->tab[0][1]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[0][0], &derriere->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &derriere->tab[0][1]);
  // Face ARRIERE -> Face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  permuteCellule(&avant->tab[0][0], &gauche->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &gauche->tab[0][1]);
  // Modification de la face HAUT
  Face *haut = returnFace(HAUT, rubik);
  permuteCellule(&haut->tab[0][0], &haut->tab[1][0]);
  permuteCellule(&haut->tab[0][0], &haut->tab[1][1]);
  permuteCellule(&haut->tab[0][0], &haut->tab[0][1]);
}

void rotationD(Face *rubik[NB_FACE])
{
  // Face AVANT -> Face DROITE
  Face *droite = returnFace(DROITE, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&droite->tab[1][0], &avant->tab[1][0]);
  permuteCellule(&droite->tab[1][1], &avant->tab[1][1]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[1][0], &derriere->tab[1][0]);
  permuteCellule(&avant->tab[1][1], &derriere->tab[1][1]);
  // Face ARRIERE -> Face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  permuteCellule(&avant->tab[1][0], &gauche->tab[1][0]);
  permuteCellule(&avant->tab[1][1], &gauche->tab[1][1]);
  // Modification de la face HAUT
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&bas->tab[0][0], &bas->tab[0][1]);
  permuteCellule(&bas->tab[0][0], &bas->tab[1][1]);
  permuteCellule(&bas->tab[0][0], &bas->tab[1][0]);
}

void rotationDPrime(Face *rubik[NB_FACE])
{
  // Face AVANT -> Face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&gauche->tab[1][0], &avant->tab[1][0]);
  permuteCellule(&gauche->tab[1][1], &avant->tab[1][1]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[1][0], &derriere->tab[1][0]);
  permuteCellule(&avant->tab[1][1], &derriere->tab[1][1]);
  // Face ARRIERE -> Face DROITE
  Face *droite = returnFace(DROITE, rubik);
  permuteCellule(&avant->tab[1][0], &droite->tab[1][0]);
  permuteCellule(&avant->tab[1][1], &droite->tab[1][1]);
  // Modification de la face Bas
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&bas->tab[0][0], &bas->tab[1][0]);
  permuteCellule(&bas->tab[0][0], &bas->tab[1][1]);
  permuteCellule(&bas->tab[0][0], &bas->tab[0][1]);
}

void rotationF(Face *rubik[NB_FACE])
{
  Face *haut = returnFace(HAUT, rubik);
  Face *droite = returnFace(DROITE, rubik);
  // Face HAUT -> Face DROITE
  permuteCellule(&haut->tab[1][0], &droite->tab[0][0]);
  permuteCellule(&haut->tab[1][1], &droite->tab[1][0]);
  // Face DROITE -> Face BAS
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&haut->tab[1][0], &bas->tab[0][1]);
  permuteCellule(&haut->tab[1][1], &bas->tab[0][0]);
  // Face BAS -> Face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  permuteCellule(&haut->tab[1][0], &gauche->tab[0][0]);
  permuteCellule(&haut->tab[1][1], &gauche->tab[1][0]);
  // rotation face AVANT
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&avant->tab[0][0], &avant->tab[0][1]);
  permuteCellule(&avant->tab[0][0], &avant->tab[1][1]);
  permuteCellule(&avant->tab[0][0], &avant->tab[1][0]);
}

void rotationFPrime(Face *rubik[NB_FACE])
{
  Face *haut = returnFace(HAUT, rubik);
  Face *gauche = returnFace(GAUCHE, rubik);
  // Face HAUT -> Face GAUCHE
  permuteCellule(&haut->tab[1][0], &gauche->tab[0][0]);
  permuteCellule(&haut->tab[1][1], &gauche->tab[1][0]);
  // Face GAUCHE -> Face BAS
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&haut->tab[1][0], &bas->tab[0][1]);
  permuteCellule(&haut->tab[1][1], &bas->tab[0][0]);
  // Face BAS -> Face DROITE
  Face *droite = returnFace(DROITE, rubik);
  permuteCellule(&haut->tab[1][0], &droite->tab[0][0]);
  permuteCellule(&haut->tab[1][1], &droite->tab[1][0]);
  // Rotation Face AVANT
  Face *avant = returnFace(DEVANT, rubik);
  permuteCellule(&avant->tab[0][0], &avant->tab[1][0]);
  permuteCellule(&avant->tab[0][0], &avant->tab[1][1]);
  permuteCellule(&avant->tab[0][0], &avant->tab[0][1]);
}

void rotationB(Face *rubik[NB_FACE])
{
  Face *haut = returnFace(HAUT, rubik);
  Face *droite = returnFace(DROITE, rubik);
  // Face HAUTE -> Face DROITE
  permuteCellule(&haut->tab[0][0], &droite->tab[0][1]);
  permuteCellule(&haut->tab[0][1], &droite->tab[1][1]);
  // Face DROITE -> Face BAS
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&haut->tab[0][0], &bas->tab[1][1]);
  permuteCellule(&haut->tab[0][1], &bas->tab[1][0]);
  // Face BAS -> Face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  permuteCellule(&haut->tab[0][0], &gauche->tab[1][0]);
  permuteCellule(&haut->tab[0][1], &gauche->tab[0][0]);
  // Rotation Face Arriere
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[1][0]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[1][1]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[0][1]);
}

void rotationBPrime(Face *rubik[NB_FACE])
{
  Face *haut = returnFace(HAUT, rubik);
  Face *gauche = returnFace(GAUCHE, rubik);
  // Face HAUTE -> Face GAUCHE
  permuteCellule(&haut->tab[0][0], &gauche->tab[1][0]);
  permuteCellule(&haut->tab[0][1], &gauche->tab[0][0]);
  // Face GAUCHE -> Face BAS
  Face *bas = returnFace(BAS, rubik);
  permuteCellule(&haut->tab[0][0], &bas->tab[1][0]);
  permuteCellule(&haut->tab[0][1], &bas->tab[1][1]);
  // Face BAS -> Face DROITE
  Face *droite = returnFace(DROITE, rubik);
  permuteCellule(&haut->tab[0][0], &droite->tab[0][1]);
  permuteCellule(&haut->tab[0][1], &droite->tab[1][1]);
  // Rotation Face Arriere
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[0][1]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[1][1]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[1][0]);
}