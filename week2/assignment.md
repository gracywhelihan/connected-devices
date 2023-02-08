#Assignment 2

This week I continued to work on my device data dashboard. I am building off the MQTT Node.js Client HTML example on glitch that I remixed. I spend a lot of time this week working on trying to understand the code that was already there. Last week I just plugged in my broker info and was all set, but this week I wanted to try to understand each line of code. Also, I am pretty rusty and clueless when it comes to HTML and CSS, so I wanted to review some of that as well. 


<img width="556" alt="Screen Shot 2023-02-07 at 8 50 27 PM" src="https://user-images.githubusercontent.com/76453899/217408116-e0709218-0209-4340-a592-35aa8a8f9191.png">

<br/><br/>

I feel pretty comfortable with all of the code in the script.js file, but server.js is still a little unclear. Also, I noticed that the script.js file kept disconnecting and reconnecting to the broker. I am sending data every second, so maybe the lag of the data is making it disconnect? It doesn't really matter becasue the numbers from the data are showing on the screen and updating, but I think for an actual interface it would not be nice to see the "disconnecting" "connected to broker" blinking. Also, it makes me wonder if there is a way to know if there is no data sending at all. It looks like there is a connection timeout of 10 secon, but is there a way that you can reconnect or would you have to go to the arduino and make sure it is working?

I was able to get the temperature as a number with units in both C and F and the humidity as % from the script.js file to the html file using getElementById() and .innerHTML. It seems like there is a lot to learn about how these files communicate and what functions I can use to have the script.js file communicate with the html file.

##Questions:
- Is the MQTT broker connnection supposed to be a "smooth" and constant connection? Or will it continuously connect and disconnect?
- Can you do anything from your interface to get your ardunio and sensor reconnected?
-
