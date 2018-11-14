#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE * fichier = NULL;
    int ligne = 1;
    int characteractuel = 0;
    int* timer;
    int* pouls;
    int i, a;

    fichier = fopen("battements.csv", "r");

    if (fichier != NULL)
    {
        while(characteractuel != EOF)  // Tant que le caractère n'est pas le dernier, continuer => END OF FILE
        {
            characteractuel = fgetc(fichier);
            if (characteractuel == '\n')    //Sert à compter le nombre de ligne dans le csv
                ligne++;                  //et donc d'allouer assez de mémoire plus tard
        }

        if(!(timer = malloc(sizeof(*timer) * (ligne)))){    // Si le malloc marche pas, on arrête et si ça marche, on aura des tableaux assez grands pour mettre toutes les valeurs.
            return 0;
        }
        if(!(pouls = malloc(sizeof(*timer) * (ligne)))){   // Crée la taille du tableau
            return 0;
        }
        rewind(fichier);   // On remet le fgetc au début.

        for(i=0; i < ligne ; i++){
            fscanf(fichier, "%d;%d\n", &timer[i], &pouls[i]);    //On assigne les valeurs du .csv dans le tableau
        }
        fclose(fichier);  // fermer le fichier pour ne pas consommer la RAM.


    }

    else{
        printf("Le fichier battements.csv est introuvable");
    }
    for(int i = 0 ; i < ligne - 1; i++){
        printf("%d, %d\n",timer[i],pouls[i]);
    }
    return 0;
}
