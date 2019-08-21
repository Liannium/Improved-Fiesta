#include <iostream>
void printHeader ();

int main ()
{
  printHeader ();
  return 0;
}

void printHeader ()
{
  std::cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890\n";
  std::cout << "     |          Planes Added            |     Runways      |   Queue  Lengths  \n";
  std::cout << "Time | Takeoff Landing (Fuel Remaining) | 1   2   3  Crash | Takeoff  Landing \n";
  std::cout << "---- | -------------------------------- | ---------------- | -------  -------\n";
}
