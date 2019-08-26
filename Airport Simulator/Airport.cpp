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

void Airport::timePasses ()
{
  landing.first();
  for (int i = 0; i < landing.size(); i++)
  {
    Plane temp;
    int priorityDump;
    landing.peek (temp, priorityDump);
    temp.processTurn();
    landing.updateCurrent(temp);
    landing.next();
  }
  departing.first();
  for (int i = 0; i < departing.size(); i++)
  {
    Plane temp;
    int priorityDump;
    departing.peek(temp, priorityDump);
    temp.processTurn();
    departing.updateCurrent(temp);
    departing.next();
  }
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

void Airport::departNextPlane ()
{
  Plane departed;
  int wait;
  int runwayUsed = NUM_RUNWAYS - runwaysLeft;
  departing.dequeue(departed);
  wait = departing.getWait ();
  departingWait.insertAfter (wait);
  runways[runwayUsed] = RunwayState::departed;
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

void Airport::turn ();
{
  landing.first();
  {
    Plane fuelCheck;
    int priorityDump;
    landing.peek (fuelCheck, priorityDump);
    if (fuelCheck == 0)
    {
      landNextPlane ();
    }
  }
  

RunwayState Airport::getRunwayState (int runway)
{
  return runways[runway];
}
