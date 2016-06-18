#include <stdio.h>
#include <stdlib.h>
//#include "donnees.h"
#include "hdd.h"


int main()
{
    HARD_DISK dd; // Déclaration de mon DD
    FICHIER fic1;
    unsigned int taille;
    taille=64000;
    fic1.nom="notes.txt";
    fic1.inode.numero=5;
    fic1.inode.premierBloc=6;
    fic1.inode.dernierBloc=9;

    dd = initBlockTab(taille); // Fonction init tableau de blocs

    dd.tabBlock[0].fichier=fic1;
    dd.tabBlock[0].etat=1;
    printf("Fichier du bloc : %s\n",dd.tabBlock[0].fichier.nom);
    printf("Etat du bloc : %d\n",dd.tabBlock[0].etat);

    // readBlocData(dd,2); // Fonction lecture d'un bloc de données du disque dd
//    printf("Type du block 0 : %s \n",dd.tabBlock[0].typeBlock);
//    printf("Type du block 1 : %s \n",dd.tabBlock[1].typeBlock);
//    printf("Type du block 2 : %s \n",dd.tabBlock[2].typeBlock);

    int i;
    for (i=0;i<taille;i++)
    {
            printf("Bloc numéro : %d \n"),dd.tabBlock[i].numero;

    }
    printf("Test");




    return 0;
}
