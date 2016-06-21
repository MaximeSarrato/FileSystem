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
    // Adding directory informations to the container block
    for(i=0; i<NB_PARTITIONS; i++) { // In the first partition
        for(j=firstFreeBlock; j<firstFreeBlock+1; j++) { // Start loop with the first free block to the number of blocks needed
            disk->partitions[i].tabBlocksData[j].directory.dirName=dirName;
            disk->partitions[i].tabBlocksData[j].directory.inode=dirInode;
            disk->partitions[i].tabBlocksData[j].etat=1;
            disk->partitions[i].tabBlocksData[j].directory.nbSlots=NB_MAX_FILES;
            // Initialization of the array files of the directory
            // Supposing a directory can strictly contains a maximum of 4 files
            disk->partitions[0].tabBlocksData[j].directory.files = calloc(NB_MAX_FILES,sizeof(FICHIER));
        }
            // Inode association with the directory.
        disk->partitions[i].tabInodes[fileNumber].numero=fileNumber;
        disk->partitions[i].tabInodes[fileNumber].premierBloc=firstFreeBlock;
        disk->partitions[i].tabInodes[fileNumber].dernierBloc=firstFreeBlock;
        printf("\nThe inode number of \"%s\" is : %d \n",dirName,disk->partitions[i].tabInodes[fileNumber].numero);
        printf("The directory \"%s\" have been stored in the block %d.\n\n",dirName,disk->partitions[i].tabInodes[fileNumber].premierBloc);
    }
    fileNumber++;
}

/*************************************
* Function of empty directory deletion
**************************************/
void rmdir(HARD_DISK* disk, char* dirName) {
    bool emptyDirectory = false;
    bool existingDirectory = false;
    int i,j,k;
    int numInode, blockContainer;
    printf("\nAsking for suppression of file \"%s\" in progress... \n",dirName);
    // Browse the blocks of our partitions
    for(i=0; i<NB_PARTITIONS; i++) { //
        for(j=0; j<DISK_SIZE; j++) { //
            // If the directory exists (issue : if 2 directories have the same name
            // both will be deleted
            if(disk->partitions[i].tabBlocksData[j].directory.dirName==dirName) {
                    blockContainer = j;
                    printf("blockContainer = %d\n",blockContainer);
                    existingDirectory = true;
                    numInode = disk->partitions[i].tabBlocksData[j].directory.inode.numero;
                    // Browse of the directory's files
                    for(k=0; k<NB_MAX_FILES; k++) { // For the moment a directory can just contain 4 files
                        if(disk->partitions[i].tabBlocksData[j].directory.files[k].fileName==NULL) {
                            emptyDirectory = true;
                        }
                        else {
                            emptyDirectory = false;
                            printf("%s \n",disk->partitions[i].tabBlocksData[j].directory.files[k].fileName);
                            printf ("The directory \"%s\" is not empty. Impossible to delete it.\n",dirName);
                            printf("The directory contains : %s \n",disk->partitions[i].tabBlocksData[j].directory.files[k].fileName);
                        }
                    }
            }
        }
        if(emptyDirectory) {
            printf ("The directory \"%s\" is empty.\n",dirName);
            disk->partitions[i].tabBlocksData[blockContainer].directory.dirName=NULL;
            disk->partitions[i].tabInodes[numInode].numero=NULL;
            disk->partitions[i].tabBlocksData[blockContainer].etat=0;
            printf("The directory \"%s\" has been deleted\n",dirName);
            fileNumber--;
    }
    }
    if(existingDirectory == false) {
            printf("The directory \"%s\" doesn't exists.\n",dirName);
    }
}

/*************************************
* Function which permits to put an
* existing file in a directory
**************************************/
void link(HARD_DISK* disk, char* dirName, char* fileName) {

    int i, j, k, directoryBlock, firstFreeSlot;
    FICHIER file;
    DIRECTORY directory;
    bool existingFile = false;
    bool existingDirectory = false;
    firstFreeSlot = NB_MAX_FILES;

    // Looking if the file and the directory exists
    for(i=0; i<NB_PARTITIONS; i++) { //
        for(j=0; j<DISK_SIZE; j++) { //
            if(disk->partitions[i].tabBlocksData[j].fichier.fileName == fileName) {
                existingFile = true;
                file = disk->partitions[i].tabBlocksData[j].fichier;
                file.inode = disk->partitions[i].tabBlocksData[j].fichier.inode;
            }
            else if (disk->partitions[i].tabBlocksData[j].directory.dirName == dirName) {
                    existingDirectory = true;
                    directory = disk->partitions[i].tabBlocksData[j].directory;
                    directoryBlock = j;
            }
        }
    }
    // If the directory and the file exist then i check if the directory has a free slot
    if(existingFile && existingDirectory) {
        for(i=0; i<NB_PARTITIONS; i++) { //
            for(j=0; j<DISK_SIZE; j++) { //
                for(k=0; k<NB_MAX_FILES; k++)
                    // Searching the first free slot
                    if(disk->partitions[i].tabBlocksData[directoryBlock].directory.files[k].inDirectory==false) {
                        firstFreeSlot = k;
                    }
            }
            // If the directory have not empty slot
            if (firstFreeSlot == NB_MAX_FILES) {
                printf("The directory \"%s\" is full, can't store file \"%s\".\n",dirName,fileName);

            }
        }
    }

    // If one of those elements does not exist
    else if (existingDirectory == false || existingFile == false) {
            printf("The directory \"%s\" or ",dirName);
            printf("the file \"%s\" doesn't exist in %c partition.\n",fileName,(char)BASE_PARTITION_IDENTITY_LETTER);
    }

    // If directory is not full system can add the file
    if (firstFreeSlot < NB_MAX_FILES) {
        for(i=0; i<NB_PARTITIONS; i++) {
            for(j=0; j<NB_MAX_FILES; j++) {
                disk->partitions[i].tabBlocksData[directoryBlock].directory.files[firstFreeSlot].fileName=fileName;  // Set file name
                disk->partitions[i].tabBlocksData[directoryBlock].directory.files[firstFreeSlot].inode = file.inode; // Set file inode
                disk->partitions[i].tabBlocksData[directoryBlock].directory.files[firstFreeSlot].inDirectory = true;
            }
        }
        printf("The file \"%s\" has been added in the directory \"%s\" at slot %d.\n",fileName,dirName,firstFreeSlot);
    }
}
