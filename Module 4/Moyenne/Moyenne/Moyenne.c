#include <stdio.h>
#include <stdlib.h>

int moyenne(int tab[], int N) {
	int nb1, nb2, nbcase, somme, i, moyenne ;
	somme = 0;
	printf("je veux la moyenne de la case : a la case :\n");
	scanf_s("%i %i", &nb1, &nb2);
	for ( i = nb1; i<= nb2 ; i++){
		somme = somme + tab[i] ;	
		
	}
	nbcase = (nb2 - nb1)+1;
	moyenne = somme / nbcase;
	printf("la moyenne de la case %i a la case %i est %i", nb1, nb2, moyenne);
	scanf_s("%i %i", &nb1, &nb2);
	return moyenne;
}
int main() {

	int tab[10] = {1,2,3,4,5,6,7,8,9,10};
	moyenne(tab, 10);

}