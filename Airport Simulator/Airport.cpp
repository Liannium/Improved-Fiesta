#include "Airport.h"

Airport::Airport ()
{
  for (int i = 0; i < NUM_RUNWAYS; i++)
  {
    runways[i] = empty;
  }
}

Airport::~Airport ()
{
}

void Airport::addPlane (Plane plane)
{
  Goal goal = plane.getGoal ();
  if (goal == Goal::departing)
    departing.rqEnqueue (plane);
  else
  {
    int fuel = plane.getFuel ();
    landing.enqueue (plane, fuel);
  }
}

int Airport::getTime ()
{
  return time;
}

void Airport::landNextPlane ()
{
  Plane landed;
  int fuel;
  int wait;
  int runwayUsed = NUM_RUNWAYS - runwaysLeft;
  landing.dequeue (landed, fuel);
  fuel = landed.getFuel ();
  wait = landed.getWait ();
  landingWait.insertAfter (wait);
  landingFuel.insertAfter (fuel);
  if (fuel == 0)
    runways[runwayUsed] = RunwayState::emergency;
  else
    runways[runwayUsed] = RunwayState::landed;
  runwaysLeft--;
}

bool Airport::isEmpty ()
{
  return (landing.isEmpty() && departing.rqIsEmpty());
}

int Airport::getRunwaysLeft ()
{
  return runwaysLeft;
}

RunwayState Airport::getRunwayState (int runway)
{
  return runways[runway];
}
