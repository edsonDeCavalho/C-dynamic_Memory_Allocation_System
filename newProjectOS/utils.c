//
// Created by nudian on 01/04/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "utils.h"
#include "functions.h"


int getTille(struct TestInstructions testinstructions){
    return testinstructions.taille;
}

int getNbOperations(struct TestInstructions testinstructions){
    return testinstructions.nBoperations;
}

void menuInteractif(){
    printf("*******************************");
    printf("\n Mod : Interactive menu\n");
    printf("*******************************");
    struct Operation operation;
    operation=creationOfAnOperation();
    printf("%d\n",operation.operation);
    printf("%d\n",operation.reallocValue);
    printf("%d\n",operation.value);
    printf("%d\n",operation.variable);
    Test(operation);
}


struct Operation creationOfAnOperation(){
    struct Operation *operation;
    operation=malloc(sizeof(struct Operation));
    operation->variable=0;
    operation->variable=0;
    operation->value=0;
    operation->reallocValue=0;
    printf(" \n Select the nature of the variable:\n");
    printf("1: char\n");
    printf("2: short int\n");
    printf("3: long int\n");
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
    scanf("%d",&operation->value);
    return *operation;
}

void Test(struct Operation operation){
    char *variableChar;
    short int *variableShortInt;
    int *varibleInt;
    switch(operation.variable){
        case 1:
            varibleInt=(int)myalloc(sizeof(int));
            varibleInt=operation.value;
            if(operation.reallocValue!=0){
                myrealloc(&varibleInt,operation.reallocValue);
            }
            myfree(&varibleInt);
            break;
        case 2:
            variableShortInt=(short int )myalloc(sizeof(short int ));
            variableShortInt=operation.value;
            if(operation.reallocValue!=0){
                myrealloc(&variableShortInt,operation.reallocValue);
            }
            myfree(&variableShortInt);
            break;
        case 3:
            variableChar=(char)myalloc(sizeof(char));
            variableChar=operation.value;
            if(operation.reallocValue!=0){
                myrealloc(&variableChar,operation.reallocValue);
            }
            myfree(&variableChar);
            break;
        default:
            printf("Error choix variable");
    }
}
