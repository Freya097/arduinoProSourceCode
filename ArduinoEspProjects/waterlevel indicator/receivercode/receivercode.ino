/*  
 *   
 *   --LCD--
 *  RS: pin D12
 *  E: pin D11
 *  D4: pin D2
 *  D5: pin D3
 *  D6: pin D4
 *  D7: pin D5
 *  Vo: A4
 *  D13: gnd
 *  
 *  --HC 12--
++++++++++++++++++++++++++++++++++++++++++++++
 *  
 *  --Button--
 *  B1: pin 9
 *  B2: pin 10
 *  
 *  --LED pins--
 *  G_led: pin A1
 *  R_led: pin A0
 *  Y_led:pin A2
 *  
 *  BonifonFreya./Jiju123
 *  
 *  buzzer:A3
*/

// defining libraries
#include <LiquidCrystal.h>   //for LCD 
#include <SoftwareSerial.h>  //for HC-12 wireless module

//SoftwareSerial HC12(7, 8);

const byte rxPin = 0;
const byte txPin = 1;
SoftwareSerial mySerial (rxPin, txPin);

LiquidCrystal lcd{12, 11, 2, 3, 4, 5};

int backlight_time = 30000;   //The time LCD backlight is turned on in miliseconds
int buzzer_freq = 1000;    //Frequenzy of the buzzer


int refill_time = 17000;    //delay time for the "refilling.." massege
int re_disp_time = 35000;   //"refilling.." massege display time


int refill_Maxtime = 0;
int button1 = 9;
boolean backlight_state = 0;
boolean button2_stat = 0;
boolean button_check = 0;
int button2_state[3] ={ 0, 0, 0};   // to check the button2 is pressed when level is low
int value1 =0;                     
int check1 = 0;
int value2 = 0;
boolean refill_check[3] = {0, 0, 0};  // to check the button2 is pressed when level is high
int data = 50;
int previous_data = 0;
int button2 = 10;
int red_led = A0;
int yellow_led = A2;
int green_led = A1;
int buzzer = A3;
int ground = 13;
int contrast = A4;
int backlight = A5;

// variablals for mult-tasking
long p3Mili = 0;    
long p1Mili = 0;
long p2Mili = 0;
long p4Mili = 0;
long p5Mili = 0;

