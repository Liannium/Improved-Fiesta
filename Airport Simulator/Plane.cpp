#include "Plane.h"

Plane::Plane ()
{
  goal = departing;
}

Plane::Plane (const int& fuel)
{
  fuelRemaining = fuel;
  if (fuel == 0)
    goal = landing;
  else
    goal = departing;
}

int Plane::getFuel ()
{
  return fuelRemaining;
}

int Plane::getWait ()
{
  return timeWaiting;
}

int Plane::processTurn ()
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
