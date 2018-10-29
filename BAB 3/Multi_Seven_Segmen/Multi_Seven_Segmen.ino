#include "SevSeg.h"

SevSeg sevseg; //Initiate a seven segment controller object
int sensorPin = A2;
int sensorValue =0;
int i=0;
int waktu_awal;
int waktu=0;
int a = 2;
int button = 1;
int buttonState =0;

void setup() {
pinMode(button,INPUT);
byte numDigits = 4;
Serial.begin(9600);

//D1, D2, D3, D4
byte digitPins[] = {13, 10, 9, 7};

//A, B, C, D, E, F, G, P
byte segmentPins[] = {12, 8, 5, 3, 2, 11, 6, 4}; 
// bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
//  byte hardwareConfig = COMMON_ANODE; // See README.md for options
//  bool updateWithDelays = false; // Default. Recommended
//  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

sevseg.setBrightness(90);

}


void loop() {
buttonState = digitalRead(button);
Serial.println(buttonState);

//a++;
//if(a == 4)
//a=0;  
  sevseg.setNumber(1234,1); // , 1 = angka kecil koma dimulai dari kanan, angka besar dimulai dari kiri  

  sevseg.refreshDisplay(); 
}
