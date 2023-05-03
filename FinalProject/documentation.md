## Wind API

# Idea

My roommate recently asked me if it would be possible to put a wind sensor on the roof of our apartment building so he could see how windy it is up there. We live on the second floor and the roof is on the 6th floor, so it would mostly be so he doesn't have to walk up all the stairs just to realize it's too windy to be up there. 

I think putting my own wind sensor on the roof would be a better solution for this, but since we are working with APIs I thought, getting the wind data from an API was a good place to start. 

After doing some research on weather APIs, I decided to use the [Tomorrow.io](https://docs.tomorrow.io/reference/welcome) API. The main reason I decided to go with this one over other APIs is because I was able to make realtime requests. Most of the other weather APIs would give forecasts, and for my project I want the measurements to be realtime and I do not need the forecast info. I originally wanted to use [Stormglasss.io](https://stormglass.io/) because the API response includes windSpeeds from muliple different sources such as, NOAA, ICON (Germany’s National Meteorological Service), SMHI (Swedish Meteorological and Hydrological Institute), and FMI (The Finnish Meteorological Institution). I thought this was cool and helpful because they all are slightly different. But Stormglass only allows for 10 requests per day, which is not a lot for testing - I ran out pretty quick. It also might not be enough once it is in use. 

One thing I did have a hard time finding out is how far the readings are from my house. I am able to put in my lat and long. But it looks like the response is using Brooklyn, which is fine, but I would like to do more exploring on how to find that info.

I was able to successfully connect to the API using Tom's [AQI Web Client Code](https://github.com/tigoe/MakingThingsTalk2/tree/main/3rd_edition/chapter4/AQIWebClient002) and adjusted it to parse out the info I needed from the tomorrow.io API. I then added in my stepper motor code and set the wind speed to the speed of the motor. I think this is the part that is going to be the hardest, because I think there will need to be a lot of adjusting and mapping the values to make the speed correlate with the actual wind speed. Also, I don't think I will be able to have the motor running all of the time, so I need to figure out what to do there. 


## Process

Of course, when I went to go test my motor again and try to dial in how I should map the readings so they are meaningful, the motor didn't work. I spent all day Sunday trying to get the motor to work. I was using an H-Brigde and a stepper motor and all of the wiring was the same as it was the last time I tried it, so I was very confused as to why the motor wasn't working. I tried a smaller stepper motor and that worked a little better, but I also realized that I had already built me enclosure for the Nema 17 stepper motor. 

I tried a bunch of different things to try to get the Nema 17 to work with the H-Bridge. And I got very frustrated. Then I realized that maybe I could just use a DC motor and control the speed. But, I would most likely have to rebuild my enclosure to fit the motor :( Thankfully, Priyanka witnessed my frustration and offered to let me try out her motor driver to see if it worked with my stepper motor... It worked perfectly!

After wasting a lot of time trying to get my stepper motor to work, I was finally able to put all of the pieces together -> the code, the circuit and motor, and the enclosure. 

![IMG_9DE2E2FFF47F-1](https://user-images.githubusercontent.com/76453899/235832052-f0ccf2a1-1cbd-470a-bea3-d691a17ef853.jpeg)

I was not able to test the speed of the spinner with my roommate because of the whole motor issue, but I did find this wind chart from the National Weather Service:



<img width="929" alt="Screen Shot 2023-05-02 at 9 32 32 PM" src="https://user-images.githubusercontent.com/76453899/235832297-b49608a2-0fcd-4209-8f35-689dd684152e.png">

So I decided to map the wind speed from 0 to 100 to 0 to 200 (so double it) just to start. But I will need to do more testing on this for sure. Also, would like to add indicator lights, like the connected LED and a request LED. The connected LED was already written into Tom's example code, but I forgot to add it into my circut. I wrote in the request LED code so that the LED will light up when the request interval has passed, so that you know when it is okay to send a request. I had already glued a most of my enclosure together before trying to add the LEDs. So I decided to just leave them out so I didn't have to rebuild everything. 

I am super excited that I was able to get all of it working, but sometimes it can get a little scary (as in I think it's all broken) because the http request takes such a long time.


https://vimeo.com/823234399?share=copy


Overall I am pretty happy with the wind device, but I think this really is a 1st itereation - I need to rebuild to add in the LEDs and make sure the speed makes sense. And maybe using a DC motor would make more sense becasue it has a smoother rotation ¯\_(ツ)_/¯ 



