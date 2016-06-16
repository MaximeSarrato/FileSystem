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
     BLOCK* tabBlock[64000];


 }HARD_DISK;
















#endif // __HDD
