#define enA 9
#define in1 10
#define in2 11

int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor

//const int irSensorPin = 2;
const int motorPin = 7;
const int buzzerPin = 3;

int varCount = 0;

void setup() {
  
   pinMode(sensorPin, INPUT);
   pinMode(buzzerPin, INPUT);
   pinMode(7, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(enA, OUTPUT);
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);

   int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); 
  analogWrite(enA, pwmOutput); 
  
   Serial.begin(9600);
}

void loop() {

   //int sensorStatus = digitalRead(irSensorPin);
   sensorValue = analogRead(sensorPin);
   if (analogRead(sensorValue) == 0) {
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      
      delay(500);
      //digitalWrite(7, HIGH);
      //digitalWrite(buzzerPin, HIGH);
//      for (varCount = 700; varCount < 800; varCount++) {
//         tone(buzzerPin, varCount);
//         delay(15);
//      }
//      for (varCount = 800; varCount > 700; varCount--) {
//         tone(buzzerPin, varCount);
//         delay(15);
//      }
      Serial.print("data1");

      //   } else if (irSensorPin == HIGH && irSensorPin == LOW) {
      //      digitalWrite(in1, LOW);
      //      digitalWrite(in2, LOW);
      //      delay(500);
      //      digitalWrite(7, HIGH);
      //      delay(500);
      //      for (varCount = 700; varCount < 800; varCount++) {
      //         tone(9, varCount);
      //         delay(15);
      //      }
      //      for (varCount = 800; varCount > 700; varCount--) {
      //         tone(9, varCount);
      //         delay(15);
      //      }
      //      Serial.print("data1.............");
      //   }

   } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(buzzerPin, LOW);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      delay(500);
      digitalWrite(7, LOW);
      Serial.print("out of loop......");

   }digitalWrite(buzzerPin, LOW);
}
