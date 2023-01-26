## week 1 - class notes

&nbsp

- Packet switched vs. circuit switched 
&nbsp

ls /dev/cu.* —>  see all incoming ports
cat /dev/cu.usbmodem123 —> data from serial port Arduino
cat /dev/cu.usbmodem123 >> log.txt —> puts serial data into a file
cat /dev/cu.usbmodem123 | tee log.txt —> splits the data between log.txt and the terminal

&nbsp

less —> lets you look at the contents of a file page by page

&nbsp

nc -l 8080 —> listen on port 8080
nc IP 8080 —> send 

&nbsp

-v for verbose

&nbsp

Why can’t you listen on port 8080 with nc -l 8080 ?
- Could be a fire wall 

&nbsp

Device data 
- When sending data —> need to decide what the best protocol ex. JSON

&nbsp

python3 -m http.server —>
nc -l 8000 |tee log.json & python3 -m http.server
