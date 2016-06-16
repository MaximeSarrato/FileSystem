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
     long int taille;
     BLOCK* tabBlock[];


 }HARD_DISK;
















#endif // __HDD
