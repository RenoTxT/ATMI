#include <Servo.h>
#include <TM1637Display.h>
#include <Ultrasonic.h>

TM1637Display display(12, 11);
Servo myservo;
Ultrasonic ultrasonic(22, 24);

int ANIMDELAY = 100; // animation delay, default value is 100
int INTENSITYMIN = 0; // minimum brightness, valid range [0,15]
int INTENSITYMAX = 8; // maximum brightness, valid range [0,15]
byte MAXREG_DECODEMODE = 0x09;
byte MAXREG_INTENSITY = 0x0a;
byte MAXREG_SCANLIMIT = 0x0b;
byte MAXREG_SHUTDOWN = 0x0c;
byte MAXREG_DISPTEST = 0x0f;
int kondisi, b;
int DIN_PIN = 32; // data in pin
int CS_PIN = 34; // load (CS) pin
int CLK_PIN = 36; // clock pin
const unsigned char snowflake[] =
{
  B00111111,
  B00000011,
  B00000101,
  B00001001,
  B00010001,
  B00100001,
  B01000000,
  B10000000

};


void merah_hijau_merah() {
  digitalWrite(4, HIGH);// merah1
  digitalWrite(7, LOW);//merah2
  digitalWrite(10, HIGH);//merah3
  digitalWrite(3, LOW);//kuning1
  digitalWrite(6, LOW);//kuning2
  digitalWrite(9, LOW);//kuning3
  digitalWrite(2, LOW);//hijau1
  digitalWrite(5, HIGH);//hijau2
  digitalWrite(8, LOW);//hijau3

}

void setRegistry(byte reg, byte value) {
  digitalWrite(CS_PIN, LOW);
  putByte(reg); // specify register
  putByte(value); // send data
  digitalWrite(CS_PIN, LOW);
  digitalWrite(CS_PIN, HIGH);
}

void putByte(byte data) {
  byte i = 8;
  byte mask;
  while (i > 0)
  {
    mask = 0x01 << (i - 1); // get bitmask
    digitalWrite( CLK_PIN, LOW); // tick
    if (data & mask) // choose bit
      digitalWrite(DIN_PIN, HIGH); // send 1
    else
      digitalWrite(DIN_PIN, LOW); // send 0
    digitalWrite(CLK_PIN, HIGH); // tock
    --i; // move to lesser bit
  }
}

void kuning_kuning_merah() {
  digitalWrite(4, LOW);// merah1
  digitalWrite(7, LOW);//merah2
  digitalWrite(10, HIGH);//merah3
  digitalWrite(3, HIGH);//kuning1
  digitalWrite(6, HIGH);//kuning2
  digitalWrite(9, LOW);//kuning3
  digitalWrite(2, LOW);//hijau1
  digitalWrite(5, LOW);//hijau2
  digitalWrite(8, LOW);//hijau3
}

void hijau_hijau_merah() {
  digitalWrite(4, LOW);// merah1
  digitalWrite(7, HIGH);//merah2
  digitalWrite(10, HIGH);//merah3
  digitalWrite(3, LOW);//kuning1
  digitalWrite(6, LOW);//kuning2
  digitalWrite(9, LOW);//kuning3
  digitalWrite(2, HIGH);//hijau1
  digitalWrite(5, LOW);//hijau2
  digitalWrite(8, LOW);//hijau3
}

void hijau_merah_merah() {
  digitalWrite(4, LOW);// merah1
  digitalWrite(7, HIGH);//merah2
  digitalWrite(10, HIGH);//merah3
  digitalWrite(3, LOW);//kuning1
  digitalWrite(6, LOW);//kuning2
  digitalWrite(9, LOW);//kuning3
  digitalWrite(2, HIGH);//hijau1
  digitalWrite(5, LOW);//hijau2
  digitalWrite(8, LOW);//hijau3
}

void kuning_merah_kuning() {
  digitalWrite(4, LOW);// merah1
  digitalWrite(7, HIGH);//merah2
  digitalWrite(10, LOW);//merah3
  digitalWrite(3, HIGH);//kuning1
  digitalWrite(6, LOW);//kuning2
  digitalWrite(9, HIGH);//kuning3
  digitalWrite(2, LOW);//hijau1
  digitalWrite(5, LOW);//hijau2
  digitalWrite(8, LOW);//hijau3
}

