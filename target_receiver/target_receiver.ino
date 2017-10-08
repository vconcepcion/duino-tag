/* Target Receiver

   This sends a message to a receiving device when a hit against a target is registered.
 */

#include <Wire.h>

const int buttonPin = 2;

int currButtonState;
int prevButtonState;

void setup() {
  Serial.begin(9600);
  
  // Read input from button
  pinMode(buttonPin, INPUT);
  prevButtonState = digitalRead(buttonPin);
}

void loop() {
  // Detect and handle button press
  currButtonState = digitalRead(buttonPin);
  if (currButtonState != prevButtonState) {
    if (currButtonState == HIGH) {
      // Target hit
      Serial.write('H');
      delay(250);
    }
    prevButtonState = currButtonState;
  }
}
