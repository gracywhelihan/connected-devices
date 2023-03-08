# Data Dashboard and Connected Device

Priyanka and I created two houses called "casa amor" to house our sensors. Priyanka helped me a LOT with the fabrication - she is very very good at soldering! Much better than I am. We both created houses out of acrylic. There are no walls, only the front of the house becasue I am using a temperature and humidity sensor, so there needs to be open air flow. My house also has a chimney that allows for the microphone to be in the open as well. 

<img width="581" alt="Screen Shot 2023-03-07 at 10 04 39 PM" src="https://user-images.githubusercontent.com/76453899/223609314-b78341f8-3514-495d-b671-70d950f9497c.png">

Both of our data is sending to [this](https://priyanka-gracy-casa-amor.glitch.me/) dashboard. Unfortunately at this moment it is only hosted on Glitch, so we are not loggin the data into a json file.

The light color values control the color of Pryianka's house, and the temperature controls the color of my house. These aren't values that you will be able to visually see change right before you becasue the changes are quite small, but if you check the dashboard at different times you might notice a difference. To be honest there is not really any clear point as to why I would want to collect this data. I know that I am using all of these sensors for my thesis so I think I am using it as practice for that. But Priyanka and I did have fun working togther and it is cool to see out data coming in and our enclosures next to each other. I think design wise all three are quite cohesive. Also, as we were creating our enclosures I thought a lot about more fun designs - I think a lot of connected devices are minimalist in design, but I wonder if some users would enjoy a little more flare?

I also will say that my css and html code are pretty messy. I think that is actually something I really need to work on. HTML + CSS and honestly just tidying up all of code once I am able to get everything working. 

## Questions:

- Why did we not set up a broker for this class? Like a private conndev broker?
- When I added the time to my arduino code and tried to send it to shiftr.io I was getting -2 error but when I removed the time it worked fine. Why would the time stop shiftr.io from allowing my data?
