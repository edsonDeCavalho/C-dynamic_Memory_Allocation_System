//
// Created by nudian on 01/04/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "aboutDataStructure.h"


//Tests show that void* is a kind of char*, so we move the position by unit 'byte'
static void *myMemoryPool;
static ListBlock myFreeLists[FREE_LIST_NUMBER];
static ListBlock myUserList;

/*
int initMemory(int nBytes){
    int local = INIT_MEMORY_SIZE(nBytes);
    if((myMemoryPool=(void*)malloc(INIT_MEMORY_SIZE(nBytes)))==NULL){
        fprintf(stderr,"Erreur dans la allocation de la memoire initiale");
        return 1;
    }
    else{
        printf("Memoire allueée avec succées!!!!!!! %d \n",local);

        Footer firstCase = myMemoryPool + local - 2*UNIT_SIZE;
        Header lastCase = myMemoryPool + UNIT_SIZE;
        Footer initHeader = myMemoryPool ;
        printf("Erreur25 initHeader=%p,=%p",initHeader, myMemoryPool);
        Header initFooter = myMemoryPool + local - UNIT_SIZE;
        void *firstBlock = myMemoryPool+2*UNIT_SIZE;
        *initHeader = 0;
        printf("Erreur initHeader=%p,=%p",initHeader, myMemoryPool);
        *initFooter = 0;
        firstBlock += UNIT_SIZE;
        addHeader(firstBlock,(local-2*UNIT_SIZE),STATE_FREE);
        addFooter(firstBlock,(local-2*UNIT_SIZE),STATE_FREE);

        for (int i=0;i<FREE_LIST_NUMBER;i++){
            myFreeLists[i]=(ListBlock) malloc(sizeof(struct listBlock));
        }
        insertFreeList(myFreeLists, firstBlock);

        myUserList = (ListBlock) malloc(sizeof(struct listBlock));


    }

    short int t = 16;
    printf("Memoire allueée avec succées??????????? %d \n",t==local);

    return 0;
}
*/

int freeMemory(){
    free(myMemoryPool);
}


void* myalloc(int nBytes){
    ListBlock new = findFreeList(myFreeLists, nBytes);
    new->size=nBytes;
    *(new->block->header)*=STATE_BUSY;
    *(new->block->footer)*=STATE_BUSY;
    insertUserList(myUserList,new);
    return new->block->data;
}
int myfree(void* p){
    freeUserList(myUserList, p, myFreeLists);
}
void* myrealloc(void *p, int nBytes){
    myfree(p);
    p = myalloc(nBytes);
    return p;

}