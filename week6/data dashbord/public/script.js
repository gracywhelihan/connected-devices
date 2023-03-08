/*
  mqtt.js client

  On document load, this script gets two divs from the HTML
  for local and remote messages. Then it attempts
  to connect to the broker. Once every two seconds, 
  it sends a message if it's connected. 
  The publish button allows you to turn on and off publishing status.

  created 29 Dec 2022
  modified 4 Jan 2023
  by Tom Igoe
*/

// All these brokers work with this code.
// Uncomment the one you want to use.


//////// shiftr.io, requires username and password
// (see options variable below):
const broker = "wss://public.cloud.shiftr.io";

//////// test.mosquitto.org, uses no username and password:
//const broker = 'wss://test.mosquitto.org:8081';

// MQTT client:
let client;

// connection options:
let options = {
  // Clean session
  clean: true,
  // connect timeout in ms:
  connectTimeout: 10000,
  // Authentication
  clientId: "mqttJsClient",
  // add these in for public.cloud.shiftr.io:
  username: "public",
  password: "public",
};
// topic to subscribe to when you connect:
let topic = "conndev/#";
// let topic = 'vgw3869/#';

// divs to show messages:
let localDiv,
  remoteDiv,
  tempCDiv,
  tempFDiv,
  humDiv,
  timeDiv,
  soundDiv,
  rDiv,
  gDiv,
  bDiv;
// whether the client should be publishing or not:
let publishing = true;

let sound = -1000;
let tempF = -1000;
let tempC = -1000;
let tempFVal = -1000;
let hum = -1000;


let r = -1000;
let g = -1000;
let b = -1000;

function setup() {
  // put the divs in variables for ease of use:
  localDiv = document.getElementById("local");
  remoteDiv = document.getElementById("remote");

  // incoming data divs
  tempCDiv = document.getElementById("tempC");
  tempFDiv = document.getElementById("tempF");
  humDiv = document.getElementById("hum");
  timeDiv = document.getElementById("time");
  soundDiv = document.getElementById("sound");
  rDiv = document.getElementById("r");
  gDiv = document.getElementById("g");
  bDiv = document.getElementById("b");

  // set text of localDiv:
  //localDiv.innerHTML = "trying to connect";
  // attempt to connect:
  client = mqtt.connect(broker, options);
  // set listeners:
  client.on("connect", onConnect);
  client.on("close", onDisconnect);
  client.on("message", onMessage);
  client.on("error", onError);
}

// handler for mqtt connect event:
function onConnect() {
  // update localDiv text:
  localDiv.innerHTML = "connected to broker. Subscribing...";
  // subscribe to the topic:
  client.subscribe(topic, onSubscribe);
}

// handler for mqtt disconnect event:
function onDisconnect() {
  // update localDiv text:
  localDiv.innerHTML = "disconnected from broker.";
}

// handler for mqtt error event:
function onError(error) {
  // update localDiv text:
  localDiv.innerHTML = error;
}

// handler for mqtt subscribe event:
function onSubscribe(response) {
  // update localDiv text:
  localDiv.innerHTML = "Subscribed to " + topic;
}

// handler for mqtt message received event:
function onMessage(topic, payload, packet) {
  //console.log(topic);
  let result = "received a message on topic:  " + topic;
  // message is  a Buffer, so convert to a string:

  result += "<br>message payload: " + payload.toString();
  //data = JSON.parse(payload.toString());
  //console.log(result);

  // update the remote div text:
  if (topic == "conndev/vgw3869") {
    let datag = JSON.parse(payload.toString());

    tempC = Math.round(datag["temp"]) + " °C";
    tempF = Math.round(datag["temp"] * (9 / 5) + 32) + " °F";
    tempFVal = datag["temp"] * (9 / 5) + 32;
    hum = Math.round(datag["hum"]) + " %";
    sound = datag["sound"];

  }
  if (topic == "conndev/makin-stuff") {
    let datap = JSON.parse(payload.toString());

    r = datap["red"];
    g = datap["green"];
    b = datap["blue"];

  }
  
  if(r == -1000 || g == -1000 || b == -1000 || tempC == -1000 || tempF == -1000 || hum == -1000 || sound == -1000){
    r = "no data";
    g = "no data";
    b = "no data";
    
    tempF = "no data";
    tempC = "no data";
    sound = "no data";
    hum = "no data"
  }

  tempCDiv.innerHTML = tempC;
  tempFDiv.innerHTML = tempF;
  humDiv.innerHTML = hum;
  soundDiv.innerHTML = sound;

  rDiv.innerHTML = r;
  gDiv.innerHTML = g;
  bDiv.innerHTML = b;
}

// on page load, call the setup function:
document.addEventListener("DOMContentLoaded", setup);
