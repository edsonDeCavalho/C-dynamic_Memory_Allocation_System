#include <stdio.h>
#include <string.h>
#include "support/parametres.h"

/**
 * Fichier main principal que contient
 * le menu de l'application
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[]) {
    printf("Bien venu au Progrmme de alocation Memoire!\n");

        if (strcmp(&(*(argv[1])),"-i")==0){
            printf("%c \n");

        }
        if (strcmp(&(*(argv[1])),"-f")==0){
            printf("Vous avez   choisie mode interactif \n");
        }
        if (strcmp(&(*(argv[1])),"-i")==0){
            printf("Vous avez choisie mode interactif \n");
        }
    return 0;
}






