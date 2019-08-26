#include "Queue.h"
#include "RegularQueue.h"
#include "Plane.h"
#pragma once

enum RunwayState {empty, departed, landed, emergency};
class Airport
{
  public:
    Airport ();
    ~Airport ();
    void addPlane (Plane plane);
    int getTime ();
    void takeTurn ();
    void landNextPlane ();
    void departNextPlane ();
    bool isEmpty ();
    int getRunwaysLeft ();
    void turn ();
    RunwayState getRunwayState (int runway);

    static const int NUM_RUNWAYS = 3;
    static const int MAX_NEW_PLANES_LANDING = 3;
  private:
    Queue<Plane> landing;
    RegularQueue<Plane> departing;
    List <int> landingWait;
    List <int> landingFuel;
    List <int> departingWait;
    RunwayState runways[NUM_RUNWAYS];
    int time = 1;
    int emergencyLandings = 0;
    int safeLandings = 0;
    int crashes = 0;
    int runwaysLeft = NUM_RUNWAYS;
};
