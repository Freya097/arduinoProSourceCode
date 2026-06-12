#include <Servo.h>
Servo esc_motor;
Servo esc_motorOne;

int command ;

void setup() {
  Serial.begin(9600); // put your setup code here, to run once:

  esc_motor.attach(3);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_motor.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000); 
  esc_motorOne.attach(5);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_motorOne.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000); 
  Serial.println("System Check...");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
   {
    command=(Serial.read());
    if (command=='F')
    {
      Serial.println("Forward");
      esc_motor.write(55);     
    
    }else if (command=='B')
    {
      Serial.println("Reverse");
      esc_motor.write(0); 
    }
    else if (command=='T')
    {
      Serial.println("ThrustForward");
      esc_motorOne.write(55); 
    }
    else if (command=='S')
    {
      Serial.println("Thrust Stop");
      esc_motorOne.write(0); 
    }
   }
}
