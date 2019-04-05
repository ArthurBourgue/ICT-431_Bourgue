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

        printf("Veuillez choisir l'opriton que vous désirez:\n");
        printf("(1): afficher les règles du jeu.\n");
        printf("(2): afficher les diffèrents modes de jeux.\n");
        printf("(3): quitter le programme.\n");
        scanf("%d", &ChoixBase);

        switch (ChoixBase) {
            default:
                printf("Veuillez entrez un nombre valide.");
                system("cls");
                break;

            case 1:
                system("cls");
                printf("vous voila dans les règles du jeu :\n\n");
                printf("=====================================================================================================\n");
                printf("▬ Le but du jeu est de selectionner des cases (entre 1 et 9) et de toucher tout les bateaux adverse.\n\n");
                printf("▬ si vous toucher une case avec un bateau, un (1) s'affichera, si vous loupé un (3) sera affiché.\n\n");
                printf("▬ A la fin de la partie le programme vous affichera le nombre de coups que vous avez utilisé.\n\n");
                printf("=====================================================================================================\n\n");
                system("pause");
                break;

            case 2:
                printf("Veulliez desormais choisir le mode de jeu:\n\n");
                do {
                    printf("1): Maquettes pré-construite\n");
                    printf("2): Joueur vs IA\n");

                    scanf("%d", &ChoixJeux);
                    system("cls");
                }
                while(ChoixJeux > 2 || ChoixJeux < 1);

                switch(ChoixJeux){
                    default:
                        printf("Veuillez entrez un nombre valide.");
                        system("cls");

                        break;

                    case 1:
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

                            if(numMaquette == 4){
                                srand((unsigned)time( NULL ) );
                                numMaquette = 1 + rand() % 3;
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

                                VPBat = VPBat - HPPbateau(ligne,collonne);
                                int moyenBat = HPMbateau(ligne,collonne);
                                VMBat = VMBat - moyenBat;
                                VM2Bat = VM2Bat - HPM2bateau(ligne,collonne);
                                VGBat = VGBat - HPGbateau(ligne,collonne);
                                VEBat = VEBat - HPEbateau(ligne,collonne);

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

                        } else if (numMaquette == 2){
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
                                printf("============================================\n");
                                printf("Il reste %d /103 de ses HP à la maquette\n",nbVie);
                                printf("============================================\n");
                                system("pause");
                                system("cls");
                            }
                            printf("Bravooo!!! Vous avez réussi en %d coups!!!\n",compteur);
                            system("pause");
                            } else{
                            while(nbVie !=0) {

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
                                Maquette3(ligne,collonne);
                                nbVie = nbVie - hpPartie3(ligne,collonne);
                                compteur ++;
                                printf("============================================\n");
                                printf("Il reste %d /103 de ses HP à la maquette\n",nbVie);
                                printf("============================================\n");
                                system("pause");
                                system("cls");
                            }
                            printf("Bravooo!!! Vous avez réussi en %d coups!!!\n",compteur);
                            system("pause");
                        }
                        break;

                    case 2:
                        system("cls");
                        printf("Joueur vs IA");
                        system("pause");
                        break;

                }


                break;

            case 3:
                return 400;


    }


}