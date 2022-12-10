const int ledPin = LED_BUILTIN;
int ledState = LOW;
unsigned long previousMillis = 0;  


const long intervalClockError = 150;
const long intervalClockisConnected = 3000;
const long intervalIsSwitchActivated = 1000;

int ledIndicatorGND = A1;
int ledIndicator = A2;

void blinkLed( long interval ) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
    digitalWrite(ledIndicator, ledState);
  }
}

void initLetIndicator() {
  pinMode(ledIndicator, OUTPUT);
  pinMode(ledIndicatorGND, OUTPUT);
  digitalWrite(ledIndicator, LOW);
  digitalWrite(ledIndicatorGND, LOW);
}