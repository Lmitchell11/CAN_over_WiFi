#include "Energia.h"

#line 1 "D:/Backup from SSD/TxRxStringCreateNet/CreateNetwork/CreateNetwork.ino"
















#ifndef __CC3200R1M1RGC__
#include <SPI.h>
#endif

#include <WiFi.h>
#include <WiFiUDP.h>




void setup();
void loop();
void printWifiStatus();

#line 27
WiFiUDP Udp;


char wifi_name[] = "LiamTest";
char wifi_password[] = "Test12345";

IPAddress gateway;
unsigned int localPort = 8000;      


char packetBuffer[255]; 
char ReplyBuffer[] = "Ready for Transmission -------------------------------------------------------------------------------------------------";       

char SendBuffer[255]; 




void setup() {






    
    













}

int j = 0;
void loop() {

    int packetSize = Udp.parsePacket();

    
    if (j == 0) {
        for (j = 0; j < 1; j++) {
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Serial.println(ReplyBuffer);
            Udp.write(ReplyBuffer);
            Udp.endPacket();
        }
    }

    if (j != 0) {
        if (packetSize) {



            Serial.print("Client: ");
            IPAddress remoteIp = Udp.remoteIP();
            Serial.print(remoteIp);
            Serial.print(", Port: ");
            Serial.println(Udp.remotePort());

            
            int len = Udp.read(packetBuffer, 255);

            if (len > 0) packetBuffer[len] = 0;
            Serial.print("Contents: ");
            Serial.println(packetBuffer);
            
        }
    }
}

void printWifiStatus() {
    
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
}



