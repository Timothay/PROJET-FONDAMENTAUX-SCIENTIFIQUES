#include "param.h" /* ce fichier est créé par le code en C et contient la macro du numéro de la fonction que l'on va utiliser*/
/* les 3 lignes suivantes sont ici par sécurité au cas où PARAMETRE ne serait pas défini*/
#ifndef PARAMETRE 
#define PARAMETRE 0
#endif
/* Ici on active chaque port que l'on utilise, sachant que l'on commence au port 2 sur la carte Arduino*/
void setup() {
  for (int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
}
/* fonction qui fait clignoter une lumière sur deux*/
int alternance2() {
  double bpm = random(60,80);
/* ici on allume les ports pairs*/
int i;
i = 2;
while (i != 14){
  digitalWrite(i, HIGH);
  i = i + 2;
}
delay(30000/bpm);
/* a servira à éteindre tous les ports d'un coup*/
int a;
a = 0;
while(a != 13) {
  digitalWrite(a, LOW);
  a++;
}
delay(30000/bpm);
/* ici on allume les ports impairs*/
int b;
b = 3;
while (b !=15){
  digitalWrite(b, HIGH);
  b = b + 2;
}
delay(30000/bpm);
a = 0;
while(a != 13) {
  digitalWrite(a, LOW);
  a++;
}
delay(30000/bpm);
}
/* ici on fait clignoter une led sur trois*/
int alternance3() {
  double bpm = random(60,80);
/* ici on allume une led sur trois à partir du port 2*/
 int i;
 i = 2;
 while (i != 14){
  digitalWrite(i, HIGH);
  i = i + 3;
  }
 delay(30000/bpm);
 /* a servira à éteindre tous les ports d'un coup*/
  int a;
  a = 0;
  while (a != 14){
    digitalWrite(a, LOW);
    a++;
    }
 delay(30000/bpm);
/* ici on allume une led sur trois à partir du port 3*/ 
 int b;
b = 3;
while (b !=15){
  digitalWrite(b, HIGH);
  b = b + 3;
}
delay(30000/bpm);
/* a servira à éteindre tous les ports d'un coup*/
a = 0;
while(a != 13) {
  digitalWrite(a, LOW);
  a++;
}
delay(30000/bpm);
/* ici on allume une led sur trois à partir du port 4*/
int d;
d = 4;
while (d !=16){
  digitalWrite(d, HIGH);
  d = d + 3;
}
delay(30000/bpm);
a = 0;
while(a != 13) {
  digitalWrite(a, LOW);
  a++;
}
delay(30000/bpm);
}
/* ici on allume une led à la fois à la suite, en chenille*/
int chenille1() {
  double bpm = random(60,80);
  int a = 2;
  /* ici on allume la led suivante en même temps que l'actuelle s'éteint*/
  for(a; a<12; a++){
    digitalWrite(a, HIGH);
    delay(60000/bpm);
    digitalWrite(a, LOW);
  }
}
/* on fait clignoter toutes les leds en même temps*/
int all() {
  
  double bpm = random(60,80);
  for(int a = 2; a<12; a++){
    digitalWrite(a, HIGH);
    }
  delay(30000/bpm);
  for(int a = 2; a<12; a++){
    digitalWrite(a, LOW);
    }
  delay(30000/bpm);  
}
/*Même principe que la chenille 1 sauf qu'au lieu d'allumer une led par battement on fait un tour complet par battement*/
int chenille2() {
  double bpm = random(60,80);
  int a = 2;
  for(a; a<12; a++){
    digitalWrite(a, HIGH);
    delay(6000/bpm);
    digitalWrite(a, LOW);
  }
}
/*Ici encore même principe, sauf que toutes leds s'allument dans l'ordre croissant et restent allumées, puis elles s'éteignent dans l'ordre où elles se sont allumées*/
int chenille3() {
  double bpm = random(60,80);
for (int i = 2; i<12; i++)
{
  digitalWrite(i, HIGH);
  delay(3000/bpm);
  }
  int a= 0;
  while(a != 12){
  digitalWrite(a, LOW);
  a++;
  delay(3000/bpm);
  }
}
/*ici on sélectionne une led et on la fait clignoter*/
int unique() {
  double bpm = random(60,80);
  int param = PARAMETRE+1;
  digitalWrite(param, HIGH);
  delay(30000/bpm);
  int a = 0;
  while(a != 13) {
    digitalWrite(a, LOW);
    a++;
  }
  delay(30000/bpm);
}


void loop() {
  /*ici on récupère le numéro du mode sélectionné dans param.h puis on exécute la fonction correspondante*/
  switch(MODE) {
    case 1:
      all();
      break;
    case 2:
      alternance2();
      break;
    case 3:
      alternance3();
      break;
    case 4:
      unique();
      break;
    case 5:
       chenille1();
       break;
    case 6:
      chenille2();
      break;
    case 7:
      chenille3();
      break;
  }
}
