#include "fichier.h"
#include "donnees.h"
void mkdir(HARD_DISK* disk, char* dirName);
void rmdir(HARD_DISK* disk, char* dirName);
void link(HARD_DISK* disk, char* dirName, char* fileName);
void unlinkFile(HARD_DISK* disk, char* dirName, char* fileName);
