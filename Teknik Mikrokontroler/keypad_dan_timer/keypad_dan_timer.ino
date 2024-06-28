#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {52, 50, 48, 46};
byte colPins[COLS] = {44, 42, 40, 38};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int startButtonPin = 8;
const int resetButtonPin = 9;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

unsigned int startTime = 0;
unsigned int elapsedTime = 0;
unsigned int targetTime = 0;
bool isTimerRunning = false;

void setup() {
  Serial.begin(9600);
  pinMode(startButtonPin, INPUT);
  pinMode(resetButtonPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Set time: ----");
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY && key >= '0' && key <= '9' && !isTimerRunning) {
    targetTime = targetTime * 10 + (key - '0');
    lcd.setCursor(10, 0);
    lcd.print(targetTime);
  }

  if (digitalRead(startButtonPin) == HIGH && targetTime > 0 && !isTimerRunning) {
    isTimerRunning = true;
    lcd.clear();
    lcd.print("Running:");
    lcd.setCursor(0, 1);
    lcd.print(targetTime);
    startTime = millis();
  }

  if (digitalRead(resetButtonPin) == HIGH) {

    isTimerRunning = false;
    targetTime = 0;
    elapsedTime = 0;
    lcd.clear();
    lcd.print("Set time: ----");
  }

  if (isTimerRunning) {
    unsigned int currentMillis = millis();
    elapsedTime = (currentMillis - startTime) / 1000;
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("Timer");
    
    lcd.setCursor(7 - (targetTime >= 1000), 1);
    lcd.print(targetTime - elapsedTime);

    if (elapsedTime >= targetTime) {
      isTimerRunning = false;
      lcd.setCursor(0, 0);
      lcd.print("Time's up!");
      lcd.setCursor(0, 1);
      lcd.print("Press Reset");
    }
  }

  delay(100);
}
