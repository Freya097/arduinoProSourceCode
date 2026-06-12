int motorA1 = 2; // Pin  2 of L293
int motorA2 = 3; // Pin  7 of L293
int motorB1 = 4; // Pin 10 of L293
int motorB2 = 5; // Pin 14 of L293

int vel = 255; // Speed Of Motors (0-255)
int state = '0'; // Initialise Motors

void setup() { 
Serial.begin(9600); // Initialize serial communication at 9600 bits per second
   // Set pins as outputs
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
} 

void loop() { 

if(Serial.available()>0){ // Reads from bluetooth and stores its value
state = Serial.read();
}
if(state=='F'){ // Forward
  Serial.println("state");
analogWrite(motorA1, vel); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, vel); 
analogWrite(motorB2, 0); 
}
if(state=='B'){ // Reverse
    Serial.println("state1");
analogWrite(motorA1, 0); 
analogWrite(motorA2, vel);
analogWrite(motorB1, 0); 
analogWrite(motorB2, vel); 
}
if(state=='R'){ // Right
    Serial.println("state2");
analogWrite(motorA1, vel); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, 0); 
analogWrite(motorB2, vel); 
}
if(state=='L'){ // Left
    Serial.println("state3");
analogWrite(motorA1, 0); 
analogWrite(motorA2, vel);
analogWrite(motorB1, vel);
analogWrite(motorB2, 0); 
} 
if(state=='S'){ // Stop
    Serial.println("state4");
analogWrite(motorA1, 0); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, 0); 
analogWrite(motorB2, 0); 

}

}
