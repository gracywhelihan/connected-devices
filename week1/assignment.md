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

In class we looked at a simple http client that was hosted on [glitch](https://tigoe-mqtt-client.glitch.me/). I thought a good way to start would be to remix this glitch project and see if I could figure out how to get my data to connect. I noticed there was a server.js file and a script.js file. I changed the broker to test.mosquitto.org and the topic to my topic - gwBroker/# in both of the js files. After a little bit of a wait, I was able to get it connected!
<img width="1447" alt="Screen Shot 2023-01-30 at 11 21 49 AM" src="https://user-images.githubusercontent.com/76453899/215543958-a63486ee-8b94-4603-a738-d434123dc13e.png">
<br/><br/>
I know that in class Tom talked about us not copying the code, so although I was able to get it working there is still a lot I need to learn before I understand exactly how the server.js and script.js are working. But for now I think this is a good start. 
<br/><br/>
## Questions:
1. How do we set up our own MQTT Broker? Is it better to use a public broker like test.mosquitto.org or a private broker?
2. Can I add a p5.js sketch to the website and use the sensor data there?
3. Why do both the server.js and script.js files have to connect to the MQTT broker? The script.js file is for the front end and the server.js file is for the backend? But can they communicate with each other to get the data so there is only one connection to the broker?


<br/><br/>

"Some people name their PC - many people curse or complain to their PC" - [The Coming Age of Calm Technology](https://calmtech.com/papers/coming-age-calm-technology.html)
