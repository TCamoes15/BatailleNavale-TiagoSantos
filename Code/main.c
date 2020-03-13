#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        {0, 0, 1, 0, 0, 6, 6, 6, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0},
        {0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0},


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

        printf("Ou veux tu tirer en horizontal?\n");
        scanf("%d", &horizontal);

        printf("Ou veux tu tirer en vertical?\n");
        scanf("%d", &vertical);

        horizontal = horizontal - 1;
        vertical = vertical - 1;

        if (grillemasque1010[horizontal][vertical] == 1 ||
            grillemasque1010[horizontal][vertical] == 2 ||
            grillemasque1010[horizontal][vertical] == 3 ||
            grillemasque1010[horizontal][vertical] == 4) {
            grille1010[horizontal][vertical] = 'T';
        } else {
            grille1010[horizontal][vertical] = 'R';
        }
        system("cls");
    }

}

void aide() {
    FILE *fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("Aide//Aide.txt", "r");

    if (fichier != NULL) {
        do {
            caractereActuel = fgetc(fichier);
            printf("%c", caractereActuel);

        } while (caractereActuel != EOF);
        system("pause");
        fclose(fichier);
    }
}

void afficherMenu ()
{
    printf("1 - Jouer\n");
    printf("2 - Aide\n");
    printf("3 - Scores\n");
    scanf("%d", &menu);


    switch (menu){
        case 1:
            jouer(grille1010,grillemasque1010);
            break;
        case 2:
            aide();
            break;
        case 3: printf ("\n");
            break;
        case 4: printf ("\n");
            break;
        default: printf ("\n");
            break;
    }
}

int main() {

    afficherMenu();

    return 0;
}
