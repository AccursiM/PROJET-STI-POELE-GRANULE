#include <rgb_lcd.h>
#include <Wire.h>


rgb_lcd lcd;

String chaineReception="";
int octetReception=0; // variable de stockage des valeurs reçues sur le port Série (ASCII)
char caractereRecu=0; // variable pour stockage caractère recu

const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
const float SOUND_SPEED = 340.0 / 1000; // Vitesse du son dans l'air en mm/us

void setup() {
  
  Serial.begin(115200); //initial the Serial
  lcd.begin(8,2);
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(1, INPUT);
}

void loop() {
  
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
            Serial.println (chaineReception);
            lcd.print(chaineReception);
            chaineReception = chaineReception="";
          };
          
          if (chaineReception == "balai jupiter") {
            lcd.clear();
            Serial.println (chaineReception);
            lcd.print(chaineReception);
            chaineReception = chaineReception="";
          };
  }
  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;
   
  /* Affiche les résultats en mm, cm et m */
  Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));
   
  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(1000);
  
}

