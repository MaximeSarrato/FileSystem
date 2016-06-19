#include <stdio.h>
#include <stdlib.h>
#include "hdd.h"


int main()
{
    printf("File System : START\n");

    int i = 0;

    // Init hard disk
    printf("\n    Init hard drive : START");

    HARD_DISK hardDisk;
    hardDisk.taille = DISK_SIZE;
    hardDisk.nbPartition = NB_PARTITIONS;
    hardDisk.partitions = calloc(NB_PARTITIONS, sizeof(PARTITION));

    printf("    Init hard drive : DONE\n");


    // Create partitions and add them to hard disk
    printf("    Create partitions : START\n");

    // Create and add NB_PARTITIONS to hard drive
    for(i = 0; i<NB_PARTITIONS; i++) {
        PARTITION partition;
        hardDisk.partitions[i] = partition;
    }

    printf("    Create partitions : DONE\n");


    // Make cofee (init all in) with all properties in partitions
    printf("    Init partitions : START\n");

    for(i = 0; i<NB_PARTITIONS; i++) {
        // Init block boot
        BLOCK_BOOT* blockBoot = malloc(sizeof(BLOCK_BOOT));

        if(i == 0) {
            blockBoot->bootPartition = true;
        } else {
            blockBoot->bootPartition = false;
        }

        hardDisk.partitions[i].blockBoot = blockBoot;

        // Init inode list : Nothing to do because no file or directory already in partition
        hardDisk.partitions[i].tabInodes = calloc(1, sizeof(INODE));

        // Init data block area (list of block) : : Nothing to do because no file or directory already in partition
        hardDisk.partitions[i].tabBlocksData = calloc(DISK_SIZE/NB_PARTITIONS, sizeof(BLOCK));

        // Init super block
        SUPER_BLOCK* superBlock = malloc(sizeof(SUPER_BLOCK));

        superBlock->checkIntegrity = false;
        superBlock->systemIdentity = BASE_PARTITION_IDENTITY_LETTER + i;
        superBlock->dataBlocksLength = DISK_SIZE/NB_PARTITIONS;
        superBlock->freeDataBlocksLength = superBlock->dataBlocksLength;


        hardDisk.partitions[i].superBlock = superBlock;
    }

    printf("    Init partitions : DONE\n");


    printf("File System : END\n\n");

    printHardDiskInfo(hardDisk);

    // File creation
    INODE* inodeFichier1 = createFile(&hardDisk,"file1");
    printf("Inode number : %d\n",inodeFichier1->numero);
    INODE* inodeFichier2 = createFile(&hardDisk,"file2");
    printf("Inode number : %d\n",inodeFichier2->numero);
    INODE* inodeFichier3 = createFile(&hardDisk,"file3");
    printf("Inode number : %d\n",inodeFichier3->numero);
    INODE* inodeFichier4 = createFile(&hardDisk,"file4");
    printf("Inode number : %d\n",inodeFichier4->numero);

     return 0;
}
