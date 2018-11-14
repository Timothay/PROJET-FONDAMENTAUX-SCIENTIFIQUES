#include <stdio.h>
#include <stdlib.h>


int ft_lecturecriture()
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

void swap(int *nb1, int *nb2)
{
    int temp; 
    temp = *nb1;
    *nb1 = *nb2;
    *nb2 = temp;
}

int ft_max(int tableau[], int taille)
{
    int i;
    int n = taille;
    for(i=0; i != taille; i++)
    {
        if (tableau[i] > tableau[n])
            n = i;
    }
    return n;
}

int ft_min(int tableau[], int taille)
{
    int i;
    int n = taille;
    for(i=0; i != taille; i++)
    {
        if(tableau[i] < tableau[n])
            n = i;
    }
    return n;
}

void tri_selection(int tableau[], int tableau2[], int taille, int ordre)
{
    int res;
    int taillebis = taille - 1;
    int i;
    switch(ordre)
    {
        case 1:
        for(i=0; i < taille; i++)
        {
            res = ft_max(tableau, taillebis);
            swap(&tableau[res], &tableau[taillebis]);
            swap(&tableau2[res], &tableau2[taillebis]);
            taillebis--;
        }
        break;

        case 2: 
        for(i=0; i < taille; i++)
        {
            res = ft_min(tableau, taillebis);
            swap(&tableau[res], &tableau[taillebis]);
            swap(&tableau2[res], &tableau2[taillebis]);
            taillebis--;
        }
        break;
        
        case 3: 
        for(i=0; i < taille; i++)
        {
            res = ft_min(tableau2, taillebis);
            swap(&tableau2[res], &tableau2[taillebis]);
            swap(&tableau[res], &tableau[taillebis]);
            taillebis--;
        }

    }
}

int main()
{
    int tableau[10] = {1,2,4,6,8,10,12,14,16,18};
    int tableau2[10] = {10,20,30,40,50,60,70,80,90,100};
    int taille = 10;
    int menu;
    printf("choisissez\n");
    scanf("%d", &menu);
    tri_selection(tableau, tableau2, taille, menu);
    for (int i = 0; i < taille; i++)
        printf("%d,%d\n", tableau[i], tableau2[i]);

    return 0;


}