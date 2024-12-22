#include <SevSeg.h>
SevSeg sevseg;

const byte ledMerah = 11;   
const byte ledKuning = 12;  
const byte ledHijau = 13;   
const int buttonPin = 1;    

const int display1Pin = 2;  
const int display2Pin = 3; 

int segA = 4; 
int segB = 5; 
int segC = 6;  
int segD = 7; 
int segE = 8;  
int segF = 9;  
int segG = 10; 

int buttonState = 0;
int lastButtonState = 0;
unsigned long debounceDelay = 50;
unsigned long lastDebounceTime = 0;

bool blinking = true;   
bool trafficRunning = false;

unsigned long previousMillis = 0;
unsigned long interval = 0;
int countdownValue = 0;

enum TrafficState {NORMAL, KUNING1, MERAH, KUNING2, HIJAU};
TrafficState currentState = NORMAL;

void setup() {
  byte numDigits = 2; 
  byte digitPins[] = {display1Pin, display2Pin}; 
  byte segmentPins[] = {segA, segB, segC, segD, segE, segF, segG}; 
  bool resistorsOnSegments = true;
  byte hardwareConfig = COMMON_ANODE;
  bool updateWithDelays = false; 
  bool leadingZeros = true; 
  bool disableDecPoint = true;

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);

  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        trafficRunning = true; 
        blinking = false;      
        digitalWrite(ledHijau, LOW); 
        currentState = KUNING1;
        interval = 2000;       
        previousMillis = millis(); 
      }
    }
  }

  lastButtonState = reading;

  if (!trafficRunning) {
    static unsigned long previousMillisBlink = 0;
    unsigned long currentMillisBlink = millis();

    if (currentMillisBlink - previousMillisBlink >= 500) { 
      previousMillisBlink = currentMillisBlink;
      digitalWrite(ledHijau, blinking ? HIGH : LOW);
      blinking = !blinking; 
    }
  } else {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      switch (currentState) {
        case KUNING1:
          digitalWrite(ledKuning, LOW); 
          currentState = MERAH;
          interval = 1000;  
          countdownValue = 20;
          break;

        case MERAH:
          if (countdownValue >= 0) {
            sevseg.setNumber(countdownValue, 2);
            sevseg.refreshDisplay();
            countdownValue--;
            interval = 1000;
          } else {
            digitalWrite(ledMerah, LOW); 
            currentState = KUNING2;     
            countdownValue = 20;        
            interval = 2000;            
          }
          break;

        case KUNING2:  
          digitalWrite(ledKuning, LOW);
          interval = 2000;              
          currentState = HIJAU;          
          break;

        case HIJAU:
          sevseg.blank();               
          digitalWrite(ledHijau, HIGH);
          interval = 2000;             
          trafficRunning = false;       
          currentState = NORMAL;     
          break;

        case NORMAL:
          break;
      }
      previousMillis = currentMillis;
    }

    if (currentState == KUNING1 || currentState == KUNING2) {
      sevseg.blank();
      digitalWrite(ledKuning, HIGH);
    } else if (currentState == MERAH) {
      digitalWrite(ledMerah, HIGH);
    } else if (currentState == HIJAU) {
      sevseg.blank(); 
      digitalWrite(ledHijau, HIGH);
    }
  }

  sevseg.refreshDisplay();
}


