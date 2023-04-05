# Phillips Hue Controller

My inspiration for the phillips hue controller came from the sound activated switch, [The Clapper](https://en.wikipedia.org/wiki/The_Clapper) from the 1980's.

<img width="130" alt="Screen Shot 2023-04-04 at 9 14 54 PM" src="https://user-images.githubusercontent.com/76453899/229956535-9290033b-4258-46fb-8675-162eca02c1b6.png">

I highly recommend watching the [commercial](https://www.youtube.com/watch?v=Ny8-G8EoWOw&ab_channel=JosephEnterprises)!

Anyways The Clapper turns the lights on and off with two claps in a row. I remember this being a really cool thing people would do in movies and tv too, so I thought I would try it out. I started out by testing with a button press to see if logic was working. I was able to register a double press of the button by adding a count when the button was pressed and taking the millis() when the count was 1 and 2 and then subtracting those times. If that range was lower than 250 then it would either turn the light on or off. I also added in logic so that when the button was pressed and the count was 1, if 2 seconds passed before the next clap it would set the count back to 0. This is to make it easier for peopl to try again with their claps. 

Next, I needed to translate the logic into the sound sensor. The sensor I am using is the [microphone sound sensor ky-038](https://makeradvisor.com/tools/microphone-sound-sensor-ky-038/) and has a few settings that you can change based on how you want to collect data. The first thing I did was set it to only listen if the sound was louder than a certain threshold. I did this by turning the resistor until one of the LED's turned off. Then I used the digital pin so that it reads HIGH or LOW. Then the logic was pretty much the same as the button. 

I didn't have a whole lot of time to test wether it would trigger when it is around continuous loud noise or from what range (like how far away you can be for the sensor to detect a clap) but these would be good things to test to make the switch more reliable.

I also wanted to implement a single clap to dim and brighten the lights when the light is on. If I have time I think I can do this it would also just require some logic in the code that at the time of me writing the blog post I do not have the brain power to do. But maybe I will have it figure it out before class. Oh, and I would have liked to make an encosure for it but I ran out of time. 


## Feedback

To account for a long loud sound not counting a as two claps, you can also look for a valley or an "off" time between the two claps.
