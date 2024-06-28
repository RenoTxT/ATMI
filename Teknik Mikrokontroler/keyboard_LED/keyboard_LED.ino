char keyboard;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    keyboard = Serial.read(); // Read the incoming character

    if (keyboard == '1') {
      digitalWrite(2, !digitalRead(2)); // Toggle the state of pin 2 (red LED)
      if (digitalRead(2) == HIGH) {
        Serial.println("Lampu 1 menyala.");
      } else {
        Serial.println("Lampu 1 mati.");
      }

    }
    
    if (keyboard == '2') {
      digitalWrite(3, !digitalRead(3)); // Toggle the state of pin 3
      if (digitalRead(3) == HIGH) {
        Serial.println("Lampu 2 menyala.");
      } else {
        Serial.println("Lampu 2 mati.");
      }
    }
    
    if (keyboard == '3') {
      digitalWrite(4, !digitalRead(4)); // Toggle the state of pin 4
      if (digitalRead(4) == HIGH) {
        Serial.println("Lampu 3 menyala.");
      } else {
        Serial.println("Lampu 3 mati.");
      }
    }
  }
}
