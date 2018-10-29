#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// Analog input pin that the potentiometer is attached to 
const int analogInPin = A2; 
// Analog output pin that the LED is attached to
const int analogOutPin = 9;
 // value read from the pot 
int sensorValue = 0; 
// value output to the PWM (analog out) 
int outputValue = 0; 
void setup() { 
// initialize serial communications at 9600 bps: 
  lcd.begin(16,2); 
 
} void loop() { 
// read the analog in value: 
sensorValue = analogRead( analogInPin);
// map it to the range of the analog out: 
outputValue = map(sensorValue, 0, 1023, 0, 255); 
// change the analog out value: 
analogWrite(analogOutPin, outputValue); 
// print the results to lcd
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Nilai Potensio");
  lcd.setCursor(0,1); //Start at character 4 on line 0
  lcd.print(sensorValue);
  lcd.print("       ");
// wait 2 milliseconds before the next loop 
// for the analog-to-digital converter to settle 
// after the last reading: 
delay(2); 
}
