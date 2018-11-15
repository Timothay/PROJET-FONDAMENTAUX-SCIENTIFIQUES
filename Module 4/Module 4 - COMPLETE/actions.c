#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


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
    for(i=0; i < taille; i++)
    {
        if(tableau[i] < tableau[n])
            n = i;
    }
    return n;
}

void tri_selection(int tableau[], int tableau2[], int taille)
{
    int res;
    int taillebis = taille - 1;
    int i, a;
    int ordre;
    printf("\nChoisissez le mode tri que vous souhaitez :\n1) Pouls dans l'ordre croissant.\n2) Pouls dans l'ordre decroissant.\n3) Temps dans l'ordre decroissant.\n\n");
    scanf("%d", &ordre);
    printf("\n");
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
        break;
    }
    for(int a = 0 ; a < taille - 1; a++)
    {
    printf("%d, %d\n",tableau[a],tableau2[a]);
    }
}

void rechdicho(int timer[], int pouls[], int ligne) {
	int debut, fin, val, mil, nb;
	bool trouve;

	debut = 0;
	fin = ligne;
	trouve = false;
	printf("Entrez le temps pour lequel vous voulez le pouls.\n");
	scanf("%i", &val);

	while (trouve != true && debut <= fin) {
		mil = (debut + fin) / 2;
		if (timer[mil] == val) {
			trouve = true;
			}
		else if(val>timer[mil]){
			debut = mil + 1;
		}
		else {
			fin = mil - 1;
		}
	}
	if (trouve == true) {
        printf("Pour le temps %i ms, on a un pouls qui vaut %i bpm.\n", val, pouls[mil]);
	}
	else {
		printf("La valeur %i n'est pas dans le tableau.", val);
	}
}

int rechdichocase(int timer[], int ligne, int nb1)
{
    int debut, fin, val, mil, nb;
	bool trouve;

	debut = 0;
	fin = ligne;
	trouve = false;
    val = nb1;

	while (trouve != true && debut <= fin) {
		mil = (debut + fin) / 2;
		if (timer[mil] == val) {
			trouve = true;
			}
		else if(val>timer[mil]){
			debut = mil + 1;
		}
		else {
			fin = mil - 1;
		}
	}
	if (trouve == true) {
    return (mil);
	}
	else {
		printf("La valeur %i n'est pas dans le tableau.", val);
	}
}


void ft_mintableau(int tableau[], int ligne)
{
	int valeurmin;
    int i;
	valeurmin = tableau[0];
	for(i = 0; i < ligne - 1; i++)
    {
        if(tableau[i] < valeurmin)
        {
            valeurmin = tableau[i];
        }
    }
	
    printf("Le pouls mininimum est de %d bpm.\n", valeurmin);
}

void ft_maxtableau(int tableau[], int ligne)
{
    int valeurmax;
    int i;
	valeurmax = tableau[0];
    for(i = 0; i < ligne; i++)
    {
        if(tableau[i] > valeurmax)
        {
            valeurmax = tableau[i];
        }
    }       
    printf("Le pouls maximum est de %d bpm.\n", valeurmax);
}

void ft_moyenne(int tab[], int tab2[], int ligne) {
	int temp1;
    int temp2;
    int nb1;
    int nb2;
    int nbcase;
    int somme;
    int i;
    int moyenne ;
	
    somme = 0;

	printf("Entrez les deux temps entre lesquels vous voulez la moyenne de pouls :\n");
	scanf("%i %i", &temp1, &temp2);
    nb1 = rechdichocase(tab, ligne, temp1);
    nb2 = rechdichocase(tab, ligne, temp2);

	for ( i = nb1; i<= nb2 ; i++){
		somme = somme + tab2[i] ;	
		
	}
	nbcase = (nb2 - nb1)+1;
	moyenne = somme / nbcase;
	printf("La moyenne de pouls entre %i ms et %i ms est de %i.\n", temp1, temp2, moyenne);
}