void merah_merah_hijau() {
  digitalWrite(4, HIGH);// merah1
  digitalWrite(7, HIGH);//merah2
  digitalWrite(10, LOW);//merah3
  digitalWrite(3, LOW);//kuning1
  digitalWrite(6, LOW);//kuning2
  digitalWrite(9, LOW);//kuning3
  digitalWrite(2, LOW);//hijau1
  digitalWrite(5, LOW);//hijau2
  digitalWrite(8, HIGH);//hijau3
}

void merah_kuning_kuning() {
  digitalWrite(4, HIGH);// merah1
  digitalWrite(7, LOW);//merah2
  digitalWrite(10, LOW);//merah3
  digitalWrite(3, LOW);//kuning1
  digitalWrite(6, HIGH);//kuning2
  digitalWrite(9, HIGH);//kuning3
  digitalWrite(2, LOW);//hijau1
  digitalWrite(5, LOW);//hijau2
  digitalWrite(8, LOW);//hijau3
}

void setup() {
  pinMode(2, OUTPUT); // hijau
  pinMode(3, OUTPUT); // kuning
  pinMode(4, OUTPUT); // merah
  pinMode(5, OUTPUT); // hijau
  pinMode(6, OUTPUT); // kuning
  pinMode(7, OUTPUT); // merah
  pinMode(8, OUTPUT); // hijau
  pinMode(9, OUTPUT); // kuning
  pinMode(10, OUTPUT); // merah
  pinMode(31, OUTPUT); //Buzzer
  pinMode(DIN_PIN, OUTPUT);

  pinMode(CLK_PIN, OUTPUT);

  pinMode(CS_PIN, OUTPUT);

  myservo.attach(26);
  setRegistry(MAXREG_SCANLIMIT, 0x07);
  setRegistry(MAXREG_DECODEMODE, 0x00); // using an led matrix (not digits)
  setRegistry(MAXREG_SHUTDOWN, 0x01); // not in shutdown mode
  setRegistry(MAXREG_DISPTEST, 0x00); // no display test
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);
  setRegistry(1, snowflake[0]);
  setRegistry(2, snowflake[1]);
  setRegistry(3, snowflake[2]);
  setRegistry(4, snowflake[3]);
  setRegistry(5, snowflake[4]);
  setRegistry(6, snowflake[5]);
  setRegistry(7, snowflake[6]);
  setRegistry(8, snowflake[7]);
}

void loop() {
  while (kondisi == 0) {

    merah_hijau_merah();
    myservo.write(0);
    for (b = 5; b >= 0; b--) {
      display.setBrightness(0x0f);
      display.showNumberDec(b, true);
      digitalWrite(31, HIGH);
      delay(500);
      digitalWrite(31, LOW);
      delay(500);
      if (b == 3) {
        kuning_kuning_merah();
        display.setBrightness(0x0f);
        display.showNumberDec(b, true);
      }
      if (b == 1 ) {
        hijau_merah_merah();
        myservo.write(90);
        kondisi = 1;
      }
    }
  }
  while (kondisi == 1) {

    for (b = 5; b >= 0; b--) {
      display.setBrightness(0x0f);
      display.showNumberDec(b, true);
      delay(1000);
      if (b == 3) {
        kuning_merah_kuning();
        display.setBrightness(0x0f);
        display.showNumberDec(b, true);
      }
      if (b == 1 ) {
        merah_merah_hijau();
        kondisi = 2;
        myservo.write(0);
        setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
      }
    }
  }
  while (kondisi == 2) {

    for (b = 5; b >= 0; b--) {
      display.setBrightness(0x0f);
      display.showNumberDec(b, true);
      delay(1000);
      if (b == 3) {
        merah_kuning_kuning();
        display.setBrightness(0x0f);
        display.showNumberDec(b, true);
      }
      if (b == 1 ) {
        merah_hijau_merah();
        setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
        kondisi = 0;

      }
    }
  }
}
