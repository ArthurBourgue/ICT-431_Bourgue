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
    int ChoixBase,ChoixJeux,collonne,ligne,numMaquette = 0,nbVie = 103,compteur = 0;

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
                printf("vous voila dans les règles du jeu :\n");
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

                        if (numMaquette == 1){                                              //
                            while(nbVie !=0) {
                                printf("Binevenu(e) dans la Maquette1\n\n");
                                printf("entrer le num de la collonne :");
                                scanf("%d", &collonne);
                                printf("entrer le num de la ligne :");
                                scanf("%d", &ligne);
                                Maquette1(ligne,collonne);
                                nbVie = nbVie - hpPartie(ligne,collonne);
                                compteur ++;
                                printf("Il reste %d /103 de ses HP à la maquette\n",nbVie);
                                system("pause");
                                system("cls");
                            }
                                printf("Bravooo!!! Vous avez réussi en %d coups!!!\n",compteur);
                                system("pause");

                        } else if (numMaquette == 2){
                            while(nbVie !=0) {

                                printf("Binevenu(e) dans la Maquette2\n\n");
                                printf("entrer le num de la collonne :");
                                scanf("%d", &collonne);
                                printf("entrer le num de la ligne :");
                                scanf("%d", &ligne);
                                Maquette2(ligne,collonne);
                                nbVie = nbVie - hpPartie2(ligne,collonne);
                                compteur ++;
                                printf("Il reste %d /103 de ses HP à la maquette\n",nbVie);
                                system("pause");
                                system("cls");
                            }
                            printf("Bravooo!!! Vous avez réussi en %d coups!!!\n",compteur);
                            system("pause");
                            } else{
                            while(nbVie !=0) {

                                printf("Binevenu(e) dans la Maquette3\n\n");
                                printf("entrer le num de la collonne :");
                                scanf("%d", &collonne);
                                printf("entrer le num de la ligne :");
                                scanf("%d", &ligne);
                                Maquette3(ligne,collonne);
                                nbVie = nbVie - hpPartie3(ligne,collonne);
                                compteur ++;
                                printf("Il reste %d /103 de ses HP à la maquette\n",nbVie);
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