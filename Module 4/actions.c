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

void rechdicho(int tableau[], int ligne) {
	int debut, fin, val, mil, nb;
	bool trouve;

	debut = 0;
	fin = ligne;
	trouve = false;
	printf("entrez la valeur à chercher.\n");
	scanf("%i", &val);

	while (trouve != true && debut <= fin) {
		mil = (debut + fin) / 2;
		if (tableau[mil] == val) {
			trouve = true;
			}
		else if(val>tableau[mil]){
			debut = mil + 1;
		}
		else {
			fin = mil - 1;
		}
	}
	if (trouve == true) {
		printf("la valeur %i est la %ième valeur", val, mil+1);
	}
	else {
		printf("la valeur %i n'est pas dans le tableau.", val);
	}
}

/*int main()
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


}*/

int main()
{
    int tableau[10] = {1,2,4,6,8,10,12,14,16,18};
    int tableau2[10] = {10,20,30,40,50,60,70,80,90,100};
    int taille = 10;
    rechdicho(tableau, taille);
    return 0;

}