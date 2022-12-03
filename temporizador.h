#include <DS3232RTC.h>
#include "simulador.h"

DS3232RTC RTC;

void initRTC() {
  Serial.begin(115200);
  RTC.begin();
  setSyncProvider(RTC.get);  // the function to get the time from the RTC
  if (timeStatus() != timeSet)
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");
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