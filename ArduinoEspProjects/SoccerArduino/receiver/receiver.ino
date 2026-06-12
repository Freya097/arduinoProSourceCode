/* 
   NRF24L01 pins:
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED

   Servo Pins: 
   LEFTWHEEL     to Arduino pin 2   to board pin 1  
   RIGHTWHEEL    to Arduino pin 3   to board pin 2
   KICKER        to Arduino pin 4   to board pin 3
  
 */

//Libraries needed
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

//Servos needed
Servo myservoLEFTWHEEL;
Servo myservoRIGHTWHEEL;
Servo myservoKICKER;

//Variables needed
int pos = 0;

// Radio protocole needed:
RF24 radio(9, 10); // Create a Radio
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe
int message[9];  // 9 different messages to receive

// name of messages received
int  xAxis;
int  yAxis;
int buttonUp;
int buttonRight;
int buttonDown;
int buttonLeft;
int buttonE;
int buttonF;
int buttonJoystick;

void setup() {
  
  // Attach servos to pins               
  myservoLEFTWHEEL.attach(2);   //1
  myservoRIGHTWHEEL.attach(3);  //2
  myservoKICKER.attach(4);   //3
   

  // detach servos to avoid jitter on power up
  myservoLEFTWHEEL.detach();
  myservoRIGHTWHEEL.detach();
  myservoKICKER.detach();
 
      
  // Serial begin for debugging in serial monitor 
  Serial.begin(9600);
  
  // Radio settings
  radio.begin();  
  radio.setChannel(101);  
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate( RF24_250KBPS ) ; 
  radio.openReadingPipe(1,pipe);

}

