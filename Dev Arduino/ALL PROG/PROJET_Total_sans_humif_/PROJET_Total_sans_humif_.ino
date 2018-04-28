#include <rgb_lcd.h>
#include <Wire.h>

const int pingPin = A0;
rgb_lcd lcd;

String chaineReception="";
int octetReception=0; // variable de stockage des valeurs reçues sur le port Série (ASCII)
char caractereRecu=0; // variable pour stockage caractère recu

void setup() {
  
  Serial.begin(115200); //initial the Serial
  lcd.begin(8,2);
}

void loop() {
  
  // Humiditée
  
  
  
  // Afficheur
  while (Serial.available()>0) { // tant qu'un octet en réception

        octetReception=Serial.read(); // Lit le 1er octet reçu et le met dans la variable
        caractereRecu=char(octetReception); // convertit l'octet reçu en caractère
        chaineReception=chaineReception+caractereRecu; // ajoute le caratère au String
          
          if (chaineReception == "nicole") {
            lcd.clear();
            Serial.println (chaineReception);
            lcd.print(chaineReception);
            chaineReception = chaineReception="";
          };
          
          if (chaineReception == "starf") {
            lcd.clear();
            Serial.println(chaineReception);
            lcd.print(chaineReception);
            chaineReception = chaineReception="";
          };
          
          if (chaineReception == "balai jupiter") {
            lcd.clear();
            Serial.println (chaineReception);
            lcd.print(chaineReception);
            chaineReception = chaineReception="";
          };
            if (chaineReception == chaineReception) {
            lcd.clear();
            Serial.println (chaineReception);
            lcd.print(chaineReception);
            chaineReception = chaineReception="";
          };
  };
  
  // Ultrason
  long duration, cm;

  // Morceau de code permettant de réinitialiser le capteur pour l’envoie d’une nouvelle onde
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // on utilise pulseIn pour recevoir une durée de type long
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // On converti la durée en distance grâce à une fonction que vous trouverez plus bas
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  // Comme expliqué auparavant nous divisons la durée par la vitesse et par 2 pour avoir la distance d’un aller simple.
  return microseconds / 29 / 2;
}

