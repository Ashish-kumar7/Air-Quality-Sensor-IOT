#include <ESP8266WiFi.h>;
 
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;
 
const char* ssid = "12345"; //Your Network SSID
 
const char* password = "333333333"; //Your Network Password
 
int val;
 
int LDRpin = A0; //LDR Pin Connected at A0 Pin
 
 
 
WiFiClient client;
 
unsigned long myChannelNumber =  834519; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "KUKLI1668ZG3X0G5"; //Your Write API Key
 
void setup()
 
{
 
Serial.begin(9600);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
 
 
 
ThingSpeak.begin(client);
 
}
 
 
 
void loop()
 
{
 
val = analogRead(LDRpin); //Read Analog values and Store in val variable
 
Serial.println(val); //Print on Serial Monitor
 
delay(1000);
 
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
 
 
 
delay(100);
 
}