/*
 # the sensor value description
 # 0 ~300 dry soil
 # 300~700 humid soil
 # 700~950 in water
*/
#include<LiquidCrystal.h>

int sensorPin = A2; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor
int rotDirection = 0;
const int ledPinCheck = A5;
const int ledPinCheck1 = A4;
//SoftwareSerial esp(1, 0);
const int buzzEr = A1;

LiquidCrystal lcd(7,6,5,4,3,2);

#define enA 9
#define in1 10
#define in2 11

byte degree[8] =
{
0b00011,
0b00011,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000
};

void setup(){

  lcd.begin(16,2);
  lcd.createChar(1, degree);
  lcd.setCursor(2,0);
  lcd.print("Bonifon");
  lcd.setCursor(2,1);
  lcd.print("Agriculture");
  delay(2000);
  lcd.clear();

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  analogWrite(enA, pwmOutput); // Send PWM signal to L298N Enable pin

  pinMode(ledPinCheck, OUTPUT);
  pinMode(ledPinCheck1, OUTPUT);
  pinMode(buzzEr, OUTPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  pinMode(sensorPin, INPUT);
  Serial.begin(115200);
}
void loop(){
 // Get a reading from the Moisture sensor:
  sensorValue = analogRead(sensorPin);  
/*------Display Moisture Sensor Value in Serial Monitor------*/
 Serial.print("Moisture Sensor Value:");
 Serial.println(sensorValue); 
 //Display the Moisture Percentage
 float moisturePercentage;
 moisturePercentage= (sensorValue/300)*100;
 Serial.print("Moisture Percentage = ");
 Serial.print(moisturePercentage);
 Serial.print("%\n");

 //Display the plant need
 if(sensorValue > 1020
 ){
  Serial.println("I am thirsty, please give me water");

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(ledPinCheck1, HIGH);
  digitalWrite(buzzEr, HIGH);
  delay(1000);
  digitalWrite(buzzEr, HIGH);
  delay(1000);
  //digitalWrite(ledPinCheck, HIGH);
 }
 else if(sensorValue > 300 && sensorValue < 1023){
  Serial.println("I feel so comfortable");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(buzzEr, HIGH);
  delay(500);
  digitalWrite(buzzEr, HIGH);
  delay(500);
  digitalWrite(ledPinCheck, HIGH);
  delay(500);
  //digitalWrite(ledPinCheck1, HIGH);
 }
     if(sensorValue > 700){
      Serial.println("Too much water, I might get hurt");
    //  digitalWrite(ledPinCheck1, LOW);
    //  digitalWrite(ledPinCheck, LOW);
    digitalWrite(buzzEr, LOW);
     }
         else{
          
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(buzzEr, LOW);
          digitalWrite(ledPinCheck1, LOW);
          digitalWrite(ledPinCheck, LOW);
          }
 
    Serial.print("\n");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0,1);
    lcd.print(sensorValue);
    lcd.setCursor(6,1);
    lcd.print("&");
    lcd.setCursor(8,1);
    lcd.print(moisturePercentage);
    lcd.print(" %");

 delay(500);
} 
