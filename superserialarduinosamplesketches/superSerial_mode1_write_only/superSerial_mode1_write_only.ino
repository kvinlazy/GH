/* Fabio D'Agnano - superSerial, write only testing
use it with the GH plugin, in mode 1 - write only.
If the string that you send starts with superSperial and then a number (N)
(i.e. superserial N), Arduino will blink N times.
Testing purpose, replace it with your logic.*/

const int ledPin = 13; // LED connected to pin 13
String lastReceivedData = ""; // Store the last received data

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin 13 as an output
  Serial.begin(9600);      // Initialize serial communication at 9600 baud
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available
    String receivedData = Serial.readStringUntil('\n'); // Read incoming data

    if (receivedData != lastReceivedData) { // Only process if it's new data
      lastReceivedData = receivedData;     // Update the last received data

      if (receivedData.startsWith("superSerial")) {
        int blinkCount = receivedData.substring(12).toInt(); // Extract the number after "superSerial"
        for (int i = 0; i < blinkCount; i++) {
          digitalWrite(ledPin, HIGH); // Turn LED on
          delay(500);
          digitalWrite(ledPin, LOW); // Turn LED off
          delay(500);
        }
        delay(5000); // Wait for 5 seconds after blinking
      } else {
        digitalWrite(ledPin, HIGH); // Turn LED on if any other data is received
      }
    }
  } else {
    digitalWrite(ledPin, LOW); // Turn LED off if no data is received
  }
}
