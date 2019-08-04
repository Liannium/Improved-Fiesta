#include "List.h"

int main ()
{
  List<char> fiesta;
  char peekTest;

  fiesta.insertAfter ('h');
  fiesta.insertAfter ('i');
  fiesta.peek (peekTest);
  return 0;
}