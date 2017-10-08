/* Timed Score Keeper

   This sketch displays a count of button presses on a seven seg display.

   Dependencies:
   https://github.com/DeanIsMe/SevSeg
 */

#include <SevSeg.h>
#include <SoftwareSerial.h>

int score = 0;
bool gameOver = false;

SevSeg sevSegScore;
//SoftwareSerial targetP1(19, 18); // RX, TX

void setup() {
  byte numDigits = 4;

  // Digits: 1, 2, 3, 4 <--put one resistor (ex: 220 Ohms, or 330 Ohms, etc, on each digit pin)
  byte digitPins[] = {13, 12, 11, 10};

  // Segments: A, B, C, D, E, F, G, Period
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

  // 'false' means resistors are on digit pins
  bool resistorsOnSegments = false;

  // See SevSeg README for options
  byte hardwareConfig = COMMON_CATHODE;

  // Default. Recommended
  bool updateWithDelays = false;

  // Use 'true' if you'd like to keep the leading zeros
  bool leadingZeros = false;

  // Initialize seven seg display
  sevSegScore.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevSegScore.setBrightness(90);

  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  if (!gameOver) {
    sevSegScore.setNumber(score);
  } else {
    sevSegScore.setChars((char*)"End");
  }

  // Must run repeatedly
  sevSegScore.refreshDisplay();
}

// Hit registered event signaled on port 1
void serialEvent1(){
  while (Serial1.available()) {
    char ch = Serial1.read();
    if (ch == 'H') {
      score++;
    }
  }
}

// Countdown ended event signaled on port 2
void serialEvent2(){
  while (Serial2.available()) {
    char ch = Serial2.read();
    if (ch == 'E') {
      gameOver = true;
    }
  }
}

