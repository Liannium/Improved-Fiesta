#include "DynamicStack.h"

int main()
{
  DynamicStack<int> dynamicFiesta;
  int pushtest = 5;
  int poptest;

  dynamicFiesta.push (pushtest);
  dynamicFiesta.pop (poptest);
  return 0;
}