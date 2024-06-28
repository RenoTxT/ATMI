
#include <LiquidCrystal.h>

const int rs = 22, en = 24 , d4 =  26, d5 = 28, d6 = 30, d7 = 32;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonMerah, buttonBiru, buttonHijau, buttonKuning, var, ledMerah;

void setup() {
  pinMode(2, INPUT);//tombol merah
  pinMode(3, INPUT);//tombol biru
  pinMode(4, INPUT);//tombol kuning
  pinMode(5, INPUT);//tombol hijau
  pinMode(8, OUTPUT);//lampu hijau
  pinMode(9, OUTPUT);//lampu kuning
  pinMode(10, OUTPUT);//lampu merah
  Serial.begin(9600);



}

void loop() {



  switch (var) {
    case 0:

      Serial.println(var);
      buttonMerah = digitalRead(2);
      buttonBiru = digitalRead(3);

      while (var) {
        if (buttonMerah == 1) {
          var = 1;
        }
        if (buttonBiru == 1) {
          var = 2;
        }
        lcd.begin(16 , 2);
        lcd.setCursor(0, 0);
        lcd.print("Selamat Datang!");
        lcd.setCursor(0, 1);
        lcd.print("Mahasiswa ATMI!");
        delay(1000);
        lcd.clear();
        lcd.begin(16 , 2);
        lcd.setCursor(0, 0);
        lcd.print("Tekan tombol!");
        lcd.setCursor(0, 1);
        lcd.print("Merah atau Biru");
        delay(1000);
        lcd.clear();
      }


    case 1:
      while (ledMerah == 0) {
        Serial.println(var);
        buttonKuning = digitalRead(4);
        buttonHijau = digitalRead(5);
        if (buttonKuning == 1) {
          digitalWrite(10, HIGH);
          ledMerah = 1;
          delay(500);
        }
        if (buttonHijau == 1) {
          digitalWrite(10, LOW);
          ledMerah = 0;
          var = 0;
          break;
        }
      }
      while (ledMerah == 1) {
        buttonKuning = digitalRead(4);
        buttonHijau = digitalRead(5);
        if (buttonKuning == 1) {
          digitalWrite(10, LOW);
          ledMerah = 0;
          delay(500);
        }
        if (buttonHijau == 1) {
          digitalWrite(10, LOW);
          ledMerah = 0;
          var = 0;
          break;
        }
      }

    case 2:
      Serial.println(var);
      while (var == 2) {
        int val = analogRead(A1);
        val = map(val, 0, 1023, 0, 255);
        analogWrite(10, val);
        buttonHijau = digitalRead(5);
        if (buttonHijau == 1) {
          digitalWrite(10, LOW);
          ledMerah = 0;
          var = 0;
        }
        break;
      }
  }
}
