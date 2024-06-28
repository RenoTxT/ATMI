#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
#define servoPin 10
Servo myservo;
int angle = 0;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

const int rs = 22, en = 24, d4 = 26, d5 = 28, d6 = 30, d7 = 32;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char var;
int angka_awal, angka_akhir;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  myservo.attach(servoPin);
}

void loop() {
  var = customKeypad.getKey();
  if (var == 'A') {
    angka_akhir++;
    Serial.println(angka_akhir);
  }
  if (var == 'B') {
    angka_akhir--;
    Serial.println(angka_akhir);
  }
  if (var == 'C') {
    angka_akhir = 2023;
    Serial.println(angka_akhir);
  }
  if (var == 'D') {
    angka_akhir = 0;
    Serial.println(angka_akhir);
  }
  if (var == '1') {
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);

    for (angle = 0; angle <= 180; angle += 1) {
      myservo.write(angle);
      delay(15);
    }

    for (angle = 180; angle >= 0; angle -= 1) {
      myservo.write(angle);
      delay(30);
    }
    delay(1000);
  }
  if (var == '2') {
    for (angle = 0; angle <= 180; angle += 1) { 
      myservo.write(angle);                  
      delay(10);                          
    }

    for (angle = 180; angle >= 0; angle -= 1) { 
      myservo.write(angle);                   
      delay(10);                          
    }
  }
  lcd.setCursor(0, 1);
  lcd.print(angka_akhir);
}
