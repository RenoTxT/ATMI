void beep() {
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0) {
    char button = Serial1.read();
    Serial.print(button);
    beep();
    if (button == '4') {
      digitalWrite(3, !digitalRead(3));
    }
  }
}
