#ifndef __HDD.H__
#define __HDD.H__
#include "donnees.h"


/***************************************
 *
 * Définition de la structure du HDD
 *
 ***************************************/

typedef struct HARD_DISK
 {
     unsigned int taille;
     BLOCK* tabBlock;

 }HARD_DISK;


HARD_DISK initBlockTab(unsigned int taille);
void readDataBloc(HARD_DISK disk, unsigned int numBloc);




#endif // __HDD
