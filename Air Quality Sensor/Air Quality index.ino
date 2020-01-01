#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>;
 
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;

LiquidCrystal_I2C lcd(0x27, 16, 2);

 
const char* ssid = "12345"; //Your Network SSID
 
const char* password = "333333333"; //Your Network Password
 
int val;
 
int LDRpin = A0; //LDR Pin Connected at A0 Pin
  
WiFiClient client;
 
unsigned long myChannelNumber =  834519; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "V63J3IE4GAIGW0S5"; //Your Write API Key


void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(3, 0);
  lcd.print("AIR QUALITY ");
  
  lcd.setCursor(5, 1);      
  lcd.print("SENSOR");

  delay(1000);
  lcd.clear();
  
  lcd.setCursor(3,0);
  lcd.print("MADE BY");
  delay(1000);
  lcd.clear();
  lcd.print("ASHISH KUMAR");
  delay(1000);
  lcd.clear();
  lcd.print("ANUKRITI DAS");
  delay(1000);
  lcd.clear();
  lcd.print("SHASHANK");
  delay(1000);
  lcd.clear();

  lcd.setCursor(3,0);
  lcd.print("MENTOR");
  delay(1000);
  lcd.clear();
  lcd.print("SHREYASH GANVIR");
  delay(1000);
  lcd.clear();
  
Serial.begin(9600);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
 
ThingSpeak.begin(client);

}

void loop() {

val = analogRead(LDRpin); //Read Analog values and Store in val variable
 
Serial.println(val); //Print on Serial Monitor

lcd.println(val);
lcd.println(" ");
lcd.println("PPM");
delay(1000);
lcd.clear();

if(val<=200)
{
lcd.println("LOW QUALITY");
delay(600);
lcd.clear();
Serial.println("LOW QUALITY");
}

else if(val<=400 && val>200)
{
lcd.println("MODERATE QUALITY");
delay(600);
lcd.clear();
Serial.println("MODERATE QUALITY");
}

else 
{
lcd.println("BAD QUALITY");
delay(600);
lcd.clear();
Serial.println("BAD QUALITY");
}
 
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
delay(70);
 

  
}