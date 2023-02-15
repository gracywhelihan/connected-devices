# Assignment 3

This week I focused on getting multiple sensors sending data through Mqtt and showing data on my data dashboard. This part was mostly for my Thesis, as I am planning to have multiple sensors sending data. I chose to use the IMU in the arduino, [temperature/humidity sensor](https://www.amazon.com/Onyehn-Temperature-Humidity-Barometric-Pressure/dp/B07KR24P6P), and [proximity and light sensor](https://www.adafruit.com/product/466). I am now realizing I used [Tom's code](https://github.com/tigoe/LightProjects/tree/main/LightSensorProjects/) for a the [TCS34725 Color Sensor](https://ams.com/tcs34725) for the light sensor, but it's fine because I was just trying to get all of the sensors connected. I plan to sure a sound level sensor, but I had some issues with the package getting delivered. Also, I played around with an [ultasonic distance sensor](https://www.sparkfun.com/products/17777?gclid=EAIaIQobChMIrcKKvMyW_QIVmc3ICh0dgwApEAQYAiABEgLzefD_BwE) but I don't think I am going to use it so I didn't include it in the dashboard. 
<br></br>
Here is my [data dashboard](https://jasper-frost-hisser.glitch.me/index.html)

<img width="1278" alt="Screen Shot 2023-02-14 at 10 17 56 PM" src="https://user-images.githubusercontent.com/76453899/218923530-2ec9cdf0-36e3-4a8e-8fe8-ce2cebb75ee4.png">
<br></br>
There is still a lot I need to do visually and style wise, but it is resposive so I am excited about that!
I think the html and css just takes some gettin used to. I also am not loggin any data into a file at the moment. This will be something I need to get set up and then be able to fetch the data to make some better time laspes visualizations. I will also need to add time stamps to my Arduino code to get this part up and running. I think it might be nice to include a page for each sensor and then include more of the visuals there. 
I noticed that the Arudino that was connected to the temperature sensor will disconnect from the network after like 20 minutes. I am not really sure why it is doing this?
