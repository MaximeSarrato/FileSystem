#include <stdio.h>
#include <stdlib.h>
#include "hdd.h"

#define DISK_SIZE 16
#define NB_PARTITIONS 2
#define BASE_PARTITION_IDENTITY_LETTER 67 // Is ASCII code for C letter

int main()
{
    printf("File System : START");
    lineReturn();

    int i = 0;

    // Init hard disk
    printf("    Init hard drive : START");
    lineReturn();

    HARD_DISK hardDisk;
    hardDisk.taille = DISK_SIZE;
    hardDisk.nbPartition = NB_PARTITIONS;
    hardDisk.partitions = calloc(NB_PARTITIONS, sizeof(PARTITION));

    printf("    Init hard drive : DONE");
    lineReturn();


    // Create partitions and add them to hard disk
    printf("    Create partitions : START");
    lineReturn();

    // Create and add NB_PARTITIONS to hard drive
    for(i = 0; i<NB_PARTITIONS; i++) {
        PARTITION partition;
        hardDisk.partitions[i] = partition;
    }

    printf("    Create partitions : DONE");
    lineReturn();


    // Make cofee (init all in) with all properties in partitions
    printf("    Init partitions : START");
    lineReturn();

    for(i = 0; i<NB_PARTITIONS; i++) {
        // Init block boot
        BLOCK_BOOT* blockBoot = malloc(sizeof(BLOCK_BOOT));

        if(i == 0) {
            blockBoot->bootPartition = true;
        } else {
            blockBoot->bootPartition = false;
        }

        hardDisk.partitions[i].blockBoot = blockBoot;
        lineReturn();

        // Init inode list : Nothing to do because no file or directory already in partition

        // Init data block area (list of block) : : Nothing to do because no file or directory already in partition
        hardDisk.partitions[i].tabBlocksData = calloc(DISK_SIZE/NB_PARTITIONS, sizeof(BLOCK));

        // Init super block
        SUPER_BLOCK* superBlock = malloc(sizeof(SUPER_BLOCK));

        superBlock->checkIntegrity = false;
        superBlock->systemIdentity = BASE_PARTITION_IDENTITY_LETTER + i;
        superBlock->dataBlocksLength = DISK_SIZE/NB_PARTITIONS;
        superBlock->freeDataBlocksLength = superBlock->dataBlocksLength;

        hardDisk.partitions[i].superBlock = superBlock;
        lineReturn();
    }

    printf("    Init partitions : DONE");
    lineReturn();


    printf("File System : END");
    lineReturn();

    printHardDiskInfo(hardDisk);

    return 0;
}

void printHardDiskInfo(HARD_DISK hardDisk) {
    int i;

    printf("Hard Disk size : %d", hardDisk.taille);
    lineReturn();
    for(i = 0; i < hardDisk.nbPartition; i++) {
        if(i>0) {
            printf("    *******************************");
            lineReturn();
        }
        printf("    Partition name : %c", hardDisk.partitions[i].superBlock->systemIdentity);
        lineReturn();
        printf("    Boot partition : %d", hardDisk.partitions[i].blockBoot->bootPartition);
        lineReturn();
        printf("    Data blocks : %d", hardDisk.partitions[i].superBlock->dataBlocksLength);
        lineReturn();
        printf("    Free data blocks : %d", hardDisk.partitions[i].superBlock->freeDataBlocksLength);
        lineReturn();
        printf("    Need to check integrity : %d", hardDisk.partitions[i].superBlock->checkIntegrity);
        lineReturn();
    }
}

void lineReturn() {
    printf("\n");
}
