/*Updated With Servo Code*/

#include <Servo.h>
Servo myservo;  
int pos = 0;

int Motor_A_Enable = 6;
int Motor_A_Reverse = 3;
int Motor_A_Forward = 4;

int Motor_B_Enable = 10;
int Motor_B_Reverse = 12;
int Motor_B_Forward = 7;
char incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Motor_A_Enable, OUTPUT);
  pinMode(Motor_A_Forward, OUTPUT);
  pinMode(Motor_A_Reverse, OUTPUT);

  pinMode(Motor_B_Enable, OUTPUT);
  pinMode(Motor_B_Forward, OUTPUT);
  pinMode(Motor_B_Reverse, OUTPUT);

}

void loop() {
  myservo.attach(A0);
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    if (incomingByte == '1') // Forward
    {
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 100);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Forward, HIGH);
      }else if (incomingByte == '2') // Left
    {
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 100);
        digitalWrite(Motor_A_Forward, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, HIGH);
        digitalWrite(Motor_B_Reverse, HIGH);
    }else if (incomingByte == '3') {
      analogWrite(Motor_A_Enable, 100);
        analogWrite(Motor_B_Enable, 0);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
      }else if (incomingByte == '4') {
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 0);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, HIGH);
        }else if (incomingByte == '7') {
          analogWrite(Motor_A_Enable, 0);
          analogWrite(Motor_B_Enable, 0);
          }
    }if(incomingByte == '0'){
        myservo.write(90);
        Serial.println("stop");
        delay(500);
        myservo.write(0);
      }
}
