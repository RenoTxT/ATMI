#include <Servo.h>
#include <TM1637Display.h>
#include <Ultrasonic.h>


Servo myservo;
Ultrasonic ultrasonic(22, 24);
TM1637Display display(12, 11);

uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };

int a, b, c, d;
int kondisi, counting_down;
int button1, button2, jarak, putaran;

void counting_seven_segment() {
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

void setup() {
  pinMode(28, INPUT);
  pinMode(30, INPUT);
  pinMode(31, OUTPUT);
  pinMode(2, OUTPUT); // hijau
  pinMode(3, OUTPUT); // kuning
  pinMode(4, OUTPUT); // merah
  pinMode(5, OUTPUT); // hijau
  pinMode(6, OUTPUT); // kuning
  pinMode(7, OUTPUT); // merah
  pinMode(8, OUTPUT); // hijau
  pinMode(9, OUTPUT); // kuning
  pinMode(10, OUTPUT); // merah
  myservo.attach(26);
  Serial.begin(9600);
}

void loop() {

  while (kondisi == 0) {
    button1 = digitalRead(28);
    button2 = digitalRead(30);
    jarak = ultrasonic.read();
    if (jarak < 50) {
      myservo.write(0);
    }
    if (jarak > 50) {
      myservo.write(180);
    }

    display.showNumberDec(0, true);

    Serial.println(kondisi);
    if (button1 == HIGH) {
      kondisi = 1;
    }
    if (button2 == HIGH) {
      kondisi = 2;
    }
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(10, LOW);
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(31, LOW);
    display.setBrightness(0x0f);
    display.showNumberDec(0, true);
    a = 0;
  }
  while (kondisi == 1) {
    data[0] = display.encodeDigit(a);
    data[1] = display.encodeDigit(b);
    data[2] = display.encodeDigit(c);
    data[3] = display.encodeDigit(d);
    display.setSegments(data);
    button1 = digitalRead(28);
    button2 = digitalRead(30);
    display.setBrightness(0x0f);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(10, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);

    digitalWrite(31, HIGH);
    delay(500);
    digitalWrite(31, LOW);
    delay(500);

    if (button2 == HIGH) {
      kondisi = 2;
    }
    counting_seven_segment();
  }
  while (kondisi == 2) {
    button1 = digitalRead(28);
    button2 = digitalRead(30);
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    for (counting_down = a; counting_down >= 0; counting_down--) {
      display.setBrightness(0x0f);
      display.showNumberDec(counting_down, true);
      digitalWrite(31, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(10, HIGH);
      delay(500);//wait for 1ms
      digitalWrite(31, LOW);
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      digitalWrite(10, LOW);
      delay(500);
    }
    digitalWrite(31, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    myservo.write(180);

    delay(5000);
    if (counting_down == -1) {
      kondisi = 0;
    }
    delay(1000);
  }
}
