int sensorPin = A2; 
int ledPin = 13; 
int sensorValue = 0; // variable to store the value coming from the sensor 

void setup() { 
  pinMode(ledPin, OUTPUT); 
} 

void loop() { 
  sensorValue = analogRead(sensorPin); 
  // turn the ledPin on 
  digitalWrite(ledPin, HIGH); 
  // stop the program for <sensorValue> milliseconds: 
  delay(sensorValue); 
  // turn the ledPin off: 
  digitalWrite(ledPin, LOW); 
  // stop the program for for <sensorValue> milliseconds: 
  delay(sensorValue); 
}

