/* 
 *  RFID Module RC522
 *  Simple Project:- Arduino will read RFID Tag and Display To the Serial Monitor!
 *  
 *  RFID RC522 and Arduino Uno Pin Configuration
 *  
 *  RFID RC522          Arduino Uno
 *  SS/SDA              D10
 *  SCK                 D13
 *  MOSI                D11
 *  MISO                D12
 *  IRQ                 Not Connected
 *  GND                 GND
 *  RST                 D9
 *  3.3V                3.3V
 *  
 *  //Note: We connected LCD to the Analog Pins.
 *  Remember, Analog Pins can be act as a Digital Pins,
 *  But Digital Pins CAN NOT be act as a Analog Pins.
 *  
 *  LCD(16x2) Connections
 *  
 *  VSS pin to GND
 *  VCC pin to 5V
 *  //We are connecting "Contrast pin to GND for Maximum Brightness"
 *  //You can also connect it to 10K Pot if you wish to change the Brightness Of LCD.
 *  VEE pin to GND 
 *  RS pin to Analog pin A0
 *  R/W pin to ground
 *  Enable pin to Analog pin A1
 *  D4 pin to Analog pin 5
 *  D5 pin to Analog pin 4
 *  D6 pin to Analog pin 3
 *  D7 pin to Analog pin 2
 *  LED+ pin to POWER
 *  LED- pin to GND 
 *   
 *  Servo is Connected to Digital Pin 5  
 *  
 *  RGB LED
 *  From RGB LED, We need Only Red and Green Color, 
 *  So we are not connecting Blue pin of the RGB. 
 *  
 *  Red pin to Digital pin 6
 *  Green pin to Digital pin 7
 *  
 *  Buzzer to Digital pin 8
 * https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json 
 *  
 *  Note:- RFID uses SPI Protocol to transfer the information.
 *  I took the Melody(for the Buzzer) from, 
 *  File -> Examples -> Digital -> ToneMelody
*/


//#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>

//#define RST_PIN 9
//#define SS_PIN  10

byte readCard[4];
byte a = 0;

#define SS_PIN 23
#define RST_PIN 28

//LiquidCrystal_I2C lcd(0x27, 16, 2);

//const int rs = 2,
//  en = 3,
//  d4 = 4,
//  d5 = 5,
//  d6 = 6
//  d7 = 7;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

LiquidCrystal lcd1(2, 3, 4, 5, 6, 7);
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {

  lcd1.init();
  lcd1.backlight();
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();
  lcd1.setCursor(2, 0);
  lcd1.print("Put your card");
  Serial.begin(9600);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return 0;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Scanned UID");
  a = 0;
  Serial.println(F("Scanned PICC's UID:"));
  for ( uint8_t i = 0; i < 4; i++) {  //
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
    Serial.print(" ");
    lcd1.setCursor(a, 1);
    lcd1.print(readCard[i], HEX);
    lcd1.print(" ");
    delay(500);
    a += 3;
  }
  Serial.println("");
  mfrc522.PICC_HaltA();
  return 1;
}
