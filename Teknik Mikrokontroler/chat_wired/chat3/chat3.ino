String message;
String message1;
String message2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  // TRANSMITER
  if (Serial.available() > 0) {
    message2 = Serial.readString();
    Serial.print("Shigure UI: " + message2);
    Serial1.print("Shigure UI: " + message2);
    Serial2.print("Shigure UI: " + message2);
  }

  //RECEIVER
  if(Serial1.available()>0){
    message = Serial1.readString();
    Serial.print(message);
  }
  if(Serial2.available()>0){
    message1 = Serial2.readString();
    Serial.print(message1);
  }
}
