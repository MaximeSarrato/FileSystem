#include "directory.h"
INODE* createFile(HARD_DISK* disk, char* file, int* sizeTabInode, int fileSize);
void printFileNumber();
void readFile(HARD_DISK* disk, INODE* inode, int nbBytes);
INODE* openFile (HARD_DISK* disk, char* fileName, int* sizeTabInode);
void writeFile(HARD_DISK* disk, INODE* inode, int nbBytes, char* data);
bool fileExists(HARD_DISK* disk, char * fileName);
INODE* getInode(HARD_DISK* disk, char* fileName);
