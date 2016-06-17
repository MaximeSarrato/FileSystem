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


//HARD_DISK initHDD (char* nomHDD, unsigned int tailleHDD);
HARD_DISK initBlockTab(unsigned int taille);















#endif // __HDD
