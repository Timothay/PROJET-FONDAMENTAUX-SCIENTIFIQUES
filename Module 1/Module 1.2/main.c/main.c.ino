#include "cardio.h"

const int analogIn = A0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  RenvoiCSV(timer(),pouls_alea());
  delay(1000);

}
