#include "hdd.h"

/********************************************
 * Print the different hard disk informations
 ********************************************/

void printHardDiskInfo(HARD_DISK hardDisk) {
    int i;

    printf("Hard Disk size : %d\n", hardDisk.taille);
    for(i = 0; i < hardDisk.nbPartition; i++) {
        if(i>0) {
            printf("    *******************************\n");
        }
        printf("    Partition name : %c\n", hardDisk.partitions[i].superBlock->systemIdentity);
        printf("    Boot partition : %d\n", hardDisk.partitions[i].blockBoot->bootPartition);
        printf("    Data blocks : %d\n", hardDisk.partitions[i].superBlock->dataBlocksLength);
        printf("    Free data blocks : %d\n", hardDisk.partitions[i].superBlock->freeDataBlocksLength);
        printf("    Need to check integrity : %d\n", hardDisk.partitions[i].superBlock->checkIntegrity);
    }
}

/***************************************
 * Print the number of free blocks
 **************************************/

void printFreeBlocks(HARD_DISK disk) {
    int i,j;
    unsigned int freeBlocks = DISK_SIZE;

    for(i=0; i<NB_PARTITIONS; i++) { //
        for(j=0; j<DISK_SIZE; j++) { //
            // If a block is used
            if(disk.partitions[i].tabBlocksData[j].etat==1) {
                    freeBlocks--;
            }
        }
        printf("It currently still %d free blocks.\n",freeBlocks);
    }
}
