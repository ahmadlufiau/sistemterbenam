#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("3.34.16.1.02 ");
  lcd.print("AHMAD LUFI A U ");
  lcd.print("D3TI POLINES");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(500);
}
