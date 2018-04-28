const int pingPin = A0;

void setup() {
  // initialise la communication série
  Serial.begin(9600);
}

void loop()
{
  // déclaration des variable pour le temps entre deux ondes et la distance
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

