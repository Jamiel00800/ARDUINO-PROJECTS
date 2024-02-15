//SUMERACRUZ, JAMIEL R.
// BSIT-NS0-3A
// MP4



const int trigPin = 7; //connects to the trigger pin on the distance sensor
const int echoPin = 6; //connects to the echo pin on the distance sensor
const int redPin = 8; //pin to control the red LED inside the RGB LED
const int greenPin = 10; //pin to control the green LED inside the RGB LED
const int yellowPin = 9; //pin to control the blue LED inside the RGB LED

const int buzzer = 3;

float distance = 0; //stores the distance measured by the distance sensor

void setup()
{
Serial.begin (9600); //set up a serial connection with the computer
pinMode(trigPin, OUTPUT); //the trigger pin will output pulses of electricity
pinMode(echoPin, INPUT); //the echo pin will measure the duration of pulses coming back from the distance sensor
//set the RGB LED pins to output
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(yellowPin, OUTPUT);
 pinMode(buzzer, OUTPUT); 

}

void loop() {
distance = getDistance(); //variable to store the distance measured by the sensor
Serial.print(distance); //print the distance that was measured
Serial.println(" in"); //print units after the distance

 if (distance > 10 && distance <= 20) {
    digitalWrite(greenPin, HIGH);
     digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
}
 else if (5 < distance && distance <= 9) { 
//make the RGB LED yellow
    digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
} 
else if (1 < distance && distance <= 5) { 
 digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite (buzzer, LOW) ;
  delay(2000);
  digitalWrite (buzzer, HIGH) ; 
}


delay(50); //delay 50ms between each reading
}




//------------------FUNCTIONS-------------------------------
//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance()
{
float echoTime; //variable to store the time it takes for a ping to bounce off an object
float calculatedDistance; //variable to store the distance calculated from the echo time
//send out an ultrasonic pulse that's 10ms long
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
echoTime = pulseIn(echoPin, HIGH); //use the pulsein command to see how long it takes for the
//pulse to bounce back to the sensor
calculatedDistance = echoTime / 148.0; //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
return calculatedDistance;}
