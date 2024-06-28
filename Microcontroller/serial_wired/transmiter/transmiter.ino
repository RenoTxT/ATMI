void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop() {
  if (Serial1.available() > 0) {
    Serial.println(Serial1.readString());
  }
  else {
    if (digitalRead(2) == HIGH) {
      Serial1.print(1);
      Serial2.print(1);
    }
    if (digitalRead(3) == HIGH) {
      Serial1.print(2);
      Serial2.print(2);
    }
    if (digitalRead(4) == HIGH) {
      Serial1.print(3);
      Serial2.print(3);
    }
    if (digitalRead(5) == HIGH) {
      Serial1.print(4);
      Serial2.print(4);
    }
    delay(200);
  }
