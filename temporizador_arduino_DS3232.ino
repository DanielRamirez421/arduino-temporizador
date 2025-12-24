#include "temporizador.h"

String startTime = "18:30:00";
String endTime = "02:59:00";

boolean isTimeSimulated = false;
boolean isClockConnected = false;

void setup()
{
  initLetIndicator();
  isClockConnected = initRTC();
}

void loop()
{

  if (!isClockConnected)
  {
    blinkLed(intervalClockError);
    return;
  }

  String actualTime = isTimeSimulated ? getSimulatedTime() : getStrTime();
  boolean isInTimeRange = isTimeBetween(startTime, endTime, actualTime);
  boolean pinSwitchState = isReleActivatedWithVCC ? isInTimeRange : !isInTimeRange;

  boolean isRelayActive = isReleActivatedWithVCC ? pinSwitchState : !pinSwitchState;
  int blinkInterval = isRelayActive ? intervalIsSwitchActivated : intervalClockisConnected;
  blinkLed(blinkInterval);

  digitalWrite(pinSwitch, pinSwitchState);
  Serial.println(actualTime + " " + getStrDate() + " | Relay is " + (isRelayActive ? "ON" : "OFF"));

  delay(isTimeSimulated ? 1 : 1000);
}
