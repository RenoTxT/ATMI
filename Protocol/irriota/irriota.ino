#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// network credentials
const char* ssid = "chuna";
const char* password = "belisendiri";

const int LED = 4;

//over the air upload code
//**DO NOT REMOVE**//
void ota() {
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
//end of OTA code

void setup() {
  Serial.begin(115200);           //Serial Monitor Activated
  ota();                          //Called OTA
  pinMode(LED, OUTPUT);           //Test if the OTA Work, you cam remove this(LED GPIO4)
}

void loop() {
  ArduinoOTA.handle();            //OTA Parts
  //LED Blink Simple Code
  digitalWrite(LED, HIGH);        
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  //End LED Blink Simple Code
}