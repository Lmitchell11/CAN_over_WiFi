/*
  CreateNetwork
  Start WiFi in in AP mode creating a network that you can connect to
  from a PC or SmartPhone. There is a limitation that only ONE device
  can be connected. Trying to connect to the network with a second client 
  will fail. To connect with a different device, first disconnect the device
  currently connected.
  
  Hardware Required:
  * CC3200 LaunchPad or MSP430/TivaC LaunchPad with CC3200 BoosterPack

  Created November 2014
  by Robert Wessels
  
  This example code is in the public domain.
*/
#ifndef __CC3200R1M1RGC__
#include <SPI.h>
#endif
#include <WiFi.h>
#include <WiFiUDP.h>


WiFiUDP Udp;

char wifi_name[] = "LiamTest";
char wifi_password[] = "Test12345";

IPAddress gateway;
unsigned int localPort = 8000;      // local port to listen on


char packetBuffer[255]; //buffer to hold incoming packet
char ReplyBuffer[] = "Ready for Transmission -------------------------------------------------------------------------------------------------";       // a string to send back


void setup() {
    Serial.begin(115200);   //UART USB/Console
    Serial1.begin(115200);  //UART Tx/Rx Pins


    // Start WiFi and create a network with wifi_name as the network name
    // with wifi_password as the password.
    Serial.println("Creating network...");
    WiFi.beginNetwork(wifi_name, wifi_password);
    Udp.begin(localPort);
    while(WiFi.localIP() == INADDR_NONE) {
        delay(300);
    }
    Serial.println("Done\n");

    printWifiStatus();


    Serial.println("\nWaiting for a packet to be transmitted from a client...\n");

}

int i = 0;
void loop() {

    int packetSize = Udp.parsePacket();

    // send a message to the IP address and port. (confirming its ready for transmission ONCE)
    if (i == 0) {
        for (i = 0; i < 1; i++) {
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Serial.println(ReplyBuffer);
            Udp.write(ReplyBuffer);
            Udp.endPacket();
        }
    }

    if (i != 0) {
        if (packetSize) {
//          Serial.print("Received packet of size ");
//          Serial.println(packetSize);
//          Serial.print("From ");
            Serial.print("Client: ");
            IPAddress remoteIp = Udp.remoteIP();
            Serial.print(remoteIp);
            Serial.print(", Port: ");
            Serial.println(Udp.remotePort());

            // read the packet into packetBufffer
            int len = Udp.read(packetBuffer, 255);

            if (len > 0) packetBuffer[len] = 0;
            Serial.print("Contents: ");
            Serial.println(packetBuffer);             //Printing contents plus newline to console/USB-Terminal
            Serial1.println(packetBuffer);            //Basically this is just to print using UART from pins P03 and P04 on Microcontroller

            
        }
    }
}

void printWifiStatus() {
    // print your WiFi IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
}
