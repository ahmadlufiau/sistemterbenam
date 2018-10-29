//Running LED 
int ledPin1 = 2; 
int ledPin2 = 3; 
int ledPin3 = 4; 

void setup() { 
  //Setting PIN Output 
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT); 
  pinMode(ledPin3, OUTPUT); 
  } 
void loop() { 
  digitalWrite(ledPin1, HIGH); 
  digitalWrite(ledPin2,LOW); 
  digitalWrite(ledPin3, LOW); 
  delay(100); 
  digitalWrite(ledPin1, LOW); 
  digitalWrite(ledPin2, HIGH); 
  digitalWrite(ledPin3, LOW); 
  delay(100); 
  digitalWrite(ledPin1, LOW); 
  digitalWrite(ledPin2, LOW); 
  digitalWrite(ledPin3, HIGH); 
  delay(100); 
 
}

