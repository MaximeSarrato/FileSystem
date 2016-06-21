#include "directory.h"

/*********************************
 * Function of directory creation
 *********************************/

void mkdir(HARD_DISK* disk, char* dirName) {
    int i,j;
    int firstFreeBlock = 0;

    // Inode declaration
    INODE dirInode;
    dirInode.numero=fileNumber;

    // Research of the first free block where we can store the directory
    for(i=0; i<NB_PARTITIONS; i++) { //
        for(j=0; j<DISK_SIZE; j++) { //
            // In case of the block is already allocated
            if(disk->partitions[i].tabBlocksData[j].etat==1) {
                printf("The block %d is already allocated. Looking for the next block.\n",j);
                firstFreeBlock++;
            }
        }
    }

    for(i=0; i<NB_PARTITIONS; i++) { // In the first partition
        for(j=firstFreeBlock; j<firstFreeBlock+1; j++) { // Start loop with the first free block to the number of blocks needed
            disk->partitions[i].tabBlocksData[j].directory.dirName=dirName;
            disk->partitions[i].tabBlocksData[j].directory.inode=dirInode;
            }
                    // Inode association with the directory.
                    disk->partitions[i].tabInodes[fileNumber].numero=fileNumber;
                    disk->partitions[i].tabInodes[fileNumber].premierBloc=firstFreeBlock;
                    disk->partitions[i].tabInodes[fileNumber].dernierBloc=firstFreeBlock;
                    printf("\nThe inode number of \"%s\" is : %d \n",dirName,disk->partitions[i].tabInodes[fileNumber].numero);
                    printf("The directory \"%s\" have been stored in the block %d.\n",dirName,disk->partitions[i].tabInodes[fileNumber].premierBloc);

                }
    fileNumber++;
}
