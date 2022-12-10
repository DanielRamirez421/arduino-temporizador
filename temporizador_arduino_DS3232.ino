#include "temporizador.h"

String startTime = "18:00:00";
String endTime   = "23:59:00";

boolean isTimeSimulated = false;
boolean isClockConnected = false;

void setup() {
  initLetIndicator();
  isClockConnected = initRTC();
}

void loop() {

  if ( !isClockConnected ) {
    blinkLed( intervalClockError );
    return;   
  }

  String actualTime = isTimeSimulated ? getSimulatedTime() : getStrDate();
  boolean pinSwitchState = isReleActivatedWithVCC ? isTimeBetween(startTime, endTime, actualTime) : !isTimeBetween(startTime, endTime, actualTime);

  blinkLed( intervalClockisConnected && ( isReleActivatedWithVCC ? pinSwitchState : !pinSwitchState ) ? intervalIsSwitchActivated : intervalClockisConnected );

  digitalWrite(pinSwitch, pinSwitchState);
  Serial.println( actualTime );
  delay( isTimeSimulated ? 1 : 1000 );

}


