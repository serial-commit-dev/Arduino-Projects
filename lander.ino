#include <Servo.h>
#include <NewPing.h>

#define trig_pin 3
#define echo_pin 4
#define max_dist 200

NewPing ultrasonic_sensor(trig_pin, echo_pin, max_dist);

Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;

void setup() {
  Serial.begin(9600);

  myServo1.attach(8); 
  myServo1.write(0);

  myServo2.attach(7);
  myServo2.write(0);

  myServo3.attach(6);
  myServo3.write(0);

  myServo4.attach(5);
  myServo4.write(0);
}

void loop() {
  // Add a small delay to let the sensor stabilize
  delay(50);
  
  int distance = ultrasonic_sensor.ping_cm();
  
  // Check if distance is valid (not 0)
  if (distance == 0) {
    distance = ultrasonic_sensor.ping_cm(); // Try again
  }
  
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println(" cm");

  // Only act on valid distances
  if (distance > 0) {
    if (distance > 15 && distance < 30) {
      deploy_legs();
    } else {
      contract_legs();
    }
  }

  delay(500);
}

void deploy_legs(){
    myServo1.write(0);
    delay(1000);
    myServo2.write(180);
    delay(1000);
    myServo3.write(0);
    delay(1000);
    myServo4.write(0);
    delay(1000);
}

void contract_legs(){
    myServo1.write(90);
    delay(1000);
    myServo2.write(90);
    delay(1000);
    myServo3.write(90);
    delay(1000);
    myServo4.write(70);
    delay(1000);
}