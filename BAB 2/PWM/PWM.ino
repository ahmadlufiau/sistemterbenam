// Declare the LED pin with PWM 

int LED = 3; 
void setup() { 
// Declare the pin for the LED as Output 
  pinMode(LED, OUTPUT); 
  } 
void loop(){ 
// Here we will fade the LED from 0 to maximum, 255 
  for (int i = 0; i < 256; i++){ 
    analogWrite(LED, i); 
    delay(5); 
  } 
// Fade the LED from maximum to 0 
  for (int i = 255; i >= 0; i--){ 
    analogWrite(LED, i); 
    delay(5); 
   } 
}

