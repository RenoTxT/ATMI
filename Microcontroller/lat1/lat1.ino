int a, b;

void setup() {
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  a = digitalRead(5);
  b = digitalRead(6);
  if(a == 1){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
}
