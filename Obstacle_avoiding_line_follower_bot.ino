// Slayer_bots //
// Obstacle avoiding line follower bot //

#include <Servo.h>
#define Motor11 7
#define Motor12 6
#define Motor21 9
#define Motor22 8

//HC-SR04 Sensor connection 
const int trigPin = 11; 
const int echoPin = 12;
long duration; 
int distance; 
int stop_distance = 6; 

void setup() {
  
  pinMode(Motor11,OUTPUT);
  pinMode(Motor12,OUTPUT);
  pinMode(Motor21,OUTPUT);
  pinMode(Motor22,OUTPUT);

pinMode(A2, INPUT); // initialize Right sensor as an inut
pinMode(A3, INPUT); // initialize Left sensor as as input

}

void loop() {

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;


  int LEFT_SENSOR = analogRead(A2);
  int RIGHT_SENSOR = analogRead(A3);
  
if(distance < stop_distance)
 {
              digitalWrite(Motor11, LOW);
              digitalWrite(Motor12, LOW);
              digitalWrite(Motor21, LOW);
              digitalWrite(Motor22, LOW);
}
else 
{
  if(RIGHT_SENSOR<36 && LEFT_SENSOR<36) //FORWARD
{
            digitalWrite(Motor11, HIGH);
            digitalWrite(Motor12, HIGH);
            digitalWrite(Motor21, HIGH);
            digitalWrite(Motor22, HIGH);
}

  else if(RIGHT_SENSOR>36 && LEFT_SENSOR<36) //LEFT
 {
            digitalWrite(Motor11, LOW);
            digitalWrite(Motor12, HIGH);
            digitalWrite(Motor21, HIGH);
            digitalWrite(Motor22, LOW);
}

  else if(RIGHT_SENSOR<36 && LEFT_SENSOR>35) //RIGHT
 {
              digitalWrite(Motor11, HIGH);
              digitalWrite(Motor12, LOW);
              digitalWrite(Motor21, LOW);
              digitalWrite(Motor22, HIGH);
}

  else if(RIGHT_SENSOR>35 && LEFT_SENSOR>35) //STOP
{
              digitalWrite(Motor11, LOW);
              digitalWrite(Motor12, LOW);
              digitalWrite(Motor21, LOW);
              digitalWrite(Motor22, LOW);
              delay(10000);
 }
}
}
