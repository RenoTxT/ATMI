String message;
String message1;
String message2;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  //TRANSMITER
  if (Serial.available() > 0) {
    message = Serial.readString();
    Serial.print("Reno: " + message);
    Serial1.print("Reno: " + message);
    Serial2.print("Reno: " + message);
  }

  //RECEIVER
  if (Serial1.available() > 0) {
    message1 = Serial1.readString();
    Serial.print(message1);
  }
  if (Serial2.available() > 0) {
    message2 = Serial2.readString();
    Serial.print(message2);
  }
}
