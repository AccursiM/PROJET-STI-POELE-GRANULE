#include <Wire.h>
#include <rgb_lcd.h>

rgb_lcd lcd;

void setup() {
  Serial.begin(115200);  //initial the Serial
  lcd.begin(16, 2);
}

void loop() {
  
  const int colorR = 204;
  const int colorG = 0;
  const int colorB = 204;
  
  lcd.display();
  
  if (Serial.available())  {
    Serial.write(Serial.read());
    lcd.print(Serial.read());
    Serial.println();
  }
}
