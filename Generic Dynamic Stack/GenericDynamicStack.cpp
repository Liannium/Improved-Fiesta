#include "DynamicStack.h"
#include <iostream>
#include <cstdio>
#include <fstream>

int main()
{
  char word[6] = "ababa";
  DynamicStack<char> palindromeForwards;
  DynamicStack<char> palindromeBackwards;
  //std::ifstream palindromes ("palindromes.txt");
  int wordlength, wordhalf;
  bool isPalindrome = true;

  for (wordlength = 0; word[wordlength] != '\0'; wordlength++)
    palindromeForwards.push (word[wordlength]);

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
  
  std::cout << word;
  if (isPalindrome)
    std::cout << " [Palindrome] \n";
  else
    std::cout << " [not a palindrome] \n";
  return 0;
}