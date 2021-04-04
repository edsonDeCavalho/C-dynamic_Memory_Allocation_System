/*!
 * \file ListeBlock.c
 * \brief Implementation of the functions for the management of ListeBlock objects.
 * \author De Carvalho Edson , Wang Alexandre
 * \date 3 April 2021
 * \version 2.7
 */

#include "ListeBlock.h"
/**
 * \fn ListeBlock initListe()
 * \brief Initilize an ListeBlock
 * \param void
 * \return void
 */
ListeBlock initListe()
{
    return NULL;
}
/**
 * \fn bool estVide(ListeBlock l)
 * \brief Check if a ListeBlock it's NULL or not
 *
 * \param Instance of a liste Block
 * \return Boolean true our false.
 */
bool estVide(ListeBlock l)
{
    return l==NULL;
}
/**
 * \fn void inserteteListe(ListeBlock *l,struct Block block)
 * \brief Insert a new ListeBlock.
 * \param Instance of ListeBlock and an instace of a Block.
 * \return void
 */
void inserteteListe(ListeBlock *l,struct Block block)
{
    ListeBlock cel;
    cel=(ListeBlock)malloc(sizeof(struct cellule));
    cel->block=block;
    cel->suivant=*l;
    *l=cel;
}
/**
 * \fn ListeBlock next(ListeBlock l)
 * \brief Return the next ListBlock
 * \param Instance of an ListeBlock
 * \return Instanceof a ListBlock.
 */
ListeBlock next(ListeBlock l)
{
    return (ListeBlock) l->suivant;
}
/**
 * \fn void diplayListeBlock(ListeBlock l)
 * \brief Displays the ListeBlock.
 *
 * \param Instance of an listBlock
 * \return void.
 */
void diplayListeBlock(ListeBlock l)
{
    int i=0;
    printf(" \n Affichage de la liste : \n \n");
    while(l != NULL)
    {
        printf(" Premiere %d  :  [Adresse : %p ] \n",i,getData(l));
        printf(" Taille de la variable :  [ %d ] \n",getTaille(l));
        printf("\n");
        l = next(l);
        i++;
    }
}
/**
 * \fn struct Block getBlock(ListeBlock l)
 * \brief Returns the block of a ListeBlock.
 * \param Instance of an listBlock
 * \return Instance of an object Block.
 */
struct Block getBlock(ListeBlock l){
    return l->block;
}
/**
 * \fn int tailleListeBlock(ListeBlock l)
 * \brief Returns the size of a ListeBlock.
 * \param Instance of an listBlock
 * \return Integer.
 */
int tailleListeBlock(ListeBlock l){
    int i = 0;
    while(l != NULL) {
        i++;
        l= next(l);
    }
    return i;
}
/**
 * \fn void *getData(ListeBlock l)
 * \brief Returns the data of an ListeBlock.
 * \param Instance of an listBlock
 * \return Pointer.
 */
void *getData(ListeBlock l){
    return (void*)  l->block.data;
}
/**
 * \fn int getTaille(ListeBlock l)
 * \brief Returns the size of a block.
 * \param Instance of an listBlock
 * \return Integer.
 */
int getTaille(ListeBlock l){
    return l->block.taille;
}
