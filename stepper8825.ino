// Ablauf:
// 1. Eine volle Umdrehung langsam CW
// 2. Eine volle Umdrehung schnell CCW
// 3. 5 volle Umdrehungen schnell CW
// 4. 5 volle Umdrehungen schnell CCW
//
// Definiere stepper Motor Anschlüsse und Schritte pro Umdrehung
#define dirPin 5                // direction = Richtung 
#define stepPin 2               // step = Schritt
#define enablePin 8             // enable = Aktivieren
#define stepsPerRevolution 200  // Schritte pro voller Umdrehung
#define CW HIGH                 // clockwise CW = im Uhrzeigersinn
#define CCW LOW                 // counterclockwise CCW = gegen den Uhrzeigersinn

void setup() {
  // Pins zur Motorsteuerung als Output definieren
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);

}

void loop() {
  // Setze die Drehrichtung im Uhrzeigersinn (CW = clockwise)
  digitalWrite(dirPin, CW);

  // Drehe den Motor eine volle Umdrehung langsam
  for (int i = 0; i < stepsPerRevolution; i++) {
    // die folgenden 4 Anweisungen sind für einen Schritt
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(5000);
  }

  delay(1000);

  // Setze die Drehrichtung gegen den Uhrzeigersinn (CCW = counterclockwise)
  digitalWrite(dirPin, CCW);

  // Drehe den Motor eine volle Umdrehung schnell
  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);

  // Setze die Drehrichtung im Uhrzeigersinn (CW = clockwise)
  digitalWrite(dirPin, CW);

  // Drehe den Stepper für 5 volle Umdrehungen schnell
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }

  delay(1000);

  // Setze die Drehrichtung gegen den Uhrzeigersinn (CCW = counterclockwise)
  digitalWrite(dirPin, CCW);

  // Drehe den Stepper für 5 volle Umdrehungen schnell
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }

  delay(1000);
}