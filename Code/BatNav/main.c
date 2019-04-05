#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "Maquette1.h"
#include "Maquette2.h"
#include "Maquette3.h"
#pragma execution_character_set( "utf-8" )





int main()
{
    //====VARIABLES====//
    int ChoixBase,ChoixJeux,collonne,ligne,numMaquette = 0,nbVie = 103,compteur = 0,VPBat = 2,VMBat = 3,VM2Bat = 3,VGBat = 4,VEBat = 5;

    //====CODES====//
    SetConsoleOutputCP(65001);
    printf("====Bienvenu(e) dans cette BATTAILLE NAVAL!!!\n\n");

        printf("Veuillez choisir l'opriton que vous désirez:\n");           //Différents choix du menu
        printf("(1): afficher les règles du jeu.\n");
        printf("(2): afficher les diffèrents modes de jeux.\n");
        printf("(3): quitter le programme.\n");
        scanf("%d", &ChoixBase);                                            //récupération du choix du joueur

        switch (ChoixBase) {                                                //switch par rapport au choix du joueur
            default:                                                        //Case si le joueur entre autre chose que ce qui est demandé
                printf("Veuillez entrez un nombre valide.");
                system("cls");
                break;

            case 1:                                                         //Affiche les règles du jeu
                system("cls");
                printf("vous voila dans les règles du jeu :\n\n");
                printf("=====================================================================================================\n");
                printf("▬ Le but du jeu est de selectionner des cases (entre 1 et 9) et de toucher tout les bateaux adverse.\n\n");
                printf("▬ si vous toucher une case avec un bateau, un (1) s'affichera, si vous loupé un (3) sera affiché.\n\n");
                printf("▬ A la fin de la partie le programme vous affichera le nombre de coups que vous avez utilisé.\n\n");
                printf("=====================================================================================================\n\n");
                system("pause");
                break;

            case 2:                                                       //Affiche un 2eme menu qui montre les différents jeux
                printf("Veulliez desormais choisir le mode de jeu:\n\n");  //Demande à quel type de jeu l'utilisateur  veut jouer
                do {
                    printf("1): Maquettes pré-construite\n");
                    printf("2): Joueur vs IA\n");

                    scanf("%d", &ChoixJeux);                                //récupère le choix de l'utilisateur.
                    system("cls");
                }
                while(ChoixJeux > 2 || ChoixJeux < 1);                      //boucle qui tourne tant que l'utilisateur n'a pas choisi.

                switch(ChoixJeux){
                    default:                                                //Case qui sert si l'utilisateur ne rentre pas un nb vaide
                        printf("Veuillez entrez un nombre valide.");
                        system("cls");

                        break;

                    case 1:                                                 //ouvre le mode de jeu près construit
                        system("cls");
                        printf("Maquettes pré-construite\n");
                        system("pause");

                        do {
                            printf("Veuilleuz choisir le numéraux de la maquette\n\n");     //Choix de la maquette
                            printf("1)\n");
                            printf("2)\n");
                            printf("3)\n");
                            printf("4)\n");
                            scanf("%d", &numMaquette);                                      //Récuperation du choix de la maquette

                            if(numMaquette == 4){                                           //condition pour entre le nb doit être = 4
                                srand((unsigned)time( NULL ) );                             //sert a faire que le nb génèré aléatoirement soit tjrs différent
                                numMaquette = 1 + rand() % 3;                               //produit un nb aléatoire entre 1 et 3
                            }

                        }while(numMaquette >3 || numMaquette <1);                           //Test du num de la maquette

                        if (numMaquette == 1){                                              //Maquette1
                            while(nbVie !=0) {                                              //Boucle qui tourne tant que Vie !=0

                                system("cls");
                                printf("============================================\n");
                                printf("Binevenu(e) dans la Maquette1\n");
                                printf("============================================\n\n");
                                printf("============================================\n");
                                printf("entrer le num de la collonne :");
                                scanf("%d", &collonne);
                                printf("entrer le num de la ligne :");
                                scanf("%d", &ligne);
                                printf("============================================\n");
                                Maquette1(ligne,collonne);
                                nbVie = nbVie - hpPartie(ligne,collonne);
                                compteur ++;

                                VPBat = VPBat - HPPbateau(ligne,collonne);                  //Calcul des HP des bateaux
                                VMBat = VMBat - HPMbateau(ligne,collonne);;                 //""
                                VM2Bat = VM2Bat - HPM2bateau(ligne,collonne);               //""
                                VGBat = VGBat - HPGbateau(ligne,collonne);                  //"
                                VEBat = VEBat - HPEbateau(ligne,collonne);                  //"

                                printf("============================================\n");
                                if(VPBat != 0) {                                            //condition si Vie != 0 affiche ...
                                    printf("Il reste %d /2 HP au petit bateau\n", VPBat);
                                }else {                                                     //sinon affiche coulé
                                    printf("Petit Bateau: Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VMBat != 0) {                                            //condition si Vie != 0 affiche ...
                                    printf("Il reste %d /3 HP au moyen bateau(1)\n", VMBat);
                                }else {                                                     //sinon affiche coulé
                                    printf("Moyen bateau(1): Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VM2Bat !=0) {                                            //condition si Vie != 0 affiche ...
                                    printf("Il reste %d /3 HP au moyen bateau(2)\n", VM2Bat);
                                }else {                                                     //sinon affiche coulé
                                    printf("Moyen bateau(2): Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VGBat !=0) {                                             //condition si Vie != 0 affiche ...
                                    printf("Il reste %d /4 HP au grand bateau\n", VGBat);
                                }else {                                                     //sinon affiche coulé
                                    printf("Grand bateau: Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VEBat !=0) {                                             //condition si Vie != 0 affiche ...
                                    printf("Il reste %d /5 HP au enorme bateau\n", VEBat);
                                }else{                                                     //sinon affiche coulé
                                    printf("Enorme bateau: Coulé!!!\n");
                                }
                                printf("============================================\n\n");
                                printf("============================================\n");
                                printf("Il reste %d /103 de ses HP à la maquette\n",nbVie); //affiche le nb de vie restant
                                printf("============================================\n");
                                system("pause");
                                system("cls");
                            }
                                printf("Bravooo!!! Vous avez réussi en %d coups!!!\n",compteur);//affiche le nb de coups à la fin de la partie
                                system("pause");

                        } else if (numMaquette == 2){                                           //identique a la maquette 1
                            while(nbVie !=0) {

                                system("cls");
                                printf("============================================\n");
                                printf("Binevenu(e) dans la Maquette2\n");
                                printf("============================================\n\n");
                                printf("============================================\n");
                                printf("entrer le num de la collonne :");
                                scanf("%d", &collonne);
                                printf("entrer le num de la ligne :");
                                scanf("%d", &ligne);
                                printf("============================================\n\n");
                                Maquette2(ligne,collonne);
                                nbVie = nbVie - hpPartie2(ligne,collonne);
                                compteur ++;

                                VPBat = VPBat - HPPbateau2(ligne,collonne);
                                VMBat = VMBat - HPMbateau2(ligne,collonne);;
                                VM2Bat = VM2Bat - HPM2bateau2(ligne,collonne);
                                VGBat = VGBat - HPGbateau2(ligne,collonne);
                                VEBat = VEBat - HPEbateau2(ligne,collonne);

                                printf("============================================\n");
                                if(VPBat != 0) {
                                    printf("Il reste %d /2 HP au petit bateau\n", VPBat);
                                }else {
                                    printf("Petit Bateau: Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VMBat != 0) {
                                    printf("Il reste %d /3 HP au moyen bateau(1)\n", VMBat);
                                }else {
                                    printf("Moyen bateau(1): Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VM2Bat !=0) {
                                    printf("Il reste %d /3 HP au moyen bateau(2)\n", VM2Bat);
                                }else {
                                    printf("Moyen bateau(2): Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VGBat !=0) {
                                    printf("Il reste %d /4 HP au grand bateau\n", VGBat);
                                }else {
                                    printf("Grand bateau: Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if(VEBat !=0) {
                                    printf("Il reste %d /5 HP au enorme bateau\n", VEBat);
                                }else{
                                    printf("Enorme bateau: Coulé!!!\n");
                                }
                                printf("============================================\n\n");
                                printf("============================================\n");
                                printf("Il reste %d /103 de ses HP à la maquette\n",nbVie);
                                printf("============================================\n");
                                system("pause");
                                system("cls");
                            }
                            printf("Bravooo!!! Vous avez réussi en %d coups!!!\n",compteur);
                            system("pause");

                        } else {
                            while (nbVie != 0) {                                                //identique à la maquette 1 et 2

                                system("cls");
                                printf("============================================\n");
                                printf("Binevenu(e) dans la Maquette3\n");
                                printf("============================================\n\n");
                                printf("============================================\n");
                                printf("entrer le num de la collonne :");
                                scanf("%d", &collonne);
                                printf("entrer le num de la ligne :");
                                scanf("%d", &ligne);
                                printf("============================================\n");
                                Maquette3(ligne, collonne);
                                nbVie = nbVie - hpPartie3(ligne, collonne);
                                compteur++;

                                VPBat = VPBat - HPPbateau3(ligne, collonne);
                                VMBat = VMBat - HPMbateau3(ligne, collonne);;
                                VM2Bat = VM2Bat - HPM2bateau3(ligne, collonne);
                                VGBat = VGBat - HPGbateau3(ligne, collonne);
                                VEBat = VEBat - HPEbateau3(ligne, collonne);

                                printf("============================================\n");
                                if (VPBat != 0) {
                                    printf("Il reste %d /2 HP au petit bateau\n", VPBat);
                                } else {
                                    printf("Petit Bateau: Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if (VMBat != 0) {
                                    printf("Il reste %d /3 HP au moyen bateau(1)\n", VMBat);
                                } else {
                                    printf("Moyen bateau(1): Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if (VM2Bat != 0) {
                                    printf("Il reste %d /3 HP au moyen bateau(2)\n", VM2Bat);
                                } else {
                                    printf("Moyen bateau(2): Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if (VGBat != 0) {
                                    printf("Il reste %d /4 HP au grand bateau\n", VGBat);
                                } else {
                                    printf("Grand bateau: Coulé!!!\n");
                                }
                                printf("============================================\n");
                                if (VEBat != 0) {
                                    printf("Il reste %d /5 HP au enorme bateau\n", VEBat);
                                } else {
                                    printf("Enorme bateau: Coulé!!!\n");
                                }
                                printf("============================================\n\n");
                                printf("============================================\n");
                                printf("Il reste %d /103 de ses HP à la maquette\n", nbVie);
                                printf("============================================\n");
                                system("pause");
                                system("cls");
                            }
                            printf("Bravooo!!! Vous avez réussi en %d coups!!!\n", compteur);
                            system("pause");
                        }
                        break;

                    case 2:                                                                             //rentre dans le mode de jeu joueur VS IA


                        system("cls");
                        printf("Joueur vs IA");
                        system("pause");
                        break;

                }


                break;

            case 3:                                                                                   //quitte le programme
                return 400;


    }


}