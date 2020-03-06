#include <stdio.h>
#include <stdlib.h>
#pragma execution_character_set("utf-8")

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

int main() {

    aide();
    return 0;
}
