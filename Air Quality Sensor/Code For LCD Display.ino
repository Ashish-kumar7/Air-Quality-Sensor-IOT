#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

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

}

void loop() {
}