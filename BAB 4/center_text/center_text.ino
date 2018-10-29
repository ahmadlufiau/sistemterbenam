#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int cursor;
String nama = "AHMAD LUFI A U";
String nim = "3.34.16.1.02";

void setup() {
  Serial.begin(9600);
  lcd.backlight();
  lcd.begin(16,2);
}

void loop() {
  cursor = (16 - nama.length())/2;
  lcd.setCursor(cursor,0);
  lcd.print(nama);
  cursor = (16 - nim.length())/2;
  lcd.setCursor(cursor,1);
  lcd.print(nim);
}
