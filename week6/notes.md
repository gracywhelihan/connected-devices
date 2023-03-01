# Notes

## Websockets:

- HTTP --> stateless process
- Sockets are a less useful protocol then mqtt because the socket does not have to be open all the time and the mqtt broker is helpful in keeping info when the device is no responsive.

Example:

[Express Basics](https://glitch.com/edit/#!/tigoe-express-basics?path=README.md%3A1%3A0)

- POST requests
<img width="570" alt="Screen Shot 2023-03-01 at 9 53 31 AM" src="https://user-images.githubusercontent.com/76453899/222175919-75981d26-899b-4cb6-b232-a0925009ebc5.png">

- the query is public
- the body is encrypted

<img width="828" alt="Screen Shot 2023-03-01 at 10 13 05 AM" src="https://user-images.githubusercontent.com/76453899/222181053-f17b499a-c102-4adf-9dee-419fc169a419.png">


[websockets](https://glitch.com/edit/#!/tigoe-websocket-server?path=server.js%3A1%3A0)

- websocket > socket.io

WifiSSLClient --> 8883
wifiClient --> 1883


Run the data log on a private server - like the one we made in understanding networks
- [mqttNodeClientFileWriter](https://github.com/tigoe/mqtt-examples/tree/main/node-clients/MqttNodeClientFileWriter/)
