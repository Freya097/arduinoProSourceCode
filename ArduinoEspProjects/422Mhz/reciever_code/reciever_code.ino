// RECIEVER CODE

#include <VirtualWire.h>

const int IN1 = 3;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 9;

void setup () {
  Serial.begin (9600);          	// Debugging only
  Serial.println ("Setup");

  // Initialise the IO and ISR
  vw_setup (2000);      // Bits per sec
  vw_set_rx_pin (2);    // Rx Data pin to Digital  Pin 2
  vw_rx_start ();       // Start the receiver PLL running
  
  for (int i = 0; i < 12; i ++) {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
  }
}

void loop () {
  uint8_t buf [VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message (buf, &buflen)) {
    int i;
    
    digitalWrite(13, true); 
    
    // Message with a good checksum received, dump it.
    for (i = 0; i < buflen; i ++) {
      Serial.print (buf [i]);
      
      if(buf [i] == '1') {
        forward ();
        Serial.println (" = forward");
      }
      
      if(buf [i] == '2') {
        backward ();
        Serial.println (" = backward");
      }
      
      if(buf [i] == '3') {
        left ();
        Serial.println (" = left");
      }
      
      if(buf [i] == '4') {
        right ();
        Serial.println (" = right");
      }
      
      if (buf [i] == '5') {
        STOP ();
        Serial.println (" = stopped");
      }
      
      Serial.print(" ");
    }
    
    Serial.println("");
    digitalWrite(13, false);
  }
}

void forward () {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void backward () {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void right () {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void left () {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void STOP () {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}
