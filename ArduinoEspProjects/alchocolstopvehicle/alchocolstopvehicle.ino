#define MQ3pin A2

int IN1=11;
int IN2=12;

int IN3=4;
int IN4=5;

int buzzer=9;
float sensorValue;  //variable to store sensor value

void setup() {
  
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ3 warming up!");
  delay(20000); // allow the MQ3 to warm up
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
}

void loop() {
  
 sensorValue = analogRead(MQ3pin); // read analog input pin 0
 Serial.print("Sensor Value: ");
 Serial.println(sensorValue);
//  
//  delay(2000); // wait 2s for next reading

  if(sensorValue>210)
  {
    digitalWrite(buzzer,HIGH);
    //delay(2000);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    //delay(1000);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
   }
      else{
       digitalWrite(buzzer,LOW);
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,HIGH);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,HIGH);
        //Serial.print("Am here: ");
      }
}
