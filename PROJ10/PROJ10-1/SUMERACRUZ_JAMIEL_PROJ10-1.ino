//MON 2-5 IT371L
//KAYCEE BULANTE
//PROJECT PROJECT 10.1
/* Change these values based on your calibration values */ 
int lowerThreshold = 420; 
int upperThreshold = 520; 

// Sensor pins 
#define sensorPower 7 
#define sensorPin A0 

// Value for storing water level 
int val = 0; 

// Declare pins to which LEDs are connected 
int redLED = 2; 
int yellowLED = 3; 
int greenLED = 4;

void setup() { 
  Serial.begin(9600); 
  pinMode(sensorPower, OUTPUT); 
  digitalWrite(sensorPower, LOW); 
  
  // Set LED pins as an OUTPUT 
  pinMode(redLED, OUTPUT); 
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}
void loop() { 
    //get the reading from the function below and print it 
    int level = readSensor();

    Serial.print("Water level: "); 
    Serial.println(level); 
    
    delay(1000); 
 } 
    //This is a function used to get the reading
    int readSensor() { 
      digitalWrite(sensorPower, HIGH); // Turn the sensor ON
      delay(10); // wait 10 milliseconds 
      val = analogRead(sensorPin); // Read the analog value form sensor 
      digitalWrite(sensorPower, LOW);// Turn the sensor OFF

      if(val<=lowerThreshold){
        digitalWrite(redLED,HIGH);
        digitalWrite(yellowLED,LOW);
        digitalWrite(greenLED,LOW);
      }else if(val>lowerThreshold && val<upperThreshold){
        digitalWrite(yellowLED,HIGH);
        digitalWrite(redLED,LOW);
        digitalWrite(greenLED,LOW);
      }else if(val>=upperThreshold){
        digitalWrite(greenLED,HIGH);
        digitalWrite(yellowLED,LOW);
        digitalWrite(redLED,LOW);
      }
return val; // send current reading 
}
