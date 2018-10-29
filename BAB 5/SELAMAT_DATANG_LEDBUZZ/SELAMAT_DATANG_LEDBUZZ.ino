/* 
 || @file Keypad Password
 || @version 1.0
 || @author Andrew Mascolo
 || @date May 7, 2013
 ||
 || @description
 || Simple use of keypad, password and LCD
*/
#include <Pushbutton.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define Password_Lenght 7 // Give enough room for six chars + NULL char
#define BUTTON_PIN 10
int led[] = {12, 13};
int pinbuzz = 1;

LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //Set the LCD I2C address
char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "123";
byte data_count = 0, master_count = 0;
bool Pass_is_good; 
char customKey;
const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
} ;
byte rowPins[ROWS] = {9,8,7,6};//connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad
Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad 

void setup()
{
  pinMode(pinbuzz, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  lcd.begin(16,2);
  //lcd.init();// initialize the lcd 
  lcd.backlight(); }
  
void loop()
{
  pinMode(led, OUTPUT);
  lcd.setCursor(0,0);  
  lcd.print("Enter Password");
  customKey = customKeypad.getKey();

  switch(customKey) 
  { 
    case '0' ... '9':
    if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
    {
      Data[data_count] = customKey; // store char into data array     
      lcd.setCursor(data_count,1); // move cursor to show each new
  
      lcd.print(Data[data_count]); // print char at said cursor    
      data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered  
    }
    
    if(data_count == Password_Lenght-1) // if the array index is equal to the number of expected chars, compare data to master
    {   
      lcd.clear();  
      break;
      
      case '/': 
         lcd.clear();
         lcd.setCursor(0, 0);  
         //lcd.print("Password is ");
      if(!strcmp(Data, Master))
      { // equal to (strcmp(Data, Master) ==   0)
        lcd.print("Selamat Datang");
        // Hijau
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        digitalWrite(pinbuzz, HIGH);
        delay(2000);
        //tone (pinbuzz, 1000)
        digitalWrite(12, LOW);
        digitalWrite(pinbuzz, LOW);
      }
      else
      {
        // Merah
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        lcd.print("Password Salah");
        digitalWrite(pinbuzz, HIGH);
        delay(2000);
        //tone (pinbuzz, 1000)
        digitalWrite(13, LOW);
        digitalWrite(pinbuzz, LOW);
      }
      delay(5000);// added 1 second delay to make sure the password is completely shown on screen before it gets cleared.   
      lcd.clear(); 
      clearData();  
      break;
    } 
  }
}

void clearData()
{
  while(data_count !=0)
  {   // This can be used for any array size, 
    Data[data_count--] = 0; //clear array for new data
  }  
  return;
} //End Program

