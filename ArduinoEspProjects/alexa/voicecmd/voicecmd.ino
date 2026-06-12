/*

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>
// define the GPIO connected with Relays and switches
#define RelayPin1 D2  //D1
#define RelayPin2 D3  //D2
#define RelayPin3 D4 //D5
#define RelayPin4 D5 //D6

#define SwitchPin1 10  //SD3
#define SwitchPin2 0   //D3 
#define SwitchPin3 13  //D7
#define SwitchPin4 3   //RX

#define wifiLed   16   //D0

int toggleState_1 = 0; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 0; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 0; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 0; //Define integer to remember the toggle state for relay 4

// prototypes
boolean connectWifi();
//callback functions
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);
void fourthLightChanged(uint8_t brightness);

// WiFi Credentials
const char* ssid = "SSID";
const char* password = "PSWD@123";

// device names
String Device_1_Name = "Study Lamp";
String Device_2_Name = "CFL";
String Device_3_Name = "Yellow light";
String Device_4_Name = "Red light";

boolean wifiConnected = false;

Espalexa espalexa;

//our callback functions
void firstLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin1, LOW);
      Serial.println("Device1 ON");
      toggleState_1 = 1;
    }
  else
  {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("Device1 OFF");
    toggleState_1 = 0;
  }
}

void secondLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin2, LOW);
      Serial.println("Device2 ON");
      toggleState_2 = 1;
    }
  else
  {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Device2 OFF");
    toggleState_2 = 0;
  }
}

void thirdLightChanged(uint8_t brightness)
{
  //Control the device  
  if (brightness == 255)
    {
      digitalWrite(RelayPin3, LOW);
      Serial.println("Device3 ON");
      toggleState_3 = 1;
    }
  else
  {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("Device3 OFF");
    toggleState_3 = 0;
  }
}

void fourthLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin4, LOW);
      Serial.println("Device4 ON");
      toggleState_4 = 1;
    }
  else
  {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("Device4 OFF");
    toggleState_4 = 0;
  }
}

void relayOnOff(int relay){

    switch(relay){
      case 1: 
             if(toggleState_1 == 0){
              digitalWrite(RelayPin1, LOW); // turn on relay 1
              toggleState_1 = 1;
              Serial.println("Device1 ON");
              }
             else{
              digitalWrite(RelayPin1, HIGH); // turn off relay 1
              toggleState_1 = 0;
              Serial.println("Device1 OFF");
              }
             delay(100);
      break;
      case 2: 
             if(toggleState_2 == 0){
              digitalWrite(RelayPin2, LOW); // turn on relay 2
              toggleState_2 = 1;
              Serial.println("Device2 ON");
              }
             else{
              digitalWrite(RelayPin2, HIGH); // turn off relay 2
              toggleState_2 = 0;
              Serial.println("Device2 OFF");
              }
             delay(100);
      break;
      case 3: 
             if(toggleState_3 == 0){
              digitalWrite(RelayPin3, LOW); // turn on relay 3
              toggleState_3 = 1;
              Serial.println("Device3 ON");
              }else{
              digitalWrite(RelayPin3, HIGH); // turn off relay 3
              toggleState_3 = 0;
              Serial.println("Device3 OFF");
              }
             delay(100);
      break;
      case 4: 
             if(toggleState_4 == 0){
              digitalWrite(RelayPin4, LOW); // turn on relay 4
              toggleState_4 = 1;
              Serial.println("Device4 ON");
              }
             else{
              digitalWrite(RelayPin4, HIGH); // turn off relay 4
              toggleState_4 = 0;
              Serial.println("Device4 OFF");
              }
             delay(100);
      break;
      default : break;      
      }
}
// connect to wifi – returns true if successful or false if not
boolean connectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  return state;
}

void addDevices(){
  // Define your devices here.
  espalexa.addDevice(Device_1_Name, firstLightChanged); //simplest definition, default state off
  espalexa.addDevice(Device_2_Name, secondLightChanged);
  espalexa.addDevice(Device_3_Name, thirdLightChanged);
  espalexa.addDevice(Device_4_Name, fourthLightChanged);
  espalexa.begin();
}
void setup()
{
  Serial.begin(115200);

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(wifiLed, OUTPUT);

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);

  // Initialise wifi connection
  wifiConnected = connectWifi();

  if (wifiConnected)
  {
    addDevices();
  }
  else
  {
    Serial.println("Cannot connect to WiFi. So in Manual Mode");
    delay(1000);
  }
}

void loop()
{
   if (WiFi.status() != WL_CONNECTED)
  {
    //Serial.print("WiFi Not Connected ");
    //Serial.println(wifiConnected);
    digitalWrite(wifiLed, HIGH); //Turn off WiFi LED
    //Manual Switch Control
    if (digitalRead(SwitchPin1) == LOW){
      delay(200);
      relayOnOff(1);      
    }
    else if (digitalRead(SwitchPin2) == LOW){
      delay(200);
      relayOnOff(2);
    }
    else if (digitalRead(SwitchPin3) == LOW){
      delay(200);
      relayOnOff(3);
    }
    else if (digitalRead(SwitchPin4) == LOW){
      delay(200);
      relayOnOff(4);
    }
    
  }
  else
  {
    //Serial.print("WiFi Connected  ");
    //Serial.println(wifiConnected);
    digitalWrite(wifiLed, LOW);
    //Manual Switch Control
    if (digitalRead(SwitchPin1) == LOW){
      delay(200);
      relayOnOff(1);      
    }
    else if (digitalRead(SwitchPin2) == LOW){
      delay(200);
      relayOnOff(2);
    }
    else if (digitalRead(SwitchPin3) == LOW){
      delay(200);
      relayOnOff(3);
    }
    else if (digitalRead(SwitchPin4) == LOW){
      delay(200);
      relayOnOff(4);
    }
    //WiFi Control
    if (wifiConnected){
      espalexa.loop();
      delay(1);
    }
    else {
      wifiConnected = connectWifi(); // Initialise wifi connection
      if(wifiConnected){
      addDevices();
      }
    }
  }
}
*/



