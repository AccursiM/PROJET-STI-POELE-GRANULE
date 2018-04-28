#include <rgb_lcd.h>
#include <Wire.h>


rgb_lcd lcd;

String chaineReception="";
int octetReception=0; // variable de stockage des valeurs reçues sur le port Série (ASCII)
char caractereRecu=0; // variable pour stockage caractère recu

void setup() {
  
  Serial.begin(115200); //initial the Serial
  lcd.begin(8,2);
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
}

