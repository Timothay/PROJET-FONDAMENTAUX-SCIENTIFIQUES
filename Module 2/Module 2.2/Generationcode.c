#include <stdio.h>
#include <stdlib.h>
//Ici on crée le fichier param.h
void writeParams(const char* texte, int parametre) {
  FILE* fichier = NULL;
  fichier = fopen("param.h", "w");
  if (fichier != NULL) {
    fprintf(fichier, "%s", texte);
    if (parametre != 0) {
      fprintf(fichier, "%i", parametre);
    }
    fclose(fichier);
  }
}
//ici on a chaque fonction qui écrit une macro différente dans le param.h qui sera ensuite lu par le code Arduino
void all (){
writeParams("#define MODE 1", 0);
}

void alternance2 (){
writeParams("#define MODE 2\n#define PARAMETRE ", 0);
}

void alternance3() {
writeParams("#define MODE 3\n#define PARAMETRE ", 0);
}

void unique(parametre) {
  writeParams("#define MODE 4\n#define PARAMETRE ", parametre);
}

void chenille1() {
  writeParams("#define MODE 5", 0);
}

void chenille2() {
	writeParams("#define MODE 6", 0);
}

void chenille3() {
	writeParams("#define MODE 7", 0);
}