#include <iostream>
#include <fstream>
#include "Airport.h"
#include "Plane.h"
void printHeader ();
void printValue (int maxChars, int value);

int main ()
{
  const char* FILENAME = "Airport.txt";

  std::ifstream file;
  Airport airport;

  file.open (FILENAME);
  if (!file)
    throw "File failed to open";

  printHeader ();

  while (!file.eof ())
  {
    int time = airport.getTime ();
    int newPlanesDeparting;
    int newPlanesLanding;

    file >> newPlanesDeparting;
    file >> newPlanesLanding;
    
    for (int i = 0; i < newPlanesDeparting; i++)
    {
      Plane planeDeparting;
      airport.addPlane (planeDeparting);
    }
    for (int i = 0; i < newPlanesLanding; i++)
    {
      int fuel;
      file >> fuel;
      Plane planeLanding (fuel);
      airport.addPlane (planeLanding);
    }
    for (int i = 0; i < Airport::NUM_RUNWAYS; i++)
    {
    }
  }
  return 0;
}

void printHeader ()
{
  std::cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890\n";
  std::cout << "     |          Planes Added            |     Runways      |   Queue  Lengths  \n";
  std::cout << "Time | Takeoff Landing (Fuel Remaining) | 1   2   3  Crash | Takeoff  Landing \n";
  std::cout << "---- | -------------------------------- | ---------------- | -------  -------\n";
}

void printValue (int maxChars, int value)
{
  
}
