#include <stdbool.h>

/**
// Created by De Carvalho Edson on 24/02/2021.
**/

typedef struct{
    int taille;
    int nbstructure;
    bool allocationMem;
    bool liberationMem;
}Parametres;


int getTaille(Parametres parametres);
int getNbstructure(Parametres parametres);
bool getAllocationMem(Parametres parametres);
bool getLibliberationMem(Parametres parametres);