#include <stdio.h>
#include <stdlib.h>
#pragma execution_character_set("utf-8")

int menu;

void aide ()
{
    FILE* fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("Aide//Aide.txt", "r");

    if (fichier != NULL){
            do{
                caractereActuel = fgetc(fichier);
                printf("%c", caractereActuel);
            }while (caractereActuel != EOF);

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
        case 1: printf ("1 - Jouer\n");
            break;
        case 2: printf ("2 - Aide\n");
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
