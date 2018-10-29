/*
|| @version 1.0
|| @author Andrew Mascolo
|| @date May 15, 2013
||
|| @description
|| Simple use of keypad and LCD
*/
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

long first = 0;
long second = 0;
double total = 0;
char keypressed;

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4;

char keymap[numRows][numCols] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols] = {5,4,3,2}; //Columns 0 to 3

//initialize an instance of class NewKeypad
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  //lcd.init(); // initialize the lcd
  lcd.backlight();
}
void loop()
{
  keypressed = myKeypad.getKey();
  switch(keypressed)
  {
    case '0' ... '9': // This keeps collecting the first valueuntil a operator is pressed "+-*/"
        lcd.setCursor(0,0);
        first = first * 10 + (keypressed - '0');
        lcd.print(first);
        break;
    case '+':
        first = (total != 0 ? total : first);
        lcd.setCursor(1,0);
        lcd.print("+");
        second = SecondNumber(); // get the collected the second number
        total = first + second;
        lcd.setCursor(0,1);
        lcd.print(total);
        first = 0, second = 0; // reset values back to zero fornext use
        break;
    case '-':
        first = (total != 0 ? total : first);
        lcd.setCursor(1,0);
        lcd.print("-");
        second = SecondNumber();
        total = first - second;
        lcd.setCursor(0,1);
        lcd.print(total);
        first = 0, second = 0;
        break;
    case '*':
        first = (total != 0 ? total : first);
        lcd.setCursor(1,0);
        lcd.print("*");
        second = SecondNumber();
        total = first * second;
        lcd.setCursor(0,1);
        lcd.print(total);
        first = 0, second = 0;
        break;
    case '/':
        first = (total != 0 ? total : first);
        lcd.setCursor(1,0);
        lcd.print("/");
        second = SecondNumber();
        lcd.setCursor(0,1);
        second == 0 ? lcd.print("Invalid") : total = (float)first /
        (float)second;
        lcd.print(total);
        first = 0, second = 0;
        break;
    case 'C':
        total = 0;
        lcd.clear();
        break;
  }
}

long SecondNumber()
{
  while( 1 )
  {
    keypressed = myKeypad.getKey();
    if(keypressed >= '0' && keypressed <= '9')
    {
      second = second * 10 + (keypressed - '0');
      lcd.setCursor(2,0);
      lcd.print(second);
    }
    if(keypressed == '=') break; //return second;
  }
  return second;
}

