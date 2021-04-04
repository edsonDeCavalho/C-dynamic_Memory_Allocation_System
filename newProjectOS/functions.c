/*!
 * \file functions.c
 * \brief The main memory management functions are implemented in this file.
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */
#include "functions.h"
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
 * Function pour alluer de la memoire pour une variable dans le
 * espace memoire reserveé pour le programme.
 * @param nBytes
 * @return
 */
void* myalloc(int nBytes){

    int tailleVariable=nBytes;
    /*Incrementation Memoire*/
    char *ancienneAdresse=donnesProgramme.AdresseMemoireAcuelle;
    if((nBytes<0) || (donnesProgramme.AdresseMemoireAcuelle>donnesProgramme.AdresseMemoireMax)){
        fprintf(stderr,"Segmente defaoult d'hors de la memoire autorisée");
        displayMemoryStatus();
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

        /*Creation de header*/
        struct Block block;
        /*Recuperation de l' adresse*/
        //block.data=calculPourLaPage(ancienneAdresse,nBytes);
        block.data=donnesProgramme.AdresseMemoireAcuelle;
        block.taille=nBytes;
        /*Ajout dans la liste*/
        inserteteListe(&listeOfBlocksAlueted, block);
        /*En return le block->data*/

        displayMemoryStatus();
        return (void*) block.data;
    }
}
/**
 * \fn void *myalloc(int nBytes)
 * \brief Function to go from memory for a variable.
 * \param nteger with the size of the variable.
 * \return Adresse ou NULL.
 *  Function to go from memory for a variable to the memory space reserved for the program.
 */
void *myalloc2(int nBytes){
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
    d->taillePageDuSysteme=NULL;
    d->taillePageDuSysteme=getpagesize();
    d->tailleMemoireTotal=NULL;
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
            printf("The block has been delated \n");
            free(listeOfBlocksAlueted);
            free(p);
            listeOfBlocksAlueted = next(listeOfBlocksAlueted);
        }
    }
    return i;
}
/**
 * \fn void divisionOfMemoryZone()
 * \brief Divides the memory zone i block.
 * \param[in,out] void .
 * \return void.
 * Divides the memory zone in different size blocks of 4 , 8 and random between 9 and 100.
 */
void divisionOfMemoryZone(){
    int *memp=donnesProgramme.AdresseMemoireInitiale+donnesProgramme.tailleMemoireTotal;
    int mD=donnesProgramme.tailleMemoireTotal/2;
    char *AmD=donnesProgramme.AdresseMemoireInitiale+mD;
    char *AmD2=donnesProgramme.AdresseMemoireInitiale+mD+mD;
    char *AmD3=donnesProgramme.AdresseMemoireInitiale+mD+mD+mD;
    char *AmD4=donnesProgramme.AdresseMemoireMax;
    int pointTap=0;
    srand( time( NULL ) );
    int searchedValue = rand() % 101;
    /**
     * Division for 4 bits
     */
     char *i=donnesProgramme.AdresseMemoireAcuelle;
     while(i<AmD && i<donnesProgramme.AdresseMemoireMax){
         i=i+4;
         struct Block block;
         block.taille=4;
         block.data=i;
         inserteteListe(&ListOfFreeBlocks, block);
     }
    /**
    * Division for 8 bits
    */
     printf("AMd2 :\n");
     char *f=AmD;
     while(f<AmD2 && f<donnesProgramme.AdresseMemoireMax){
         f=f+8;
         struct Block block;
         block.taille=8;
         block.data=f;
         inserteteListe(&ListOfFreeBlocks, block);
     }
     /**
      * Divison for 2²
      */
      printf("AMd3\n");
      int a=4;
      char *e=AmD2;
      while(e<AmD3 && e<donnesProgramme.AdresseMemoireMax){
          a=a*2;
          e=e+a;
          struct Block block;
          block.taille=a;
          block.data=e;
          inserteteListe(&ListOfFreeBlocks, block);
      }
      /**
       * Divison for 5⁵ (if it's possible)
       */
    int b=5;
    char *t=AmD3;
    while(t<AmD4 && t<donnesProgramme.AdresseMemoireMax){
        a=a*5;
        t=t+a;
        struct Block block;
        block.taille=a;
        block.data=t;
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
        if(nBytes==ListOfFreeBlocks->block.taille){
            return ListOfFreeBlocks;
        }
        ListOfFreeBlocks= next(ListOfFreeBlocks);
    }
    return -1;
}