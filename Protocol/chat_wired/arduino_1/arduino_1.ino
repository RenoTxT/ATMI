String inputMessage;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  //TRANSMITER
  if (Serial.available() > 0) {
    inputMessage = Serial.readString();
    sendMessage(inputMessage);
  }
  if (Serial1.available() > 0) {
    inputMessage = Serial1.readString();
    sendMessage(inputMessage);
  }
  if (Serial2.available() > 0) {
    inputMessage = Serial2.readString();
    sendMessage(inputMessage);
  }
}

void sendMessage(String message) {
  Serial.println(message);
  Serial1.println(message);
  Serial2.println(message);
}
