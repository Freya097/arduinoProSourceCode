int ledPin = 2;                // LED 
int pirPin = 8;                 // PIR Out pin 
int pirStat = 0;                   // PIR status

const int buzzerPin=9;

#define Threshold 300
#define MQ2pin A0

float sensorValue;  //variable to store sensor value

void setup() {
 pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 pinMode(buzzerPin, OUTPUT); 
 Serial.begin(9600);
}
void loop(){
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

//  if(sensorValue > Threshold)
//  {
//    digitalWrite(buzzerPin,HIGH);
//    Serial.print(" | Smoke detected!");
//  }
  
  Serial.println("");
  delay(2000); // wait 2s for next reading
  
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH  ) {// if motion detected
   digitalWrite(ledPin, HIGH); // turn LED ON
   
   Serial.println("Hey I got you!!!");
 } 
 if(sensorValue > Threshold){
  digitalWrite(buzzerPin,HIGH);
  }
//  if(sensorValue <= 400){
//    
//  digitalWrite(buzzerPin,HIGH);
//  
//  }
  
 else {
   digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
   digitalWrite(buzzerPin,LOW);
 }
} 
