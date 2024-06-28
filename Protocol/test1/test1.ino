#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// network credentials
const char* ssid = "bens";
const char* password = "mesinrekindo";

const int LED = 4;

File webFile;

ESP8266WebServer server(80);

void LEDoff() {
  Serial.println("LED off page");
  digitalWrite(LED, HIGH);  //LED off
  server.send(200, "text/html", "LED is OFF");
}

void LEDon() {
  Serial.println("LED on page");
  digitalWrite(LED, LOW);  //LED is connected in reverse
  server.send(200, "text/html", "LED is ON");
}

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

void konten() {
  String content = "<!DOCTYPE html><html>";
  content += "<head><title>IRRIOTA</title>";
  content += "<style>";
  content += "html {";
  content += "font-family: Serif;";
  content += "display: inline-block;";
  content += "margin: 0px auto;";
  content += " text-align: center;";
  content += " }";
  content += " body {";
  content += " margin-top: 50px;";
  content += " }";
  content += "h1 {";
  content += "  color: #027373;";
  content += "   margin: 50px auto 30px;";
  content += "  }";
  content += " h3 {";
  content += "    color: #038C7F;";
  content += "    margin-bottom: 30px;";
  content += " }";
  content += " h4 {";
  content += "      color: #FFFFF;";
  content += "       margin-bottom: 30px;";
  content += "    }";
  content += "    .button {";
  content += "      display: block;";
  content += "      width: 80px;";
  content += "           background-color: #1abc9c;";
  content += "border: none;";
  content += "    color: white;";
  content += "     padding: 13px 30px;";
  content += "    text-decoration: none;";
  content += "          font-size: 25px;";
  content += "           margin: 0px auto 35px;";
  content += "           cursor: pointer;";
  content += "          border-radius: 4px;";
  content += "      }";
  content += "       .button-on {";
  content += "          background-color: #1abc9c;";
  content += "      }";
  content += "      .button-on:active {";
  content += "          background-color: #16a085;";
  content += "     }";
  content += "      .button-off {";
  content += "         background-color: #444444;";
  content += "      }";
  content += "     .button-off:active {";
  content += "        background-color: #2c3e50;";
  content += "    }";
  content += "   p {";
  content += "        font-size: 14px;";
  content += "        color: #888;";
  content += "        margin-bottom: 10px;";
  content += "   }";
  content += "   .myButton {";
  content += "       box-shadow: 0px 10px 14px -7px #3e7327;";
  content += "      background: linear-gradient(to bottom, #77b55a 5%, #72b352 100%);";
  content += "      background-color: #77b55a;";
  content += "      border-radius: 4px;";
  content += "      border: 1px solid #4b8f29;";
  content += "      display: inline-block;";
  content += "      cursor: pointer;";
  content += "      color: #ffffff;";
  content += "      font-family: Arial;";
  content += "      font-size: 13px;";
  content += "     font-weight: bold;";
  content += "     padding: 6px 12px;";
  content += "     text-decoration: none;";
  content += "      text-shadow: 0px 1px 0px #5b8a3c;";
  content += "   }";
  content += " .myButton:hover {";
  content += "        background: linear-gradient(to bottom, #72b352 5%, #77b55a 100%);";
  content += "         background-color: #72b352;";
  content += "    }";
  content += "    .myButton:active {";
  content += "         position: relative;";
  content += "         top: 1px;";
  content += "}";
  content += "</style>";
  content += "</head>";
  content += "<body>";
  content += "<h1>IrriOTA Control<h1>";
  content += "<h3>Control Mode</h3>";
  content += "<p>LED On / Off</p>";
  content += "<a class=\" myButton \" href=\"/LEDoff\">ON</a>";
  content += "<p>Pompa air On / Off</p>";
  content += "<a class=\"myButton \" href=\"/LEDon\">ON</a>";
  content += "</body>";
  content += "</html>";
  server.send(200, "text/html", content);
}

void setup() {
  Serial.begin(115200);  //Serial Monitor Activated
  ota();                 //Called OTA
  server.begin();
  server.on("/", konten);
  server.on("/LEDon", LEDon);
  server.on("/ledOff", LEDoff);
}

void loop() {
  ArduinoOTA.handle();  //OTA Parts
  server.handleClient();
}
