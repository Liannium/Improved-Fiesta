#include "Stack.h"

int main ()
{
  Stack <int>Fiesta;
  int pushTest = 42;
  int popTest;
  Fiesta.push (&pushTest);
  Fiesta.pop (&popTest);
  return 0;
}