#include <Arduino.h>
#include <ESP8266wifi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h>
#include <ArduinoJson.h>
#include <StreamString.h>
#include <AceButton.h>

using namespace ace_button;
ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;
WiFiClient client;

#define MyApiKey "rgdgdgdfg-1a90-4951-a3c2-dgdfgdfgdfg" //  API Key
#define MySSID "SSID" // Wifi network SSID
#define MyWifiPassword "PSWD@123" //  Wifi network password

#define HEARTBEAT_INTERVAL 300000 // 5 Minutes 

uint64_t heartbeatTimestamp = 0;
bool isConnected = false;

String device_ID_1 = "xxxxxx";
String device_ID_2 = "vvvvv";
String device_ID_3 = "vvvvvv";
String device_ID_4 = "eeeeeee";

// define the GPIO connected with Relays and switches

// Relays
#define RelayPin1 D2  //D1
#define RelayPin2 D3  //D2
#define RelayPin3 D4  //D5
#define RelayPin4 D4  //D6

// Switches
#define SwitchPin1 10  //SD316,2
#define SwitchPin2 D3   //D3 
#define SwitchPin3 D7  //D7
#define SwitchPin4 3   //RX

//WiFi Status LED
#define wifiLed    D0   //D0


ButtonConfig config1;
AceButton button1(&config1);
ButtonConfig config2;
AceButton button2(&config2);
ButtonConfig config3;
AceButton button3(&config3);
ButtonConfig config4;
AceButton button4(&config4);

void handleEvent1(AceButton*, uint8_t, uint8_t);
void handleEvent2(AceButton*, uint8_t, uint8_t);
void handleEvent3(AceButton*, uint8_t, uint8_t);
void handleEvent4(AceButton*, uint8_t, uint8_t);

void setPowerStateOnServer(String deviceId, String value);

// deviceId is the ID assgined to your smart-home-device in sinric.com dashboard. Copy it from dashboard and paste it here

void turnOn(String deviceId) {
  if (deviceId == device_ID_1) // Device ID of 1st device
  {
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin1, LOW);
  }
  if (deviceId == device_ID_2) // Device ID of 2nd device
  {
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin2, LOW);
  }
  if (deviceId == device_ID_3) // Device ID of 3rd device
  {
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin3, LOW);
  }
  if (deviceId == device_ID_4) // Device ID of 4th device
  {
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin4, LOW);
  }
}

