/*!
 * \file functions.c
 * \brief The main memory management functions are declare in this file.
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ListeBlock.h"

struct DataProgramme {
    char *AdresseMemoireInitiale;
    char *AdresseMemoireMax;
    char *AdresseMemoireAcuelle;
    int taillePageDuSysteme;
    int tailleMemoireTotal;
};
/**
 *  \brief Funtions of memory management.
 */
void initMemory(int nbytes);
void *myalloc(int nBytes);
int myfree(void *p);
void *myrealloc(void *p,int newSize);
/**
 * \brief Fonctions to help in the management of the memory
 */
ListeBlock getBestBlock(int nBytes);
void divisionOfMemoryZone();
void displayMemoryStatus();
void initUtils(int nBytes);
struct DataProgramme createDetailsProgrmme(int nBytes);