#include <stdio.h>
#include <string.h>
#include "aboutDataStructure.h"
#include "functions.h"
#include "utils.h"
#include "test.h"

void choixDeMenu(int argc);



int main(int argc ,char **argv) {
   // choixDeMenu(2);
    readFileInstructions();
    return 0;
}

void choixDeMenu(int argc){
    switch(argc) {
        case 1:
            break;
        case 2:
                menuInteractif();
            //}
            //if (strcmp(&argv,"-h")==0){
            //    printf("Mod: Help");
            //}
            /*else{
                printf(stderr,"Erreur parametres erronnées consulter le menu help -h\n");
            }*/
            break;
        case 3:
            break;
        default:
            break;
    }
}












