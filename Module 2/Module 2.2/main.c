#include "menu.h"
#include "generationCode.h"
//Le main appelle juste la fonction choiceParam présente dans le menu.c
int main() {
int mode=-1;
while(mode!=0){
    mode=choiceParam();
  }
  return 0;
}
