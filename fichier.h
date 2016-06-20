#include "hdd.h"
int fileNumber=0;

INODE* createFile(HARD_DISK* disk, char* file, int* sizeTabInode);
void printFileNumber();
void readFile(HARD_DISK* disk, INODE* inode, int nbBytes);
//INODE* openFile (HARD_DISK* disk, char* fileName, int* sizeTabInode);
