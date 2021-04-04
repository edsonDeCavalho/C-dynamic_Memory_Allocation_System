/*!
 * \file main.c
 * \brief File that contains de main test whith the main function, with the 3 different mods
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
//#include "aboutDataStructure.h"
//#include "functions.h"
#include "utils.h"
#include "functions.h"
/**
 * Declaration of the functions used to help in the tests
 */
void menuHelp();
bool file_exists (char *filename);
/**
 * \fn int main (int argc ,char **argv)
 * \brief Launch function main of the 3 execution mods with the project
 * \param [in] argc
 * \param [in] argv
 * \return void
 * \date 3 April 2021
 */

int main(int argc ,char **argv) {
    /*En function de la taille du tableau avec les argumets en prcede a effectuer un mode*/

    switch(argc) {
        case 1:
            /**
             * mode ligne de commande
             */
            initMemory(1000);
            menuInteractif();
            break;
        case 2:
            /**
             * mode: interactiv
             */
            if (strcmp(&(*(argv[1])),"-i")==0){
                initMemory(500);
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
                        //MainTest(&testsInstructions->operations[i]);
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
/**
 * \fn bool file_exists (char *filename)
 * \brief Check if a file exists or not
 * \param filename [in]  Name of the to check in char
 * \return Boolean who can be true or false
 */
bool file_exists (char *filename) {
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}
/**
 * \fn bool file_exists (char *filename)
 * \brief Display how to do to lunch the 3 mods of tests
 * \return (void)
 */
void menuHelp(){
    printf("\n**********************************\n");
    printf("-h to show the help menu\n");
    printf("-i for the interactive mode\n");
    printf("-f  (fichConf) for the mode batch\n");
    printf("**********************************\n\n");
}









