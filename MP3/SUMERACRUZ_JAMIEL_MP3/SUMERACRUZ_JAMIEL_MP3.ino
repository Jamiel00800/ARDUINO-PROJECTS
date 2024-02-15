//SUMERACRUZ, JAMIEL R.
// BSIT-NS-3A-M

#include<Servo.h>

const int trigPin = 11; //connects to the trigger pin on the distance sensor
const int echoPin = 12; //connects to the echo pin on the distance sensor

int IN1 = 5;  
int IN2 = 6;
int IN3 = 8;
int IN4 = 9;
Servo servo_motor;

float distance = 0; //stores the distance measured by the distance sensor
void setup()
{
 Serial.begin (9600); //set up a serial connection with the computer
 pinMode(trigPin, OUTPUT); //the trigger pin will output pulses of electricity
 pinMode(echoPin, INPUT); //the echo pin will measure the duration of pulses coming back from the distance sensor
 pinMode(IN3, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN4, OUTPUT);

 servo_motor.attach(7

}
void loop() {
 distance = getDistance(); //variable to store the distance measured by the sensor
 Serial.print(distance); //print the distance that was measured
 Serial.println(" in"); //print units after the distance
 delay(50); //delay 50ms between each reading
 int distanceRight=0;
  int distanceLeft=0;
 
 forward();

 if (distance < 20){
  stopmove();
  delay(300);
  backward();
  distanceRight = lookRight();
  delay(300);
  distanceLeft = lookLeft();
  delay(300);

  if(distance>=distanceLeft){
    turnRight();
    stopmove();
  }
  else{
    turnLeft();
    stopmove();
  }
 }else{
  forward();
}
}




//------------------FUNCTIONS-------------------------------
//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
int getDistance()
{
 int echoTime; //variable to store the time it takes for a ping to bounce off an object
 int calculatedDistance; //variable to store the distance calculated from the echo time
 //send out an ultrasonic pulse that's 10ms long
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 echoTime = pulseIn(echoPin, HIGH); //use the pulsein command to see how long it takes for the
 //pulse to bounce back to the sensor
 calculatedDistance = echoTime / 148.0; //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
 return calculatedDistance; //send back the distance that was calculated
}

void forward(){
     digitalWrite(IN1,LOW);
    digitalWrite(IN3,LOW);

    digitalWrite(IN2,HIGH);
    digitalWrite(IN4,HIGH);
}
void stopmove(){
     digitalWrite(IN1,LOW);
    digitalWrite(IN3,LOW);

    digitalWrite(IN2,LOW);
    digitalWrite(IN4,LOW);
}

void backward(){

    digitalWrite(IN1,HIGH);
    digitalWrite(IN3,HIGH);

    digitalWrite(IN2,LOW);
    digitalWrite(IN4,LOW);
}

int lookRight(){
  servo_motor.write(50);
  delay(500);
  int distance = getDistance();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = getDistance();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);

}

void turnRight(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN4,HIGH);

  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);

  delay(500);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);

  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
}
void turnLeft(){
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);

  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);

  delay(500);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);

  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
}
