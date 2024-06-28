const int tapSensorPin = 2; // Digital pin connected to the Tap Sensor module's DOUT pin

void setup() {
  pinMode(tapSensorPin, INPUT_PULLUP); // Set the Tap Sensor pin as INPUT_PULLUP
  Serial.begin(9600); // Initialize serial communication for debugging (optional)
  pinMode(3, INPUT);
}

void loop() {
  int tapState = digitalRead(tapSensorPin); // Read the state of the Tap Sensor

  if (tapState == LOW) {
    Serial.println("Tap detected!");
    digitalWrite(3, HIGH);
    delay(3000);
    digitalWrite(3, LOW);// Display a message when a tap is detected
    // Your custom actions or functions can be added here.
  }
  else {
    digitalWrite(3, LOW);
  }

  // Add optional delay to prevent rapid repeated detections
  // delay(100);
}
