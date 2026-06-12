#include <LiquidCrystal.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#include <LiquidCrystal_I2C.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
LiquidCrystal_I2C lcd1(0x27, 16, 2);

#define REPORTING_PERIOD_MS     1000
 
PulseOximeter pox;
uint32_t tsLastReport = 0;

byte customChar[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};


void onBeatDetected()
{
Serial.println("Beat!");
}
 
void setup()
{
  Serial.begin(115200);
  Serial.print("Initializing pulse oximeter..");
  lcd.begin(16,2);
  lcd.print("Initializing...");
  delay(3000);
  lcd.clear();

  lcd1.begin(16,2);
  lcd1.backlight();
  lcd1.print("Initializing...");
  delay(3000);
  lcd1.clear();
 
// Initialize the PulseOximeter instance
// Failures are generally due to an improper I2C wiring, missing power supply
// or wrong target chip
if (!pox.begin()) {
Serial.println("FAILED");
for(;;);
} else {
Serial.println("SUCCESS");
}
     pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
// Register a callback for the beat detection
pox.setOnBeatDetectedCallback(onBeatDetected);
}
 
void loop()
{
// Make sure to call update as fast as possible
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate ♥ :");
    Serial.print(pox.getHeartRate());
    Serial.print("bpm / SpO2:");
    Serial.print(pox.getSpO2());
    Serial.println("%");

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BPM : ");
    lcd.print(pox.getHeartRate());

    lcd.setCursor(0,1);
    lcd.print("SpO2: ");
    lcd.print(pox.getSpO2());
    lcd.print("%");
    tsLastReport = millis();

    lcd1.clear();
    lcd1.setCursor(0,0);
    lcd1.print("BPM  : ");
    lcd1.print(pox.getHeartRate());

    lcd1.setCursor(0,1);
    lcd1.print("SpO2: ");
    lcd.createChar(0, customChar);    // Custom Character
    lcd1.print(pox.getSpO2());
    lcd1.print("%");
    tsLastReport = millis();
}
}
