 int pushButton = 8; // Pin for the push button
int lightBulb = 7;  // Pin for the light bulb (or LED)

void setup() {
  pinMode(8, INPUT_PULLUP); // Set push button pin as input with internal pull-up
  pinMode(7, OUTPUT); // Set light bulb pin as output
}

void loop() {
  // Read the state of the push button
  int buttonState = digitalRead(8);

  // If the button is pressed (active LOW)
  if (buttonState == LOW) {
    digitalWrite(7, HIGH); // Turn the light bulb on
  } else {
    digitalWrite(7, LOW); // Turn the light bulb off
  }
}