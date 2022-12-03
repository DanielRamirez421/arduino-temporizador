#include "temporizador.h"

String startTime = "18:00:00";
String endTime   = "23:59:00";

boolean isClockConnected = false;

void setup() {
  initLetIndicator();
  isClockConnected = initRTC();
}

void loop() {

  if ( !isClockConnected ) {
    blinkLed( intervalError );
    return;  
  }

  blinkLed( intervalSuccess );

  // digitalWrite(pinSwitch, isTimeBetween(startTime, endTime, getSimulatedTime()));
  // Serial.println( getSimulatedTime() );
  // delay(1);

  digitalWrite(pinSwitch, isTimeBetween(startTime, endTime, getStrDate()));
  Serial.println( getStrDate() );
  delay(1000);

}


