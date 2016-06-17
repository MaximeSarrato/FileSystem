#include "hdd.h"
#include <stdio.h>
#include <stdlib.h>
/*
HARD_DISK initHDD(char* nomHDD, unsigned int tailleHDD)
{
    HARD_DISK hdd;
    nomHDD.taille=tailleHDD;
    nomHDD.tabBlock[tailleHDD];

    return nomHDD;

}
*/

BLOCK* initBlockTab (HARD_DISK disk, unsigned int taille)
{
    int i;
    disk.tabBlock[taille];
    for(i=0;i<10;i++)
    {
        BLOCK *monBloc;
        monBloc = malloc(sizeof(BLOCK));
        disk.tabBlock[i]=monBloc;                                 // Association du Block avec sa case dans le tableau de Blocks
        disk.tabBlock[i]->numero=i;                               // Initialisation des numéros de blocks de 0 à Taille du DD -1
        disk.tabBlock[i]->etat=0;                                 // On met tous les blocks à l'état vide
        printf("Bloc numéro = %d\n",disk.tabBlock[i]->numero);
        printf("Fichier du bloc %d : %s\n",i,disk.tabBlock[i]->fichier.nom);
        printf("Etat du bloc : %d\n",disk.tabBlock[i]->etat);
    }
    printf("Les %d blocs ont bien été initialisés.\n",taille);

    return *disk.tabBlock;
}