void turnOff(String deviceId) {
  if (deviceId == device_ID_1) // Device ID of 1st device
  {
    Serial.print("Turn off Device ID: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin1, HIGH);
  }
  if (deviceId == device_ID_2) // Device ID of 2nd device
  {
    Serial.print("Turn off Device ID: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin2, HIGH);
  }
  if (deviceId == device_ID_3) // Device ID of 3rd device
  {
    Serial.print("Turn off Device ID: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin3, HIGH);
  }
  if (deviceId == device_ID_4) // Device ID of 4th device
  {
    Serial.print("Turn off Device ID: ");
    Serial.println(deviceId);
    digitalWrite(RelayPin4, HIGH);
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      isConnected = false;
      WiFiMulti.addAP(MySSID, MyWifiPassword);
      Serial.printf("[WSc] Webservice disconnected from sinric.com!\n");
      break;
    case WStype_CONNECTED: {
        isConnected = true;
        Serial.printf("[WSc] Service connected to My TrialDoc: %s\n", payload);
        Serial.printf("Waiting for commands from TrialDoc\n");
      }
      break;
      case WStype_TEXT: {
        Serial.printf("[WSc] get text: %s\n", payload);

        #if ARDUINOJSON_VERSION_MAJOR == 5
                DynamicJsonBuffer jsonBuffer;
                JsonObject& json = jsonBuffer.parseObject((char*)payload);
        #endif
        #if ARDUINOJSON_VERSION_MAJOR == 6
                DynamicJsonDocument json(1024);
                deserializeJson(json, (char*) payload);
        #endif
        String deviceId = json ["deviceId"];
        String action = json ["action"];

        if (action == "setPowerState") { // Switch or Light
          String value = json ["value"];
          if (value == "ON") {
            turnOn(deviceId);
          } else {
            turnOff(deviceId);
          }
        }
        else if (action == "test") {
          Serial.println("[WSc] received test command from sinric.com");
        }
      }
      break;
    case WStype_BIN:
      Serial.printf("[WSc] get binary length: %u\n", length);
      break;
  }
}

void setup() {
  Serial.begin(9600);

  WiFiMulti.addAP(MySSID, MyWifiPassword);
  Serial.println();
  Serial.print("Connecting to Wifi: ");
  Serial.println(MySSID);

  // Waiting for Wifi connect
  if (WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting...");
  }
  if (WiFiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.print("WiFi connected. ");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);

  pinMode(wifiLed, OUTPUT);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
  
  //During Starting WiFi LED should TURN OFF
  digitalWrite(wifiLed, HIGH);

  config1.setEventHandler(button1Handler);
  config2.setEventHandler(button2Handler);
  config3.setEventHandler(button3Handler);
  config4.setEventHandler(button4Handler);
  
  button1.init(SwitchPin1);
  button2.init(SwitchPin2);
  button3.init(SwitchPin3);
  button4.init(SwitchPin4);

  // server address, port and URL
  webSocket.begin("iot.sinric.com", 80, "/");

  // event handler
  webSocket.onEvent(webSocketEvent);
  webSocket.setAuthorization("apikey", MyApiKey);

  // try again every 5000ms if connection has failed
  webSocket.setReconnectInterval(5000);   // If you see 'class WebSocketsClient' has no member named 'setReconnectInterval' error update arduinoWebSockets
}

void loop() {

  if (WiFiMulti.run() != WL_CONNECTED)
  {  
    //  Serial.println("Not Connected");
    digitalWrite(wifiLed, HIGH);
  }
  else
  {
    //Serial.println(" Connected");
    digitalWrite(wifiLed, LOW);
    webSocket.loop();
  }

  button1.check();
  button2.check();
  button3.check();
  button4.check();

  if (isConnected) {
    uint64_t now = millis();

    // Send heartbeat in order to avoid disconnections during ISP resetting IPs over night. Thanks @MacSass
    if ((now - heartbeatTimestamp) > HEARTBEAT_INTERVAL) {
      heartbeatTimestamp = now;
      webSocket.sendTXT("H");
    }
  }
}

void setPowerStateOnServer(String deviceId, String value) {
  #if ARDUINOJSON_VERSION_MAJOR == 5
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
  #endif
  #if ARDUINOJSON_VERSION_MAJOR == 6
    DynamicJsonDocument root(1024);
  #endif
  
    root["deviceId"] = deviceId;
    root["action"] = "setPowerState";
    root["value"] = value;
    StreamString databuf;
  #if ARDUINOJSON_VERSION_MAJOR == 5
    root.printTo(databuf);
  #endif
  #if ARDUINOJSON_VERSION_MAJOR == 6
    serializeJson(root, databuf);
  #endif
  webSocket.sendTXT(databuf);
}

void button1Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT1");
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      setPowerStateOnServer(device_ID_1, "ON");
      digitalWrite(RelayPin1, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      setPowerStateOnServer(device_ID_1, "OFF");
      digitalWrite(RelayPin1, HIGH);
      break;
  }
}

void button2Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT2");
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      setPowerStateOnServer(device_ID_2, "ON");
      digitalWrite(RelayPin2, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      setPowerStateOnServer(device_ID_2, "OFF");
      digitalWrite(RelayPin2, HIGH);
      break;
  }
}

void button3Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT3");
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      setPowerStateOnServer(device_ID_3, "ON");
      digitalWrite(RelayPin3, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      setPowerStateOnServer(device_ID_3, "OFF");
      digitalWrite(RelayPin3, HIGH);
      break;
  }
}

void button4Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT4");
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      setPowerStateOnServer(device_ID_4, "ON");
      digitalWrite(RelayPin4, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      setPowerStateOnServer(device_ID_4, "OFF");
      digitalWrite(RelayPin4, HIGH);
      break;
  }
}
