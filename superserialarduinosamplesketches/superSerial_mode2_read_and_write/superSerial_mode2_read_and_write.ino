/* Fabio D'Agnano - superSerial, write only testing
use it with the GH plugin, in mode 2 - read and write.
Testing purpose, replace it with your logic.*/

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available
    String receivedData = Serial.readStringUntil('\n'); // Read incoming data
    Serial.print("I have received ");
    Serial.println(receivedData); // Respond with the received value
  }
}