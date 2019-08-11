#include "List.h"

int main ()
{
  List<char> fiesta;
  char peekTest;
  char peekNextTest;
  char deleteTest;
  fiesta.insertAfter ('h');
  fiesta.insertAfter ('i');
  fiesta.peek (peekTest);
  fiesta.first ();
  fiesta.peekNext (peekNextTest);
  fiesta.last ();
  fiesta.updateCurrent ('e');
  fiesta.insertAfter ('l');
  fiesta.insertAfter ('l');
  fiesta.insertAfter ('o');
  fiesta.first ();
  for (int i = 0; i < 3; i++)
  {
    fiesta.next ();
  }
  fiesta.deleteCurrent (deleteTest);
  fiesta.insertBefore ('o');
  return 0;
}