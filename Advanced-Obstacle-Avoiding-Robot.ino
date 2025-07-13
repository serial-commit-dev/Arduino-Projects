#include <NewPing.h>
#include <Servo.h>

#define trig_pin 6
#define echo_pin 5
#define max_dist 200
NewPing  ultrasonic_sensor(trig_pin,echo_pin,max_dist);

int Distance;

//motor
int in1 = 13;
int in2 = 12;
int in3 = 11;
int in4 = 10;

Servo head;

int leftside = 0;
int rightside = 0;

int left_value;
int right_value;

#define left_sensor  3
#define right_sensor  4


void setup() {
  Serial.begin(9600);

  head.attach(7);
  head.write(90);//initialize position

  pinMode(3,INPUT);//right sensor
  pinMode(4,INPUT);//left sensor

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  stop();
}

void loop() {
  //IR program
  left_value = digitalRead(left_sensor);
  right_value = digitalRead(right_sensor);

  if ((right_value == 1)&&(left_value == 1)) {
    stop();
    delay(2000);
  } else if((right_value == 0)&&(left_value == 0)) {
    forward();
    delay(2000);
  } else if ((right_value == 1)&&(left_value == 0)) {
    left();
    delay(2000);
  }else if ((right_value == 0)&&(left_value == 1)) {
    right();
    delay(2000);
  }

  delay(100);//allows sensors time to detect surroundings

/////////////////////////////////////////////////////////////////////////////

  //Ultrasound program
  Distance = ultrasonic_sensor.ping_cm();
  Serial.print("Distance: ");
  Serial.println(Distance);

  if (Distance == 0){
    forward();
    return;
  }
  
     if((Distance < 13)&&(Distance > 1)) {
      stop();
      delay(3000);
      direction_settings();

     }

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

void direction_settings(){
  head.write(150);
  delay(800);
  leftside = ultrasonic_sensor.ping_cm();

  head.write(30);
  delay(800);
  rightside = ultrasonic_sensor.ping_cm();

  head.write(90);
  delay(200);
}

void forward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void right(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void left(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}


void stop(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
