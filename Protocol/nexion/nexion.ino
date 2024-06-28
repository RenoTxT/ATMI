#include "Nextion.h"
#include "TimerOne.h"

unsigned long lastPotentiometerMillis = 0; // Variable to store the last execution time
const unsigned long potentiometerInterval = 200;
const int merah = 2;
const int kuning = 3;
const int hijau = 4;

int h, l, kondisi;

NexText tState = NexText(3, 12, "tState");
NexText tState1 = NexText(3, 13, "tState1");
NexText tState2 = NexText(3, 14, "tState2");
NexText tState3 = NexText(4, 4, "tState3");

NexProgressBar pot = NexProgressBar(4, 3, "pot");


NexButton bOn = NexButton(3, 5, "bOn");
NexButton bOn1 = NexButton(3, 7, "bOn1");
NexButton bOn2 = NexButton(3, 8, "bOn2");

NexButton bStart = NexButton(4, 5, "bStart");

NexButton bOff = NexButton(3, 6, "bOff");
NexButton bOff1 = NexButton(3, 9, "bOff1");
NexButton bOff2 = NexButton(3, 10, "bOff2");


NexTouch *nex_listen_list[] = {
  &bOn,
  &bOn1,
  &bOn2,
  &bStart,
  &bOff,
  &bOff1,
  &bOff2,
  NULL
};
void potensiometer() {
  unsigned long currentMillis = millis(); // Get the current time

  // Check if enough time has passed since the last execution
  if (currentMillis - lastPotentiometerMillis >= potentiometerInterval) {
    lastPotentiometerMillis = currentMillis; // Update the last execution time

    h = analogRead(A0);
    l = map(h, 0, 1023, 0, 100);
    char temp[10] = { 0 };

    itoa(h, temp, 10);
    tState3.setText(temp);
    pot.setValue(l);
  }
}

void bOnPopCallback(void *ptr) {
  tState.setText("ON");
  digitalWrite(merah, HIGH);
}
void bOn1PopCallback(void *ptr) {
  tState1.setText("ON");
  digitalWrite(kuning, HIGH);
}
void bOn2PopCallback(void *ptr) {
  tState2.setText("ON");
  digitalWrite(hijau, HIGH);
}
void bOffPopCallback(void *ptr) {
  tState.setText("OFF");
  digitalWrite(merah, LOW);
}
void bOff1PopCallback(void *ptr) {
  tState1.setText("OFF");
  digitalWrite(kuning, LOW);
}
void bOff2PopCallback(void *ptr) {
  tState2.setText("OFF");
  digitalWrite(hijau, LOW);
  Serial.print("hello");
}
void bStartPopCallback(void *ptr) {
  potensiometer();
}
void setup() {
  Serial1.begin(9600);
  nexInit();
  bOn.attachPop(bOnPopCallback, &bOn);
  bOn1.attachPop(bOn1PopCallback, &bOn1);
  bOn2.attachPop(bOn2PopCallback, &bOn2);

  bStart.attachPop(bStartPopCallback, &bStart);

  bOff.attachPop(bOffPopCallback, &bOff);
  bOff1.attachPop(bOff1PopCallback, &bOff1);
  bOff2.attachPop(bOff2PopCallback, &bOff2);

  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}


void loop() {
  nexLoop(nex_listen_list);
  potensiometer();
}
