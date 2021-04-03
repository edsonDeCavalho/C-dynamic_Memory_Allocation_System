#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "aboutDataStructure.h"
#include "functions.h"
#include "utils.h"

void menuHelp();
bool file_exists (char *filename);

int main(int argc ,char **argv) {

    switch(argc) {
        case 1:
            /**
             * mode ligne de commande
             */
            printf("Mode Automatique\n");
            return 0;
            break;
        case 2:
            /**
             * mode: interactiv
             */
            if (strcmp(&(*(argv[1])),"-i")==0){
                menuInteractif();
            }
            if(strcmp(&(*(argv[1])),"-h")==0){
                menuHelp();
            }
            break;
        case 3:
            /**
             * mode: batch
             */
            if(strcmp(&(*(argv[1])),"-f")==0){
                if(file_exists(*(&(argv[2])))) {
                    struct TestInstructions *testsInstructions;
                    testsInstructions=malloc(sizeof(struct TestInstructions));
                    *testsInstructions=readFile(argv[2]);
                    for(int i=0;i<testsInstructions->nBoperations;i++){
                        printf("%d  \n",testsInstructions->operations[i].variable)   ;
                        /*Envoie vers MainTest*/
                        //MainTest(testsInstructions->operations[i]);
                    }
                }
                else{
                    fprintf(stderr,"File doesnt exist");
                    exit(1);
                }
            }
            break;
        default:
            break;
    }
    return 0;
}
bool file_exists (char *filename) {
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}

void menuHelp(){
    printf("\n**********************************\n");
    printf("-h to show the help menu\n");
    printf("-i for the interactive mode\n");
    printf("-f  (fichConf) for the mode batch\n");
    printf("**********************************\n\n");
}









