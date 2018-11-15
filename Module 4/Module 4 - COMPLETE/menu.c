#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "donnees.h"


int menulecture()
{
    int choix;
    printf("Choisissez l'action que vous souahitez realiser :\n1) Afficher les donnees dans l'ordre du fichier.\n2) Afficher les donnees en ordre croissant/decroissant (selon le temps, selon le pouls).\n3) Rechercher et afficher les donnees pour un temps particulier.\n4) Afficher la moyenne de pouls dans une plage de temps donnee.\n5) Afficher le nombre de lignes de donnees actuellement en memoire.\n6) Rechercher et afficher les max/min de pouls.\n7) Quitter l'application.\n");
    printf("\n");
    scanf("%d", &choix);
    switch(choix)
    {
        case 1 :
        ft_lecturecriture();
        break;

        case 2 :
        ft_lectureinverse();
        break;

        case 3 :
        ft_lecturerecherche();
        break;

        case 4 :
        ft_lecturemoyenne();
        break;

        case 5 :
        ft_lectureligne();
        break;

        case 6 :
        ft_lectureminmax();
        break;

        case 7 :
        return 0;
        break;

    }

}
