int kondisi;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void mematikan_lampu() {

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  Serial.println("Lampu telah dimatikan");
}


void loop() {
  while (kondisi == 0) {
    kondisi = 1;
    mematikan_lampu();
  }
  while (kondisi == 1) {

    delay(3000);
    digitalWrite(2, HIGH);
    Serial.println("Lampu merah nyala");
    delay(1000);           // Wait for 1 second
    digitalWrite(2, LOW);  // Turn off pin 2

    // Turn on pin 3
    digitalWrite(3, HIGH);
    Serial.println("Lampu kuning nyala");
    delay(1000);           // Wait for 1 second
    digitalWrite(3, LOW);  // Turn off pin 3

    // Turn on pin 4
    digitalWrite(4, HIGH);
    Serial.println("Lampu hijau nyala");
    delay(1000);           // Wait for 1 second
    digitalWrite(4, LOW);  // Turn off pin 4

    kondisi = 0;
  }
}
