//
// Created by nudian on 28/03/2021.
//

#include "ListeBlock.h"

ListeBlock initListe()
{
    return NULL;
}
bool estVide(ListeBlock l)
{
    return l==NULL;
}

void inserteteListe(char *adresse, int taille,ListeBlock *l)
{
    ListeBlock cel;
    cel=(ListeBlock)malloc(sizeof(struct celule));
    cel->adresseDebut=adresse;
    cel->taille=taille;
    cel->suivant=*l;
    *l=cel;
}

ListeBlock suivant(ListeBlock l)
{
    return (ListeBlock) l->suivant;
}

void afficheListe(ListeBlock l)
{
    int i=0;
    printf(" \n Affichage de la liste : \n \n");
    while(l != NULL)
    {
        i++;
        printf(" Premiere %d  :  [Adresse : %p ] \n",i,getadresseVariable(l));
        printf(" Taille de la variable :  [ %d ] \n",gettailleVariable(l));
        printf("\n");
        l =suivant(l);
    }
}

char *getadresseVariable(ListeBlock l){
    return l->adresseDebut;
}
int gettailleVariable(ListeBlock l){
    return l->taille;
}
