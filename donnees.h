#ifndef __DONNEES__
#define __DONNEES__

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOC_SIZE 1024
#define DISK_SIZE 16
#define NB_PARTITIONS 1
#define BASE_PARTITION_IDENTITY_LETTER 67 // Is ASCII code for C letter
#define NB_MAX_FILES 4

int fileNumber;

/***************************************
 *
 * Structure de donnees des inodes
 *
 ***************************************/

typedef struct INODE
{
    int numero;
    int longueur;           // Taille du fichier en octets
    int premierBloc;        // Numéro du premier bloc
    int dernierBloc;        // Numéro du dernier bloc
}INODE;


/***************************************
 *
 * Définition d'une structure FICHIER
 *
 ***************************************/

typedef struct FICHIER
{
    INODE inode;
    char* fileName;
    int fileSize;
    char* donnees[BLOC_SIZE];
    bool inDirectory;

} FICHIER;

/***************************************
 *
 * Structure de données des repertoires
 *
 ***************************************/

typedef struct DIRECTORY
{
    char* dirName;             // Nom du fichier
    INODE inode;              // Numéro de l'inode
    INODE parentInode;
    FICHIER* files;
    int nbSlots;
    int nbDirectory;          // nombre de répertoires qu'il contient
} DIRECTORY;


/***************************************
 *
 * Définition d'une structure BLOCK
 *
 ***************************************/

 typedef struct BLOCK
 {
     FICHIER fichier;
     DIRECTORY directory;
     unsigned int numero;      // Numéro du bloc
     int etat;
     char* donnees[BLOC_SIZE];
     char* typeBlock;

 }BLOCK;


/***************************************
 *
 * Définition d'une structure BLOCK_BOOT
 *
 ***************************************/

 typedef struct BLOCK_BOOT
 {
     bool bootPartition;

 }BLOCK_BOOT;


/***************************************
 *
 * Définition d'une structure SUPER_BLOCK
 *
 ***************************************/

 typedef struct SUPER_BLOCK
 {
     int systemIdentity;
     unsigned int dataBlocksLength;
     unsigned int freeDataBlocksLength;
     bool checkIntegrity;

 }SUPER_BLOCK;


/***************************************
 *
 * Structure de partition
 *
 ***************************************/
 typedef struct PARTITION
 {
    BLOCK_BOOT* blockBoot;
    SUPER_BLOCK* superBlock;
    INODE* tabInodes;
    BLOCK* tabBlocksData;
 } PARTITION;

#endif // __DONNEES__
