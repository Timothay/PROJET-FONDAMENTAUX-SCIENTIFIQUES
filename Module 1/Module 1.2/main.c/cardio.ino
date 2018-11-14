//Fonction renvoyant une valeur aléatoire entre 60 et 80.
int pouls_alea() {
 int pouls = random(60,80);
 return pouls;
}

//Fonction affichant le temps passé depuis le démarrage de l'Arduino
long timer() {
// On utilise uint32_t pour assurer suffisamment d'espace mémoire
  uint32_t temps = micros() / 1000;
// micros est une fonction permettant de renvoyer le temps en millisecondes 
  return temps;
}

//Fonction permettant d'accéder au csv comportant les valeurs (et l'afficher)
void RenvoiCSV(long timestamp, int pouls) {
  Serial.print(timestamp);
  Serial.print(";");
  Serial.println(pouls);
  
}
