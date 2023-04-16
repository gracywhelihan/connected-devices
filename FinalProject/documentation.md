## Wind API

# Idea

My roommate recently asked me if it would be possible to put a wind sensor on the roof of our apartment building so he could see how windy it is up there. We live on the second floor and the roof is on the 6th floor, so it would mostly be so he doesn't have to walk up all the stairs just to realize it's too windy to be up there. 

I think putting my own wind sensor on the roof would be a better solution for this, but since we are working with APIs I thought, getting the wind data from an API was a good place to start. 

After doing some research on weather APIs, I decided to use the [Tomorrow.io](https://docs.tomorrow.io/reference/welcome) API. The main reason I decided to go with this one over other APIs is because I was able to make realtime requests. Most of the other weather APIs would give forecasts, and for my project I want the measurements to be realtime and I do not need the forecast info. I originally wanted to use [Stormglasss.io](https://stormglass.io/) because the API response includes windSpeeds from muliple different sources such as, NOAA, ICON (Germany’s National Meteorological Service), SMHI (Swedish Meteorological and Hydrological Institute), and FMI (The Finnish Meteorological Institution). I thought this was cool and helpful because they all are slightly different. But Stormglass only allows for 10 requests per day, which is not a lot for testing - I ran out pretty quick. It also might not be enough once it is in use. 

One thing I did have a hard time finding out is how far the readings are from my house. I am able to put in my lat and long. But it looks like the response is using Brooklyn, which is fine, but I would like to do more exploring on how to find that info.

I was able to successfully connect to the API using Tom's [AQI Web Client Code](https://github.com/tigoe/MakingThingsTalk2/tree/main/3rd_edition/chapter4/AQIWebClient002) and adjusted it to parse out the info I needed from the tomorrow.io API. I then added in my stepper motor code and set the wind speed to the speed of the motor. I think this is the part that is going to be the hardest, because I think there will need to be a lot of adjusting and mapping the values to make the speed correlate with the actual wind speed. Also, I don't think I will be able to have the motor running all of the time, so I need to figure out what to do there. 
