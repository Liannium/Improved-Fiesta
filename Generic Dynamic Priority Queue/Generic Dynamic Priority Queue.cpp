#include "Queue.h"
#include <string>
int main ()
{
  std::string one ("one");
  std::string two ("two");
  std::string six ("six");
  std::string first ("zero");
  std::string secondTwo ("second two");
  std::string last ("ten");
  std::string popTest (" ");
  int popPriority;
  Queue<std::string> improvedFiesta;
  improvedFiesta.enqueue (six, 6);
  improvedFiesta.enqueue (one, 1);
  improvedFiesta.enqueue (two, 2);
  improvedFiesta.enqueue (secondTwo, 2);
  improvedFiesta.enqueue (first, 0);
  improvedFiesta.enqueue (last, 10);
  improvedFiesta.dequeue (popTest, popPriority);
  improvedFiesta.changePriority (-1);
  return 0;
}