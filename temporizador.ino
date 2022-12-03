#include "temporizador.h"


void setup() {
  initRTC();
}

void loop() {
  // Serial.println(getStrDate());
  // digitalWrite(13, true);
  // delay(250);
  // digitalWrite(13, false);
  // delay(250);

  Serial.println( getSimulatedTime() );
  delay(100);
}
