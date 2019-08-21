#pragma once

enum Goal {land, depart}; //taking off was two words so I had to use departing instead >.>
//in C this is going to be const int landing = 0; const int departing = 1;
enum Status {waiting, landedSafe, landedEmergency, crashed, departed};
class Plane
{
  public:
    Plane ();
    Plane (int fuel);
    int getFuel ();
    int getWait ();
    int processTurn ();
    void crash ();
    void land ();

    Status status;
    Goal goal;
  private:
    int fuelRemaining;
    int timeWaiting;
};
