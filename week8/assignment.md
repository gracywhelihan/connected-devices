## Data Dashboard Update

I was no super suprised when I saw my data from spring break. I knew that my arduino was disconnecting from the broker after about a day when I was testing it, but I didn;t want to bring it home with me to Colorado. So when I saw it was off the whole time I was there I was not surprised. I would like to try to add a reset mechanism like we talked about in class. So, I will defintely look into that. From the data that was collected I did see kind of an interesting patter that I assume is from my heater turning on and off (blue = sound, yellow = temp, red = humidity):

<img width="481" alt="Screen Shot 2023-03-22 at 2 09 13 PM" src="https://user-images.githubusercontent.com/76453899/227243729-26a1240c-030c-435e-8423-645d1f8427b9.png">

Here is a close up:

<img width="478" alt="Screen Shot 2023-03-22 at 2 09 26 PM" src="https://user-images.githubusercontent.com/76453899/227243891-2452a22d-3505-4832-8dd7-34cd5969a52d.png">

This was during that little snow storm we had so it make sense that the heater was on (although it is on all the time because I dont have control over it) and that the temperature would rise as it's on and fall until it turned back on again. Also, it looks like the mic was picking up more sound when the heater was on, which also makes sense because it is super loud. 

Then looking at the data from when I reset the arduino when I go home, it is quite different. It was also a lot warmer outsite so the heater wan't on and the temperature and sound are a lot more flat.

<img width="477" alt="Screen Shot 2023-03-22 at 2 11 09 PM" src="https://user-images.githubusercontent.com/76453899/227245241-074990f3-9922-416e-a05f-2fb0dcdccd3c.png">



## Reading

[The Slow Death of Surveillance Capitalism Has Begun](https://www.wired.com/story/meta-surveillance-capitalism/)

[A Skeptical Take on the A.I. Revolution](https://www.nytimes.com/2023/01/06/opinion/ezra-klein-podcast-gary-marcus.html)

My take away from both readings is that there are going to be regulations that limit the way tech companies can collect data, which is good. That means that connected devices will also have regulations on what information they can collect and where they can send it. I think this also means that connected device need to be simple and secure. What I mean by this is, they should only be doing what they are made to do, and the company making it should be very transparent about it's funcitonality. Also, I think security is an obvious one, but the device should be secure. 

I do wonder with all of the A.I. and data regulations if people will feel inclined to stop using the voice controllers like Google Home and Alexa.

On the other hand, it is interesting because I feel that if the U.S. were actually going to ban TikTok people would be enraged. But TikTok does collect a lot of information about it's users. And I know it is quite entertaining and a lot of people make a lot of money from it, but also wonder if it were run by a company like Facebook if people would be more worried about their data being collected. Or maybe the users on TikTok really don't care about their data being collected?

The past few months I feel like so many people have been freaking out about A.I. but not for the reasons that were brought up in The Ezra Klein Show podcast. When I am talking about people I mean my friends and family outside of ITP. I found that everyone I talked to was very worked up about the fact that ChatGPT was so human-like and how scary that was. Which is pretty freaky but also makes sense because of the way it was trained, but I think this really does make people think that the model can critically think and know what is wrong or right. This is the scary part. There was that one article, [Bing's A.I. Chat: 'I Want to Be Alive'](https://www.nytimes.com/2023/02/16/technology/bing-chatbot-transcript.html), that had all of my coworkers in a frenzy! But in reality the A.I. doesn't know what it means when it is saying the stuff. And it is scary that it can produce false new and false info in such a human way, but just like the rest of the internet people should be aware of where they are getting their info.

Also, to bring data back into the conversation, don't the A.I. companies also need to collect data from their users to they can improve their model?

## Phillips Hue Control

I had no luck creating a user name to control the light strip on pillar 12. I tried to create one using the [javascript client example](https://tigoe.github.io/hue-control/client-example-js/) but I kept getting the error that it failed to fetch. I followed the directions and pressed the button on the hub bridge and then clicked create user.
<img width="651" alt="Screen Shot 2023-03-26 at 11 09 08 AM" src="https://user-images.githubusercontent.com/76453899/227785635-37342c51-1154-4a43-9f6f-018a969680b6.png">

I thought maybe I was not on the right network so I tried connecting on both the nyu network and sandbox370, but still no luck. Then I tried to see if I could connect to the bridge through the app. But it said it could not find any brides:

![IMG_4018](https://user-images.githubusercontent.com/76453899/227785757-20b17616-dfef-48c9-b7fa-312cdcc33465.PNG)


UPDATE:
I asked Adnan how he connected to the stip because I know he is in Light, and he told me I had to download the source code and request a username while running the code locally. And it was successful!!

I tested the Arduino switch code that turns the light on and off and it was successful. 
