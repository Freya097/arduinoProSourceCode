#include "nodes.h"

const int ledPin=8; // led 2
const int ledPinOne=9;// Led 1

const int relayPin=11; // relay1
const int relayPinOne=12;// relay2

const int pirSensorPin=6; // motion sensor
const int gasSensorPin=A0; // gas sensor

#define homeAppliance 2
#define homeApplianceOne 3
#define homeApplianceTwo 4

int pirState=0; // sensor value
int sensorThreshold=300; // gassensor value

void setup() {
  
  pinMode(relayPin,OUTPUT);   
  pinMode(relayPinOne,OUTPUT); 
  
  pinMode(ledPin,OUTPUT);  
  pinMode(ledPinOne,OUTPUT);
  
  pinMode(pirSensorPin,INPUT);
  pinMode(gasSensorPin,INPUT);

  pinMode(buzzerSound,OUTPUT);

  pinMode(homeAppliance,OUTPUT); 
  pinMode(homeApplianceOne,OUTPUT); 
  pinMode(homeApplianceTwo,OUTPUT); 

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   pirState = digitalRead(pirSensorPin);
   int analogSensorValue = analogRead(gasSensorPin);

 if (pirState == HIGH) {                 // if motion detected
   digitalWrite(relayPin, HIGH);        // turn relay 1 ON
   delay(2000);
   digitalWrite(relayPinOne, HIGH);   //turn relay 2 ON
   delay(2000);
//   digitalWrite(ledPin, HIGH);
//   digitalWrite(ledPinOne, HIGH);
   digitalWrite(homeAppliance, HIGH);
   delay(2000);
   digitalWrite(homeApplianceOne, HIGH);
   delay(2000);
   digitalWrite(homeApplianceTwo, HIGH);
   
   Serial.println("Detected!!!\n");
 } 
 
 if (analogSensorValue > sensorThreshold){
    sirenSound();
    digitalWrite(ledPin,HIGH);
    //digitalWrite(ledPinOne,HIGH);
    Serial.print("Value Pass One:");
    
  }

 if (analogSensorValue > 200 || analogSensorValue < 300){
//    digitalWrite(ledPin,HIGH);
//    digitalWrite(ledPinOne,HIGH);
    Serial.print(analogSensorValue);
    Serial.print("Value Here\n");
    digitalWrite(homeAppliance, LOW);
   delay(2000);
   digitalWrite(homeApplianceOne, LOW);
   delay(2000);
   digitalWrite(homeApplianceTwo, LOW);
  }
  
 else {
   digitalWrite(relayPin, LOW); // turn LED OFF All Relay
   delay(2000);
   digitalWrite(relayPinOne, LOW);
   //digitalWrite(ledPin,LOW);
   digitalWrite(ledPinOne,LOW);
   digitalWrite(homeAppliance, LOW);
   delay(2000);
   digitalWrite(homeApplianceOne, LOW);
   delay(2000);
   digitalWrite(homeApplianceTwo, LOW);
 }
 
}
