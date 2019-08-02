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

  while (palindromes.peek () != '\0')
  {
    char temp = palindromes.get ();
    palindromeForwards.push (temp);
    std::cout << temp;
    palindromes.seekg (1, palindromes._Seekcur);
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