//
// Created by nudian on 28/03/2021.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int TElement ;

typedef struct celule
{
    int taille;
    char *adresseDebut;
    struct cellule *suivant;
}*ListeBlock;



void afficheListe(ListeBlock l);
void inserteteListe(char *adresse, int taiile,ListeBlock *l);
bool estVide(ListeBlock l);
ListeBlock initLite();
char *getadresseVariable(ListeBlock l);
int gettailleVariable(ListeBlock l);
ListeBlock initListe();