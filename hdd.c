#include "hdd.h"
#include <stdio.h>
#include <stdlib.h>


/***************************************
 *
 * Fonction d'initialisation du HDD et de ses Blocs
 *
 ***************************************/
HARD_DISK initBlockTab(unsigned int taille)
{
    HARD_DISK disk;
    disk.taille = taille;
    disk.tabBlock = malloc(sizeof(BLOCK)* taille);
    int i,j;
    for(i=0;i<disk.taille;i++)
    {
        BLOCK *monBloc;
        monBloc = malloc(sizeof(BLOCK));
        disk.tabBlock[i]=*monBloc;                                 // Association du Bloc avec sa case dans le tableau de Blocs
        disk.tabBlock[i].numero=i;                               // Initialisation des numéros de blocks de 0 à Taille du DD -1
        disk.tabBlock[i].etat=0;
        printf("Bloc numéro = %d\n",disk.tabBlock[i].numero);
        printf("Fichier du bloc %d : %s\n",i,disk.tabBlock[i].fichier.nom);
        printf("Etat du bloc : %d\n",disk.tabBlock[i].etat);
        for (j=0;j<BLOC_SIZE;j++)
        {
            disk.tabBlock[i].donnees[j]="a";
        }
    }
    printf("Les %d blocs ont bien été initialisés.\n",disk.taille);

    return disk;
}

void readDataBloc(HARD_DISK disk, unsigned int numBloc)
{
    int i;
    for(i=0;i<BLOC_SIZE;i++)
    {
        printf("Données de la case %d : %s\n",i,disk.tabBlock->donnees[i]);
    }
}
