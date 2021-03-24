#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



char *memoireInitiale;
char *memoireMax;
char *memoireActuelle;
int tailleDePageDeSysteme;

/*Functions Demandées*/
void initMemory();
void* myalloc(int nbytes);
/*Functions utils*/
int calculTaille(int tailleVariable);
void setTaileDePageSysteme();
void setMemoireActuelle(char nouvelleMemoire);

int main(){

    initMemory(50);

    printf("Memoire initiale %p \n",memoireInitiale);
    printf("Memoire Max %p\n",memoireMax);
    printf("Memoire Actuelle %p\n",memoireActuelle);
    int *a;
    printf("Taille variable %ld\n",sizeof(int));
    a=(int)myalloc(sizeof(int));

    printf("Adresse variable %p\n",a);
    printf("Memoire Actuelle %p\n",memoireActuelle);

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
        return 0;
    }else{
        memoireActuelle=tailleVariable+memoireActuelle;
        return (void *)ancienneAdresse;
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