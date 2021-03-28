//
// Created by nudian on 28/03/2021.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

struct Header{
    int taille;
    bool estvide;
};

struct Footer{
    int taille;
    bool estvide;
};

struct Block {
    struct Header header;
    void* data;
    struct Footer footer;
};

typedef struct celule
{
    struct Block block;
    struct celule *suivant;
}*ListeBlock;


void afficheListe(ListeBlock l);
void inserteteListe(char *adresse, int taiile,ListeBlock *l);
bool estVide(ListeBlock l);
ListeBlock initLite();
char *getadresseVariable(ListeBlock l);
int gettailleVariable(ListeBlock l);
ListeBlock initListe();