//
// Created by nudian on 02/04/2021.
//

#include "test.h"
//
// Created by nudian on 02/04/2021.
//
#include <stdio.h>
#include <stdlib.h>



void readFileInstructions(){
    int n,i;
    FILE *fp;
    fp=fopen("functions.c","r");
    if(fp==NULL){
        printf("\nError : File is not present");
        exit(1);
    }
    for(i=1;i<=10;i++){
        fscanf(fp,"%d",&n);
        printf("\n %d",n);
    }
    fclose(fp);
}
