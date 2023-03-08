QTT Client sender
  This sketch demonstrates an MQTT client that connects to a broker, subsrcibes to a topic,
  and both listens for messages on that topic and sends messages to it, a random number between 0 and 15.
  When the client receives a message, it parses it, and if the number matches the client's
  number (myNumber, chosen arbitrarily), it sets an LED to full. When nothing is happening,
  if the LED is not off, it's faded down one point every time through the loop.
  This sketch uses https://shiftr.io/try as the MQTT broker.
  the arduino_secrets.h file:
  #define SECRET_SSID ""    // network name
  #define SECRET_PASS ""    // network password
  #define SECRET_MQTT_USER "public" // broker username
  #define SECRET_MQTT_PASS "public" // broker password
  created 11 June 2020
  updated 11 April 2021
  by Tom Igoe
*/

#include <WiFiNINA.h>
#include <ArduinoMqttClient.h>
#include <Wire.h>

#include "Adafruit_SHT31.h"
#include "secrets.h"

//real time clock library
#include <RTCZero.h>  // include the library
RTCZero rtc;


Adafruit_SHT31 sht31 = Adafruit_SHT31();

// initialize SSL WiFi connection:
WiFiSSLClient wifi;
// initialize Wifi connection:
// WiFiClient wifi;
MqttClient mqttClient(wifi);

// details for MQTT client:
char broker[] = "public.cloud.shiftr.io";
//char broker[]= "localhost";
// SSL port
//int port = 8886; // for test.mosquitto.org
// port
int port = 8883;
char topic[] = "conndev/vgw3869";
String clientID = "gracy-temp-hum-sound";

// last time the client sent a message, in ms:
long lastTimeSent = 0;
// message sending interval:
int interval = 10*1000;

//initialize sound sensor pins
int soundPin = A0;  
int sensorValue = 0;

void setup() {
  // initialize serial:
  Serial.begin(9600);

 rtc.begin(); // initialize RTC
  
  // wait for serial monitor to open:
  if (!Serial) delay(3000);

  // initialize WiFi, if not connected:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Connecting to ");
    Serial.println(SECRET_SSID);
    WiFi.begin(SECRET_SSID, SECRET_PASS);
    delay(2000);
  }

  // print IP address once connected:
  Serial.print("Connected. My IP address: ");
  Serial.println(WiFi.localIP());


  // set the credentials for the MQTT client:
    mqttClient.setId(clientID);
  // login to the broker with a username and password:
  mqttClient.setUsernamePassword(SECRET_MQTT_USER, SECRET_MQTT_PASS);

  // try to connect to the MQTT broker once you're connected to WiFi:
  while (!connectToBroker()) {
    Serial.println("attempting to connect to broker");
    delay(1000);
  }
  Serial.println("connected to broker");

  // initialize the SHT31 sensor
   if (! sht31.begin(SHT31_DEFAULT_ADDR)) {
    Serial.println("Couldn't find SHT31");
    while (1) { delay(1); }       // wait forever
  }
}

void loop() {
  // time

//  int netTime = WiFi.getTime();
//  rtc.setEpoch(netTime);
  
  //int dd = rtc.getEpoch();
  //Serial.println(dd);

  
  // if not connected to the broker, try to connect:
  if (!mqttClient.connected()) {
    Serial.println("reconnecting");
    connectToBroker();
  }

// once every interval, send a message:
  if (millis() - lastTimeSent > interval) {
    // start a new message on the topic:
    mqttClient.beginMessage(topic);
    // add a random number as a numeric string (print(), not write()):
    float tt = sht31.readTemperature();
    float hh = sht31.readHumidity();

    float ss = analogRead(soundPin);


  String body = "{\"temp\": tt, \"hum\": hh, \"sound\": ss}";
  //String body = "{\"sound\": ss, \"time\": dd}";
   body.replace("tt", String(tt));
   body.replace("hh", String(hh));
   body.replace("ss", String(ss));
   //body.replace("dd", String(dd));

    mqttClient.println(body);
//    Serial.println(body);
    // send the message:
    mqttClient.endMessage();
    lastTimeSent = millis();
  }

}

boolean connectToBroker() {
  // if the MQTT client is not connected:
  if (!mqttClient.connect(broker, port)) {
    // print out the error message:
    Serial.print("MOTT connection failed. Error no: ");
    Serial.println(mqttClient.connectError());
    // return that you're not connected:
    return false;
  }
  // once you're connected, you
  // return that you're connected:
  return true;
}
