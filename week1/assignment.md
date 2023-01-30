# week 1 - assignment
## 

To get started on connecting environmental data from my Arduino to a webpage, I started small and worked my way up. 
<br/><br/>
1.First I set up my Arduino and temperature/humidity sensor and tested the hardware.
<br/><br/>
<img width="283" alt="Screen Shot 2023-01-30 at 9 21 33 AM" src="https://user-images.githubusercontent.com/76453899/215523373-40ba00b3-8150-4f45-82c9-e7e80d5cf206.png">
<br/><br/>
2. Then I used the WiFiNINA "Scan Networks" example sketch to scan the networks at my apartement to make sure the wifi antenna on my Ardunio was working.
<br/><br/>
<img width="518" alt="Screen Shot 2023-01-30 at 8 53 31 AM" src="https://user-images.githubusercontent.com/76453899/215524122-0d23a1e7-2075-41b8-8646-6e714ce5875d.png">
<br/><br/>
3. Now that I knew the wifi and the hardware were working, the next step was to send my sensor data to an MQTT Broker. I used the mqttClientSender code we used in Understanding Networks last semester to send the temperature and humidity data to a topic I created called gwBroker.
<br/><br/>
<img width="820" alt="Screen Shot 2023-01-30 at 10 37 13 AM" src="https://user-images.githubusercontent.com/76453899/215525199-b42947c4-01e5-4538-a3b6-6e470746c81a.png">

<br/><br/>
Those steps were easy as I have already sent sensor data to an MQTT topic in Understaning Networks and Device to Database (classes I took last fall and spring). So, connecting that data to an http client will be the difficult part. I know that I need to first have an http client for MQTT to connect to and would probably have to do that via sockets and using node.js. 
<br/><br/>
#Questions:
How do we set up our own MQTT Broker? Is it better to use a public broker like test.mosquitto.org or a private broker?

<br/><br/>

"Some people name their PC - many people curse or complain to their PC" - [The Coming Age of Calm Technology](https://calmtech.com/papers/coming-age-calm-technology.html)
