#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "hdd.h"


int main()
{
    HARD_DISK dd; // Déclaration de mon DD
    int i;
    FICHIER fic1;
    fic1.nom="notes.txt";

    dd.taille=64000;        // Taille du disque
    dd.tabBlock[dd.taille];   // Déclaration tableau de pointeurs sur BLOCK en fonction de la taille du DD

/*
    BLOCK *monBloc;
    monBloc = malloc(sizeof(BLOCK));
    dd.tabBlock[0]=monBloc;
    monBloc->fichier=fic1;
    monBloc->etat=1;
    monBloc->numero=0;


    printf("Taille du disque en octet = %d\n",dd.taille);
    printf("Bloc numéro = %d\n",dd.tabBlock[0]->numero);
    printf("Fichier du bloc 1 : %s\n",monBloc->fichier.nom);
    printf("Etat du bloc : %d",monBloc->etat);
*/

    for(i=0;i<dd.taille;i++)
    {
        printf("i=%d\n",i);
        BLOCK *monBloc;
        monBloc = malloc(sizeof(BLOCK));
        dd.tabBlock[i]=monBloc;
    }

/*
    for(i=0; i<dd.taille; i++)
    {

        BLOCK *monBloc;
        monBloc = malloc(sizeof(BLOCK));
        dd.tabBlock[i]=monBloc;
        printf("Taille du disque en octet = %d\n",dd.taille);
        printf("Bloc numéro : %d\n", dd.tabBlock[i]->numero);

    }
*/



    return 0;
}
