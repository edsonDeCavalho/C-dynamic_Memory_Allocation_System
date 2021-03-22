#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>


#define TAIILEPAGE 4060

//#include "support/parametres.h"

/**
 * Fichier main principal que contient
 * le menu de l'application
 *
 * @param argc
 * @param argv
 * @return
 */

/**
 * Pour mmap:
 * PROT_EXEC  Pages may be executed.
 * PROT_READ  Pages may be read.
 * PROT_WRITE Pages may be written.
 * PROT_NONE  Pages may not be accessed.
 *
 *      RETURN VALUE:
 *          On success, mmap() returns a pointer to the mapped area.  On error, the
 *          value MAP_FAILED (that is, (void *) -1) is returned, and errno  is  set
 *          to indicate the cause of the error.
 *
 *
 *
 */
/*sysconf(_SC_PAGE_SIZE)*/
//int *memoirePourProgremme=0;
int nombreDePages;
int taillePageOs;
char *memoirePourProgremme;
/**
 * Functions a realizer
 */
void initMemory2();
void myfree();
/**
 * Functions Tests
 */
void setNombreDePAges(int NombreDePages);
void test1();
void test_brk();
void setPagesize();
void test_mmap();
void test_Adresse();
void initMemory();

int main(int argc, char *argv[]) {
    initMemory();
    //myfree();
    //printf("Memoire fin :%p \n",memoirePourProgremme);
    //test_mmap();
    //test_Adresse();
    test_brk();
    return 0;
}

void test1(){
    for(int i=0;i<5;i++){
        char *ptr=malloc(5000000);
        printf("Got (memory=%p)\n",ptr);
        printf("Got (taille=%ld)\n",sizeof(ptr));
    }
}
void test_brk(){
    void *first =sbrk(0);
    void *second=sbrk(TAIILEPAGE);
    void *third=sbrk(0);

    printf("First: %p\n",first);
    printf("Second: %p\n",second);
    printf("Third: %p\n",third);
}
void test_mmap(){
    int deux;
    char* first=mmap((void*)0x7fd9d5787000,deux,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    char* second=mmap(NULL,deux,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);

    printf("First: %p\n",first);
    printf("Second:%p\n",second);
}
void setPagesize(){
    taillePageOs=getpagesize();
}
void setNombreDePAges(int NombreDePages){
    nombreDePages=NombreDePages;
}
void initMemory(){
    setNombreDePAges(3);
    setPagesize();
    printf("Memoire avant progrmme est :%p \n",memoirePourProgremme);
    memoirePourProgremme=mmap(NULL,nombreDePages*taillePageOs,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    if(*memoirePourProgremme!=-1){
        printf("La memoire progrmme est :%p \n",memoirePourProgremme);
    }else {
        printf("Erreur dans la alocation de la memoire");
        exit(1);
    }
    char * edson=sbrk(0);
    printf("La memoire progrmme apres brk est :%p \n",edson);

}

void myfree(){
    if(munmap(memoirePourProgremme,nombreDePages*taillePageOs)){
        fprintf(stderr,"Erreur munap");
    }else{
        fprintf(stdout,"Memoire efface");
    }
}

void test_Adresse(){
    int aa = 10; // Your variable 'aa'
    int* aa_ptr = &aa; // 'aa_ptr' contains the address of the variable aa.
    printf("\n");
    printf("The variable 'aa' is at the address %p and contains the value: %d", aa_ptr, *aa_ptr); // '*aa_ptr' would show the value of the variable 'aa'

}

void initMemory2(){



}

