/* Fabio D'Agnano - superSerial, write only testing
use it with the GH plugin, in mode 2 - read and write.
This needs a separator in GH (,)
the first value will be a bounce back of the received values
Testing purpose, replace it with your logic.*/

tring receivedData = ""; // Variable to store the received string
int counter = 1;         // Counter variable (1 to 100)

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    // Read the incoming string until a newline character
    receivedData = Serial.readStringUntil('\n');

    // Read sensor values from A0, A1, and A2
    int sensorA0 = analogRead(A0);
    int sensorA1 = analogRead(A1);
    int sensorA2 = analogRead(A2);

    // Construct the response string
    String response = receivedData + "," + 
                      String(sensorA0) + "," + 
                      String(sensorA1) + "," + 
                      String(sensorA2) + "," + 
                      String(counter);

    // Send the response back over serial
    Serial.println(response);

    // Increment the counter and reset it if it exceeds 100
    counter++;
    if (counter > 100) {
      counter = 1;
    }
  }
}
