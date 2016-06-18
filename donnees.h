#ifndef __DONNEES__
#define __DONNEES__


/***************************************
 *
 * Structure de données des repertoires
 *
 ***************************************/

#define FILENAME        (32 - sizeof(int))

typedef struct REPERTOIRE
{
    char name [FILENAME];   // Nom du fichier
    int inode;              // Numéro de l'inode
    int nbFic;              // Nombre de fichiers qu'il contient
    int nbRep;              // nombre de répertoires qu'il contient
} REPERTOIRE;


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
    char* donnees[1024];

} FICHIER;


 /***************************************
 *
 * Définition d'un tableau d'Inode pour le 3e Bloc
 *
 ***************************************/


 typedef struct
 {
    INODE* tabInode;

 }INODE_TAB;


 /***************************************
 *
 * Définition d'une structure BLOCK
 *
 ***************************************/
#define BLOC_SIZE 1024
 typedef struct BLOCK
 {
     FICHIER fichier;   // Fichier ou répertoire qu'il contient
     unsigned int numero;      // Numéro du bloc
     int etat;
     char* donnees[BLOC_SIZE];
     char* typeBlock;

 }BLOCK;



#endif // __DONNEES__
