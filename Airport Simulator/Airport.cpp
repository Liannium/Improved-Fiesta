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

void Airport::addPlane (Plane& plane)
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
