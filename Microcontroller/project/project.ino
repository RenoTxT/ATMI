#include <Keyboard.h>
#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(5) == HIGH) {

  }
  if (digitalRead(6) == HIGH) {

  }

}
