#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int buttonPin = 2; 
int sensorPin = A2;
int sensorValue = 0; 
int sensorBuzzer = 3;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
int state = LOW;
int reading;
int previous = HIGH;
long time = 0;
long debounce = 200;
const int numRows = 2;
const int numCols = 16;

void setup()   /*­­­­( SETUP: RUNS ONCE )­­­­*/
{
  pinMode(buttonPin, INPUT); 
  pinMode(sensorBuzzer, OUTPUT);
  lcd.begin(numCols, numRows);
  //lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
// ­­­­­­­ Quick 3 blinks of backlight  ­­­­­­­­­­­­­
 
} /*­­(end setup )­­­*/
void loop(){
  sensorValue = analogRead(sensorPin);
  reading = digitalRead(buttonPin);
  if (reading == HIGH && previous == LOW && millis () - time > debounce){
    if (state == HIGH) {
      state = LOW;
    }else{
      state = HIGH;
    }
    time = millis();
  } 
   if (state == LOW && sensorValue != 0) {
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tidak ada Akses");
      digitalWrite(sensorBuzzer, HIGH);
   } else if (state == LOW && sensorValue == 0) {
      //delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Anda Tidak Punya Hak Akses");
       digitalWrite(sensorBuzzer, LOW);
   }else if(state == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(sensorValue);
      lcd.print("                    ");
      digitalWrite(sensorBuzzer, LOW);
   }
    previous = reading;
}


