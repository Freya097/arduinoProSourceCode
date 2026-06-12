


const int ledOne = 6;
const int ledTwo = 7;
const int ledOThree = 8;
const int ledFour = 9;

const int sensorOne = A0;
const int sensorTwo = A2;

const int runMotor = 2;

int value = 0; // variable to store the sensor value
int valueOne = 0; // variable to store the sensor valueOne

void setup() {

  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledOThree, OUTPUT);
  pinMode(ledFour, OUTPUT);
  
  pinMode(sensorOne, INPUT);
  pinMode(sensorTwo, INPUT);

  pinMode(runMotor, OUTPUT);

  Serial.begin(9600);
  
 }

void loop() {
  
  value = analogRead(sensorOne); // read the analog value from sensor
  valueOne = analogRead(sensorTwo);  
  Serial.print("Sensor value A0: ");
  Serial.println(value);
  Serial.print("Sensor value A1: ");
  Serial.println(valueOne);
  delay(1000);

  if( analogRead(value)<=1010) {
    
      digitalWrite(runMotor,HIGH); 
      delay(2000);
      digitalWrite(ledOne,HIGH);
      Serial.print("statement 1");
  }
  
  if(analogRead(value)>=240 &&analogRead(valueOne)<=500){
    
    digitalWrite(runMotor,HIGH);
    delay(2000);
    digitalWrite(ledTwo,HIGH);
    Serial.print("statement 2");
    }
    
    if(analogRead(value)>=240 &&analogRead(valueOne)<=680){
      digitalWrite(runMotor,HIGH);
      digitalWrite(ledOThree,HIGH);
      }
    
    if(analogRead(value)>=250 &&analogRead(valueOne)<=730){
      digitalWrite(runMotor,LOW);
      delay(2000);
      digitalWrite(ledFour,HIGH);
      Serial.print("statement 3");
      }
    
  else {
    
      digitalWrite(runMotor,LOW);
      digitalWrite(ledOne,LOW);    
      digitalWrite(ledTwo,LOW);
      digitalWrite(ledOThree,LOW);
      digitalWrite(ledFour,LOW);
   }
   
}



/*
Sensor 1 Value 230-led1,led2 -1020
Sensor Value 2 640-led3,led4 -680
*/
