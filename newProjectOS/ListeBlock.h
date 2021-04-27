/*!
 * \file ListeBlock.h
 * \brief File who contains all of the declaration of the functions who
 * manage the Object ListeBlock.
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
 * \struct Block utils.h "Block"
 * \brief This structure represent an block of memory.
 *
 * This structure represent an block of memory.
 */
struct Block {
    int  taille;
    void* data;
};
/**
 * \struct cellule utils.h "ListeBlock"
 * \brief This structure regroups information about a block of memoey.
 *
 * This structure regroups information about a block of memoey.
 */
typedef struct cellule
{
    int used;
    struct Block block;
    struct cellule *suivant;
}*ListeBlock;


void diplayListeBlock(ListeBlock l);
int tailleListeBlock(ListeBlock l);
void inserteteListe(ListeBlock *l,struct Block block);
bool estVide(ListeBlock l);
ListeBlock initLite();
char *getadresseVariable(ListeBlock l);
int gettailleVariable(ListeBlock l);
ListeBlock initListe();
void *getData(ListeBlock l);
int getTaille(ListeBlock l);
ListeBlock next(ListeBlock l);