 #include <TM1637Display.h>

#define CLK 12
#define DIO 11

TM1637Display display(CLK, DIO);

void hijau_merah_merah() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}
void kuning_kuning_merah() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}
void merah_hijau_merah() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}
void merah_kuning_kuning() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}
void merah_merah_hijau() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}
void kuning_merah_kuning() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void delayed_5_detik() {
  int a;
  for (a = 5; a >= 0; a--) {
    display.showNumberDec(a, true);
    delay(1000);
  }
}

void delayed_3_detik() {
  int b;
  for (b = 3; b >= 0; b--) {
    display.showNumberDec(b, true);
    delay(1000);
  }
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
}


void loop() {
  display.setBrightness(0x0f);
  hijau_merah_merah();
  delayed_5_detik();
  kuning_kuning_merah();
  delayed_3_detik();
  merah_hijau_merah();
  delayed_5_detik();
  merah_kuning_kuning();
  delayed_3_detik();
  merah_merah_hijau();
  delayed_5_detik();
  kuning_merah_kuning();
  delayed_3_detik();
}
