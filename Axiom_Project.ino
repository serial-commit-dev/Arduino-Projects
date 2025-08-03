#include <Servo.h>
#include <NewPing.h>

Servo gate;

int Distance;
#define trig_pin 9
#define echo_pin 8
#define max_dist 15
NewPing ultrasonic_sensor(trig_pin,echo_pin,max_dist);


void setup() {
Serial.begin(9600);

gate.attach(10);
gate.write(0);


}

void loop() {
  Distance = ultrasonic_sensor.ping_cm();
  Serial.print("Distance: ");
  Serial.print(Distance);
  Serial.println(" cm");

  if (Distance < 10 && Distance > 5){
    gate.write(90);
    delay(2500);
  } else{
    gate.write(0);
  }
}
