#include "Energia.h"

#line 1 "D:/Backup from SSD/TxRxString3/WiFiUdpSendReceiveString/WiFiUdpSendReceiveString.ino"

















#ifndef __CC3200R1M1RGC__

#include <SPI.h>
#endif
#include <WiFi.h>
#include <Wire.h>
#include "Adafruit_TMP006.h"

void setup();
void loop();
void printWifiStatus();

#line 26
Adafruit_TMP006 tmp006(0x41);
WiFiUDP Udp;




char ssid[] = "LiamTest";

char password[] = "Test12345";

int keyIndex = 0;

unsigned int localPort = 8000;      


char packetBuffer[255]; 
char replyBuffer[] = "Starting transmission now";       


void setup() {


    
    Serial.begin(115200);

    
    Serial.print("Attempting to connect to Network named: ");
    
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);

    while ( WiFi.status() != WL_CONNECTED) {
        
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nYou're connected to the network");

    while (WiFi.localIP() == INADDR_NONE) {
        
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

            

            int len = Udp.read(packetBuffer, 255);

            if (len > 0) packetBuffer[len] = 0;
            Serial.println("Contents:");
            Serial.println(packetBuffer);

            
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Udp.write(replyBuffer);
            Udp.write("\n");
            Udp.endPacket();
        }
    }

    if (i != 0) {
        















        float objt = tmp006.readObjTempC();
        Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");
        float diet = tmp006.readDieTempC();
        Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C\n");


        Udp.beginPacket(ip, localPort);

        Udp.print("Object Temperature: ");
        Udp.print(objt);
        Udp.println("*C");
        Udp.print("             Die Temperature: ");
        Udp.print(diet);
        Udp.println("*C\n");
        Udp.endPacket();
        delay(4000);
    }

}

void printWifiStatus() {
    
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    IPAddress gateway = WiFi.gatewayIP();
    Serial.print("Gateway: ");
    Serial.println(gateway);

    
    long rssi = WiFi.RSSI();
    Serial.print("Signal Strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
  }



