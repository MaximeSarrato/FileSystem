#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include "hdd.h"


#define MAX 1024
#define MAX_NB 50

int nbMots(char* str, char caracSep);
void launchShell(HARD_DISK* disk);
int recupCommande(char* str, HARD_DISK* disk);
void retireCarac(char* str, char carac);
void separe(char* str, char** mots, int nbLettres, char caracSep);
int commandePerso(char* str, char** mots, int taille, HARD_DISK* disk);
void echo(char** str, int taille, HARD_DISK* disk);
