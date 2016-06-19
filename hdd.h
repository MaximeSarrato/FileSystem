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


void printHardDiskInfo(HARD_DISK hardDisk);


#endif // __HDD

