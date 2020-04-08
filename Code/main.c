/**
 *    Titre: Bataille Navale
      Auteur: Tiago Santos
      Date: 08.04.2020
      Description: Version 1.0 Bataille Navale
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#pragma execution_character_set("utf-8")

int menu;

char grille1010[11][11] = {
        {'X', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
        {'0', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'2', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'3', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'4', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'5', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'6', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'7', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'8', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'9', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},

};
int grillemasque1010[11][11] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0},
        {0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0},


};

int jouer() {
    bool jeuactif = true;
    int i = 0, j = 0, vertical, horizontal;


    while (jeuactif == true) {
        for (i = 0; i < 11; i++) {

            for (j = 0; j < 11; j++) {
                printf("%c\t", grille1010[i][j]);
            }
            printf("\n");
        }

        printf("Ou veux tu tirer en vertical? (0-9)\n");
        scanf("%d", &horizontal);

        printf("Ou veux tu tirer en horizontal? (1-10, 1 = A 2 = B etc)\n");
        scanf("%d", &vertical);

        horizontal = horizontal + 1;



        if (grillemasque1010[horizontal][vertical] == 1 ||
            grillemasque1010[horizontal][vertical] == 2 ||
            grillemasque1010[horizontal][vertical] == 3 ||
            grillemasque1010[horizontal][vertical] == 4 ||
            grillemasque1010[horizontal][vertical] == 5) {
            grille1010[horizontal][vertical] = 'T';
        } else {
            grille1010[horizontal][vertical] = 'R';
        }
        system("cls");
    }

}

void aide() {


    printf("\nRègles\n\n");
    printf("Vous devez choisir une grille et les bateaux seront pose de forme aleatoire.\n"
           "Vous devriez par la suite choisir le numero de la ligne et le numero de la colonne pour pouvoir tirer.\n"
           "Quand la lettre 'X' ce affiche c'est pour vous dire que vous avez toucher un bateau.\n"
           "Quand la lettre 'O' ce affiche c'est pour vous dire que vous avez rate votre tir\n"
           "Quand la lettre 'C' ce affiche c'est pour vous dire que vous avez toucher et couler le bateau.");
    printf("Il y'a 5 bateaux :\n"
           "1 porte-avions (5 cases)\n"
           "1 croiseur (4 cases)\n"
           "1 contre-torpilleur (3 cases)\n"
           "1 torpilleur (2 cases)\n"
           "1 sous-marin (1 case)\n"
           "\n"
           "Pour gagner il faut faire couler tous les bateaux adverses dans le moins de tour possible.\n");
    system("pause");
}

void afficherMenu() {
    do {
        system("cls");
        printf("1 - Jouer\n");
        printf("2 - Aide\n");
        printf("3 - Scores\n");
        printf("4 - Quitter\n");
        scanf("%d", &menu);


        switch (menu) {
            case 1:
                jouer(grille1010, grillemasque1010);
                break;
            case 2:
                aide();

                break;
            case 3:
                printf("\n");
                break;
            case 4:
                printf("\n");
                break;
            default:
                printf("\n");
                break;
        }
    }while(menu!=4);
}

int main() {
    SetConsoleOutputCP(65001);

    afficherMenu();

    return 0;
}
