#include <Arduino.h>
#define RELAY_PIN 2
#define TEMPERATURE_PIN 3
#define PRESSURE_PIN 4
#define WATER_PRESSURE_PIN 5

const int seuilTempMax = 90;        // Seuil de température maximale acceptable pour le moteur
const int seuilPressionHuileMin = 25;  // Seuil minimal de pression d'huile acceptable
const int seuilPressionEauMin = 10;    // Seuil minimal de pression d'eau de citerne acceptable
void setup() {
  Serial.begin(115200);
  
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(TEMPERATURE_PIN, INPUT);
  pinMode(PRESSURE_PIN, INPUT);
  pinMode(WATER_PRESSURE_PIN, INPUT);
  
    // Allume le moteur diesel
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);

  // Éteint le moteur diesel
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}

void loop() {

// Lecture de la température
  int temperature = analogRead(TEMPERATURE_PIN);
// Lecture de la pression
  int pressure = analogRead(PRESSURE_PIN);
   // Lecture de la pression d'eau
  int waterPressure = analogRead(WATER_PRESSURE_PIN);
  // Vérification de la température

  //affichage les valeurs mesurés
  Serial.println("Temperature du moteur: " + String(temperature));
  Serial.println("Pression d'huile: " + String(pressure));
  Serial.println("Pression d'eau de citerne: " + String(waterPressure));
  
  
  if (temperature < seuilTempMax && pressure > seuilPressionHuileMin && waterPressure > seuilPressionEauMin) {
    digitalWrite(RELAY_PIN, HIGH);
    
   // Ajouter ici d'autres actions ou capteurs en fonction de vos besoins
    delay(60000);  // Attendez 1 minute avant de vérifier à nouveau les conditions
  } 
  else {

    digitalWrite(RELAY_PIN, LOW);
   // Ajouter ici d'autres actions ou capteurs en fonction de vos besoins

   delay(60000);  // Attendez 1 minute avant de vérifier à nouveau les conditions
  }
}
