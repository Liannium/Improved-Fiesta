#include "List.h"

int main ()
{
  List<char> fiesta;
  char peekTest;
  char peekNextTest;

  fiesta.insertAfter ('h');
  fiesta.insertAfter ('i');
  fiesta.peek (peekTest);
  fiesta.first ();
  fiesta.peekNext (peekNextTest);
  fiesta.last ();
  fiesta.updateCurrent ('e');

  return 0;
}