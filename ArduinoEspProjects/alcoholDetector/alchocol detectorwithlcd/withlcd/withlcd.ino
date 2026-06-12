#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int redLed = 10;
int greenLed = 12;

int buzzer = 9;
int smokeA0 = A1;

// Your threshold value
int sensorThres = 200;
 
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT); // buzzer
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}
 
void loop() {
  int analogSensor = analogRead(smokeA0);
 
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  lcd.print("Alchocol:");
  lcd.print(analogSensor-50);
  // Checks if it has reached the threshold value
  if (analogSensor-50 > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alert....!!!");
    digitalWrite(12, LOW);
    digitalWrite(buzzer, LOW);

//for (int i=0; i <= 255; i++){
//analogWrite(buzzer, i);
//delay(10);
//}
  }
  
  
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(12, HIGH);
    lcd.setCursor(0, 2);
    lcd.print(".....Normal.....");
   digitalWrite(buzzer, HIGH);

//for (int i=0; i <= 255; i--){
//analogWrite(buzzer, i);
//delay(10);
//}
  }
  delay(500);
  lcd.clear();
}
