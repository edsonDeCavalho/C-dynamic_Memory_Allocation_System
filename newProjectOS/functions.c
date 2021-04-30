/*!
 * \file functions.c
 * \brief The main memory management functions are implemented in this file.
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */
#include "functions.h"
#include <string.h>
#include <stdio.h>

static ListeBlock listeOfBlocksAlueted;
static ListeBlock ListOfFreeBlocks;
static  struct DataProgramme donnesProgramme;

/**
 * \fn void *myalloc(int nBytes)
 * \brief Function who makes the allocation for the memory space for the program.
 * \param nteger with the size of the variable.
 * \return Adresse ou NULL.
 *
 */
void initMemory(int nbytes){
    initUtils(nbytes);
    donnesProgramme.tailleMemoireTotal=nbytes;
    if((donnesProgramme.AdresseMemoireInitiale=(char*)malloc(nbytes))==NULL){
        fprintf(stderr,"Erreur dans la allocation de la memoire initiale");
        displayMemoryStatus();
        exit(1);
    }
    else{
        printf("Memoire allueée avec succées \n");
        donnesProgramme.AdresseMemoireMax=donnesProgramme.AdresseMemoireInitiale+nbytes;
        donnesProgramme.AdresseMemoireAcuelle=donnesProgramme.AdresseMemoireInitiale;
    }
    displayMemoryStatus();
    divisionOfMemoryZone();
}

/**
 * \fn void *myalloc(int nBytes)
 * \brief Function to go from memory for a variable.
 * \param nteger with the size of the variable.
 * \return Adresse ou NULL.
 *  Function to go from memory for a variable to the memory space reserved for the program.
 */
void *myalloc(int nBytes){
    ListeBlock l;
    if((l=getBestBlock(nBytes))==-1){
        printf("Depacement de memoire\n");
        return NULL;
    }
    else{
        inserteteListe(&listeOfBlocksAlueted,l->block);
        printf("Memoire by myalloc returned : %p",l->block.data);
        return (void*) l->block.data;
    }
}
/**
 * \fn void displayMemoryStatus()
 * \brief Fonction who cdisplays the status of the memory.
 * \param Integer with the size of the memory.
 * \return Instance of the structure DataProgramme.
 *  DataProgramme  store the parameters of the progemme.
 */
void displayMemoryStatus(){
    printf("\n************************************************ \n");
    printf("Memoire initiale: %p\n",donnesProgramme.AdresseMemoireInitiale);
    printf("Memoire Actuelle: %p\n",donnesProgramme.AdresseMemoireAcuelle);
    printf("Memoire Max     : %p\n",donnesProgramme.AdresseMemoireMax);
    printf("Total de bloks alluées : %d",tailleListeBlock(listeOfBlocksAlueted));
    printf("\n************************************************ \n");
}
/**
 * \fn struct DataProgramme createDetailsProgrmme(int nBytes)
 * \brief Fonction who creates and initializes the global variable DataProgramme
 * \param Integer with the size of the memory.
 * \return Instance of the structure DataProgramme.
 *  DataProgramme  store the parameters of the progemme.
 */
struct DataProgramme createDetailsProgrmme(int nBytes){
    struct DataProgramme *d;
    d=malloc(sizeof(struct DataProgramme));
    d->tailleMemoireTotal=nBytes;
    d->AdresseMemoireAcuelle=NULL;
    d->AdresseMemoireMax=NULL;
    d->AdresseMemoireInitiale=NULL;
    d->taillePageDuSysteme=0;
    d->taillePageDuSysteme=getpagesize();
    d->tailleMemoireTotal=0;
    return *d;
}
/**
 * \fn void initUtils(int nBytes)
 * \brief Initialize the lists that the memory blocks will contain.
 * \param Integer with the size of the memory.
 * \return (void).
 */
void initUtils(int nBytes){
    donnesProgramme=createDetailsProgrmme(nBytes);
    listeOfBlocksAlueted=initListe();
    ListOfFreeBlocks=initListe();
}
/**
 * \fn int myfree(void *p)
 * \brief Deallocation of a zone addressed by a pointer.
 * \param[in,out] void .
 * \return void.
 */
int myfree(void *p){
    int i = 0;
    while(listeOfBlocksAlueted != NULL) {
        i++;
        if(listeOfBlocksAlueted->block.data == p) {
            printf("\n ********The block has been deleted***** \n");
            free(listeOfBlocksAlueted);
            listeOfBlocksAlueted = next(listeOfBlocksAlueted);
            p=NULL;
        }
    }

}
/**
 * \fn void divisionOfMemoryZone()
 * \brief Divides the memory zone i block.
 * \param[in,out] void .
 * \return void.
 * Divides the memory zone in different size blocks of 4 , 8 and random between 9 and 100.
 */
void divisionOfMemoryZone(){
    int mD=donnesProgramme.tailleMemoireTotal/2;
    char *AmD=donnesProgramme.AdresseMemoireInitiale+mD;
    int mD2=mD/2;
    char *AmD2=donnesProgramme.AdresseMemoireInitiale+mD2;
    char *AmD3=donnesProgramme.AdresseMemoireInitiale+mD+mD+mD;
    char *AmD4=donnesProgramme.AdresseMemoireMax;
    int pointTap=0;


    /**
    * Divison for 2²
    */
    int a=1;
    char *e=donnesProgramme.AdresseMemoireAcuelle;
    while(e<AmD3 && e<donnesProgramme.AdresseMemoireMax){
        a=a*2;
        e=e+a;
        struct Block block;
        block.taille=a;
        block.data=e;
        inserteteListe(&ListOfFreeBlocks, block);
    }

}
/**
 * \fn ListeBlock getBestBlock(int nBytes)
 * \brief Returns the list with the adequate size to the variable.
 * \param[in] Integer size of the variable.
 * \return Instance of the object ListeBlock if they finds a list, else they return -1.
 */
ListeBlock getBestBlock(int nBytes){
    while(ListOfFreeBlocks != NULL){
        if(nBytes==ListOfFreeBlocks->block.taille || nBytes < ListOfFreeBlocks->block.taille && ListOfFreeBlocks->used!=1){
            ListOfFreeBlocks->used=1;
            return ListOfFreeBlocks;
        }
        ListOfFreeBlocks= next(ListOfFreeBlocks);
    }
    return NULL;
}

void *myrealloc(void *p,int newSize){
    void * newData=myalloc(newSize);
    memcpy(newData, p, sizeof(p));
    myfree(p);
    return (void*) newData;
}