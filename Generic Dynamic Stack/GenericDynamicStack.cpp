#include "DynamicStack.h"

int main()
{
  DynamicStack<int> dynamicFiesta;
  int pushtest = 5;
  int poptest{};
  int poptest2{};

  dynamicFiesta.push (pushtest);
  dynamicFiesta.push (42);
  dynamicFiesta.pop (poptest);
  dynamicFiesta.pop (poptest2);
  return 0;
}