#include "temporizador.h"

String startTime = "18:30:00";
String endTime   = "23:59:00";

void setup() {
  initRTC();
}

void loop() {
  // digitalWrite(13, isTimeBetween(startTime, endTime, getSimulatedTime()));
  // Serial.println( getSimulatedTime() );
  // delay(1);

  digitalWrite(13, isTimeBetween(startTime, endTime, getStrDate()));
  Serial.println( getStrDate() );
  delay(1000);
}
