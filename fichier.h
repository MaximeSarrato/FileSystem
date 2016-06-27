#include "hdd.h"
#include "donnees.h"
INODE* createFile(PARTITION* diskPartition, char* file, int* sizeTabInode, int fileSize);
void printFileNumber();
void readFile(HARD_DISK* disk, INODE* inode, int nbBytes);
INODE* openFile (HARD_DISK* disk, char* fileName, int* sizeTabInode);
void writeFile(HARD_DISK* disk, INODE* inode, int nbBytes);
