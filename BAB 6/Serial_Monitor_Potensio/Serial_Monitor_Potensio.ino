// select the input pin for the potentiometer 
int sensorPin = A2; 
int ledPin = 13; 
// select the pin for the LED 
int sensorValue = 0; 
// variable to store the value coming from the sensor 
void setup() {   
  // declare the ledPin as an OUTPUT:   
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); 
  } 
void loop() { 
  // read the value from the sensor: 
  sensorValue = analogRead(sensorPin); 
  // turn the ledPin on 
  // print the results to the serial monitor: 
  Serial.print("sensorValue= " ); 
  Serial.print(sensorValue); 
  Serial.print("\n" ); 
  // stop the program for <sensorValue> milliseconds: 
  digitalWrite(ledPin, HIGH);
  delay(sensorValue); 
  // turn the ledPin off: 
  digitalWrite(ledPin, LOW); 
  // stop the program for for <sensorValue> milliseconds: 
  delay(sensorValue); 
} 

