/*!
 * \file main.c
 * \brief Ex
 *
 *
 * \version 1.0
 * \date 17/02/2020
 */

/*!
 * \mainPage Examplede pqqqqqrogrmmme :
 * \con
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"
#include "ListeBlock.h"
#include "utils.h"


int main(){
    initMemory(15);
    //initMemory(500);
    ListeBlock listBlock;
    listBlock=initListe();
    inserteteListe(0,2,&listBlock);
    inserteteListe(0,2,&listBlock);
    inserteteListe(0,2,&listBlock);
    inserteteListe(0,2,&listBlock);
    inserteteListe(0,2,&listBlock);
    inserteteListe(0,2,&listBlock);
    afficheListe(listBlock);

    return 0;
}

