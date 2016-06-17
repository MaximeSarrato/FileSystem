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

<<<<<<< HEAD
=======
    initBlockTab(dd,taille);
    printf("Fichier du bloc 0 : %d",dd.tabBlock[0]->numero); // Segfault ici
>>>>>>> ff10bbd4511bd9019575cf3b1309c7b5cc17df25

    // initBlockTab(dd,taille); // Fonction init tableau de blocs

    for(i=0; i<taille; i++)
    {

        BLOCK *monBloc;
        monBloc = malloc(sizeof(BLOCK));
        dd.tabBlock[i]=monBloc;                                 // Association du Block avec sa case dans le tableau de Blocks
        dd.tabBlock[i]->numero=i;                               // Initialisation des numéros de blocks de 0 à Taille du DD -1
        dd.tabBlock[i]->etat=0;
        printf("Bloc numéro : %d\n", dd.tabBlock[i]->numero);
        printf("Fichier du bloc %d : %s\n",i,dd.tabBlock[i]->fichier.nom);
        printf("Etat du bloc : %d\n",dd.tabBlock[i]->etat);
        dd.tabBlock[i]=monBloc;

    }
    printf("Les %d blocs ont bien été initialisés.\n",taille);

    dd.tabBlock[0]->fichier=fic1;
    dd.tabBlock[0]->etat=1;
    printf("Fichier du bloc : %s\n",dd.tabBlock[0]->fichier.nom);
    printf("Etat du bloc : %d\n",dd.tabBlock[0]->etat);

    for(i=0;i<1024;i++)
    {
        fic1.donnees[i]="Data";
        printf("Case %d %s\n",i,fic1.donnees[i]);
    }



    return 0;
}
