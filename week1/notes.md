## week 1 - class notes

<p>&nbsp;</p>

- Packet switched vs. circuit switched 
<p>&nbsp;</p>

ls /dev/cu.* —>  see all incoming ports
cat /dev/cu.usbmodem123 —> data from serial port Arduino
cat /dev/cu.usbmodem123 >> log.txt —> puts serial data into a file
cat /dev/cu.usbmodem123 | tee log.txt —> splits the data between log.txt and the terminal

<p>&nbsp;</p>

less —> lets you look at the contents of a file page by page

<p>&nbsp;</p>

nc -l 8080 —> listen on port 8080
nc IP 8080 —> send 

<p>&nbsp;</p>

-v for verbose

<p>&nbsp;</p>

Why can’t you listen on port 8080 with nc -l 8080 ?
- Could be a fire wall 

<p>&nbsp;</p>

Device data 
- When sending data —> need to decide what the best protocol ex. JSON

<p>&nbsp;</p>

python3 -m http.server —>
nc -l 8000 |tee log.json & python3 -m http.server
