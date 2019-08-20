#include "Queue.h"
#include <string>
int main ()
{
  std::string one ("one");
  std::string two ("two");
  std::string six ("six");
  Queue<std::string> improvedFiesta;
  improvedFiesta.enqueue (six, 6);
  improvedFiesta.enqueue (one, 1);
  improvedFiesta.enqueue (two, 2);
  return 0;
}