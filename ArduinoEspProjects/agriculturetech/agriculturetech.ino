
int sensorPin = A2; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor
int relayPin = 9;
void setup() {
  //put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
}

void loop() {
  
  //put your main code here, to run repeatedly:
  Serial.println(sensorValue);
  
  sensorValue = analogRead(sensorPin);
  if((analogRead(sensorValue) < 300)) {
    digitalWrite(relayPin, LOW);
    //Serial.println(sensorValue);
  }
  else {
    digitalWrite(relayPin, HIGH);
    //Serial.println("Thank You");
  }
  
}
