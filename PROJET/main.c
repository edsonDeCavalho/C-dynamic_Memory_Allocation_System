#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>


char *MAX_ADRESSE;
int NOMBRE_DE_PAGES;
int TAILLE_PAGE_OS;
int *DEJA_ALLUE;
char *MEMOIRE_INITIALE;
char *MEMOIRE_ACTUELLE;
char *REGION_DE_ADRESSE_LIVRE;


/**
 * Functions a realizer
 */
int initMemory(int nBytes);
void* myalloc(int nBytes);
void setPagesSize();
void incrementationMemoire(int incrementation);
void setPagesSize();



int main(int argc, char *argv[]) {
    initMemory(34);
    int *a=myalloc(sizeof(int));
    printf("Adresse de a=%p",&a);
    printf("Ponteur memoire total 1: %p",MEMOIRE_INITIALE);
    printf("Ponteur memoire incrementeé : %p",MEMOIRE_ACTUELLE);
    return 0;
}

int initMemory(int nBytes){
    setPagesSize();
    if(MEMOIRE_INITIALE=mmap(NULL,nBytes,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0)){
        MEMOIRE_ACTUELLE=MEMOIRE_INITIALE;
        incrementationMemoire(30);
        return 0;
    }
    else{
        fprintf(stderr,"Erreur en allocation de debut");
        return -1;
    }
}
void* myalloc(int nBytes){
    incrementationMemoire(nBytes);
    return (void *)sbrk(nBytes) ;
}
void incrementationMemoire(int incrementation){
    if(incrementation>0){
        MEMOIRE_ACTUELLE=MEMOIRE_ACTUELLE+incrementation;
    }else{
        fprintf(stderr,"ERREUR dans l'incrementation de memoire");
    }
}
void setPagesSize(){
    TAILLE_PAGE_OS=getpagesize();
}
