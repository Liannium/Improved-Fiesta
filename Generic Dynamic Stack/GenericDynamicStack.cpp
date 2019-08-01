#include "DynamicStack.h"

int main()
{
  DynamicStack<int> dynamicFiesta;
  int pushTest = 5;
  int popTest{};
  int popTest2{};
  int peekTest{};

  dynamicFiesta.push (pushTest);
  dynamicFiesta.push (42);
  dynamicFiesta.peek (peekTest);
  dynamicFiesta.pop (popTest);
  dynamicFiesta.pop (popTest2);
  return 0;
}