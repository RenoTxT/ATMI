void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A1);
  Serial.println(val);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(4, val);

}
