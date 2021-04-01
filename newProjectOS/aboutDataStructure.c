//
// Created by L'esprit pionnier on 30/03/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "aboutDataStructure.h"


void addHeader(void *pd, int size, int state){
    *(int*) (pd-UNIT_SIZE) = (size-2*UNIT_SIZE)*state;
}

void addFooter(void *pd, int size, int state){
    *(int*) (pd + (size*state-1*UNIT_SIZE)) = size*state - 2*UNIT_SIZE;
}


int *GET_FOOTER_ADR(void *pd){
    return (int *) (pd + GET_SIZE_REAL(abs(GET_HEADER_VALUE(pd))));
}

void * GET_NEXT_BLOCK_ADR(void *pd){
    return (void *) (GET_FOOTER_ADR(pd) + UNIT_SIZE);
}


char *getBlockDataPointer(Block block){
    return block->data;
}
int getBlockSize (Block block){
    return abs( GET_HEADER_VALUE(getBlockDataPointer(block)) );
}


//Check if the previous block is occupied
int checkPrevBlock(Block block){
    return GET_HEADER_VALUE(GET_PREV_BLOCK_ADR(getBlockDataPointer(block))) <= 0;
}

//Check if the next block is occupied
int checkNextBlock(Block block){
    return GET_NEXT_BLOCK_ADR(getBlockDataPointer(block)) <= 0;
}

Block initDataBlock(void *pd){
    Block new = (Block) malloc(sizeof (Block));
    new->data = GET_HEADER_ADR(pd);
    new->data = pd;
    new->footer = GET_FOOTER_ADR(pd);
}


ListBlock initListBlock(Block block){
    ListBlock new = (ListBlock) malloc(sizeof(struct listBlock));
    new->size = GET_HEADER_VALUE(block->data);
    new->block = block;
    new->next = NULL;
    new->last = NULL;
    return new;
}

void deleteList(ListBlock this){
    if (this->last!=NULL)this->last->next=this->next;
    if (this->next!=NULL)this->next->last=this->last;
    free(this);
}

void insertOrderFreeList(ListBlock head, void *pd){
    if (head==NULL){
        head=initListBlock(initDataBlock(pd));
    } else if ((head->next==NULL)||(head->size<GET_HEADER_VALUE(pd))){
        if (head->size<GET_HEADER_VALUE(pd)){
            ListBlock new = initListBlock(initDataBlock(pd));
            new->last = head;
            head->next = new;
        } else{
            ListBlock change =  initListBlock(head->block);
            head->block = initDataBlock(pd);
            head->size = GET_HEADER_VALUE(pd);
            head->next = change;
        }
    }else {
        ListBlock current = head;
        int size = GET_HEADER_VALUE(pd);
        while (current->size<size && current->next!=NULL) {
            current=current->next;
        }
        ListBlock new = initListBlock(initDataBlock(pd));
        current->last->next = new;
        new->last = current->last;
        current->last = new;
        new->next = current;
    }
}

void insertFreeList(ListBlock freeLists[], void *pd){
    int size = GET_HEADER_VALUE(pd);
    if(size>0){
        int position=-5;
        while (size!=0){
            size=size/2;
        }
        if (position<0){
            insertOrderFreeList(freeLists[0], pd);
        } else if (position>=FREE_LIST_NUMBER){
            insertOrderFreeList(freeLists[FREE_LIST_NUMBER - 1], pd);
        }else{
            insertOrderFreeList(freeLists[position], pd);
        }
    } else{
        fprintf(stderr,"Erreur, inser une liste occupé");
    }
}

ListBlock firstFitFreeList(ListBlock freeList, int size){
    ListBlock current = freeList;
    while (current->size<size){
        current=current->next;
    }
    ListBlock new = initListBlock(current->block);
    new->size=size;
    deleteList(current);
    return new;
}

ListBlock findFreeList(ListBlock freeLists[], int nBytes){
    int size = nBytes;
    if(size>0){
        int position=-5;
        while (size!=0){
            size=size/2;
        }
        if (position<0){
            firstFitFreeList(freeLists[0], nBytes);
        } else if (position>=FREE_LIST_NUMBER){
            firstFitFreeList(freeLists[FREE_LIST_NUMBER - 1], nBytes);
        }else{
            firstFitFreeList(freeLists[position], nBytes);
        }
    } else{
        fprintf(stderr,"Erreur, inser une liste occupé");
    }
}

void insertUserList(ListBlock head, ListBlock list){
    if (head==NULL){
        head=list;
    }
    ListBlock position = head;
    while (position->next!=NULL){
        position=position->next;
    }
    position->next=position;
    list->last=position;
}

void freeUserList(ListBlock userLists, void *p, ListBlock freeLists[]) {
    ListBlock position = userLists;
    while (position->block->data!=p&&position!=NULL){
        position=position->next;
    }
    if (position==NULL){
        fprintf(stderr,"Element n'exist pas!");
    } else{
        freeBusyList(freeLists,position);
    }
}

ListBlock findUserList(ListBlock userList, void *p) {
    ListBlock current = userList;
    while (current != NULL){
        if (userList->block->data==p)break;
        current=current->next;
    }
    if (current == NULL){
        fprintf(stderr,"Element n'exist pas!");
        return NULL;
    } else{
        return current;
    }
}



void freeBusyList(ListBlock freeLists[], ListBlock listToFree){
    fusionList(freeLists,initListBlock(listToFree->block));
    free(listToFree);
}



void fusionList(ListBlock freeLists[], ListBlock newList){
    void *actual = newList->block->data;
    *(newList->block->header)=abs(*(newList->block->header));
    *(newList->block->footer)=abs(*(newList->block->footer));

    int size = GET_HEADER_VALUE(GET_NEXT_BLOCK_ADR(actual));
    if( size > 0){
        size = size + GET_HEADER_VALUE(actual) + 2*UNIT_SIZE;
        deleteFusionInfo(GET_NEXT_BLOCK_ADR(actual));
        addHeader(actual,size,STATE_FREE);
        addFooter(actual,size,STATE_FREE);
    }

    size = GET_HEADER_VALUE(GET_PREV_BLOCK_ADR(newList->block->data));
    if ( size > 0){
        size = size + GET_HEADER_VALUE(actual) + 2*UNIT_SIZE;
        void *t = GET_PREV_BLOCK_ADR(actual);
        deleteFusionInfo(GET_NEXT_BLOCK_ADR(actual));
        actual = t;
        addHeader(actual,size,STATE_FREE);
        addFooter(actual,size,STATE_FREE);
    }

    free(newList);
    insertFreeList(freeLists,actual);
}


void deleteFusionInfo(void*pd){
    * (int *) (pd-UNIT_SIZE) = NULL;
    * (int *) (pd-UNIT_SIZE*2) = NULL;
}

