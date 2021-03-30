//
// Created by L'esprit pionnier on 30/03/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "aboutDataStructure.h"


void *addHeader(void *pd, int size, int state){
    void *after = pd + UNIT_SIZE;
    *(int*) pd = (size-2*UNIT_SIZE)*state;
    return after;
}

void addFooter(void *pd, int size, int state){
    *(int*) (pd + (size-1*UNIT_SIZE)*state) = size*state - 2*UNIT_SIZE;
}


int *GET_FOOTER_ADR(Block block){
    return (int *) (block + GET_SIZE_REAL(abs((block))));
}

int GET_NEXT_BLOCK_INFO(Block block){
    return *(int *) (GET_FOOTER_ADR(block) + UNIT_SIZE);
}


char *getBlockDataPointer(Block block){
    return block->data;
}
int getBlockSize (Block block){
    return abs( GET_HEADER_VALUE(getBlockDataPointer(block)) );
}


//Check if the previous block is occupied
int checkPrevBlock(Block block){
    return GET_PREV_BLOCK_INFO(getBlockDataPointer(block)) <= 0;
}

//Check if the next block is occupied
int checkNextBlock(Block block){
    return GET_NEXT_BLOCK_INFO(getBlockDataPointer(block)) <= 0;
}



ListBlock initListBlock(){
    return (ListBlock) malloc(sizeof(struct listBlock));
}

void insertOrderList(ListBlock head, void *pd){
    int size = GET_HEADER_VALUE(pd);
    while ()

}

void insertFreeList(ListBlock freeLists[], void *pd){
    int size = GET_HEADER_VALUE(pd);
    if(size>0){
        switch (size/32) {
            case 0:
                freeLists
            
        }
        
        
    } else{
        fprintf(stderr,"Erreur, inser une liste occupé");
    }

}

void insertUserList(ListBlock head, ListBlock list);










