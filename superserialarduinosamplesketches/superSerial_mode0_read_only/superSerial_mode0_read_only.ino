/* Fabio D'Agnano - superSerial, read only testing
use it with the GH plugin, in mode 0 - read.
Testing purpose, replace it with your logic.*/

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
}

void loop() {
  for (int i = 1; i <= 100; i++) {
    Serial.println(i); // Send the number over serial
    delay(100);        // Delay to prevent flooding the serial port
  }
}