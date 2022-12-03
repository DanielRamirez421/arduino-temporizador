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
  return ( putZero(hour()) + ":" + putZero( minute() ) + ":" + putZero(second()) );
}
