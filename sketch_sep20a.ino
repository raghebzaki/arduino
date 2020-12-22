#include <Servo.h> 

const int trigPin = 6;
const int echoPin = 5;
const int buzzer = 8;
int duration;
int distance;
Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(7); 
}

void loop() {
  for(int i=20;i<=160;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  if(distance<=10)
  {
      tone(8,2000,1000);
    }  
    else
    {
       noTone(8);
    }
  Serial.println(i); 
  Serial.println(distance); 
  }
  
  for(int i=160;i>20;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  if(distance<=10)
  { 
      tone(8,2000,1000);
    }  
    else
    {
      noTone(8);
    }
  Serial.println(i);
  Serial.println(distance);
  }
}
// calculating the distance
int calculateDistance(){   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
