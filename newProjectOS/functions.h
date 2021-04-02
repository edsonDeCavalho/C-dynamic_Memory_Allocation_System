//
// Created by nudian on 01/04/2021.
//

int initMemory (int nBytes);
int freeMemory();
void* myalloc(int nBytes);
int myfree(void* p);
void* myrealloc(void *p, int nBytes);