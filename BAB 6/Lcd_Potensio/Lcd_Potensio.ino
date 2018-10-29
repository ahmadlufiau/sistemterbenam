#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// select the input pin for the potentiometer 
int sensorPin = A2; 
int ledPin = 13; 
// select the pin for the LED 
int sensorValue = 0; 
// variable to store the value coming from the sensor 
void setup() {   
  // declare the ledPin as an OUTPUT:   
  pinMode(ledPin, OUTPUT); 
  lcd.begin(16,2); 
  } 
void loop() { 
  // read the value from the sensor: 
  sensorValue = analogRead(sensorPin); 
  // turn the ledPin on 
  // print the results to the serial monitor: 
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Nilai Potensio");
  lcd.setCursor(0,1); //Start at character 4 on line 0
  lcd.print(sensorValue);
  lcd.print("       ");
  
    // stop the program for <sensorValue> milliseconds: 
  digitalWrite(ledPin, HIGH);
  delay(sensorValue); 
  // turn the ledPin off: 
  digitalWrite(ledPin, LOW); 
  // stop the program for for <sensorValue> milliseconds: 
  delay(sensorValue); 
} 

