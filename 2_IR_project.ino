 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);  // IR 1 switch
  pinMode(7, INPUT);  // IR 2 switch
  pinMode(13, OUTPUT); // Set pin 13 as OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // first sensor
  Serial.print("IR 1 switch input: ");
  Serial.println(digitalRead(3));
  delay(400);

  if (digitalRead(3) == HIGH) { // Use HIGH instead of 1 for clarity
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // second sensor
  Serial.print("IR 2 switch input: ");
  Serial.println(digitalRead(5));
  delay(400);

  if (digitalRead(5) == HIGH) { // Corrected to digitalRead
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}