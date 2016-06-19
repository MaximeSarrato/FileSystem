#include "fichier.h"

INODE* createFile(HARD_DISK* disk, char* fileName){

    int i,j,k;

    // File declaration
    FICHIER file;
    file.fileName=fileName;

    // Inode declaration
    INODE inode;
    inode.numero=fileNumber;

    // File size (a block can support 1024 bytes)
    file.fileSize=2048; // The file takes two blocks
    file.inode=inode;
    file.inode.numero=fileNumber;

    // Calculation of blocks needed
    double blocksNeeded;
    blocksNeeded = (float)file.fileSize / BLOC_SIZE;
    blocksNeeded = ceil(blocksNeeded);
    printf("blocksNeeded = %d\n",(int)blocksNeeded);

    // Find the first block unused
    int firstFreeBlock = 0;
    for(i=0; i<NB_PARTITIONS; i++){ //
        for(j=0; j<DISK_SIZE; j++){ //
            // In case of the block is already allocated
            if(disk->partitions[i].tabBlocksData[j].etat==1){
                printf("Le bloc %d est déjà alloué",j);
                firstFreeBlock++;
            }
        }
    }

    // Number of blocks allocated and their numbers in the array
    for(i=0; i<NB_PARTITIONS; i++){ // In the first partition
            for(j=firstFreeBlock; j<firstFreeBlock+blocksNeeded; j++){ // Start loop with the first free block to the number of blocks needed
                for(k=0; k<BLOC_SIZE; k++){ // Fill the data block with data
                    disk->partitions[i].tabBlocksData[j].donnees[k]="Données fichier";
                    // printf("Données contenues : %s\n",disk->partitions[i].tabBlocksData[j].donnees[k]);
                    }
                }
                // Inode association with the file and the blocks which contains file's data.
                disk->partitions[i].tabInodes[fileNumber].numero=fileNumber;
                disk->partitions[i].tabInodes[fileNumber].premierBloc=firstFreeBlock;
                disk->partitions[i].tabInodes[fileNumber].dernierBloc=firstFreeBlock+blocksNeeded-1;
            }
    fileNumber++; // Incrementation of the number of files

    return &inode;
}


