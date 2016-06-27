#ifndef HDD.H
#define HDD.H

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

void printFreeBlocks(HARD_DISK disk);


#endif // __HDD

