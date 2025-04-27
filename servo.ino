#include <Servo.h>


Servo myServo;  // Create a Servo object

void setup() {

  myServo.attach(10); 
  myServo.write(0); // Initialize servo to 0  
}

void loop() {

       myServo.write(0);
       delay(1000);   
       myServo.write(90);
       delay(1000);
       myServo.write(180);
       delay(1000);
    // Delay for 1 second
}