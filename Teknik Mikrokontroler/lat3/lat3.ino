int buttonState = 0;
int ledstate = LOW;

void setup() {
  pinMode(8, INPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  buttonState = digitalRead(8);

  if (buttonState == HIGH) {
    if (ledstate == HIGH) {
      ledstate = LOW;
    }
    else {
      ledstate = HIGH;
    }
  }
  digitalWrite(12, ledstate);
  delay(500);
}
