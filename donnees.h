#ifndef __DONNEES__
#define __DONNEES__

#include <stdbool.h>

#define BLOC_SIZE 1024

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
    INODE inodeParent;
    INODE inode;
    int repertoire; // 0 si c'est un fichier 1 si c'est un répertoire
    char* nom;
    int taille;
    char* donnees[BLOC_SIZE];

} FICHIER;


/***************************************
 *
 * Définition d'une structure BLOCK
 *
 ***************************************/

 typedef struct BLOCK
 {
     FICHIER fichier;          // Fichier ou répertoire qu'il contient
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


/***************************************
 *
 * Structure de données des repertoires
 *
 ***************************************/

typedef struct REPERTOIRE
{
    char* name;             // Nom du fichier
    int inode;              // Numéro de l'inode
    int nbFic;              // Nombre de fichiers qu'il contient
    int nbRep;              // nombre de répertoires qu'il contient
} REPERTOIRE;



#endif // __DONNEES__
