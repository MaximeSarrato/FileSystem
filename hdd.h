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
     unsigned int nbPartition;
     PARTITION* partitions;

 }HARD_DISK;


HARD_DISK initBlockTab(unsigned int taille);
void readBlocData(HARD_DISK disk, unsigned int numBloc);




#endif // __HDD
