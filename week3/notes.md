# Notes

reading data from a json:
- line read, split(), take the last reading
- to make sure the time stamp is included
  - you can have the server time stamp it or have the arduino time stamp it
  - time stamp locally is more accurate representation
  - wifi.get time
  - utc --> standard for keeping time on linux systems 
  - .getutcdate() --> [utc converter](https://www.utctime.net/utc-time-zone-converter)
- What is real time? and how "real time" does it need to be?

python3 -n http

<br></br>

Why would you want a sensor to be networked? 

<br></br>
## Readings
Many of the network devices are not designed as much for the comfort but for the data that can be collected by the company.
Power grids are an interesting networks.
Power companies could have control of where your device to contorl how you use you power?
Not so much about individual devices, but it is about the energy usage for the entire house.
There are no clear boundries of what companies are allowed to audit when it comes to your energy usage?
Would you want to be able to see which of your devices in your home are using the most enengy? or would you rather have an aggregate usage report?
- could this be done locally? and then the total amount be sent to the power company?
<br></br>
## MQTT
Use public brokers to test then create your own broker
- create your own broker if you need to send a lot of data
- shiftr.io desktop is a local broker
Broker vs Server
- broker is listening and publishing/subscribing
- server store information

What makes a connection fail?
- wrong credentials
- 
<br></br>
Last will and testament - when your arduino "dies"


## script.js
humDiv.innerHTML += hum; --> will give a stream of the data
[MqttClientSubTopics](https://github.com/tigoe/mqtt-examples/blob/main/arduino-clients/MqttClientSubTopics/MqttClientSubTopics.ino)
<br></br>
p5.js 
