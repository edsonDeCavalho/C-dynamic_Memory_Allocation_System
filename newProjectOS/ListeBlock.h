/*!
 * \file utils.c
 * \brief File who contains all of the structures to help doing the differents
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
/**
 * \struct Operation utils.h "Operation"
 * \brief This structure represent an operation to do.
 *
 * This structure is shared throughout the project contains
 * it's the values of a future test to the test.
 */
struct Block {
    int  taille;
    void* data;
};
/**
 * \struct  utils.h "Operation"
 * \brief This structure represent an operation to do.
 *
 * This structure is shared throughout the project contains
 * it's the values of a future test to the test.
 */
typedef struct cellule
{
    struct Block block;
    struct cellule *suivant;
}*ListeBlock;


void afficheListe(ListeBlock l);
int tailleListeBlock(ListeBlock l);
void inserteteListe(ListeBlock *l,struct Block block);
bool estVide(ListeBlock l);
ListeBlock initLite();
char *getadresseVariable(ListeBlock l);
int gettailleVariable(ListeBlock l);
ListeBlock initListe();
void *getData(ListeBlock l);
int getTaille(ListeBlock l);
ListeBlock suivant(ListeBlock l);