#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void rechdicho(int* timer, int* pouls, 	int ligne) {
	int debut, fin, val, mil;
	int tab[ligne];
	bool trouve;

	debut = 0;
	fin = ligne;
	trouve = false;
	printf("entrez la valeur à chercher.\n");
	scanf_s("%i", &val);

	while (trouve != true && debut <= fin) {
		mil = (debut + fin) / 2;
		if (tab[mil] == val) {
			trouve = true;
			}
		else if(val>tab[mil]){
			debut = mil + 1;
		}
		else {
			fin = mil - 1;
		}
	}
	if (trouve == true) {
		printf("la valeur %i est au rang %i", val, mil);
	}
	else {
		printf("la valeur %i n'est pas dans le tableau.", val);
	}
}
