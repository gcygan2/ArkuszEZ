#include "Keyboard.h"

#define MAX 45
char konto[MAX * 2];

void handleInterrupt() {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) { 
    previousMillis = currentMillis;
    Keyboard.print(konto);
  }
}

void setup() {
  Keyboard.begin();
  
  pinMode (7, INPUT_PULLUP);

  for (int i = 0; i < MAX; i++) {
     konto[i * 2] = '\t';
     konto[i * 2 + 1] = ' ';
  }

  attachInterrupt(digitalPinToInterrupt(7), handleInterrupt, FALLING);
}

void loop() {
}
