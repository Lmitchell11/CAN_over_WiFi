#ifndef __CC3200R1M1RGC__
// Do not include SPI for CC3200 LaunchPad
#include <SPI.h>
#endif
#include <WiFi.h>
#include <Wire.h>
#include "Adafruit_TMP006.h"

Adafruit_TMP006 tmp006(0x41);
WiFiUDP Udp;



// your network name also called SSID
char ssid[] = "LiamTest";
// your network password
char password[] = "Test12345";
// your network key Index number (needed only for WEP)
int keyIndex = 0;


unsigned int localPort = 8000;      // local port to listen on

char packetBuffer[255]; //buffer to hold incoming packet
char replyBuffer[] = "Starting transmission now";       // a string to send back
int CAN_Bus_PID_Data = 0;

void setup() {

    //Initialize serial and wait for port to open:
    Serial.begin(115200);
    Serial1.begin(115200);

    // attempt to connect to Wifi network:
    Serial.print("Attempting to connect to Network named: ");
    // print the network name (SSID);
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(ssid, password);

    while ( WiFi.status() != WL_CONNECTED) {
        // print dots while we wait to connect
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nYou're connected to the network");

    while (WiFi.localIP() == INADDR_NONE) {
        // print dots while we wait for an ip address
        delay(300);
    }

    Serial.print("\nThis Device/Networks Information is: ");
    printWifiStatus();

    Serial.println("\nWaiting for response from the server...\n");
    Udp.begin(localPort);

    if (! tmp006.begin()) {
        Serial.println("No sensor found");
        while (1);
    }
}


int i = 0;
void loop() {

    //if there's data available, read a packet
    int packetSize = Udp.parsePacket();

    IPAddress ip = WiFi.localIP();
    ip[3] = 255;


    for (i = 0; i < 1; i++) {
        if (packetSize >= 100) {
            Serial.print("Received packet of size ");
            Serial.println(packetSize);
            Serial.print("From ");
            IPAddress remoteIp = Udp.remoteIP();
            Serial.print(remoteIp);
            Serial.print(", port ");
            Serial.println(Udp.remotePort());

            // read the packet into packetBufffer

            int len = Udp.read(packetBuffer, 255);

            if (len > 0) packetBuffer[len] = 0;
            Serial.println("Contents:");
            Serial.println(packetBuffer);

            // send a message to the IP address and port.
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Udp.write(replyBuffer);
            Udp.write("\n");
            Udp.endPacket();
        }
    }

    if (i != 0) {
        
        if (Serial1.available() > 0) {
            CAN_Bus_PID_Data = Serial1.read();    //Request for CANBUS Data - /* CAN BUS PID DATA for STEERING Taken from OBD2 PORT */
            CAN_Bus_PID_Data = 60;                                                                        //Default value, keep commented until data can be read into CAN_Bus_PID_Data variable...

            Serial.print(CAN_Bus_PID_Data);                                                               //Print what you're going to send to console (Serial0)
        };
        
        if (Serial1.available() <= 0){
          CAN_Bus_PID_Data = 20;                                                                          //Default value, keep commented until data can be read into CAN_Bus_PID_Data variable...
          
          Serial.print(CAN_Bus_PID_Data);                                                                 //Print what you're going to send to console (Serial0)
        };

//     char sendBuffer[] = "Insert Message Here";


//        float objt = tmp006.readObjTempC();
//        Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");
//        float diet = tmp006.readDieTempC();
//        Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C\n");


        Udp.beginPacket(ip, localPort);
//      Udp.write(sendBuffer);
//        Udp.print("Object Temperature: ");
//        Udp.print(objt);
//        Udp.println("*C");
//        Udp.print("Die Temperature: ");
//        Udp.print(diet);
//        Udp.println("*C\n");
          Udp.println(CAN_Bus_PID_Data);  
        Udp.endPacket();
        delay(4000);
    }
}

void printWifiStatus() {
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    IPAddress gateway = WiFi.gatewayIP();
    Serial.print("Gateway: ");
    Serial.println(gateway);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("Signal Strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
  }
