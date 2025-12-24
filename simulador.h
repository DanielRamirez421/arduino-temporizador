#include "helpers.h"

int hourSim = 0;
int minuteSim = 0;
int secondSim = 0;

String getSimulatedTime()
{
  secondSim++;
  secondSim++;
  secondSim++;
  secondSim++;
  secondSim++;
  secondSim++;

  if (secondSim == 60)
  {
    secondSim = 0;
    minuteSim++;
  }

  if (minuteSim == 60)
  {
    minuteSim = 0;
    hourSim++;
  }

  if (hourSim == 24)
  {
    hourSim = 0;
  }

  return (putZero(hourSim) + ":" + putZero(minuteSim) + ":" + putZero(secondSim));
}
