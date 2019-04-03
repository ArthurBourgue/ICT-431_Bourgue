#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define PETIT_BATEAU 1
#define MOYEN_BATEAU1 2
#define MOYEN_BATEAU2 21
#define GRAND_BATEAU 3
#define ENORME_BATEAU 4
#define HPPARTIE 100

#pragma execution_character_set( "utf-8" )


char tableauVisu[9][9] = {
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
};

int Maquette1(int col,int lig)                           //1ere grille de jeu.
{
    col = col - 1;
    lig = lig - 1;

    int tableauJoueur[9][9] = {
            0, 0, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 3,
            0, 0, 0, 0, 0, 2, 0, 0, 3,
            0, 0, 0, 0, 0, 0, 0, 0, 3,
            0, 0, 21, 21, 21, 0, 0, 0, 3,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 4, 4, 4, 4, 4,
    };

    if (tableauJoueur[col][lig] == PETIT_BATEAU || tableauJoueur[col][lig] == MOYEN_BATEAU1 ||
        tableauJoueur[col][lig] == MOYEN_BATEAU2 || tableauJoueur[col][lig] == GRAND_BATEAU ||
        tableauJoueur[col][lig] == ENORME_BATEAU) {
        tableauVisu[col][lig] = 1;
        printf("touché!\n");
    } else {
        tableauVisu[col][lig] = 3;
        printf("loupé\n\n");
    }
    int ligne = 0;
    int colonne = 0;
    for (ligne = 0; ligne < 9; ligne++) {
        for (colonne = 0; colonne < 9; colonne++) {
            printf("%d \t", tableauVisu[ligne][colonne]);
        }
        printf("\n");
    }
}
    int hpPartie(int col,int lig){
    col = col - 1;
    lig = lig - 1;

        int tableauJoueur[9][9] = {
                0, 0, 1, 1, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 0, 0, 3,
                0, 0, 0, 0, 0, 2, 0, 0, 3,
                0, 0, 0, 0, 0, 0, 0, 0, 3,
                0, 0, 21, 21, 21, 0, 0, 0, 3,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 4, 4, 4, 4, 4,
        };
    int hpRestant = HPPARTIE;
    if(tableauJoueur[col][lig] == PETIT_BATEAU){
        hpRestant = hpRestant - PETIT_BATEAU;
    }else if (tableauJoueur[col][lig] == MOYEN_BATEAU1){
        hpRestant = hpRestant - MOYEN_BATEAU1;
    }else if(tableauJoueur[col][lig] == MOYEN_BATEAU2){
        hpRestant = hpRestant - MOYEN_BATEAU2;
    }else if(tableauJoueur[col][lig] == GRAND_BATEAU){
        hpRestant = hpRestant - GRAND_BATEAU;
    }else if(tableauJoueur[col][lig] == ENORME_BATEAU){
        hpRestant = hpRestant - ENORME_BATEAU;
    }

    printf("Il reste %d pourcents de ses HP à la maquette",hpRestant);
    system("pause");
    system("cls");
    return hpRestant;
}


int main()
{
    //====VARIABLES====//
    int ChoixBase,ChoixJeux,collonne,ligne,numMaquette,nbVie = 1,compteur = 0,hpRestant = HPPARTIE;;

    //====CODES====//
    SetConsoleOutputCP(65001);
    printf("====Bienvenu(e) dans cette BATTAILLE NAVAL!!!\n\n");
    while(ChoixBase >3)
    {
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
                            printf("Veuilleuz choisir le numéraux de la maquette\n\n");
                            printf("1:\n");
                            printf("2:\n");
                            printf("3:\n");
                            scanf("%d", &numMaquette);

                        }while(numMaquette >3 || numMaquette <1);

                        if (numMaquette == 1){

                            while(nbVie >0) {
                                printf("entrer le num de la collonne :");
                                scanf("%d", &collonne);
                                printf("entrer le num de la ligne :");
                                scanf("%d", &ligne);
                                Maquette1(ligne,collonne);
                                nbVie = hpPartie(ligne,collonne);
                                compteur ++;
                            }

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


}