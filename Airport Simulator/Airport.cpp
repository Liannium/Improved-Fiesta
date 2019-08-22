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
  landing.dequeue (landed, fuel);
  fuel = landed.getFuel ();
  wait = landed.getWait ();
  landingWait.insertAfter (wait);
  landingFuel.insertAfter (fuel);
}
