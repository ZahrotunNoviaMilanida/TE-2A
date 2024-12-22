const int buttonPin = 10; 
const int redLedPin = 13; 
const int yellowLedPin = 12;  
const int greenLedPin = 11;   

int ledState = 0; 

void setup() {
  pinMode(buttonPin, INPUT);  
  pinMode(redLedPin, OUTPUT);  
  pinMode(yellowLedPin, OUTPUT);    
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {  
    delay(300);  
    
    if (digitalRead(buttonPin) == HIGH) {  
      ledState++;  
      
      if (ledState > 2) {
        ledState = 0;  
      }
      
      switch (ledState) {
        case 0:
          digitalWrite(redLedPin, HIGH);  
          digitalWrite(yellowLedPin, LOW);    
          digitalWrite(greenLedPin, LOW);    
          break;
        case 1:
          digitalWrite(redLedPin, LOW);   
          digitalWrite(yellowLedPin, HIGH);   
          digitalWrite(greenLedPin, LOW);      
          break;
        case 2:
          digitalWrite(redLedPin, LOW);   
          digitalWrite(yellowLedPin, LOW);     
          digitalWrite(greenLedPin, HIGH);    
          break;
      }
    }
  }
}
