#include "fichier.h"
/***************************************
 *
 * Function of file creation which returns the file's inode.
 *
 ***************************************/

INODE* createFile(HARD_DISK* disk, char* fileName, int* sizeTabInode, int fileSize){
    printf("\n        ---CREATEFILE\n");

    int i,j,k;

    // File declaration
    FICHIER file;
    file.fileName=fileName;

    // Inode declaration
    INODE inode;
    inode.numero=fileNumber;

    // File size (a block can support 1024 bytes)
    // We could improve that by using the size of a given file in parameter of function
    file.fileSize=fileSize; // The file takes two blocks
    file.inode=inode;
    file.inode.numero=fileNumber;

    // Upgrade the size of the Inode array at each time we create a new file
    disk->partitions[0].tabInodes = realloc (disk->partitions[0].tabInodes, sizeTabInode+1 * sizeof(INODE));

    // Calculation of blocks needed
    double blocksNeeded;
    blocksNeeded = (float)file.fileSize / BLOC_SIZE;
    blocksNeeded = ceil(blocksNeeded); // Rounded to the next integer to obtain the blocks needed
    printf("\nWe need %d blocks to store the file : %s\n",(int)blocksNeeded,file.fileName);

    // Find the first block unused
    int firstFreeBlock = 0;
    for(i=0; i<NB_PARTITIONS; i++) { //
        for(j=0; j<DISK_SIZE; j++) { //
            // In case of the block is already allocated
            if(disk->partitions[i].tabBlocksData[j].etat==1) {
                printf("The block %d is already allocated. Looking for the next block.\n",j);
                firstFreeBlock++;
            }
        }
    }

    // Number of blocks allocated and their numbers in the array
    for(i=0; i<NB_PARTITIONS; i++) { // In the first partition
            for(j=firstFreeBlock; j<firstFreeBlock+blocksNeeded; j++) { // Start loop with the first free block to the number of blocks needed
                disk->partitions[i].tabBlocksData[j].fichier=file;
                disk->partitions[i].tabBlocksData[j].etat=1;
                for(k=0; k<BLOC_SIZE; k++) { // Fill the data block with data
                    disk->partitions[i].tabBlocksData[j].donnees[k]="";
                    // printf("Donn�es contenues : %s\n",disk->partitions[i].tabBlocksData[j].donnees[k]);
                    }
                }
                // Inode association with the file and the blocks which contains file's data.
                disk->partitions[i].tabInodes[fileNumber].numero=fileNumber;
                printf("Inode number of \"%s\" is : %d \n",fileName,disk->partitions[i].tabInodes[fileNumber].numero);
                disk->partitions[i].tabInodes[fileNumber].premierBloc=firstFreeBlock;
                disk->partitions[i].tabInodes[fileNumber].dernierBloc=firstFreeBlock+blocksNeeded-1;
                printf("The data of the file \"%s\" have been stored in the block %d.\n",file.fileName,disk->partitions[i].tabInodes[fileNumber].premierBloc);

            }
    sizeTabInode++;
    fileNumber++; // Incrementation of the number of files

    return &inode;
}

/***************************************
 *
 * Function of print of current number
 * of files stored on the HDD.
 *
 ***************************************/
void printFileNumber() {
    printf("\nCurrently there is %d file(s) stored in the hard drive.\n",fileNumber);
}

/***************************************
 *
 * Function which permits to read a
 * a file.
 *
 ***************************************/
void readFile(HARD_DISK* disk, INODE* inode, int nbBytes) {
    printf("\n        ---READFILE\n");
    int i,j,k,firstBlock,lastBlock;
    int numInode = inode->numero; // Recuperation of the inode number

    // Blocks which contain the file's data
    // Could be improved with the partition in parameter partitions[0]
    firstBlock = disk->partitions[0].tabInodes[numInode].premierBloc;
    lastBlock = disk->partitions[0].tabInodes[numInode].dernierBloc;

    for(i=0; i<NB_PARTITIONS; i++) { // In the first partition
        for(j=firstBlock; j<=lastBlock; j++) {
                printf("In the block %d : %s, case %d \n",j,disk->partitions[i].tabBlocksData[j].donnees[0], 0);
        }
   }
}

/***************************************
 *
 * Function of open/creation file
 * which returns the file's inode.
 *
 ***************************************/

