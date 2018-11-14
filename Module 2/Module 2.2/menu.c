#include <stdio.h>
#include "Generationcode.h"

//Cette fonction permet à l'utilisateur de valider son choix : rentrer la valeur 1 exécutera le mode sélectionné au préalable
int validation() {
	int valider;
	printf("1 pour valider votre choix\n");
	scanf_s("%i", &valider);
	if (valider == 1) {
		return 1;
	}
	else {
		return -1;
	}
}

//Cette fonction permet de choisir le paramètre grâce à un switch : il appelle la fonction qui correspond après validation (cette fonction ce trouve dans Generationcode.c)
int choiceParam(){
int choice;
printf ("selectionnez un mode de clignotement pour le coeur LED:\n1) Toutes les LEDs\n2) Une LED sur deux\n3) Une LED sur trois\n4) Une LED au choix\n5) Chenille simple une par une\n6) Chenille simple une par une rapide\n7) Chenille complete fondue\n ");
scanf_s("%i",&choice);
    switch(choice) {

		
        case 1 :
            printf("Mode : clignotement de toutes les LEDs en rythme avec les battements du coeur du patient\n");
            if(validation()==1)
                all();
            break;

        case 2 :
            printf("Mode : clignotement d'une LED sur deux en rythme avec les battements du coeur du patient\n");
            if (validation()==1){
                alternance2();
            }
            break;

		case 3:
			printf("Mode : clignotement d'une LED sur trois en rythme avec les battements du coeur du patient\n");
			if (validation() == 1) {
				alternance3();
			}
			break;

        case 4 :
            printf("Mode : clignotement d'une LED selectionnee\n");
            if (validation()==1){
                int parametre;
                printf("Choisissez la LED a faire clignoter.\n");
                scanf_s("%i",&parametre);
				unique(parametre);
			}
            break;

        case 5 :
            printf("Mode : Clignotement en chenille d'une LED par une LED\n");
            if(validation()==1)
                chenille1();
            break;

		case 6:
			printf("Mode : Clignotement en chenille d'une LED par une LED rapide\n");
			if (validation() == 1)
				chenille2();
			break;

		case 7:
			printf("Mode : Clignotement en chenille longue fondue\n");
			if (validation() == 1)
				chenille3();
			break;
    }
    if (choice==0)
        return 0;
    else
        return 1;
}