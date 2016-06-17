#include "hdd.h"
#include <stdio.h>
#include <stdlib.h>

//HARD_DISK initHDD(char* nomHDD, unsigned int tailleHDD)
//{
//    HARD_DISK hdd;
//    nomHDD.taille=tailleHDD;
//    nomHDD.tabBlock[tailleHDD];
//
//    return nomHDD;
//
//}


HARD_DISK initBlockTab(unsigned int taille)
{
    HARD_DISK disk;
    disk.taille = taille;
    disk.tabBlock = malloc(sizeof(BLOCK)* taille);
    int i;
    for(i=0;i<disk.taille;i++)
    {
        BLOCK *monBloc;
        monBloc = malloc(sizeof(BLOCK));
        disk.tabBlock[i]=*monBloc;                                 // Association du Block avec sa case dans le tableau de Blocks
        disk.tabBlock[i].numero=i;                               // Initialisation des numéros de blocks de 0 à Taille du DD -1
        disk.tabBlock[i].etat=0;                                 // On met tous les blocks à l'état vide
        printf("Bloc numéro = %d\n",disk.tabBlock[i].numero);
        printf("Fichier du bloc %d : %s\n",i,disk.tabBlock[i].fichier.nom);
        printf("Etat du bloc : %d\n",disk.tabBlock[i].etat);
    }
    printf("Les %d blocs ont bien été initialisés.\n",disk.taille);

    return disk;
}

