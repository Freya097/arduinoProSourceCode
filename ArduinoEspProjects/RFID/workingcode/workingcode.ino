#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

const int buzzerPin=2;
 // A1 FC 40 1B
Servo gateOpen;
void setup() 
{
  //gateOpen.write(0);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  gateOpen.attach(6);
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(buzzerPin,OUTPUT);

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  if (content.substring(1) == "6A C2 0D 0B") //change here the UID of the card/cards that you want to give access
  {
    gateOpen.write(180);
    digitalWrite(buzzerPin,HIGH);
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
    gateOpen.write(0);
  }

  if (content.substring(1) == "") //change here the UID of the card/cards that you want to give access
  {
    //gateOpen.write(180);
    tone(buzzerPin, 500);
    delay(500);
    tone(buzzerPin, LOW);
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
    gateOpen.write(0);
  }
  
 else   {
    gateOpen.write(0);
    digitalWrite(buzzerPin,LOW);
    Serial.println(" Access denied");
    delay(3000);
  }
} 
