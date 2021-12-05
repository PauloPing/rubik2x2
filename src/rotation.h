#ifndef __ROTATION__
#define __ROTATION__

#define NB_ROTATION 12

void rotation(char *, Face **, ListeChainee *);

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

void rotationRURpUp(Face **, ListeChainee *);
int cas1(Face **, ListeChainee *);
int cas2(Face **, ListeChainee *);
int cas3(Face **, ListeChainee *);
int cas4(Face **, ListeChainee *);
int cas5(Face **, ListeChainee *);
int cas6(Face **, ListeChainee *);
int cas7(Face **, ListeChainee *);
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