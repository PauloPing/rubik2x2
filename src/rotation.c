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
  // Face HAUT->Face DERRIERE
  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&avant->tab[0][1], &derriere->tab[1][0]);
  permuteCellule(&avant->tab[1][1], &derriere->tab[0][0]);
  // // Face DERRIERE -> Face BAS
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
  // // Face BAS -> Face GAUCHE
  Face *gauche = returnFace(GAUCHE, rubik);
  permuteCellule(&haut->tab[1][0], &gauche->tab[1][1]);
  permuteCellule(&haut->tab[1][1], &gauche->tab[0][1]);
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
  Face *droite = returnFace(DROITE, rubik);
  Face *avant = returnFace(DEVANT, rubik);
  Face *bas = returnFace(BAS, rubik);

  permuteCellule(&haut->tab[1][0], &droite->tab[0][0]);
  permuteCellule(&haut->tab[1][1], &droite->tab[1][0]);
  permuteCellule(&droite->tab[0][0], &gauche->tab[1][1]);
  permuteCellule(&droite->tab[1][0], &gauche->tab[0][1]);
  permuteCellule(&bas->tab[0][0], &droite->tab[1][0]);
  permuteCellule(&bas->tab[0][1], &droite->tab[0][0]);

  permuteCellule(&avant->tab[0][0], &avant->tab[0][1]);
  permuteCellule(&avant->tab[0][1], &avant->tab[1][0]);
  permuteCellule(&avant->tab[0][1], &avant->tab[1][1]);
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
  Face *bas = returnFace(BAS, rubik);
  Face *droite = returnFace(DROITE, rubik);

  permuteCellule(&droite->tab[0][1], &haut->tab[0][0]);
  permuteCellule(&droite->tab[1][1], &haut->tab[0][1]);

  permuteCellule(&droite->tab[0][1], &gauche->tab[1][0]);
  permuteCellule(&droite->tab[1][1], &gauche->tab[0][0]);

  permuteCellule(&droite->tab[0][1], &bas->tab[1][1]);
  permuteCellule(&droite->tab[1][1], &bas->tab[1][0]);

  Face *derriere = returnFace(DERRIERE, rubik);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[0][1]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[1][1]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[1][0]);
}

void rotationRURpUp(Face *rubik[NB_FACE])
{
  rotation("R", rubik);
  rotation("U", rubik);
  rotation("Rp", rubik);
  rotation("Up", rubik);
}

int cas1(Face *rubik[NB_FACE])
{
  if (rubik[HAUT]->tab[0][0].color == JAUNE && rubik[DERRIERE]->tab[0][0].color == JAUNE && rubik[DROITE]->tab[0][0].color == JAUNE && rubik[DEVANT]->tab[0][0].color == JAUNE)
  {
    rotation("Rp", rubik);
    rotation("Up", rubik);
    rotation("R", rubik);
    rotation("Up", rubik);
    rotation("Rp", rubik);
    rotation("U", rubik);
    rotation("U", rubik);
    rotation("R", rubik);
    return 1;
  }
  return 0;
}

int cas2(Face *rubik[NB_FACE])
{
  if (rubik[HAUT]->tab[0][1].color == JAUNE && rubik[DERRIERE]->tab[0][1].color == JAUNE && rubik[GAUCHE]->tab[0][1].color == JAUNE && rubik[DEVANT]->tab[0][1].color == JAUNE)
  {
    rotation("L", rubik);
    rotation("U", rubik);
    rotation("Lp", rubik);
    rotation("U", rubik);
    rotation("L", rubik);
    rotation("U", rubik);
    rotation("U", rubik);
    rotation("Lp", rubik);
    return 1;
  }
  return 0;
}

int cas3(Face *rubik[NB_FACE])
{
  if (rubik[DERRIERE]->tab[0][0].color == JAUNE && rubik[DERRIERE]->tab[0][1].color == JAUNE && rubik[DEVANT]->tab[0][0].color == JAUNE && rubik[DERRIERE]->tab[0][1].color == JAUNE)
  {
    rotation("R", rubik);
    rotation("R", rubik);
    rotation("U", rubik);
    rotation("U", rubik);
    rotation("R", rubik);
    rotation("U", rubik);
    rotation("U", rubik);
    rotation("R", rubik);
    rotation("R", rubik);
    return 1;
  }
  return 0;
}

int cas4(Face *rubik[NB_FACE])
{
  if (rubik[DERRIERE]->tab[0][0].color == JAUNE && rubik[DEVANT]->tab[0][1].color == JAUNE && rubik[GAUCHE]->tab[0][1].color == JAUNE && rubik[DERRIERE]->tab[0][0].color == JAUNE)
  {
    rotation("F", rubik);
    rotationRURpUp(rubik);
    rotationRURpUp(rubik);
    rotation("Fp", rubik);
    return 1;
  }
  return 0;
}

int cas5(Face *rubik[NB_FACE])
{
  if (rubik[HAUT]->tab[0][1].color == JAUNE && rubik[HAUT]->tab[1][1].color == JAUNE && rubik[GAUCHE]->tab[0][1].color == JAUNE && rubik[GAUCHE]->tab[0][0].color == JAUNE)
  {
    rotation("F", rubik);
    rotationRURpUp(rubik);
    rotation("Fp", rubik);
    return 1;
  }
  return 0;
}

int cas6(Face *rubik[NB_FACE])
{
  if (rubik[HAUT]->tab[0][1].color == JAUNE && rubik[HAUT]->tab[1][1].color == JAUNE && rubik[DERRIERE]->tab[0][1].color == JAUNE && rubik[DEVANT]->tab[0][0].color == JAUNE)
  {
    rotationRURpUp(rubik);
    rotation("Rp", rubik);
    rotation("F", rubik);
    rotation("R", rubik);
    rotation("Fp", rubik);
    return 1;
  }
  return 0;
}

int cas7(Face *rubik[NB_FACE])
{
  if (rubik[HAUT]->tab[0][0].color == JAUNE && rubik[HAUT]->tab[1][1].color == JAUNE && rubik[DROITE]->tab[0][1].color == JAUNE && rubik[DEVANT]->tab[0][0].color == JAUNE)
  {
    rotation("F", rubik);
    rotation("R", rubik);
    rotation("Up", rubik);
    rotation("Rp", rubik);
    rotation("Up", rubik);
    rotation("R", rubik);
    rotation("U", rubik);
    rotation("Rp", rubik);
    rotation("Fp", rubik);
    return 1;
  }
  return 0;
}

void dernireRotation(Face *rubik[NB_FACE], int cas)
{
  rotation("Lp", rubik);
  rotation("U", rubik);
  rotation("Rp", rubik);
  rotation("D", rubik);
  rotation("D", rubik);
  rotation("R", rubik);
  rotation("Up", rubik);
  rotation("Rp", rubik);
  rotation("D", rubik);
  rotation("D", rubik);
  rotation("R", rubik);
  rotation("R", rubik);

  // L' U R' D2 R U' R' R' D2 R2
}