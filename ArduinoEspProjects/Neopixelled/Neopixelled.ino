#include "FastLED.h"

/*WS2812 IC array*/

#define NUM_LEDS 10

#define DATA_PIN 8
#define CLOCK_PIN 13

const int micPin = 7;
int micPinValue;
CRGB leds[NUM_LEDS]; 

void setup() {
  pinMode(micPin,INPUT);
  // put your setup code here, to run once:
FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  micPinValue=digitalRead(micPin);
  
  // put your main code here, to run repeatedly:
  if(micPinValue==HIGH){
    ledMove();
    }
    else{
      digitalWrite(DATA_PIN,LOW);
      }
}

void ledMove() { 
  for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = 19; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }
}
