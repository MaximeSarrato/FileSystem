//#include "shell.h"
//
//void launchShell(HARD_DISK* disk){
//    int continuer = 1;
//	while(continuer)
//	{// boucle infinie dont on sort si l'utilisateur écrit "exit"
//		char str[MAX]; // récupère ce qui est écrit par l'utilisateur
//		printf("\n[SGF] $ : "); // Prompt
//		if(feof(stdin)) // gère le CTRL+D
//			exit(0);
//		fgets(str, MAX, stdin);
//
//		continuer = recupCommande(str, disk);
//
//	}
//}
//
//int recupCommande(char* str, HARD_DISK* disk)
//{//corps du programme
//	retireCarac(str, '\n'); // enleve le \n laissé par fgets
//
//	char** mots;	// remplis dans un tableau à 2 dimensions les différents mots de la commande
//	char caracSep = ' ';
//	char* exit1 = "exit";
//	int tailleMotCommande = nbMots(str, caracSep); // compte le nombre de mots
//
//	mots = calloc(MAX_NB, sizeof(char*)); // crée les sous tableaux
//	separe(str, mots, strlen(str), caracSep); // remplis les mots dans les sous tableaux
//
//
//	if(strcmp(exit1, mots[0]) == 0) //Si on a écrit exit => on quitte
//		return 0;
//	if(mots[0][0] == '\0')
//		return 1;
//
//	int cmdPerso = 0;
//	cmdPerso = commandePerso(str, mots, tailleMotCommande, disk);
//
//	return 1;
//}
//
//int nbMots(char* str, char caracSep)
//{// Compte le nombre de mots séparés par le caracSep
//	int i = 0, cpt = 1;
//	int taille = strlen(str);
//
//	for(i = 0; i < taille; i++)
//		if(str[i] == caracSep)
//			cpt++;
//	return cpt;
//}
//
//void retireCarac(char* str, char carac)
//{//remplace la première occurence ce carac par un '\0'
//	int i = 0; // enleve le \n de la commande
//		for(i = 0; i < strlen(str); i++)
//			if(str[i] == carac)
//				str[i] = '\0';
//}
//
//void separe(char* str, char** mots, int nbLettres, char caracSep)
//{ // sépare la chaine de caractère en plusieurs mots
//	char carac = caracSep;
//	int taille = 0, nbMots = 0, cpt = 0;
//
//	while( taille < nbLettres /*&& cpt < nbLettres*/)
//	{//tant qu'on est pas à la fin du string
//		if(str[taille] == carac)
//		{// Si on tombe sur un caractère séparateur
//			mots[nbMots] = calloc(taille , sizeof(char)); // crée un nouveau mot dans le tableau
//			strncpy(mots[nbMots], str, taille);			// on y copie le mot trouvé
//			str = &str[taille + 1]; // reposition le début de la "tête" de lecture à la fin du mot ajouté
//			taille = 0;
//			nbMots++;
//			cpt++;
//		}
//		else
//		{
//			cpt++;
//			taille++;
//		}
//	} // Copie le dernier mot dans la liste des mots
//	mots[nbMots] = calloc(taille, sizeof(char));
//	strncpy(mots[nbMots], str, taille);
//
//}
//
//int commandePerso(char* str, char** mots, int taille, HARD_DISK* disk)
//{// Verifie si la commande est handmade
//
//	if(!strcmp("echo", mots[0]))
//		echo(mots, taille, disk);/*
//	else if(!strcmp("_cat", mots[0]))
//		cat(mots[1]);
//	else if(!strcmp("_cd", mots[0]))
//		cd(mots);
//	else if(!strcmp("_ls", mots[0]))
//		ls(mots[1], taille);
//	else if(!strcmp("_cp", mots[0]))
//		cp(mots[1], mots[2]);*/
//	else
//		return 0;
//	return 1;
//
//}
//
//void echo(char** str, int taille, HARD_DISK* disk)
//{//Réécrit ce qui est passé en argument + donne les valeurs des $VAR si il y en a
//	int i = 1, j = 0;
//	char c[MAX] = {""};
//	char b[MAX] = {""};
//	if(str[1][0] == '"' && str[taille-1][strlen(str[taille-1])-1] == '"'){//Quand on met pas de chevron
//
//	    for(j=0 ; j<strlen(str[1])-1 ; j++)//Recupere le 1er mot pour enlever le guillemet
//            c[j] = str[1][j+1];
//        strcpy(str[1], c);
//	    for(j=0 ; j<strlen(str[taille-1])-1 ; j++){ //Recupere le dernier mot pour enlever le guillemet
//            b[j] = str[taille-1][j];
//	    }
//        strcpy(str[taille-1], b);
//
//        while(i < taille) //Affichage a l'écran
//        {
//            printf("%s ", str[i]);
//
//            i++;
//        }
//        printf("\n");
//    }
//    else if(str[1][0] == '"' && str[taille-3][strlen(str[taille-3])-1] == '"' && strcmp(str[taille-2], ">") == 0){ //Avec un chevron
//
//        for(j=0 ; j<strlen(str[1])-1 ; j++)//Recupere le 1er mot pour enlever le guillemet
//            c[j] = str[1][j+1];
//        strcpy(str[1], c);
//	    for(j=0 ; j<strlen(str[taille-3])-1 ; j++)//Recupere le dernier mot pour enlever le guillemet
//            b[j] = str[taille-3][j];
//        strcpy(str[taille-3], b);
//
//
//        char phrase[MAX]={""}; //concatene toute la phrase en une seule variable
//        int cpt = 0;
//        for(j=1 ; j<taille-2 ; j++){
//            for(i=0 ; i < strlen(str[j]) ; i++){
//                phrase[cpt] = str[j][i];
//                cpt++;
//            }
//            phrase[cpt] = ' ';
//            cpt++;
//        }
//
//        if(fileExists(disk, str[taille-1])){ //Ecriture dans un fichier texte de la phrase
//            writeFile(disk, getInode(disk, str[taille-1]), 1, phrase);
//        }else{
//            writeFile(disk, createFile(disk, str[taille-1], fileNumber, strlen(phrase)), 1, phrase);
//            readFile(disk, getInode(disk, str[taille-1]), 30);
//        }
//
//
//    }else
//        printf("Invalid operand\n");
//}
