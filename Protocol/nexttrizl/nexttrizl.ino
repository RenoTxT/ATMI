#include "Nextion.h"

const int merah = 2;
const int kuning = 3;
const int hijau = 4;

int kondisi = 0;
int h;
int l;

NexText tState = NexText(3, 12, "tState");
NexText tState1 = NexText(3, 13, "tState1");
NexText tState2 = NexText(3, 14, "tState2");
NexText tState3 = NexText(4, 4, "tState3");

NexProgressBar pot = NexProgressBar(4, 3, "pot");

NexButton bOn = NexButton(3, 5, "bOn");
NexButton bOn1 = NexButton(3, 7, "bOn1");
NexButton bOn2 = NexButton(3, 8, "bOn2");

NexButton bNext = NexButton(2, 1, "bNext");

NexButton bOff = NexButton(3, 6, "bOff");
NexButton bOff1 = NexButton(3, 9, "bOff1");
NexButton bOff2 = NexButton(3, 10, "bOff2");


NexTouch *nex_listen_list[] = {
  &bOn,
  &bOn1,
  &bOn2,
  &bOff,
  &bOff1,
  &bOff2,
  &bNext,
  NULL
};


void bOnPopCallback(void *ptr) {
  tState.setText("ON");
  kondisi = 1;
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
void bNextPopCallback(void *ptr) {
  kondisi = 1;
  Serial.println("hehehe");
}
void potensio() {
  int l;
  h = analogRead(A0);
  l = map(h, 0, 1023, 0, 100);
  char temp[10] = { 0 };

  itoa(h, temp, 10);
  tState3.setText(temp);
  pot.setValue(l);
}
void bOffPopCallback(void *ptr) {
  kondisi = 0;
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
}
void setup() {
  Serial1.begin(9600);
  nexInit();
  bOn.attachPop(bOnPopCallback, &bOn);
  bOn1.attachPop(bOn1PopCallback, &bOn1);
  bOn2.attachPop(bOn2PopCallback, &bOn2);

  bNext.attachPop(bNextPopCallback, &bNext);

  bOff.attachPop(bOffPopCallback, &bOff);
  bOff1.attachPop(bOff1PopCallback, &bOff1);
  bOff2.attachPop(bOff2PopCallback, &bOff2);

  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}


void loop() {
  nexLoop(nex_listen_list);

  if (kondisi == 1) {
    potensio();
  }
}