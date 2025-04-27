#define in1 13
#define in2 12
#define in3 9
#define in4 8

#define left_sensor 3
#define right_sensor 5

#define en1 6   // Motor 1 speed control (PWM)
#define en2 11  // Motor 2 speed control (PWM)

int left_value;
int right_value;

void setup() {
  Serial.begin(9600);
  
  pinMode(right_sensor, INPUT);
  pinMode(left_sensor, INPUT);

  // Motor 1 control
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // Motor 2 control
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Motor speed control
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  motor_stop();
}

void loop() {
  // Read sensor values
  left_value = digitalRead(left_sensor);
  right_value = digitalRead(right_sensor);

  // Sensor-based movement logic
  if ((right_value == 1) && (left_value == 1)) {
    motor_stop();
    Serial.print("Motor stopped:");
     Serial.println(digitalRead(3));
    Serial.println(digitalRead(11));
    delay(2000);
  } else if ((right_value == 0) && (left_value == 0)) {
    forward();
    Serial.print("Motor forward:");
    Serial.println(digitalRead(3));
    Serial.println(digitalRead(11));
    delay(2000);
  } else if ((right_value == 1) && (left_value == 0)) {
    right();
    Serial.print("Motor turned right:");
    Serial.println(digitalRead(11));
    delay(2000);
  } else if ((right_value == 0) && (left_value == 1)) {
    left();
    Serial.print("Motor turned left:");
    Serial.println(digitalRead(3));
    delay(2000);
  }

  delay(100);  // Allow sensors time to detect surroundings
}

void forward() {
  analogWrite(en1, 150);  // Adjust speed (0 to 255)
  analogWrite(en2, 150);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void left() {
  analogWrite(en1, 100);  // Reduce speed for smoother turn
  analogWrite(en2, 150);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void right() {
  analogWrite(en1, 150);
  analogWrite(en2, 100);  // Reduce speed for better right turn response

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void motor_stop() {
  analogWrite(en1, 0);  // Set speed to 0 for full stop
  analogWrite(en2, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}