#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool lamp;
int button1;
int button2;
unsigned int a = 0;
unsigned int el = 0;
unsigned int detik;
unsigned int menit;
unsigned int realtime;
boolean isRunningg = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT); //Hijau
  pinMode(11, OUTPUT); //Kuning
  pinMode(12, OUTPUT); //Merah
  lcd.setCursor(4, 0);
  lcd.print("Stopwatch");
  Serial.begin(9600);
}

void loop() {
  button1 = digitalRead(8);
  button2 = digitalRead(9);

  if (button1 == HIGH) {
    if (!isRunningg) {
      isRunningg = true;
      a = millis() - el;
      lcd.clear();
      lcd.print("Running...");
    }
    else {
      isRunningg = false;
      el = millis() - a;
      lcd.clear();
      lcd.print("Paused");

    }
    delay(1000);
  }

  if (button2 == HIGH && !isRunningg) {
    // Mereset stopwatch
    el = 0;
    lcd.clear();
    lcd.print("Reset");
    lcd.setCursor(0, 1);
    lcd.print("Press START");
    delay(1000); // Debounce
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Stopwatch");
  }

  if (isRunningg) {
    realtime = millis() - a;
    printTime(realtime);
  } else {
    printTime(el);
  }
}
void printTime(unsigned int time) {
  detik = time / 1000;
  menit = detik / 60;
  detik = detik % 60;

  lcd.setCursor(6, 1);
  lcd.print(menit);
  lcd.print(":");
  if (detik < 10) {
    lcd.print("0");
  }
  lcd.print(detik);
}
