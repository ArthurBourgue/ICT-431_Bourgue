//
// Created by Arthur.BOURGUE on 05.04.2019.
//

#ifndef BATNAV_MAQUETTE1_H
#define BATNAV_MAQUETTE1_H

#endif //BATNAV_MAQUETTE1_H

#define PETIT_BATEAU 1
#define MOYEN_BATEAU1 2
#define MOYEN_BATEAU2 21
#define GRAND_BATEAU 3
#define ENORME_BATEAU 4

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
    lig = lig - 1;
    col = col - 1;
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
    if(tableauVisu[3][1] == 1 && tableauVisu[4][1] == 1){
        printf("Coulé");
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
    int hpRestant = 0;
    if(tableauJoueur[col][lig] == PETIT_BATEAU){
        hpRestant = hpRestant + PETIT_BATEAU;
    }else if (tableauJoueur[col][lig] == MOYEN_BATEAU1){
        hpRestant = hpRestant + MOYEN_BATEAU1;
    }else if(tableauJoueur[col][lig] == MOYEN_BATEAU2){
        hpRestant = hpRestant + MOYEN_BATEAU2;
    }else if(tableauJoueur[col][lig] == GRAND_BATEAU){
        hpRestant = hpRestant + GRAND_BATEAU;
    }else if(tableauJoueur[col][lig] == ENORME_BATEAU){
        hpRestant = hpRestant + ENORME_BATEAU;
    }

    return hpRestant;

}