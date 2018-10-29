// Declare the pins for the Segment display
int pinUP = 6; // Upper segment
int pinUPR = 5; // Up-right segment
int pinDWR = 4; // Down-right segment
int pinDW = 3; // Down segment
int pinDWL = 2; // Down-left segment
int pinUPL = 7; // Up-left segment
int pinCT = 8; // Center segment

int nilaiLama = 0;
int buttonPin = 13;

void setup() {
// Declare the pins as Outputs
pinMode(pinUP, OUTPUT);
pinMode(pinUPR, OUTPUT);
pinMode(pinDWR, OUTPUT);
pinMode(pinDW, OUTPUT);
pinMode(pinDWL, OUTPUT);
pinMode(pinUPL, OUTPUT);
pinMode(pinCT, OUTPUT);
pinMode(buttonPin, INPUT);
}
void writeNumber(int value){
if (value == 0){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, HIGH);
digitalWrite(pinDWL, HIGH);
digitalWrite(pinUPL, HIGH);
digitalWrite(pinCT, LOW);
}
// If we want to write 1
if (value == 1){
digitalWrite(pinUP, LOW);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, LOW);
digitalWrite(pinDWL, LOW);
digitalWrite(pinUPL, LOW);
digitalWrite(pinCT, LOW);
}
// If we want to write 2
if (value == 2){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, LOW);
digitalWrite(pinDW, HIGH);
digitalWrite(pinDWL, HIGH);
digitalWrite(pinUPL, LOW);
digitalWrite(pinCT, HIGH);
}
// If we want to write 3
if (value == 3){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, HIGH);
digitalWrite(pinDWL, LOW);
digitalWrite(pinUPL, LOW);
digitalWrite(pinCT, HIGH);
}
if (value == 4){
digitalWrite(pinUP, LOW);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, LOW);
digitalWrite(pinDWL, LOW);
digitalWrite(pinUPL, HIGH);
digitalWrite(pinCT, HIGH);
}
if (value == 5){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, LOW);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, HIGH);
digitalWrite(pinDWL, LOW);
digitalWrite(pinUPL, HIGH);
digitalWrite(pinCT, HIGH);
}
if (value == 6){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, LOW);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, HIGH);
digitalWrite(pinDWL, HIGH);
digitalWrite(pinUPL, HIGH);
digitalWrite(pinCT, HIGH);
}
if (value == 7){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, LOW);
digitalWrite(pinDWL, LOW);
digitalWrite(pinUPL, LOW);
digitalWrite(pinCT, LOW);
}
if (value == 8){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, HIGH);
digitalWrite(pinDWL, HIGH);
digitalWrite(pinUPL, HIGH);
digitalWrite(pinCT, HIGH);
}
if (value == 9){
digitalWrite(pinUP, HIGH);
digitalWrite(pinUPR, HIGH);
digitalWrite(pinDWR, HIGH);
digitalWrite(pinDW, HIGH);
digitalWrite(pinDWL, LOW);
digitalWrite(pinUPL, HIGH);
digitalWrite(pinCT, HIGH);
}
}
void loop(){
  writeNumber(nilaiLama);
  // Read the value of the input. It can either be 1 or 0.
  int buttonValue = digitalRead(buttonPin);
  if (buttonValue == HIGH) 
  {
    nilaiLama++;
    delay(1000);
  } 
}
