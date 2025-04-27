#include <NewPing.h>

#define TRIGGER_PIN 5
#define ECHO_PIN 4
#define MAX_DISTANCE 300

NewPing ultrasonic_sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int Distance;

// Motor 1
int in1 = 13;
int in2 = 12;


// Motor 2
int in3 = 9;
int in4 = 8;



void setup() {
    // Motor 1
 
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    
    // Motor 2
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);


    Serial.begin(9600);

    // Motor off
    stop_motor();
}

void loop() { 
    Distance = ultrasonic_sensor.ping_cm();
    Serial.print("Distance: ");
    Serial.println(Distance);

    if ((Distance < 34) && (Distance > 1)) {
        stop_motor();
        delay(2000);  
        left(); // Turn left
        delay(300);
        forward(); // Move forward
        delay(2000);
        
    }
     else {
        forward();
        delay(2000);
        

    }
}

void forward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    // Set speed (0-255)
   
    
}

void left() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
    // Set speed (0-255)
  
}

void stop_motor() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
    // Stop the motors
   
}

void right(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    
}
