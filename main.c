#include <stdio.h>
#include <stdlib.h>
#include "hdd.h"


int main()
{
    printf("File System : START\n");

    int i = 0;
    int* sizeTabInode = 1; // At beginning it have only one case
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


    // Make coffee (init all in) with all properties in partitions
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

        // Init inode list
        hardDisk.partitions[i].tabInodes = calloc(sizeTabInode, sizeof(INODE));

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
    INODE* inodeFichier1 = createFile(&hardDisk,"file1",&sizeTabInode);
    INODE* inodeFichier2 = createFile(&hardDisk,"file2",&sizeTabInode);
    INODE* inodeFichier3 = createFile(&hardDisk,"file3",&sizeTabInode);
    INODE* inodeFichier4 = createFile(&hardDisk,"file4",&sizeTabInode);
    INODE* inodeFichier5 = createFile(&hardDisk,"file5",&sizeTabInode);
    INODE* inodeFichier6 = createFile(&hardDisk,"file6",&sizeTabInode);
    INODE* inodeFichier7 = createFile(&hardDisk,"file7",&sizeTabInode);
    INODE* inodeFichier8 = createFile(&hardDisk,"file8",&sizeTabInode);

    readFile(hardDisk,inodeFichier1,1024);



    printFileNumber();

    // Deallocate all
    free(hardDisk.partitions);
    free(hardDisk.partitions->blockBoot);
    free(hardDisk.partitions->superBlock);
    free(hardDisk.partitions->tabInodes);
    free(hardDisk.partitions->tabBlocksData);

    return (EXIT_SUCCESS);
}
