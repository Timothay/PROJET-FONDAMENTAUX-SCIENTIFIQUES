#include "cardio.h"

const int analogIn = A0;


void setup() {
  Serial.begin(9600);
}
/* On renvoie au port analogique A0 un temps et un pouls aléatoire au fichier csv pour l'afficher */
void loop() {
  RenvoiCSV(timer(),pouls_alea());
  delay(1000);

}
