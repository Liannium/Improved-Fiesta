#include "DynamicStack.h"
#include <iostream>
#include <cstdio>
#include <fstream>

int main()
{
  std::ifstream palindromes ("palindromes.txt");

  while (palindromes.peek () != EOF)
  {
    DynamicStack<char> palindromeForwards;
    DynamicStack<char> palindromeBackwards;
    int wordhalf = 0;
    bool isPalindrome = true;
    {
      char temp;
      palindromes >> temp;
      do {
        palindromeForwards.push (temp);
        std::cout << temp;
        palindromes >> temp;
      } while (palindromes.peek () != '\n' && palindromes.peek() != EOF);
      palindromeForwards.push (temp);
      std::cout << temp;
    }

    wordhalf = palindromeForwards.getSize () / 2;
    for (int i = 0; i < wordhalf; i++)
    {
      char temp;
      palindromeForwards.pop (temp);
      palindromeBackwards.push (temp);
    }

    if (palindromeForwards.getSize () != palindromeBackwards.getSize ())
    {
      char temp;
      palindromeForwards.pop (temp);
    }

    while (isPalindrome && palindromeForwards.getSize () > 0)
    {
      char forward, backward;
      palindromeForwards.pop (forward);
      palindromeBackwards.pop (backward);
      if (forward != backward)
        isPalindrome = false;
    }

    if (isPalindrome)
      std::cout << " [Palindrome] \n";
    else
      std::cout << " [not a palindrome] \n";
  }
  palindromes.close ();
  return 0;
}