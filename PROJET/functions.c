//
// Created by nudian on 28/03/2021.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "utils.h"
#include "ListeBlock.h"

static ListeBlock listeBlock;
static  struct DonnesProgramme donnesProgramme;

/**
 * Function pour recuperer un espace memoire avec
 * malloc.
 * @param nbytes
 * @return creationd de l'adresse initiale et adresse max.
 */
void initMemory(int nbytes){
    initUtils(nbytes);
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
 * Function pour alluer de la memoire pour une variable dans le
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

        /**
         * Creation de un  Blocks
         * A faire:
         *   *Configuration du footer
         *   *Configuration du header
         *
         */
        /*Creation de footer (il faout configurer le footer) */
        struct Header header;
        header.taille=0;
        header.estvide=false;
        /*Creation de header*/
        struct Footer footer;
        footer.taille=0;
        header.estvide=false;
        struct Block block;
        /*Recuperation de l' adresse*/
        block.data=calculPourLaPage(ancienneAdresse,nBytes);
        /*Ajout dans la liste*/
        inserteteListe(&listeBlock,block);
        /*En return le block->data*/

        affichageStatusMemoire();
        return block.data;
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
    printf("Memoire initiale: %p\n",donnesProgramme.AdresseMemoireInitiale);
    printf("Memoire Actuelle: %p\n",donnesProgramme.AdresseMemoireAcuelle);
    printf("Memoire Max     : %p\n",donnesProgramme.AdresseMemoireMax);
    printf("Total de bloks alluées : %d",tailleListeBlock(listeBlock));
    printf("\n************************************************ \n");
}

struct DonnesProgramme createDetailsProgrmme(int nBytes){
    struct DonnesProgramme *d;
    d=malloc(sizeof(struct DonnesProgramme));
    d->tailleMemoireTotal=nBytes;
    d->AdresseMemoireAcuelle=NULL;
    d->AdresseMemoireMax=NULL;
    d->AdresseMemoireInitiale=NULL;
    d->taillePageDuSysteme=NULL;
    d->taillePageDuSysteme=getpagesize();
    d->tailleMemoireTotal=NULL;
    return *d;
}

void initUtils(int nBytes){
    donnesProgramme=createDetailsProgrmme(nBytes);
    listeBlock=initListe();
}