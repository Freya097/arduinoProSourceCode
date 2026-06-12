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
  Serial.begin(9600);
  //servoKick();
  // put your setup code here, to run once:
 //myservo.attach(A0); // Servo Kontrol
  //Serial.begin(9600);
  pinMode(Motor_A_Enable, OUTPUT);
  pinMode(Motor_A_Forward, OUTPUT);
  pinMode(Motor_A_Reverse, OUTPUT);

  pinMode(Motor_B_Enable, OUTPUT);
  pinMode(Motor_B_Forward, OUTPUT);
  pinMode(Motor_B_Reverse, OUTPUT);
}

void loop() {

  if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());

    switch (data)
    {
      case 'F': //FORWARD
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 100);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Forward, HIGH);
        Serial.print("Forwad");
        break;
      case 'B': //REVERSE
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 100);
        digitalWrite(Motor_A_Forward, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, HIGH);
        digitalWrite(Motor_B_Reverse, HIGH);
        Serial.print("Backward");
        break;
      case 'L': //FORWARD LEFT
        analogWrite(Motor_A_Enable, 100);
        analogWrite(Motor_B_Enable, 0);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        Serial.print("Left");
        break;
      case 'R': //FORWARD RIGHT
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 0);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, HIGH);
        Serial.print("Right");
        break;
      case '5': //REVERSE LEFT
        analogWrite(Motor_A_Enable, 100);
        analogWrite(Motor_B_Enable, 0);
        digitalWrite(Motor_A_Reverse, HIGH);
        digitalWrite(Motor_A_Forward, LOW);
        break;
      case '6': //REVERSE RIGHT
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 0);
        digitalWrite(Motor_B_Reverse, HIGH);
        digitalWrite(Motor_B_Forward, LOW);
        
        break;
        case 'S': //REVERSE RIGHT
        analogWrite(Motor_B_Enable, 100);
        analogWrite(Motor_A_Enable, 0);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, LOW);
        Serial.print("Stop");
        break;

//     case '7': //REVERSE RIGHT
//        myservo.write(90);
//        delay(1000);
//        myservo.write(0);        


        default: //If bluetooth module receives any value not listed above, both motors turn off
        analogWrite(Motor_A_Enable, 0);
        analogWrite(Motor_B_Enable, 0);
    }
  }
  
//  incomingByte = Serial.read();
//   if (incomingByte == 't')
//  { 
//  myservo.write(90);
//  Serial.println("stop");
//  delay(500);
//  myservo.write(0);
//  }

}

//void servoKick(){
//  myservo.attach(A0); // Servo Kontrol
//  
//  }
