
static int startingCount = 9; // in seconds

void setup() {
  Serial.begin(9600);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = startingCount * 10;
  static int step = 100;

  if (millis() - timer >= step && deciSeconds > 0) {
    timer += step;
    deciSeconds--; // 100 milliSeconds is equal to 1 deciSecond
    if (deciSeconds <= 0) {
      Serial.write('E');      
    }
  }
}
