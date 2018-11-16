#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "actions.h"

int ft_lecturecriture()    //Lit le fichier battements.csv et écrit le tableau dans la console
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
            fscanf(fichier, "%d;%d", &pouls[i], &timer[i]);
             }                                                  //On assigne les valeurs du .csv dans le tableau

        fclose(fichier);  // fermer le fichier pour ne pas consommer la RAM.
    }

    else{
        printf("Le fichier battements.csv est introuvable");
    }

    for(int a = 0 ; a < ligne - 1; a++){
    printf("%d, %d\n",pouls[a],timer[a]);    //Affiche les deux colonnes du tableau

    }
    return 0;
}


int ft_lectureinverse()     //Lit le .csv et trie le tableau avec un tri selection
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
            fscanf(fichier, "%d;%d", &pouls[i], &timer[i]);
             }                                                  //On assigne les valeurs du .csv dans le tableau

        fclose(fichier);  // fermer le fichier pour ne pas consommer la RAM.
    }

    else{
        printf("Le fichier battements.csv est introuvable");
    }

    tri_selection(pouls, timer, ligne);

    return (0);
}


int ft_lecturerecherche()    //Lit le .csv et lance une recherche dichotomique pour trouver une valeur du tableau
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

        for(i=0; i<ligne ; i++)
        {
            fscanf(fichier, "%d;%d", &pouls[i], &timer[i]);
        }                                                        //On assigne les valeurs du .csv dans le tableau
        fclose(fichier);  // fermer le fichier pour ne pas consommer la RAM.
    }

    else{
        printf("Le fichier battements.csv est introuvable");
    }

    rechdicho(timer, pouls, ligne);
    return 0;
}

int ft_lectureligne()    //Lit le fichier .csv et affiche le nombre de ligne du tableau
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

        if(!(timer = malloc(sizeof(*timer) * (ligne))))
        {                           // Si le malloc marche pas, on arrête et si ça marche, on aura des tableaux assez grands pour mettre toutes les valeurs.
            return 0;
        }

        if(!(pouls = malloc(sizeof(*timer) * (ligne))))
        {   // Crée la taille du tableau
            return 0;
        }
        rewind(fichier);   // On remet le fgetc au début.

        for(i=0; i<ligne ; i++)
        {
            fscanf(fichier, "%d;%d", &pouls[i], &timer[i]);
        }                                                        //On assigne les valeurs du .csv dans le tableau
        fclose(fichier);  // fermer le fichier pour ne pas consommer la RAM.
    }

    else
    {
        printf("Le fichier battements.csv est introuvable");
    }

    printf("Il y a %d lignes de donnees actuellement en memoire", ligne-1);

    return 0;
}

int ft_lectureminmax()       //Lit le .csv et affiche le minimum et maximum de pouls
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

        for(i=0; i<ligne ; i++)
        {
            fscanf(fichier, "%d;%d", &pouls[i], &timer[i]);
        }                                                        //On assigne les valeurs du .csv dans le tableau
        fclose(fichier);  // fermer le fichier pour ne pas consommer la RAM.
    }

    else{
        printf("Le fichier battements.csv est introuvable");
    }

    ft_mintableau(pouls, ligne);
    ft_maxtableau(pouls, ligne);

    return 0;
}

int ft_lecturemoyenne()     //Lit le .csv et donne la moyenne de pouls sur une plage de temps
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

        for(i=0; i<ligne ; i++)
        {
            fscanf(fichier, "%d;%d", &pouls[i], &timer[i]);
        }                                                        //On assigne les valeurs du .csv dans le tableau
        fclose(fichier);  // fermer le fichier pour ne pas consommer la RAM.
    }

    else{
        printf("Le fichier battements.csv est introuvable");
    }

    ft_moyenne(timer, pouls, ligne);
    return 0;
}
