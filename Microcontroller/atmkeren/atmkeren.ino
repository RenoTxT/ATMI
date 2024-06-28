#include <LiquidCrystal.h>
#include <Keypad.h>
int buzzer = 5;
const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {32, 33, 34, 35};
byte colPins[COLS] = {36, 37, 38, 39};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const char* correctPin = "1707"; // Ganti dengan PIN yang diinginkan
int balance = 10000; // Saldo awal

void setup() {
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Selamat Datang");
  lcd.setCursor(6, 1);
  lcd.print("TUAN");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Masukkan PIN: ");
  digitalWrite(buzzer, LOW);
  String enteredPin = getEnteredPin();

  if (enteredPin.equals(correctPin)) {
    lcd.clear();
    lcd.print("PIN Benar");
    delay(1000);
    lcd.clear();

    int option = showOptions();

    if (option == 1) {
      lcd.clear();
      lcd.print("Saldo Anda: " );
      lcd.setCursor(0, 1);
      lcd.print("$" + String(balance));
      delay(2000);
      lcd.clear();
    } else if (option == 2) {
      lcd.clear();
      lcd.print("Masukkan nominal:");
      int amount = getAmount();

      if (amount > 0 && amount <= balance) {
        balance -= amount;
        lcd.clear();
        lcd.print("Saldo Anda: " );
        lcd.setCursor(0, 1);
        lcd.print("$" + String(balance));
        delay(2000);
        lcd.clear();
      } else {
        lcd.clear();
        lcd.print("Saldo tidak cukup");
        delay(2000);
        lcd.clear();
      }
    }
  } else {
    lcd.clear();
    digitalWrite(buzzer, HIGH);
    lcd.print("PIN Salah");
    delay(1000);
    lcd.clear();
  }
}

String getEnteredPin() {
  String pin = "";
  char key;
  while (pin.length() < 4) {
    key = keypad.getKey();
    if (key) {
      pin += key;
      lcd.setCursor(pin.length(), 1);
      lcd.print("*");
      delay(300);
    }
  }
  return pin;
}

int showOptions() {
  lcd.print("1. Cek Saldo");
  lcd.setCursor(0, 1);
  lcd.print("2. Ambil Uang");

  while (true) {
    char key = keypad.getKey();
    if (key == '1') {
      return 1;
    } else if (key == '2') {
      return 2;
    }
  }
}

int getAmount() {
  String amountStr = "";
  char key;
  while (true) {
    key = keypad.getKey();
    if (key >= '0' && key <= '9') {
      amountStr += key;
      lcd.setCursor(0, 1);
      lcd.print("$" + amountStr);
    } else if (key == '#') {
      return amountStr.toInt();
    }
  }
}
