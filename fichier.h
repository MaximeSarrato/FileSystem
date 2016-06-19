#include "hdd.h"
int fileNumber=0;
INODE* createFile(HARD_DISK* disk, char* file);
void printFileNumber();
void readFile(HARD_DISK* disk, INODE* inode, int nbBytes);

