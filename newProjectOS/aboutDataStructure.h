//
// Created by L'esprit pionnier on 30/03/2021.
//

#ifndef NEWPROJECTOS_ABOUTDATASTRUCTURE_H
#define NEWPROJECTOS_ABOUTDATASTRUCTURE_H

#endif //NEWPROJECTOS_ABOUTDATASTRUCTURE_H

//Define unit as computer default, normally 4
#define UNIT_SIZE sizeof(int)
#define STATE_FREE 1
#define STATE_BUSY -1

#define FREE_LIST_NUMBER 8



//Well it seems needs to have double word for initialization, but it's still crazy to write this, but very good for relieve stress
#define INIT_MEMORY_SIZE(size) ((size+UNIT_SIZE-1)/UNIT_SIZE+1)/2*2*UNIT_SIZE

//Change the statement as: Value:(absolute value = size) Signe:(positive - available / negative - occupied )
//PS:'short int' was considered to be used here, but more hard to access, so dropped this idea
typedef int* Header;
typedef int* Footer;

void addHeader(void *pd, int size, int state);
void addFooter(void *pd, int size, int state);


//Our basic structure for (free) list, and we use pointer of char for data as it's more safe to return as void*
typedef struct block{
    Header header;
    void *data;
    Footer footer;
}*Block;

Block initDataBlock(void *pd);

//Actually we regard the address of data as the pointer return to user
char *getBlockDataPointer(Block block);

int getBlockSize (Block pb);
int checkPrevBlock(Block pb);
int checkNextBlock(Block pb);


typedef struct listBlock{
    int size;
    Block block;
    struct listBlock *last;
    struct listBlock *next;
}*ListBlock;

ListBlock initListBlock(Block block);

#define LIST_HOME_SIZE
//#define ListBlock[LIST_HOME_SIZE] MY_LIST


void insertFreeList(ListBlock freeLists[], void *pd);
void insertUserList(ListBlock head, ListBlock list);

ListBlock firstFitFreeList(ListBlock freeList, int size);
ListBlock findFreeList(ListBlock freeLists[], int nBytes);

ListBlock findUserList(ListBlock userList, void *p);

void freeUserList(ListBlock userLists, void *p, ListBlock freeLists[]);
void freeBusyList(ListBlock freeLists[], ListBlock listToFree);
void fusionList(ListBlock freeLists[], ListBlock newList);
void deleteFusionInfo(void*pd);


int countListSpace ();




//As the real allocation byte will be converted to word, we need the real size of space
#define GET_SIZE_REAL(value) ((value+UNIT_SIZE-1)%UNIT_SIZE)

//Get block's header info base on the address of block
#define GET_POINTER_VALUE(p) ( *(int *) )
#define GET_HEADER_ADR(pb) ( (pb-UNIT_SIZE) )
#define GET_HEADER_VALUE(pb) ( *(int *) GET_HEADER_ADR(pb) )
#define GET_PREV_BLOCK_ADR(pb) ( (void *) (pb-2*UNIT_SIZE) )
//Unfortunately we cannot use macro for footer as we dont know the signe, small pain but okay
int *GET_FOOTER_ADR(void *pd);
void * GET_NEXT_BLOCK_ADR(void *pd);






















