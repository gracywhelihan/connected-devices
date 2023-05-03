/*
  Adapted from Web Client code written by Tom Igoe
  Context: Arduino, with WINC1500 module
  Rewritten for HTTPS
  4 April 2023
  arduino_secrets.h includes:
  #define SECRET_SSID ""      //  your network SSID (name)
  #define SECRET_PASSWORD "" // your network password
  #define SECRET_API_KEY ""   // your airNOW API key
*/
// include required libraries and config files

#include <WiFiNINA.h>  // use this for MKR WiFi 1010 and Nano 33 IoT
#include <ArduinoHttpClient.h>
#include "secrets.h"
#include <Stepper.h>

// define number of steps on motor (nema 17)
#define STEPS 200

// declare I/O pin numbers and global variables:
const int port = 443;                 // HTTPS standard port
const int networkLED = LED_BUILTIN;   // indicates network connection
const int connectedLED = 8; 
const int requestLED =  9;          // indicates connection to server
// initiate motor speed and pins
Stepper stepper(STEPS, 4, 5, 6, 7);
int motorSpeed = 0;
const int stepsPerRevolution = 1000;
const long requestInterval = 120000;

//const long requestInterval = 120000;  // delay between updates to the server
int buttonState = 0;
int lastButtonState = 0; 
int buttonPin = 2;


// use WiFiSSLClient for https:
WiFiSSLClient netSocket;                            // network socket to server
const char serverAddress[] = "api.tomorrow.io";   // server name
String route = "/v4/weather/realtime";  // API route
long lastRequestTime = 0;                           // last request time, in ms

void setup() {
  Serial.begin(9600);             // initialize serial communication
  pinMode(networkLED, OUTPUT);    // set network LED pin as output
  pinMode(connectedLED, OUTPUT);  // set connected LED pin
  pinMode(requestLED, OUTPUT); // set requested LED pin
  pinMode(buttonPin, INPUT); // set button pin

 //set motor speed to motor speed to start
 stepper.setSpeed(motorSpeed);

  // while you're not connected to a WiFi AP,
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(SECRET_SSID);               // print the network name (SSID)
    WiFi.begin(SECRET_SSID, SECRET_PASS);  // try to connect
    blink(networkLED, 5);                      // blink the network LED
  }

  // When you're connected, print out the device's network status:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  //append the parameters and API key to the route:
  route += "?location=40.70783,-73.9426";
  route += "&units=imperial";
  route += "&apikey=";
  route += SECRET_API_KEY;
  // first connection:
  //connectToServer();

  digitalWrite(requestLED, LOW);
}

void loop() {
  // make an HTTP request once every two minutes:
  if (millis() - lastRequestTime > requestInterval) {
    digitalWrite(requestLED, HIGH);
  }

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if(buttonState != lastButtonState){

    if(buttonState == HIGH ){
      connectToServer();
       // update the status LEDs:
      motorSpeed = 10;
      stepper.setSpeed(motorSpeed);
      stepper.step(stepsPerRevolution);
      Serial.println("windy!");

      digitalWrite(requestLED, LOW);
   }
  }
 // }
  // update the status LEDs:
  setLeds();
  lastButtonState = buttonState;
}

void connectToServer() {
  int wind = -1;  // AQI value

  // make HTTP call:
  HttpClient http(netSocket, serverAddress, port);  // make an HTTPS client
  Serial.print("Connecting to ");
  Serial.print(serverAddress);
  Serial.println(route);
  http.get(route);             // make a GET request
  http.skipResponseHeaders();  // ignore the HTTP headers
  // while connected to the server:
  while (http.connected()) {
    setLeds();                                       // update status LEDs
    if (http.available()) {    
      // Serial.println(http.readString());                      // if there's a response from the server,
      bool lookfor = http.findUntil("windSpeed", "\n");  // parse response for "windSpeed"
      if (lookfor) {                                 // if there's a windSpeed value,
        wind = http.parseFloat();                       // read windSpeed value from the response
        http.flush();                                // throw out the rest of the response
        if (wind > -1) {                              // If you got an wind value,
          Serial.print("windSpeed: ");                   // print it out, and
          // set motor speed to wind
          motorSpeed = map(wind, 0, 100, 0, 200);  
          Serial.println(wind);        
        }
      }
      http.stop();  // close the request
    }
  }
  lastRequestTime = millis();  // save the time of this HTTP call
}


void setLeds() {
  // if the network is connected, turn on network LED:
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(networkLED, HIGH);
  } else {
    digitalWrite(networkLED, LOW);
  }
  // if the TCP socket is connected, turn on connected LED:
  int connectedToServer = netSocket.connected();
  digitalWrite(connectedLED, connectedToServer);
}

void blink(int thisPin, int howManyTimes) {
  // Blink the LED:
  for (int blinks = 0; blinks < howManyTimes; blinks++) {
    digitalWrite(thisPin, HIGH);
    delay(200);
    digitalWrite(thisPin, LOW);
    delay(200);
  }
}
