#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ListeBlock.h"

//
// Created by nudian on 28/03/2021.
//
struct DataProgramme {
    char *AdresseMemoireInitiale;
    char *AdresseMemoireMax;
    char *AdresseMemoireAcuelle;
    int taillePageDuSysteme;
    int tailleMemoireTotal;
};

void initMemory(int nbytes);
void* myalloc(int nBytes);
void *myalloc2(int nBytes);
int myfree(void *p);

ListeBlock getBestBlock(int nBytes);
void divisionOfMemoryZone();
void affichageStatusMemoire();
void initUtils(int nBytes);
void setTailleDePageSysteme();
int calculTaille(int tailleVariable);
void * calculPourLaPage(char *ancienneAdresse, int nBytes);
struct DataProgramme createDetailsProgrmme(int nBytes);