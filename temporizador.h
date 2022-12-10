#include <DS3232RTC.h>
#include "simulador.h"
#include "ledIndicator.h"

DS3232RTC RTC;

int pinSwitch = A3;
boolean isReleActivatedWithVCC = false;

boolean initRTC() {
  Serial.begin(115200);

  pinMode(pinSwitch, OUTPUT);
  if (!isReleActivatedWithVCC) {
    digitalWrite( pinSwitch, HIGH );
  }

  RTC.begin();
  while (timeStatus() != timeSet) {
    setSyncProvider(RTC.get);  // the function to get the time from the RTC
    delay(1000);
  }

  return true;

  // if (timeStatus() != timeSet) {
  //   Serial.println("Unable to sync with the RTC");
  //   return false;
  // } else {
  //   return true;
  // }
}

String getStrDate() {
  return (putZero(hour()) + ":" + putZero(minute()) + ":" + putZero(second()));
}

boolean isTimeBetween(String startTime, String endTime, String actualTime) {
  int startHour = startTime.substring(0, 2).toInt();
  int startMinute = startTime.substring(3, 5).toInt();
  int startSecond = startTime.substring(6, 8).toInt();

  int endHour = endTime.substring(0, 2).toInt();
  int endMinute = endTime.substring(3, 5).toInt();
  int endSecond = endTime.substring(6, 8).toInt();

  int actualHour = actualTime.substring(0, 2).toInt();
  int actualMinute = actualTime.substring(3, 5).toInt();
  int actualSecond = actualTime.substring(6, 8).toInt();

  if (startHour < endHour) {
    return (actualHour > startHour && actualHour < endHour) || (actualHour == startHour && actualMinute > startMinute) || (actualHour == endHour && actualMinute < endMinute) || (actualHour == startHour && actualMinute == startMinute && actualSecond > startSecond) || (actualHour == endHour && actualMinute == endMinute && actualSecond < endSecond);
  } else {
    if (startMinute < endMinute) {
      return (actualHour == startHour && actualMinute > startMinute && actualMinute < endMinute) || (actualHour == startHour && actualMinute == startMinute && actualSecond > startSecond) || (actualHour == endHour && actualMinute == endMinute && actualSecond < endSecond);
    } else {
      return (actualHour == startHour && actualMinute == startMinute && actualSecond > startSecond && actualSecond < endSecond);
    }
  }
}