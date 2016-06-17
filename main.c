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
    dd.tabBlock[64000];   // Déclaration tableau de pointeurs sur BLOCK en fonction de la taille du DD
    unsigned int taille;
    taille=dd.taille;

    initBlockTab(dd,taille);
    printf("Fichier du bloc 0 : %d",dd.tabBlock[0]->numero);





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
