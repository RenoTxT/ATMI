#include <Stepper.h>
#include <DHT.h>
#include <Stepper.h>
#include "Nextion.h"

#define DHTPIN 22      // Pin data sensor DHT22 terhubung ke pin digital 22
#define DHTTYPE DHT22  // Tipe sensor DHT yang digunakan

int Flame;                           //Variable Sensor Api
const int buzzerPin = 12;            //Pin Buzzer
const int flamePin = 11;             //Pin Sensor Api
const int redFire = 53;              //Pin Lampu Merah untuk sensor api
const int stanby = 51;               //Pin Lampu kuning untuk penerangan
const int stepsPerRevolution1 = 70;  //Variable Motor 1
const int stepsPerRevolution2 = 70;  //Variable Motor 2
const int greenhum = 27;             //Pin Lampu Hijau untuk sensor Humidity
const int yellowhum = 25;            //Pin Lampu Kuning untuk sensor Humidity
const int redhum = 23;               //Pin Lampu Merah untuk sensor Humidity
const int greensu = 36;              //Pin Lampu Hijau untuk sensor Suhu
const int yellowsu = 34;             //Pin Lampu Kuning untuk sensor Suhu
const int redsu = 32;                //Pin Lampu Merah untuk sensor Suhu
//const int button = 8;                 //tombol reset
int kondisi_button = 0;
int kondisi = 0;
int button;

Stepper myStepper1(stepsPerRevolution1, 2, 3, 4, 5);      //Motor Sensor Api
Stepper myStepper2(stepsPerRevolution2, 24, 26, 28, 30);  //Motor Sensor Humidity & Suhu
DHT dht(DHTPIN, DHTTYPE);                                 //Struktur Pin Sensor DHT

NexButton merah = NexButton(4, 3, "merah");
NexButton offMerah = NexButton(4, 4, "offMerah");

NexTouch *nex_listen_list[] = {
  &merah,
  &offMerah,
  NULL
};

void kebakaran() {
  Flame = digitalRead(flamePin);
  digitalWrite(stanby, HIGH);
  if (Flame == HIGH) {
    digitalWrite(redFire, HIGH);
    digitalWrite(buzzerPin, HIGH);
    myStepper1.step(stepsPerRevolution1);
  } else {
    digitalWrite(redFire, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}

void merahPopCallback(void *ptr) {
  digitalWrite(stanby, HIGH);
}

void offMerahPopCallback(void *ptr) {
  digitalWrite(stanby, LOW);
}

void suhu() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  // Logika pengendalian lampu berdasarkan kondisi
  if (h >= 30 && h <= 80) {
    digitalWrite(greenhum, HIGH);
    digitalWrite(yellowhum, LOW);
    digitalWrite(redhum, LOW);

  } else if ((h >= 27 && h <= 29) || (h >= 81 && h <= 83)) {
    digitalWrite(greenhum, LOW);
    digitalWrite(yellowhum, HIGH);
    digitalWrite(redhum, LOW);
  } else if (h < 27 || h > 83) {
    digitalWrite(greenhum, LOW);
    digitalWrite(yellowhum, LOW);
    digitalWrite(redhum, HIGH);
  } else if (f >= 24 && f <= 28) {
    digitalWrite(greensu, HIGH);
    digitalWrite(yellowsu, LOW);
    digitalWrite(redsu, LOW);
  } else if (f < 21 || f > 31) {
    digitalWrite(greensu, LOW);
    digitalWrite(yellowsu, LOW);
    digitalWrite(redsu, HIGH);
  } else if ((f >= 21 && f <= 23) || (f >= 29 && f <= 31)) {
    digitalWrite(greensu, LOW);
    digitalWrite(yellowsu, HIGH);
    digitalWrite(redsu, LOW);
  } else {
    digitalWrite(greenhum, LOW);
    digitalWrite(yellowhum, LOW);
    digitalWrite(redhum, LOW);
    digitalWrite(greensu, LOW);
    digitalWrite(yellowsu, LOW);
    digitalWrite(redsu, LOW);
  }
  // Logika pengendalian motor stepper berdasarkan kondisi
  if (h < 29) {
    myStepper2.step(stepsPerRevolution2);
  } else {
    Serial.println("Gagal membaca data dari sensor DHT");
  }
  delay(50);  // Delay antar pembacaan sensor
}



void setup() {
  myStepper1.setSpeed(60);  //Speed Motor Sensor Api
  myStepper2.setSpeed(40);  //Speed Motor Sensor Humidity & Suhu
  Serial.begin(9600);
  dht.begin();
  nexInit();

  pinMode(buzzerPin, OUTPUT);
  pinMode(redFire, OUTPUT);
  pinMode(stanby, OUTPUT);
  pinMode(flamePin, INPUT);

  pinMode(greenhum, OUTPUT);
  pinMode(yellowhum, OUTPUT);
  pinMode(redhum, OUTPUT);

  pinMode(greensu, OUTPUT);
  pinMode(yellowsu, OUTPUT);
  pinMode(redsu, OUTPUT);

  digitalWrite(greenhum, LOW);
  digitalWrite(yellowhum, LOW);
  digitalWrite(redhum, LOW);

  merah.attachPop(merahPopCallback, &merah);
  offMerah.attachPop(offMerahPopCallback, &offMerah);
}

void loop() {
  nexLoop(nex_listen_list);
  kebakaran();
  suhu();
}