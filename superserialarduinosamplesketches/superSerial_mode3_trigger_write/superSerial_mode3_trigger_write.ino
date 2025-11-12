/* Fabio D'Agnano - superSerial, write with a trigger
use it with the GH plugin, in mode 3 - It will receive the data only when triggered, useful for instance for robot moves
Testing purpose, replace it with your logic.*/

String lastReceivedData = ""; // Store the last received data

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available
    String receivedData = Serial.readStringUntil('\n'); // Read incoming data

    if (receivedData != lastReceivedData) { // Only process if it's new data
      lastReceivedData = receivedData;     // Update the last received data

      Serial.println(receivedData); // Echo back the received value
      Serial.flush();              // Immediately flush the serial buffer
    }
  }
}

