#ifndef __ROTATION__
#define __ROTATION__

#define NB_ROTATION 12

void rotation(char *, Face **);

// rotation
void rotationL(Face **);
void rotationLPrime(Face **);
void rotationR(Face **);
void rotationRPrime(Face **);
void rotationU(Face **);
void rotationUPrime(Face **);
void rotationD(Face **);
void rotationDPrime(Face **);
void rotationF(Face **);
void rotationFPrime(Face **);
void rotationB(Face **);
void rotationBPrime(Face **);
void melangerRubik(Face **);

// suite de rota pour faire la face jaune

void rotationRURpUp(Face **);
int cas1(Face **);
int cas2(Face **);
int cas3(Face **);
int cas4(Face **);
int cas5(Face **);
int cas6(Face **);
int cas7(Face **);
// Tableau avec toutes les rotations
void *mouvement[NB_ROTATION] = {
    rotationL,
    rotationLPrime,
    rotationR,
    rotationRPrime,
    rotationU,
    rotationUPrime,
    rotationD,
    rotationDPrime,
    rotationF,
    rotationFPrime,
    rotationB,
    rotationBPrime,
};

#endif