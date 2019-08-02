#include "DynamicStack.h"
#include <iostream>
#include <cstdio>
#include <fstream>

int main()
{
  DynamicStack<char> palindromeForwards;
  DynamicStack<char> palindromeBackwards;
  std::ifstream palindromes ("palindromes.txt");
  int wordlength = 0;
  int wordhalf = 0;
  bool isPalindrome = true;

  {
    char temp;
    while (palindromes >> temp)
    {
      palindromeForwards.push (temp);
      wordlength++;
    }
  }

  wordhalf = wordlength / 2;
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

  while (isPalindrome && wordhalf > 0)
  {
    char forward, backward;
    palindromeForwards.pop (forward);
    palindromeBackwards.pop (backward);
    if (forward != backward)
      isPalindrome = false;
    wordhalf--;
  }
  
  if (isPalindrome)
    std::cout << " [Palindrome] \n";
  else
    std::cout << " [not a palindrome] \n";

  palindromes.close ();
  return 0;
}