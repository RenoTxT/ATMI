#include <LiquidCrystal.h>
#include <Keypad.h>
#include <AccelStepper.h>
#include <TM1637Display.h>

LiquidCrystal lcd(6, 7, 8, 9, 10, 11);
AccelStepper stepper;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

#define CLK 38
#define DIO 40

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

TM1637Display display(CLK, DIO);

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int waktu_jogging;

int k, a, b , c, d, kondisi, kondisi1, kondisi2, kondisi3, speedd = 0;
uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
int waktu_delay;
int waktu = 0;
const int delayed = 1000; // Update interval in milliseconds
unsigned long totalMilliseconds = 0;
unsigned long previousMillis = 0;
int calories = 0;

char key;

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void counting_up() {
  display.setBrightness(0x0f);
  data[0] = display.encodeDigit(a);
  data[1] = display.encodeDigit(b);
  data[2] = display.encodeDigit(c);
  data[3] = display.encodeDigit(d);
  display.setSegments(data);

  waktu_delay = millis();
  if (waktu_delay - waktu >= delayed) {
    waktu = waktu_delay;


    if (a >= 5 && b >= 9 && c >= 5 && d >= 9) {
      a = 6;
      b = 0;
      c = 0;
      d = 0;
    }
    else {
      if (b >= 9 && c >= 5 && d >= 9) {
        a++;
        b = 0;
        c = 0;
        d = 0;
      }
      else {
        if (c >= 5 && d >= 9) {
          b++;
          c = 0;
          d = 0;
        }
        else {
          if (d >= 9) {
            c++;
            d = 0;
          }
          else {
            d++;

          }
        }
      }
    }
  }
}

void setup() {
  lcd.begin(16, 2);
  stepper.setMaxSpeed(1000);
  Serial.begin(9600);
  pinMode( 31, INPUT);
  pinMode(33, INPUT);
  pinMode(35, INPUT);
  pinMode(12, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(44, OUTPUT);
  lcd.clear();
  lcd.print("Selamat Datang!");
  delay(2000);
  lcd.clear();
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
  display.setBrightness(0x0f);
}

void loop() {

  while (kondisi == 0) {
    digitalWrite(12, HIGH);
    digitalWrite(42, LOW);
    data[0] = display.encodeDigit(0);
    data[1] = display.encodeDigit(0);
    data[2] = display.encodeDigit(0);
    data[3] = display.encodeDigit(0);
    display.setSegments(data);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Treadmill AI");
    lcd.setCursor(4, 1);
    lcd.write(4);
    lcd.setCursor(5, 1);
    lcd.write(3);
    lcd.setCursor(6, 1);
    lcd.write(4);
    lcd.setCursor(7, 1);
    lcd.write(3);
    delay(150);
    lcd.setCursor(4, 1);
    lcd.write(3);
    lcd.setCursor(5, 1);
    lcd.write(4);
    lcd.setCursor(6, 1);
    lcd.write(3);
    lcd.setCursor(7, 1);
    lcd.write(4);
    delay(150);
    kondisi3 = digitalRead(35);

    if (kondisi3 == 1) {
      kondisi = 1;

      digitalWrite(37, HIGH);
      delay(100);
      digitalWrite(37, LOW);
      speedd = 6;
      stepper.setSpeed(speedd);
      digitalWrite(12, LOW);
      digitalWrite(44, HIGH);
      lcd.clear();
    }

  }
  while (kondisi == 1) {
    kondisi2 = digitalRead(31);
    kondisi1 = digitalRead(33);
    kondisi3 = digitalRead(35);
    stepper.setSpeed(speedd);
    if (kondisi3 == 1) {
      if (speedd < 48) {
        speedd += 6;
      }
      digitalWrite(37, HIGH);
      delay(200);
      lcd.clear();
      digitalWrite(37, LOW);
    }
    if (kondisi1 == 1) {
      if (speedd > 6 ) {
        speedd -= 6;
      }
      digitalWrite(37, HIGH);
      delay(200);
      lcd.clear();
      digitalWrite(37, LOW);
    }
    if (kondisi2 == 1) {
      digitalWrite(37, HIGH);
      delay(100);
      digitalWrite(37, LOW);
      kondisi = 2;
    }
    lcd.setCursor(0, 0);
    lcd.print("Kecepatan :");
    lcd.setCursor(0, 1);
    lcd.print(speedd);
    lcd.setCursor(4, 1);
    lcd.print("rpm");
    Serial.println(speedd);
    counting_up();
    stepper.runSpeed();
    calories++;
  }
  while (kondisi == 2) {
    digitalWrite(42, HIGH);
    digitalWrite(44, LOW);
    kondisi1 = digitalRead(33);
    if (kondisi1 == 1) {
      digitalWrite(37, HIGH);
      delay(100);
      digitalWrite(37, LOW);
      kondisi = 0;
      lcd.clear();
    }
    totalMilliseconds = a * 3600000L + b * 600000L + c * 10000L + d * 1000L;
    float timeInSeconds = totalMilliseconds / 1000.0;
    float rpm = speedd / 60.0;
    lcd.clear();
    calories = timeInSeconds * rpm;
    lcd.setCursor(0, 0);
    lcd.print("Burn :");
    lcd.setCursor(7, 0);
    lcd.print(calories);
    lcd.print(" gram");
    lcd.setCursor(0, 1);
    lcd.print("Waktu: ");
    .
    lcd.setCursor(6, 1);
    lcd.print(timeInSeconds);
    lcd.print(" s");
    delay(100);
  }
}