INODE* openFile (HARD_DISK* disk, char* fileName, int* sizeTabInode) {
    printf("\n        ---OPENFILE\n");
    int i,j;
    bool fileExists = false;
    INODE* inodeFile;

    for(i=0; i<NB_PARTITIONS; i++) {
        for(j=0;j<DISK_SIZE;j++) {
            if(disk->partitions[i].tabBlocksData[j].fichier.fileName == fileName) { // If the file exists
                fileExists = true;
                printf("The file %s already exists in the block %d of the %c partition.\n"
                       ,fileName,j,(char)BASE_PARTITION_IDENTITY_LETTER);
                // Storage of the inode number
                inodeFile->numero=disk->partitions[i].tabBlocksData[j].fichier.inode.numero;
                printf("Inode of the existing file : \"%s\" is %d\n",fileName,inodeFile->numero);
            }

        }
        // The file exists then open it (read data)
        if(fileExists == true) {
            readFile(disk,inodeFile,5); // Read of 5 bytes of the existing file
        }
        else if (fileExists == false) {
            inodeFile = createFile(disk,fileName,sizeTabInode,0);
        }
    }
    return &inodeFile;
 }


void writeFile(HARD_DISK* disk, INODE* inode, int nbBytes, char* data) {
    printf("\n        ---WRITEFILE\n");
    int i,j,k,firstBlock,lastBlock;
    int numInode = inode->numero; // Recuperation of the inode number

    // Blocks which contain the file's data
    // Could be improved with the partition in parameter partitions[0]
    firstBlock = disk->partitions[0].tabInodes[0].premierBloc;
    lastBlock = disk->partitions[0].tabInodes[0].dernierBloc;
    for(i=0; i<NB_PARTITIONS; i++) { // In the first partition
        // If bytes of the file is smaller than a BLOC_SIZE
        // Filling only one block
        if (nbBytes < BLOC_SIZE) {
            for(j=firstBlock; j<=firstBlock; j++) {
                for(k=0; k<nbBytes; k++) {    // Read the number of bytes asked
                    disk->partitions[0].tabBlocksData[j].donnees[k]=data;
                    printf("In the block %d : %s, case %d \n",j,disk->partitions[i].tabBlocksData[j].donnees[k], k);
                }
                disk->partitions[0].tabBlocksData[j].fichier.fileSize = nbBytes;
            }

        }
        // If the number of bytes need 2 blocks to be stored
        else if (nbBytes > BLOC_SIZE && nbBytes < 2048) {
                for(j=firstBlock;j<firstBlock+1;j++) {
                    for(k=0; k<BLOC_SIZE; k++) {    // Read the number of bytes asked
                        disk->partitions[0].tabBlocksData[j].donnees[k]=data;
                     //   printf("In the block %d : %s, case %d \n",j,disk->partitions[i].tabBlocksData[j].donnees[k], k);
                    }
                }
                for(j=lastBlock;j<lastBlock+1;j++) {
                    for(k=0; k<(nbBytes-BLOC_SIZE); k++) {
                        disk->partitions[0].tabBlocksData[j].donnees[k]=data;
                     //   printf("In the block %d : %s, case %d \n",j,disk->partitions[i].tabBlocksData[j].donnees[k], k);
                    }
                }
                // Length of the file in attribute
                disk->partitions[0].tabBlocksData[firstBlock].fichier.fileSize = nbBytes;
                disk->partitions[0].tabBlocksData[lastBlock].fichier.fileSize = nbBytes;
        }

    }
    // Allocate supplementary blocks if the file needs more than 2 blocks to be stored
    // Should be necessary to use an array for each inode where we would store each number
    // of blocks which are containing the data of a given file
}

bool fileExists(HARD_DISK* disk, char * fileName){
//    FICHIER fichier;
//    FICHIER.fileName = filename;
    int i,j;
    for(i=0; i<NB_PARTITIONS; i++) {
        for(j=0;j<DISK_SIZE;j++) {
            if(disk->partitions[i].tabBlocksData[j].fichier.fileName == fileName) { // If the file exists
                return true;
            }
        }
    }
    return false;
}

INODE* getInode(HARD_DISK* disk, char* fileName){
    int i,j;
    INODE* inode;

    for(i=0; i<NB_PARTITIONS; i++)
        for(j=0;j<DISK_SIZE;j++)
            if (fileExists(disk, fileName))
                return &disk->partitions[i].tabBlocksData[j].fichier.inode;

    return inode;
}


