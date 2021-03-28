//
// Created by nudian on 28/03/2021.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "utils.h"


static  struct DonnesProgramme donnesProgramme;

/**
 * Function pour recuperer un espace memoire avec
 * malloc.
 * @param nbytes
 */
void initMemory(int nbytes){
    donnesProgramme=createDetailsProgrmme(nbytes);
    donnesProgramme.tailleMemoireTotal=nbytes;
    if((donnesProgramme.AdresseMemoireInitiale=(char*)malloc(nbytes))==NULL){
        fprintf(stderr,"Erreur dans la allocation de la memoire initiale");
        affichageStatusMemoire();
        exit(1);
    }
    else{
        printf("Memoire allueée avec succées \n");
        donnesProgramme.AdresseMemoireMax=donnesProgramme.AdresseMemoireInitiale+nbytes;
        donnesProgramme.AdresseMemoireAcuelle=donnesProgramme.AdresseMemoireInitiale;
    }
    affichageStatusMemoire();
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
    char *ancienneAdresse=donnesProgramme.AdresseMemoireAcuelle;
    if((nBytes<0) || (donnesProgramme.AdresseMemoireAcuelle>donnesProgramme.AdresseMemoireMax)){
        fprintf(stderr,"Segmente defaoult d'hors de la memoire autorisée");
        affichageStatusMemoire();
        return (void*)-1;
    }else{
        donnesProgramme.AdresseMemoireAcuelle=tailleVariable+donnesProgramme.AdresseMemoireAcuelle;
        //return (void *)ancienneAdresse;
        affichageStatusMemoire();
        return calculPourLaPage(ancienneAdresse,nBytes);
    }
}


int calculTaille(int tailleVariable){
    return tailleVariable+donnesProgramme.taillePageDuSysteme & ~0x7;
}

void * calculPourLaPage(char *ancienneAdresse, int nBytes){
    *(size_t *)ancienneAdresse=nBytes;
    return (void *)((char *)ancienneAdresse+donnesProgramme.taillePageDuSysteme);
}

void affichageStatusMemoire(){
    printf("\n************************************************ \n");
    printf("Memoire initiale %p\n",donnesProgramme.AdresseMemoireInitiale);
    printf("Memoire Actuelle %p\n",donnesProgramme.AdresseMemoireAcuelle);
    printf("Memoire Max %p\n",donnesProgramme.AdresseMemoireMax);
    printf("\n************************************************ \n");
}

struct DonnesProgramme createDetailsProgrmme(int nBytes){
    struct DonnesProgramme *d;
    d=malloc(sizeof(struct DonnesProgramme));
    d->AdresseMemoireAcuelle=NULL;
    d->AdresseMemoireMax=NULL;
    d->AdresseMemoireInitiale=NULL;
    d->taillePageDuSysteme=NULL;
    d->taillePageDuSysteme=getpagesize();
    d->tailleMemoireTotal=NULL;
    return *d;
}