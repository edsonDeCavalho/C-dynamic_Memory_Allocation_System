#include "ListeBlock.h"

ListeBlock initListe()
{
    return NULL;
}
bool estVide(ListeBlock l)
{
    return l==NULL;
}

void inserteteListe(ListeBlock *l,struct Block block)
{
    ListeBlock cel;
    cel=(ListeBlock)malloc(sizeof(struct cellule));
    cel->block=block;
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
        printf(" Premiere %d  :  [Adresse : %p ] \n",i,getData(l));
        printf(" Taille de la variable :  [ %d ] \n",getTaille(l));
        printf("\n");
        l =suivant(l);
        i++;
    }
}

struct Block getBlock(ListeBlock l){
    return l->block;
}

int tailleListeBlock(ListeBlock l){
    int i = 0;
    while(l != NULL) {
        i++;
        l=suivant(l);
    }
    return i;
}
void *getData(ListeBlock l){
    return (void*)  l->block.data;
}

int getTaille(ListeBlock l){
    return l->block.taille;
}
