/*!
 * \file main.c
 * \brief Ex
 *
 *
 * \version 1.0
 * \date 17/02/2020
 */

/*!
 * \mainPage Examplede pqqqqqrogrmmme :
 * \con
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct cellule{
    int donnee;
    struct cellule *suivant;
}*Liste;

/*Variables Globales*/
char *memoireInitiale;
char *memoireMax;
char *memoireActuelle;
int tailleDePageDeSysteme;

void afficheListe(Liste l);
Liste initLite();
void insertete(Liste l,int donnee);

/*Functions Demandées*/
void initMemory();
void* myalloc(int nbytes);
int freeMemory(void *p);
/*Functions utils*/
int calculTaille(int tailleVariable);
void setTaileDePageSysteme();
void setMemoireActuelle(char nouvelleMemoire);
void * calculPourLaPage(char *ancienneAdresse, int nBytes);

int main(){

    initMemory(500);

    printf("Memoire initiale %p \n",memoireInitiale);
    printf("Memoire Max %p\n",memoireMax);
    printf("Memoire Actuelle %p\n",memoireActuelle);
    /*
    int *a;
    printf("Taille variable %ld\n",sizeof(15));
    a=(int*) myalloc(sizeof(15));
    //strcpy(a, "tutorialspoint");
    *a=34;
    printf("Adresse variable %p\n",a);
    printf("Valeur de la variable %d\n",a);
    printf("Memoire Actuelle %p\n",memoireActuelle);

    freeMemory(a);
    printf("Aprés\n");
    printf("Adresse variable %p\n",a);
    printf("Valeur de la variable %d\n",a);
    */
    Liste l;
    l=initLite();
    insertete(l,3);
    insertete(l,4);
    insertete(l,5);
    insertete(l,6);

    afficheListe(l);
    return 0;
}
/**
 * Function pour recuperer un espace memoire avec
 * malloc.
 * @param nbytes
 */
void initMemory(int nbytes){

    setTaileDePageSysteme();
    if((memoireInitiale=(char*)malloc(nbytes))==NULL){
        fprintf(stderr,"Erreur dans la allocation de la memoire initiale");
        exit(1);
    }
    else{
        printf("Memoire allueée avec succées \n");
        memoireMax=memoireInitiale+nbytes;
        memoireActuelle=memoireInitiale;
    }
}
/**
 * Function pour alluer de la memoire pour une variable dasn le
 * espace memoire reserveé pour le programme.
 * @param nBytes
 * @return
 */
void* myalloc(int nBytes){
    int tailleVariable=calculTaille(nBytes);
    /*Incrementation Memoire*/
    char *ancienneAdresse=memoireActuelle;
    if((nBytes<0) || (memoireActuelle>memoireMax)){
        fprintf(stderr,"Segmente defaoult d'hors de la memoire autorisée");
        return (void*)-1;
    }else{
        memoireActuelle=tailleVariable+memoireActuelle;
        //return (void *)ancienneAdresse;
        return calculPourLaPage(ancienneAdresse,nBytes);
    }
}
/**
 * Calcul de la talle de la variable.
 * @param tailleVariable
 * @return
 */
int calculTaille(int tailleVariable){
    return tailleVariable+tailleDePageDeSysteme & ~0x7;
}
void setTaileDePageSysteme(){
    tailleDePageDeSysteme=getpagesize();
}
void * calculPourLaPage(char *ancienneAdresse, int nBytes){
    *(size_t *)ancienneAdresse=nBytes;
    return (void *)((char *)ancienneAdresse+tailleDePageDeSysteme);
}
int freeMemory(void *p){
    free(p);
}

void insertete(Liste l,int donnee){
    Liste cel=(Liste)myalloc(sizeof(struct cellule));
    cel->donnee=donnee;
    cel->suivant=l;
    *l=*cel;
}

void afficheListe(Liste l)
{
    int i=0;
    printf(" \n Affichage de la liste : \n \n");
    while(l != NULL)
    {
        i++;
        printf("%d ° :  [ %d ] \n",i,l->donnee);
        printf("\n");
        l =l->suivant;
    }
}

Liste initLite()
{
    return NULL;
}


