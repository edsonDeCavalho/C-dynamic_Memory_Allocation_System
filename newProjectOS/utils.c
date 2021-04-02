//
// Created by nudian on 01/04/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "utils.h"
#include "functions.h"




void menuInteractif(){
    printf("*******************************");
    printf("\n Mod : Interactive menu\n");
    printf("*******************************");
    struct Operation *operation;
    operation=malloc(sizeof(struct Operation));
    *operation=entryOftheOperation();
    printf(" Operation : %d\n",operation->operation);
    printf("Reealloc Value :%d\n",operation->reallocValue);
    printf("Char value : %d\n",operation->valueChar);
    printf("Variable type : %d\n",operation->variable);
    MainTest(&operation);
}


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

void MainTest(struct Operation *operation){
    int *varibleInt;
    char *variableChar;
    switch(operation->variable){
        case 1:
            varibleInt=(int)myalloc(sizeof(int));
            varibleInt=1;
            if(operation->reallocValue!=0){
                myrealloc(&varibleInt,operation->reallocValue);
            }
            myfree(&varibleInt);
        case 2:
            variableChar=(char)myalloc(sizeof(char));
            variableChar=operation->valueChar;
            if(operation->reallocValue!=0){
                myrealloc(&variableChar,operation->reallocValue);
            }
            myfree(&varibleInt);
            break;
    }
}

struct TestInstructions readFile(const char *file){
    struct TestInstructions *tests;
    tests=malloc(sizeof(struct TestInstructions));
    int n,i;
    FILE *fp;
    fp=fopen(file,"r");
    if(fp==NULL){
        printf("\nError : File is not present");
        exit(1);
    }
    for(i=0;i<3;i++){
        struct Operation *operation;
        operation=malloc(sizeof(struct Operation));
        fscanf(fp,"%d %d %d %d",&operation->variable,&operation->operation,&operation->reallocValue,&operation->valueInt);
        printf("\n %d %d %d %d",operation->variable,operation->operation,operation->reallocValue,operation->valueInt);
        tests->operations[i]=*operation;
        tests->nBoperations++;
    }
    fclose(fp);
    return *tests;
}