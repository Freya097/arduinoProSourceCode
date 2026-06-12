// TRANSMITTER CODE

#include <VirtualWire.h>

// Assigning controller buttons to Digital Pins
int forward = 8;
int backward = 9;
int rightTurn = 10;
int leftTurn = 11;
int stopMotor = 12;

// Array to store pins nos
int remotePins [] = {8, 9, 10, 11, 12};

void setup () {
  Serial.begin (9600);	       // Debugging only
  Serial.println ("Setup");

  // Initialise the IO and ISR
  vw_setup (2000);	      // Bits per sec
  vw_set_tx_pin (3);          // Transmitter Data Pin to Digital Pin 3
  
  for (int i = 0; i < 6; i ++) {
    pinMode (remotePins [i], INPUT);
    digitalWrite(remotePins [i], HIGH);
  }
}

void loop () {
  char *msg2;
  
  if (digitalRead (forward) == LOW) {
    char *msg2 = "1";
    digitalWrite(13, true);
    
    vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
    digitalWrite (13, false);
  }
  
  if (digitalRead (backward) == LOW) {
    char *msg2 = "2";
    digitalWrite (13, true);
    
    vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
    digitalWrite (13, false);
  }
  
  if (digitalRead (leftTurn) == LOW) {
    char *msg2 = "3";
    digitalWrite (13, true);
    
    vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
    digitalWrite (13, false);
  }
  
  if (digitalRead (rightTurn) == LOW) {
    char *msg2 = "4";
    digitalWrite (13, true);
    
    vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
    digitalWrite (13, false);
  }
  
  if (digitalRead(stopMotor)==LOW) {
    char *msg2 = "5";
    digitalWrite (13, true); 
    
    vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
    digitalWrite (13, false);
  } 
}
