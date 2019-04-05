//
// Created by Arthur.BOURGUE on 05.04.2019.
//



//====================================================================
//Titre: Sous programme "Maquette3"
//auteur: Arthur Bourgue
//But: Fonctionnement complet de la 1re maquette
//====================================================================


#ifndef BATNAV_MAQUETTE3_H
#define BATNAV_MAQUETTE3_H

#endif //BATNAV_MAQUETTE3_H

#define PETIT_BATEAU 1
#define MOYEN_BATEAU1 2
#define MOYEN_BATEAU2 21
#define GRAND_BATEAU 3
#define ENORME_BATEAU 4

char tableauVisu3[9][9] = {                                         //Tout idem que pour Maquette1//
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

int Maquette3(int col,int lig)
{
    lig = lig - 1;
    col = col - 1;
    int tableauJoueur[9][9] = {
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 4, 4, 4, 4, 4, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            21, 21, 21, 0, 0, 0, 0, 0, 0,
    };

    if (tableauJoueur[col][lig] == PETIT_BATEAU || tableauJoueur[col][lig] == MOYEN_BATEAU1 ||
        tableauJoueur[col][lig] == MOYEN_BATEAU2 || tableauJoueur[col][lig] == GRAND_BATEAU ||
        tableauJoueur[col][lig] == ENORME_BATEAU) {
        tableauVisu3[col][lig] = 1;
        printf("touché!\n");
    } else {
        tableauVisu3[col][lig] = 3;
        printf("loupé\n\n");
    }
    int ligne = 0;
    int colonne = 0;
    for (ligne = 0; ligne < 9; ligne++) {
        for (colonne = 0; colonne < 9; colonne++) {
            printf("%d \t", tableauVisu3[ligne][colonne]);
        }
        printf("\n");
    }
}

int HPPbateau3(int col,int lig){
    col = col - 1;
    lig = lig - 1;

    int tableauJoueur[9][9] = {
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 4, 4, 4, 4, 4, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            21, 21, 21, 0, 0, 0, 0, 0, 0,
    };
    int petitBateau = 0;

    if(tableauJoueur[col][lig] == PETIT_BATEAU){
        petitBateau = petitBateau + 1;
    }
    return  petitBateau;
}
int HPMbateau3(int col,int lig) {
    col = col - 1;
    lig = lig - 1;

    int tableauJoueur[9][9] = {
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 4, 4, 4, 4, 4, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            21, 21, 21, 0, 0, 0, 0, 0, 0,
    };
    int moyenBateau = 0;

    if (tableauJoueur[col][lig] == MOYEN_BATEAU1) {
        moyenBateau = moyenBateau + 1;
    }
    return moyenBateau;
}
int HPM2bateau3(int col,int lig) {
    col = col - 1;
    lig = lig - 1;

    int tableauJoueur[9][9] = {
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 4, 4, 4, 4, 4, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            21, 21, 21, 0, 0, 0, 0, 0, 0,
    };
    int moyenBateau2 = 0;

    if (tableauJoueur[col][lig] == MOYEN_BATEAU2) {
        moyenBateau2 = moyenBateau2 + 1;
    }
    return moyenBateau2;
}
int HPGbateau3(int col,int lig) {
    col = col - 1;
    lig = lig - 1;

    int tableauJoueur[9][9] = {
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 4, 4, 4, 4, 4, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            21, 21, 21, 0, 0, 0, 0, 0, 0,
    };
    int grandBateau = 0;
    if (tableauJoueur[col][lig] == GRAND_BATEAU) {
        grandBateau = grandBateau + 1;
    }
    return grandBateau;
}
int HPEbateau3(int col,int lig) {
    col = col - 1;
    lig = lig - 1;

    int tableauJoueur[9][9] = {
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 4, 4, 4, 4, 4, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            21, 21, 21, 0, 0, 0, 0, 0, 0,
    };
    int enormeBateau = 0;

    if (tableauJoueur[col][lig] == ENORME_BATEAU) {
        enormeBateau = enormeBateau + 1;
    }
    return enormeBateau;
}



int hpPartie3(int col,int lig){
    col = col - 1;
    lig = lig - 1;

    int tableauJoueur[9][9] = {
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 4, 4, 4, 4, 4, 0,
            0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            21, 21, 21, 0, 0, 0, 0, 0, 0,
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