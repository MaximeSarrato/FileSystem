#include "hdd.h"
#include <stdio.h>
#include <stdlib.h>


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
