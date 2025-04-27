void setup() {
  Serial.begin(9600);   // Initialize Serial communication
  pinMode(8, INPUT);    // PIR sensor pin (8) as input
  pinMode(7, OUTPUT);   // LED pin (7) as output
}

void loop() {
  if (digitalRead(8) == HIGH) {  // If motion is detected
    Serial.println("Motion detected!");  // Print message to Serial Monitor
    digitalWrite(7, HIGH);  // Turn the LED ON
    delay(200);              // Wait for 200 milliseconds
    digitalWrite(7, LOW);   // Turn the LED OFF
    delay(200);              // Wait for 200 milliseconds
  }
}