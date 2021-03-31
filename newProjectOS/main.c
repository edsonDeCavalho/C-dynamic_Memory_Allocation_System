#include <stdio.h>
#include <stdlib.h>
#include "aboutDataStructure.h"

int initMemory (int nBytes);
int freeMemory();
void* myalloc(int nBytes);
int myfree(void* p);
void* myrealloc(int nBytes);

//Tests show that void* is a kind of char*, so we move the position by unit 'byte'
void *myMemoryPool;
ListBlock myFreeLists[FREE_LIST_NUMBER];
ListBlock myUserList;

int main() {
    initMemory(10);

    freeMemory();
    return 0;
}


int initMemory(int nBytes){
    int local = INIT_MEMORY_SIZE(nBytes);
    if((myMemoryPool=(int*)malloc(INIT_MEMORY_SIZE(nBytes)))==NULL){
        fprintf(stderr,"Erreur dans la allocation de la memoire initiale");

        Header initHeader = myMemoryPool ;
        Footer initFooter = myMemoryPool + local - UNIT_SIZE;
        void *firstBlock = myMemoryPool+UNIT_SIZE;
        *initHeader = 0;
        *initFooter = 0;
        firstBlock += UNIT_SIZE;
        addHeader(firstBlock,(local-2*UNIT_SIZE),STATE_FREE);
        addFooter(firstBlock,(local-2*UNIT_SIZE),STATE_FREE);

        for (int i=0;i<FREE_LIST_NUMBER;i++){
            myFreeLists[i]=(ListBlock) malloc(sizeof(struct listBlock));
        }
        insertFreeList(myFreeLists, firstBlock);

        myUserList = (ListBlock) malloc(sizeof(struct listBlock));

        return 1;
    }
    else{
        printf("Memoire allueée avec succées %d \n",local);
    }

    short int t = 16;
    printf("Memoire allueée avec succées %d \n",t==local);

    return 0;
}


int freeMemory(){
    free(myMemoryPool);
}


void* myalloc(int nBytes){
    ListBlock new = findFreeList(myFreeLists, nBytes);
    insertUserList(myUserList,new);
}
int myfree(void* p){
    freeUserList(myUserList, p, myFreeLists);
}
void* myrealloc(int nBytes);













