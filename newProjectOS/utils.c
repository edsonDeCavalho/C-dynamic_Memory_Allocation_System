/*!
 * \file utils.c
 * \brief File who contains all of the structures to help doing the differents
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "functions.h"
/**
 * \fn void menuInteractif(void)
 * \brief First function in interactive mode, wh lunch the interactive test.
 * \param [in] void
 * \return void
 * \date 3 April 2021
 */
void menuInteractif(){
    printf("*******************************");
    printf("\n Mod : Interactive menu\n");
    printf("*******************************");
    struct Operation *operation;
    operation=malloc(sizeof(struct Operation));
    *operation=entryOftheOperation();
    printf("Value of the variable %d",operation->valueInt);
    printf("Operation : %d\n",operation->operation);
    printf("Reealloc Value :%d\n",operation->reallocValue);
    printf("Variable type : %d\n",operation->variable);
    MainTest(operation);
}
/**
 * \fn struct Operation entryOftheOperation()
 * \brief Second function in interactive mode, retrieves the parameters indicated by the user.
 * \param [in] void
 * \return  Instance of type Operation.
 * \date 3 April 2021
 */
struct Operation entryOftheOperation(){
    struct Operation *operation;
    operation=malloc(sizeof(struct Operation));

    printf(" \n Select the nature of the variable:\n");
    printf("1: int\n");
    printf("2: char\n");
    int scan;
    scanf("%d",&scan);
    operation->variable=scan;
    printf("Select the operation that you whant to make:\n");
    printf("1: Memory allocation->realloc->free memory\n");
    printf("2: Memory Allocation->free memory\n");
    printf("3: Memory Allocation->realloc\n");
    scanf("%d",&scan);
    operation->operation=scan;
    if(operation->operation==1 || operation->operation==3){
        printf("Select the value of the reallloc: \n");
        scanf("%d",&operation->reallocValue);
    }
    printf("Select a value for the variable:\n");
    if(operation->variable==2){
        scanf("%c",&operation->valueChar);
    }
    else{
        scanf("%d",&operation->valueInt);
    }
    return *operation;
}
/**
 * \fn void MainTest(struct Operation *operation)
 * \brief Second function in interactive mode, retrieves the parameters indicated by the user.
 * \param [in] Operation
 * \return void
 * \date 3 April 2021
 */
void MainTest(struct Operation *operation){
    //int *varibleInt;
    //initMemory(1000);
    char *variableChar;
    printf("Hello");
    int a=1;
    switch(a){
        case 1:
            printf("Hello");
            int *varibleInt;
            varibleInt=(int*)myalloc(40);
            *varibleInt=500;
            printf("Valeur de la variable entier : %ls \n",varibleInt);
            printf("Adresse of the integer : %p\n",&varibleInt);
           /* if(operation->reallocValue!=0){
                //realloc(&varibleInt,operation->reallocValue);
            }*/
            //free(&operation);
            printf("Sortie");
            break;
        case 2:

            variableChar=(char*)malloc(sizeof(char));
            /*
            *variableChar=operation->valueChar;
            if(operation->reallocValue!=0){
                myrealloc(&variableChar,operation->reallocValue);
            }
            myfree(&varibleInt);
            break;
             */
    }
}
/**
 * \fn struct TestInstructions readFile(const char *file)
 * \brief This function read the file with the operations instructions and bld objects of the type Operation.
 * \param [in] file an object type char who contains the name of the file.
 * \return TestInstructions a array with objects of the type Operation
 * \date 3 April 2021
 */
struct TestInstructions readFile(const char *file){
    struct TestInstructions *tests;
    tests=malloc(sizeof(struct TestInstructions));
    int nBLines=3;
    int n,i;
    FILE *fp;
    fp=fopen(file,"r");
    if(fp==NULL){
        printf("\nError : File is not present");
        exit(1);
    }
    for(i=0;i<=nBLines;i++){
        struct Operation *operation;
        operation=malloc(sizeof(struct Operation));
        fscanf(fp,"%d %d %d %d",&operation->variable,&operation->operation,&operation->reallocValue,&operation->valueInt);

        tests->operations[i]=*operation;
        tests->nBoperations++;
    }
    fclose(fp);
    return *tests;
}
/**
 * \fn int numberOfLines(const char *file)
 * \brief This function read the file with the operations instructions to count the number of lines.
 * \param [in] file an object type char who contains the name of the file.
 * \return number of lines
 * \date 3 April 2021
 */
int numberOfLines(const char *file){
    FILE *fptr;
    int ctr = 0;
    char c;

    fptr = fopen(file, "r");
    if (fptr == NULL)
    {
        printf("Could not open file %s", file);
        return 0;
    }
    // Extract characters from file and store in character c
    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n') // Increment count if this character is newline
            ctr = ctr + 1;
    fclose(fptr);
    return ctr;
}


