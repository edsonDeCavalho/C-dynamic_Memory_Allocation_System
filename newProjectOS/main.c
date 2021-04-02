#include <stdio.h>
#include <string.h>
#include "aboutDataStructure.h"
#include "functions.h"
#include "utils.h"


void choixDeMenu(int argc);



int main(int argc ,char **argv) {
    initMemory(300);
    menuInteractif();
    //readFile(argv[1]);
    return 0;
}

void choixDeMenu(int argc){
    switch(argc) {
        case 1:
            break;
        case 2:
            menuInteractif();
            break;
        case 3:
            break;
        default:
            break;
    }
}












