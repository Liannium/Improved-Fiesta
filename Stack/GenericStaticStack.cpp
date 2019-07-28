#include "Stack.h"

int main ()
{
  Stack <int>Fiesta;
  int pushTest = 42;
  int popTest{};
  int peekTest{};
  Fiesta.push (pushTest);
  Fiesta.peek (popTest);
  Fiesta.pop (popTest);
  for (int i = 0; i < 100; i++)
  {
    Fiesta.push (i);
    Fiesta.peek (peekTest);
    std::cout << peekTest << "Is currently on top of the stack \n";
  }
  return 0;
}