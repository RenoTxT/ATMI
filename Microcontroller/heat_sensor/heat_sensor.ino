#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#include <LiquidCrystal.h>
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(22, 24, 26, 28, 30, 31);
void setup() {
  lcd.begin(16, 2); //lcd size
  dht.begin();
}

void loop() {
  delay(2000);
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
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Lembab :");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Suhu :");
  lcd.print(hic);
  lcd.print(" C");
}
