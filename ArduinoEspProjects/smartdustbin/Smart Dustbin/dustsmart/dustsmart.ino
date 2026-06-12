#include <Servo.h>
Servo servoMain; // Define our Servo

const int trigpin = 2;
const int echopin = 4;

int distance;
float duration;
float cm;

  void setup()
      {
        Serial.begin(9600);
      servoMain.attach(5); // servo on digital pin 10
      pinMode(trigpin, OUTPUT);
      pinMode(echopin, INPUT);
      }

    void loop()
    {
    Serial.print("Data");
    digitalWrite(trigpin, LOW);
    delay(2);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);
    duration = pulseIn(echopin, HIGH);
    cm = (duration/58.82);
    distance = cm;
    if(distance<25)
    {
    servoMain.write(180); // Turn Servo back to center position (90 degrees)
    delay(3000);
    }
    else{
    servoMain.write(0);
    delay(2000);
    }
    }


 