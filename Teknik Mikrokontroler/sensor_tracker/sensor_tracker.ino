#define sensor 2
#define red 3
#define green 4
bool value;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  value = digitalRead(sensor);
  if (value == 0) {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    Serial.println(value);
  }
  else {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    Serial.println(value);
  }
}
