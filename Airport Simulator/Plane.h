#pragma once

enum Goal {departing, landing}; //taking off was two words so I had to use departing instead >.>
//in C this is going to be const int landing = 0; const int departing = 1;
enum Status {waiting, landedSafe, landedEmergency, crashed, left};
class Plane
{
  public:
    Plane ();
    Plane (const int& fuel);
    int getFuel ();
    int getWait ();
    void processTurn ();
    Status getStatus ();
    Goal getGoal ();

  private:
    int fuelRemaining = 0;
    int timeWaiting = 1;
    Status status = waiting;
    Goal goal;
};
