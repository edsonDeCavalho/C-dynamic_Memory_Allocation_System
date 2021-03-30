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


int *GET_FOOTER_ADR(void *pd){
    return (int *) (pd + GET_SIZE_REAL(abs(GET_HEADER_VALUE(pd))));
}

int GET_NEXT_BLOCK_INFO(void *pd){
    return *(int *) (GET_FOOTER_ADR(pd) + UNIT_SIZE);
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

Block initDataBlock(void *pd){
    Block new = (Block) malloc(sizeof (Block));
    new->data = GET_HEADER_ADR(pd);
    new->data = pd;
    new->footer = GET_FOOTER_ADR(pd);
}


ListBlock initListBlock(void *pd){
    ListBlock new = (ListBlock) malloc(sizeof(struct listBlock));
    new->size = GET_HEADER_VALUE(pd);
    new->block = initDataBlock(pd);
    return new;
}

void insertOrderList(ListBlock head, void *pd){
    ListBlock current = head;
    int size = GET_HEADER_VALUE(pd);
    while (current->size<size) {
        current=current->next;
    }



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