//custom charachtors for the presantage bar
byte p10[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte p20[8] = {B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000};
byte p40[8] = {B11000, B11000, B11000, B11000, B11000, B11000, B11000, B11000};
byte p60[8] = {B11100, B11100, B11100, B11100, B11100, B11100, B11100, B11100};
byte p80[8] = {B11110, B11110, B11110, B11110, B11110, B11110, B11110, B11110};
byte p100[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};

void setup() {
 //Serial.begin(9600);
  lcd.begin(16,2);
  //HC12.begin(9600);
   Serial.begin(9600);
 

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(contrast, OUTPUT);
  pinMode(ground, OUTPUT);
  pinMode(backlight, OUTPUT);

  lcd.createChar(0,p10);
  lcd.createChar(1,p20);
  lcd.createChar(2,p40);
  lcd.createChar(3,p60);
  lcd.createChar(4,p80);
  lcd.createChar(5,p100);

  
  analogWrite(contrast,10);
  digitalWrite(ground, 0);

  // Boot-up message
  lcd.setCursor(0,0);
  lcd.print("    WELCOME     ");
  lcd.setCursor(0,1);
  lcd.print("    -Bonifon-");
  
}

void loop() {
  unsigned long currentMillis = millis();       // Getinng the current timer for multitasking
  boolean button1_state = digitalRead(button1); //button for backlight
  backlight_on(button1_state);
  while(Serial.available ()){
    lcd.clear();

    data = Serial.read();
    if ((data<104) or (data>=0)){
      previous_data = data;
    }
    if ((data>103) or (data<0)){
      data = previous_data;
    }
    display_bar(data);
    miniNote(data);
    display_present(data);
  }
    button2_stat = button2_check(data);     //Button for muting
    level_1(data);                           //led control and alarm
    
   refill(data);                            
    value1 = data;
    if(value2 < value1){
      refill_check[0] = 1;
    }
    if((value2 != value1)&(value2 != (value1 + 1))) {
      refill_Maxtime = 0;
    }
    value2 = value1;

    if( (data > 90) & (data <110)){         //for muting the refilling alarm
        if (button_check == 0){
             button_check = digitalRead(button2);
        }
    }else button_check = 0;

}

int refill(int data){
  unsigned long currentMillis = millis();
  if(refill_check[0] == 1){     //Starting the timer for check a seconadry value.
     if(refill_check[1] == 0){
       check1 = data;
       p4Mili = currentMillis ;
       refill_check[1] = 1;     //starts the second condition
    }
    }

    if(refill_check[1] == 1){
     if(currentMillis - p4Mili > refill_time){      
       if(check1 < data){
        refill_check[2] = 1;    //start to display refilling message
        refill_check[0] = 0;
        refill_check[1] = 0;
        p4Mili = currentMillis ;
        }else {
          refill_check[0] = 0;
          refill_check[1] = 0;
          
        }
        }}

        
        if (refill_check[2] == 1){
          if((currentMillis - p5Mili < re_disp_time)&((data>=0) & (data<100))&(refill_Maxtime<12000)){  
              refill_Maxtime++;
              lcd.setCursor(0,1);
              lcd.print("Refilling..."); 
                  boolean button1_state = 1;      //turn the backlight 
                  backlight_on(button1_state);
                  button1_state = 0; 
          }else{
            refill_Maxtime = 0;
            refill_check[2] = 0;}

       }else p5Mili = currentMillis ;


        
    if( (data > 90) & (data <100)){ 
       if (button_check == 0){ //check for button press
       if (refill_check[2] == 1){ //check whether refilling is started
              if(currentMillis - p3Mili < 300){ //buzzer delay time
                 tone(buzzer, buzzer_freq);}
  
              else if (currentMillis - p3Mili > (map(data, 90, 100, 700, 300))){    //for lowering effect
               p3Mili = currentMillis;
    }
              else  noTone(buzzer);
     
       }
    }else  noTone(buzzer);
    } else  noTone(buzzer); 
    
    return refill_check;
  }

int button2_check(int data){
  //first alarm starts when the level is below 16%
  if ((data < 16) || (data > 200)){   //for low level alarm
    if (button2_stat == 0){
       button2_stat = digitalRead(button2);
    if (button2_state[0] == 0){   //turn the backlight whenever button is pressed.
     button2_state[0] = 1;        //only run once when limit is below 15
     boolean button1_state = 1;
     backlight_on(button1_state);
     button1_state = 0;
    }
       
  }
 //Second alarm starts when the level is below 10%
   else if((button2_state[1] == 0) & (data < 10)){
     button2_state[1] = 1;      //run once when limit is below 10 
     boolean button1_state = 1; //turn the backlight
     backlight_on(button1_state);
     button1_state = 0;
      button2_stat = 0;
    }
//Third alarm starts when the level is below 5%
   else if((button2_state[2] == 0) & (data < 5)){
     button2_state[2] = 1;    //run once when limit is below 5
     boolean button1_state = 1; //turn the backlight
     backlight_on(button1_state);
     button1_state = 0;
      button2_stat = 0;
    } } 
    
  else {
    button2_state[0] = 0;
    button2_state[2] = 0;
    button2_state[1] = 0;
    button2_stat = 0;
    }
 return button2_stat;
  }

//This function displays a messages
void miniNote(int data){
  
   if ((data < 8) || (data > 200)){
      lcd.setCursor(0,1);
      lcd.print("Almost Empty    "); //Keep 16 charachtors between ""
   }
   else if( (data > 7) & (data < 15)){
      lcd.setCursor(0,1);
      lcd.print("Refill          ");    
   }
   else if ((data >14) & (data < 95)){
      lcd.setCursor(0,1);
      lcd.print("Normal          ");
   }
   else if ((data>94) & (data<101)){
      lcd.setCursor(0,1);
      lcd.print("Tank Full       ");
   }
    else if ((data>100) & (data<110)){
      lcd.setCursor(0,1);
      lcd.print("Overfolwing     ");
   }
}

//For the LEDs
int level_1(int data){
  unsigned long currentMillis = millis();
  //turn red led and buzzer when level is below 15
  if ((data < 16) || (data > 200)){
    digitalWrite(red_led, 1);   
    digitalWrite(green_led, 0);
    digitalWrite(yellow_led, 0);
  
  //for the buzzer
    if (button2_stat == 0){
     if(currentMillis - p3Mili < 300){
      tone(buzzer, buzzer_freq);}
  
    else if (currentMillis - p3Mili > 600){
      p3Mili = currentMillis;
    }
     else {
      noTone(buzzer);
     }
      }
    else noTone(buzzer);     
  }
 //turn yellow led when level is between 15 and 30
  else if ((data > 15) & (data < 31)){
    digitalWrite(yellow_led, 1);//turn yellow led
    digitalWrite(green_led, 0);
    digitalWrite(red_led, 0);
    noTone(buzzer);
  }

 //turn green led  when level is between 30 and 100
  else if ((data > 30) & (data < 110)){
    digitalWrite(green_led, 1);//turn green led
    digitalWrite(yellow_led, 0);
    digitalWrite(red_led, 0);
    
  }
  else {
    digitalWrite(red_led, 0);
    digitalWrite(yellow_led, 0);
    digitalWrite(green_led, 0);
    noTone(buzzer);
  }
  if ((data > 16)&(data<90)){
    noTone(buzzer);   
  }
}

//turns the backlight on
int backlight_on(int button1_state){    //for lcd backlight
  unsigned long currentMillis = millis();
  if (button1_state == 1){
    p2Mili = currentMillis;}
  if(currentMillis - p2Mili < backlight_time){
        digitalWrite(backlight, 1);
      }
  else digitalWrite(backlight, 0);
  }
  
// displays the presantage
void display_present(int data) {
  //Serial.print('\n');
  //Serial.print(data);
  //Serial.print('\n');
  if(data<10){
    lcd.setCursor(14, 1);}  //for one digit values
  if((data<100) & (data>9)){
    lcd.setCursor(13, 1);   //for two digit values
  }
  if((data<1000) & (data>99)){
    lcd.setCursor(12, 1); //for three digit values
  }
    lcd.print(data);
    lcd.print("%");
  
}

//displays the water level as a bar
void display_bar(int data){
  if((data >= 0) & (data < 110)){
    int dplay = map(data, 0, 100, 0, 80);   
    if( dplay > 80){
      dplay = 80;
    }
    int qution = dplay / 5;     //for full blocks
    int reminder = dplay % 5;   //for partial blocks
    
    for(int x=0;x<qution;x++){
    lcd.setCursor(x, 0);
    lcd.write(5);
    }
    lcd.setCursor(qution, 0);
    lcd.write(int(reminder));


  }
}
