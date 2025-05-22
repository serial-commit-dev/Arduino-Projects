#include <Servo.h>
#include <NewPing.h>

Servo head;

//ultrasonic sensor setting
#define trig_pin 6
#define echo_pin 5
#define max_dist 200
NewPing ultrasonic_sensor(trig_pin, echo_pin, max_dist);

// Motor 1
int in1 = 13;
int in2 = 12;


// Motor 2
int in3 = 9;
int in4 = 8;

int leftside = 0;
int rightside = 0;

int Distance; 

void setup(){
  Serial.begin(9600);
  pinMode(2,OUTPUT); //Buzzer 
  //head(servo) 
  head.attach(7);
  head.write(90);
  //Motors assigned
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  stop();
  
}

void loop(){
   Distance = ultrasonic_sensor.ping_cm();
   Serial.print("Distance: ");
   Serial.println(Distance);


    if(Distance == 0){
    forward();
    return;
    }

      if((Distance > 1) && (Distance < 13)){
      stop();
      delay(1000);

      // Add direction_settings() here so leftside and rightside are updated before checking them
      direction_settings();

      if((leftside > rightside)){
        left();
        delay(700);
        forward();
      }

      if((rightside > leftside)){
        right();
        delay(700);
        forward();
      }
    }

}

//Motor settings
void forward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void left(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void right(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void direction_settings(){
  head.write(150);
    delay(700);
    leftside = ultrasonic_sensor.ping_cm();

    head.write(30);
    delay(700);
    rightside = ultrasonic_sensor.ping_cm();

    head.write(90);
    delay(200);
}

void stop(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}