void loop()
{  
  radio.startListening();
  
    while( radio.available() )
    {
      
      
      radio.read( message, sizeof(message) );
     

      // Define messages received while radio available
      xAxis           = message[0];
      yAxis           = message[1];
      buttonUp        = message[2];
      buttonRight     = message[3];
      buttonDown      = message[4];
      buttonLeft      = message[5];
      buttonE         = message[6];
      buttonF         = message[7];      
      buttonJoystick  = message[8];

      radio.stopListening();
      
      // Write what messages are received in serial monitor for debugging
      Serial.print( " X: ");
      Serial.print(xAxis);
      Serial.print( " Y: ");
      Serial.print(yAxis);
      Serial.print( " UP: ");
      Serial.print(buttonUp);
      Serial.print( " RIGHT: ");
      Serial.print(buttonRight);
      Serial.print( " DOWN: ");
      Serial.print(buttonDown);
      Serial.print( " LEFT: ");
      Serial.print(buttonLeft);
      Serial.print( " E: ");
      Serial.print(buttonE);
      Serial.print( " F: ");
      Serial.print(buttonF);      
      Serial.print( " JOYSTICK: ");
      Serial.print(buttonJoystick);
      Serial.println(" "); 

      //this is where you put the code for the servo commands
      
      // STOP
      if (xAxis > 400 && xAxis < 600 && yAxis > 400 && yAxis < 600)
      {
          myservoLEFTWHEEL.detach();
          myservoRIGHTWHEEL.detach();
          myservoKICKER.detach();
      }

      // FORWARDS FAST
      if (xAxis > 400 && xAxis < 600 && yAxis > 1018 && yAxis <= 1023)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (180);
          myservoRIGHTWHEEL.write (0);
      }

      // BACKWARDS FAST
      if (xAxis > 400 && xAxis < 600 && yAxis >= 0 && yAxis < 5)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (0);
          myservoRIGHTWHEEL.write (180);
      }

      // LEFT FAST
      if (xAxis >= 0 && xAxis < 5 && yAxis > 400 && yAxis < 600)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (0);
          myservoRIGHTWHEEL.write (0);
      }

      // RIGHT FAST
      if (xAxis > 1018 && xAxis <= 1023 && yAxis > 400 && yAxis < 600)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (180);
          myservoRIGHTWHEEL.write (180);
      }

      // FORWARDS MEDIUM
      if (xAxis > 400 && xAxis < 600 && yAxis > 750 && yAxis < 1018)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (110);
          myservoRIGHTWHEEL.write (70);
      }

      // BACKWARDS MEDIUM
      if (xAxis > 400 && xAxis < 600 && yAxis > 5 && yAxis < 250)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (70);
          myservoRIGHTWHEEL.write (110);
      }

      // LEFT MEDIUM
      if (xAxis > 5 && xAxis < 250 && yAxis > 400 && yAxis < 600)
      {
          myservoRIGHTWHEEL.attach(3);
  
          myservoRIGHTWHEEL.write (70);
      }

      // RIGHT MEDIUM
      if (xAxis > 750 && xAxis < 1018 && yAxis > 400 && yAxis < 600)
      {
          myservoLEFTWHEEL.attach(2);
  
          myservoLEFTWHEEL.write (110);
      }

      // FORWARDS SLOW
      if (xAxis > 400 && xAxis < 600 && yAxis > 600 && yAxis < 750)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (100);
          myservoRIGHTWHEEL.write (80);
      }

      // BACKWARDS SLOW
      if (xAxis > 400 && xAxis < 600 && yAxis > 250 && yAxis < 400)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (80);
          myservoRIGHTWHEEL.write (100);
      }

      // LEFT SLOW
      if (xAxis > 250 && xAxis < 400 && yAxis > 400 && yAxis < 600)
      {
          myservoRIGHTWHEEL.attach(3);
  
          myservoRIGHTWHEEL.write (80);
      }

      // RIGHT SLOW
      if (xAxis > 600 && xAxis < 750 && yAxis > 400 && yAxis < 600)
      {
          myservoLEFTWHEEL.attach(2);
  
          myservoLEFTWHEEL.write (100);
      }      

      //  FORWARDS LEFT FAST
      if (xAxis >= 0 && xAxis < 5 && yAxis > 1018 && yAxis <= 1023)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (115);
          myservoRIGHTWHEEL.write (0);
      }

      // FORWARDS RIGHT FAST
      if (xAxis > 1018 && xAxis <= 1023 && yAxis > 1018 && yAxis <= 1023)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (180);
          myservoRIGHTWHEEL.write (65);
      }

      // BACKWARDS LEFT FAST
      if (xAxis >= 0 && xAxis < 5 && yAxis >= 0 && yAxis < 5)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (65);
          myservoRIGHTWHEEL.write (180);
      }

      // BACKWARDS RIGHT FAST
      if (xAxis > 1018 && xAxis <= 1023 && yAxis >= 0 && yAxis < 5)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (0);
          myservoRIGHTWHEEL.write (115);
      }

      //  FORWARDS LEFT MEDIUM
      if (xAxis > 5 && xAxis < 400 && yAxis > 600 && yAxis < 1018)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (105);
          myservoRIGHTWHEEL.write (0);
      }

      // FORWARDS RIGHT MEDIUM
      if (xAxis > 600 && xAxis < 1018 && yAxis > 600 && yAxis < 1018)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (180);
          myservoRIGHTWHEEL.write (75);
      }

      // BACKWARDS LEFT MEDIUM
      if (xAxis > 5 && xAxis < 400 && yAxis > 5 && yAxis < 400)
      {
           myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (75);
          myservoRIGHTWHEEL.write (180);
      }

      // BACKWARDS RIGHT MEDIUM
      if (xAxis > 600 && xAxis < 1018 && yAxis > 5 && yAxis < 400)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
  
          myservoLEFTWHEEL.write (0);
          myservoRIGHTWHEEL.write (105);
      }

      // FAST KICK
      if(buttonUp == 0)
      {
          myservoKICKER.attach(4);
          delay(100);
          myservoKICKER.write (90);
          delay(200);
          myservoKICKER.write (160);
          delay(200);
          myservoKICKER.detach();
      }      

      // SLOW KICK
      if(buttonDown == 0)
      {
          myservoKICKER.attach(4);
          delay(100);

          for (pos = 160; pos >= 90; pos -= 1) 
          {     
              myservoKICKER.write (pos);            
              delay(5);                      
          }

          myservoKICKER.write (160);
          delay(200);
          myservoKICKER.detach();
      }   

      // WHEEL CALIBRATION
      if(buttonE == 0)
      {
          myservoLEFTWHEEL.attach(2);
          myservoRIGHTWHEEL.attach(3);
          delay(100);          
          myservoLEFTWHEEL.write (90);
          myservoRIGHTWHEEL.write (90);
          delay(30000);
          
      }   

      // KICKER 90 DEGREE CALIBRATION
      if(buttonF == 0)
      {
          myservoKICKER.attach(4);
          delay(100);
          myservoKICKER.write (90);
          delay(200);
          
      }      




      

      //This is where the code for the servo commands finishes
                    
   } 
}
