#include "hdd.h"
#include <stdio.h>
#include <stdlib.h>


/***************************************************
 *
 * Fonction d'initialisation du HDD et de ses Blocs
 *
 ***************************************************/
HARD_DISK initBlockTab(unsigned int taille)
{
    HARD_DISK disk;
    disk.taille = taille;
    disk.tabBlock = malloc(sizeof(BLOCK)* taille);
    disk.tabInode = malloc(sizeof(INODE)* taille);

    int i,j,k;
    for(i=0;i<disk.taille;i++)
    {
        BLOCK *monBloc;
        monBloc = malloc(sizeof(BLOCK));
        disk.tabBlock[i]=*monBloc;                                  // Association du Bloc avec sa case dans le tableau de Blocs
        disk.tabBlock[i].numero=i;                                  // Initialisation des numéros de blocks de 0 à Taille du DD -1
        disk.tabBlock[i].etat=0;
        disk.tabBlock[i].typeBlock="Bloc de données";

        if(i==0){                                                   // Si on est dans le BootBlock
            disk.tabBlock[i].etat=1;
            disk.tabBlock[i].typeBlock="BootBlock";
        }

        else if(i==1){                                                  // Si on est dans le SuperBlock
            disk.tabBlock[i].etat=1;
            disk.tabBlock[i].typeBlock="SuperBlock";
        }

        else if (i==2)                                               // Si on est le Bloc qui contient la Table des inodes
        {
            disk.tabBlock[i].etat=1;
            disk.tabBlock[i].typeBlock="Table d'inodes";

            for(k=0;k<disk.taille;k++)
            {
                disk.tabInode[k].numero=k;                          // Initialisation des numéros des Inodes
                printf("Inode numéro = %d\n",disk.tabInode[k].numero);

            }
        }

            for (j=0;j<BLOC_SIZE;j++)
            {
                disk.tabBlock[i].donnees[j]="Kikoo";                // On rentre les données dans chaque block de 1024 octets
            }

            printf("Bloc numéro = %d\n",disk.tabBlock[i].numero);
            printf("contient fichier = %s\n",disk.tabBlock[i].fichier.nom);
            printf("Etat %d\n",disk.tabBlock[i].etat);
            printf("Type de block : %s\n",disk.tabBlock[i].typeBlock);


    }
    printf("Les %d blocs ont bien été initialisés.\n",disk.taille);

    return disk;
}

void readBlocData(HARD_DISK disk, unsigned int numBloc)
{
    int i;
    for(i=0;i<BLOC_SIZE;i++)
    {
        printf("Données de la case %d : %s\n",i,disk.tabBlock->donnees[i]);
    }
}


