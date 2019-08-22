#include "Plane.h"

Plane::Plane ()
{
  goal = departing;
}

Plane::Plane (const int& fuel)
{
  fuelRemaining = fuel;
  if (fuel == 0)
    goal = departing;
  else
    goal = landing;
}

int Plane::getFuel ()
{
  return fuelRemaining;
}

int Plane::getWait ()
{
  return timeWaiting;
}

void Plane::processTurn ()
{
  if (goal == landing)
    fuelRemaining--;
  timeWaiting++;
}

Status Plane::getStatus ()
{
  return status;
}

Goal Plane::getGoal ()
{
  return goal;
}
