const int ldrPin = A0;
const int ledPin = 5;

void setup()
{
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int ldrStatus = analogRead(ldrPin);

 if (ldrStatus >= 300)
 {
  digitalWrite(ledPin, HIGH);
  Serial.print("Its DARK, Turn on the LED : ");
  Serial.println(ldrStatus);
 }

 else
 {
  digitalWrite(ledPin, LOW);
  Serial.print("Its LIGHT, Turn off the LED : ");
  Serial.println(ldrStatus);
 }
}
