#include <Servo.h>

//define our servos
Servo servo1;
Servo servo2;

//define joystick pin (Analog)
int joyX = 0;
int joyY = 1;

//variables to read the values from the analog pins and store current position
int joyValX, joyValY;
int currentPos1 = 90; //initial servo position
int currentPos2 = 90; //initial servo position

void setup()
{ 
  //attaches our servos on pins PWM 3-5
  servo1.attach(3);
  servo2.attach(5);
  
  // Initialize servos to the middle position
  servo1.write(currentPos1);
  servo2.write(currentPos2);
}

void loop()
{
  //read the value of joystick (between 0-1023)
  joyValX = analogRead(joyX);
  joyValX = map(joyValX, 0, 1023, 0, 180); //servo value between 0-180

  joyValY = analogRead(joyY);
  joyValY = map(joyValY, 0, 1023, 0, 180); //servo value between 0-180

  // Smooth movement for servo1
  if (joyValX > currentPos1) {
    for (int pos = currentPos1; pos <= joyValX; pos++) {
      servo1.write(pos);
      delay(15); // adjust this value for speed
    }
  } else {
    for (int pos = currentPos1; pos >= joyValX; pos--) {
      servo1.write(pos);
      delay(15); // adjust this value for speed
    }
  }
  
  // Smooth movement for servo2
  if (joyValY > currentPos2) {
    for (int pos = currentPos2; pos <= joyValY; pos++) {
      servo2.write(pos);
      delay(15); // adjust this value for speed
    }
  } else {
    for (int pos = currentPos2; pos >= joyValY; pos--) {
      servo2.write(pos);
      delay(15); // adjust this value for speed
    }
  }

  // Update current positions
  currentPos1 = joyValX;
  currentPos2 = joyValY;
}