#include <Stepper.h>
#include <DHT.h>
#include <Stepper.h>
#include <Nextion.h>



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

int statButton = 0;

Stepper myStepper1(stepsPerRevolution1, 2, 3, 4, 5);      //Motor Sensor Api
Stepper myStepper2(stepsPerRevolution2, 24, 26, 28, 30);  //Motor Sensor Humidity & Suhu
DHT dht(DHTPIN, DHTTYPE);                                 //Struktur Pin Sensor DHT


NexButton bOn = NexButton(3, 3, "bOn");
NexButton bOff = NexButton(3, 4, "bOff");
NexButton b1 = NexButton(0, 7, "b1");

NexSlider flowslide = NexSlider(4, 0, "flowslide");

NexText textState = NexText(3, 6, "textState");
NexText textState1 = NexText(3, 7, "textState1");
NexText textState2 = NexText(3, 8, "textState2");
NexText textState3 = NexText(5, 3, "textState3");
NexText textState4 = NexText(5, 4, "textState4");
NexText textState5 = NexText(5, 5, "textState5");

NexProgressBar jHumidity = NexProgressBar(1, 8, "jHumidity");

NexTouch *nex_listen_list[] = {
  &bOn,
  &bOff,
  &b1,
  NULL
};

void bOnPopCallback(void *ptr) {
  statButton = 1;
  if (statButton == 1) {
    textState.setText("ON");
  } else {
    textState.setText("OFF");
  }
  digitalWrite(stanby, HIGH);
}

void bOffPopCallback(void *ptr) {
  statButton = 0;
  if (statButton == 1) {
    textState.setText("ON");
  } else {
    textState.setText("OFF");
  }
  digitalWrite(stanby, LOW);
}

void h0PopCallback(void *ptr) {
  uint32_t number = 0;
  char temp[10] = { 0 };
  // change LED brightness
  analogWrite(stanby, number);
}


void kebakaran() {
  Flame = digitalRead(flamePin);
  if (Flame == HIGH) {
    kondisi = 1;
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redFire, HIGH);

    while (kondisi == 1) {
      myStepper1.step(stepsPerRevolution1);

      button = digitalRead(8);
      if (kondisi == 1) {
        digitalWrite(buzzerPin, LOW);
        digitalWrite(redFire, LOW);
        kondisi = 0;
      }


      else if (Flame == LOW) {
        digitalWrite(buzzerPin, LOW);
        digitalWrite(redFire, LOW);
      }
    }
  }
}

void suhu() {
  float suhu = dht.readTemperature();     // Membaca suhu dalam derajat Celsius
  float kelembapan = dht.readHumidity();  // Membaca kelembapan
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);

  if (motorSpeed > 0) {
    myStepper2.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper2.step(stepsPerRevolution2 / 100);
  }

  if (!isnan(suhu) && !isnan(kelembapan)) {
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print("°C, Kelembapan: ");
    Serial.print(kelembapan);
    Serial.println("%");
    static char temperatureCTemp[8];
    dtostrf(suhu, 8, 2, temperatureCTemp);
    textState1.setText(temperatureCTemp);
    textState4.setText(temperatureCTemp);
    // Update humidity percentage text
    static char temperatureHumi[9];
    dtostrf(kelembapan, 9, 2, temperatureHumi);
    textState2.setText(temperatureHumi);
    textState5.setText(temperatureHumi);

    if (statButton == 1) {
      textState.setText("ON");
      textState3.setText("ON");
    } else {
      textState.setText("OFF");
      textState3.setText("OFF");
    }

    // Logika pengendalian lampu berdasarkan kondisi
    if (kelembapan >= 30 && kelembapan <= 80) {
      digitalWrite(greenhum, HIGH);
      digitalWrite(yellowhum, LOW);
      digitalWrite(redhum, LOW);

    } else if ((kelembapan >= 27 && kelembapan <= 29) || (kelembapan >= 81 && kelembapan <= 83)) {
      digitalWrite(greenhum, LOW);
      digitalWrite(yellowhum, HIGH);
      digitalWrite(redhum, LOW);
    } else if (kelembapan < 27 || kelembapan > 83) {
      digitalWrite(greenhum, LOW);
      digitalWrite(yellowhum, LOW);
      digitalWrite(redhum, HIGH);
    } else if (suhu >= 24 && suhu <= 28) {
      digitalWrite(greensu, HIGH);
      digitalWrite(yellowsu, LOW);
      digitalWrite(redsu, LOW);
    } else if (suhu < 21 || suhu > 31) {
      digitalWrite(greensu, LOW);
      digitalWrite(yellowsu, LOW);
      digitalWrite(redsu, HIGH);
    } else if ((suhu >= 21 && suhu <= 23) || (suhu >= 29 && suhu <= 31)) {
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
    if (kelembapan < 29) {
      myStepper2.step(stepsPerRevolution2);
    }

    delay(50);  // Delay antar pembacaan sensor
  } else {
    Serial.println("Gagal membaca data dari sensor DHT");
  }
}

void setup() {
  myStepper1.setSpeed(60);  //Speed Motor Sensor Api
  myStepper2.setSpeed(40);  //Speed Motor Sensor Humidity & Suhu
  Serial.begin(9600);
  Serial1.begin(9600);
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
  bOn.attachPop(bOnPopCallback, &bOn);
  bOff.attachPop(bOffPopCallback, &bOff);
}

void loop() {
  nexLoop(nex_listen_list);

  kebakaran();
  suhu();
  delay(500);
}