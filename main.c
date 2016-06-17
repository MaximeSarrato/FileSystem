#include <stdio.h>
#include <stdlib.h>
//#include "donnees.h"
#include "hdd.h"


int main()
{
    HARD_DISK dd; // Déclaration de mon DD
    int i;
    FICHIER fic1;
    unsigned int taille;
    taille=64000;
    fic1.nom="notes.txt";

    dd = initBlockTab(taille); // Fonction init tableau de blocs


    dd.tabBlock[0].fichier=fic1;
    dd.tabBlock[0].etat=1;
    printf("Fichier du bloc : %s\n",dd.tabBlock[0].fichier.nom);
    printf("Etat du bloc : %d\n",dd.tabBlock[0].etat);

//    for(i=0;i<1024;i++)
//    {
//        fic1.donnees[i]="Data";
//        printf("Case %d %s\n",i,fic1.donnees[i]);
//    }



    return 0;
}
