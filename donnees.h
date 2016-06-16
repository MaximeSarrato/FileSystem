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
    char* nom;
    int taille;

} FICHIER;


/***************************************
 *
 * Définition du Super Bloc
 *
 ***************************************/


 #define SIGNATURE_SUPER_BLOCK      (0xBD43FF23)

 typedef struct SUPER_BLOCK
 {
     int signature;         // Signature du FileSystem
     int adresseRep;        // Adresse du 1er bloc allouable
 }SUPER_BLOCK;



 /***************************************
 *
 * Définition d'un type de bloc
 *
 ***************************************/


 typedef union
 {
     SUPER_BLOCK super;
    // BLOCK_REP rep;
     INODE inode;
    // BLOCK fichier;
 }TYPE_BLOCK;


 /***************************************
 *
 * Définition d'une structure BLOCK
 *
 ***************************************/

 typedef struct BLOCK
 {
     FICHIER fichier;   // Fichier ou répertoire qu'il contient
     int numero;      // Numéro du bloc
     int etat;
 }BLOCK;



#endif // __DONNEES__
