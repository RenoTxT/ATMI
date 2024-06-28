char keyboard;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    keyboard = Serial.read();

    if (keyboard == 'm') {
      digitalWrite(2, HIGH);
      Serial.println("Lampu merah menyala.");
    }

    if (keyboard == 'y') {
      digitalWrite(3, HIGH);
      Serial.println("Lampu kuning menyala.");
    }

    if (keyboard == 'g') {
      digitalWrite(4, HIGH);
      Serial.println("Lampu hijau menyala.");
    }

    if (keyboard == 'x') {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      Serial.println("Semua lampu mati.");
    }
  }
}
