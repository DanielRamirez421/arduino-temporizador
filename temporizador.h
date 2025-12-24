#include <DS3232RTC.h>
#include "simulador.h"
#include "ledIndicator.h"

DS3232RTC RTC;

int pinSwitch = A3;
boolean isReleActivatedWithVCC = false;

boolean initRTC()
{
  Serial.begin(115200);

  pinMode(pinSwitch, OUTPUT);
  if (!isReleActivatedWithVCC)
  {
    digitalWrite(pinSwitch, HIGH);
  }

  RTC.begin();
  while (timeStatus() != timeSet)
  {
    setSyncProvider(RTC.get); // the function to get the time from the RTC
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

String getStrTime()
{
  return (putZero(hour()) + ":" + putZero(minute()) + ":" + putZero(second()));
}

String getStrDate()
{
  return (putZero(day()) + "/" + putZero(month()) + "/" + String(year()));
}

boolean isTimeBetween(String startTime, String endTime, String actualTime)
{
  // Convertir tiempos a segundos desde medianoche para facilitar comparación
  int startHour = startTime.substring(0, 2).toInt();
  int startMinute = startTime.substring(3, 5).toInt();
  int startSecond = startTime.substring(6, 8).toInt();
  long startTotalSeconds = startHour * 3600L + startMinute * 60L + startSecond;

  int endHour = endTime.substring(0, 2).toInt();
  int endMinute = endTime.substring(3, 5).toInt();
  int endSecond = endTime.substring(6, 8).toInt();
  long endTotalSeconds = endHour * 3600L + endMinute * 60L + endSecond;

  int actualHour = actualTime.substring(0, 2).toInt();
  int actualMinute = actualTime.substring(3, 5).toInt();
  int actualSecond = actualTime.substring(6, 8).toInt();
  long actualTotalSeconds = actualHour * 3600L + actualMinute * 60L + actualSecond;

  // Si el rango cruza medianoche (ej: 23:00:00 a 01:00:00)
  if (startTotalSeconds > endTotalSeconds)
  {
    // La hora actual está en el rango si es >= startTime O <= endTime
    return (actualTotalSeconds >= startTotalSeconds) || (actualTotalSeconds <= endTotalSeconds);
  }
  else
  {
    // Rango normal dentro del mismo día
    return (actualTotalSeconds >= startTotalSeconds) && (actualTotalSeconds <= endTotalSeconds);
  }
}