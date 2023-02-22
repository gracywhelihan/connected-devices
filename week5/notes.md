## Notes
- Create a unique id for you client ID
- message.replace("ID", macAddr);

- Connection timeout --> shiftr.io might be better for avoiding timeouts / so set up our own broker
- Client and Serial come from a library called Stream

<br></br>
Multiple topics:
- Depending on what you want to do with each topic you can use if statements to get each specific topic or create a different fucntions
- subtopics and be used to send meta info to tell the broker that the device is still alive when we are interested in data that only sends when it changes
- Remember to publish my code!

<br></br>
Time:
- iso8601 date time 
- command line-- date +%s --> give time seconds since 1970
- Arduino - time and date since compilation
- if(!Serial) delay(3000){
serial.println(__DATE__);
serial.pintln(__TIME__)}
- use wifi get time
  - combine rtc with wifi get time --> tigoe.net clock club 
  - get the epoch time from the network --> rtc.setEpoch
  - redo a get time from network every 12 hours because the rtc on the arduino will "drift"

QR Codes:
- bit map file
- 
