#include "DynamicStack.h"
#include <iostream>

int main()
{
  char word[6] = "madam";
  DynamicStack<char> palindromeForwards;
  DynamicStack<char> palindromeBackwards;
  int wordlength;
  bool isPalindrome = true;

  for (wordlength = 0; word[wordlength] != '\0'; wordlength++)
    palindromeForwards.push (word[wordlength]);

  for (int i = 0; i < (wordlength / 2); i++)
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

  wordlength = wordlength / 2;
  while (isPalindrome && wordlength > 0)
  {
    char forward, backward;
    palindromeForwards.pop (forward);
    palindromeBackwards.pop (backward);
    if (forward != backward)
      isPalindrome = false;
    wordlength--;
  }
  
  std::cout << word;
  if (isPalindrome)
    std::cout << " [Palindrome] \n";
  else
    std::cout << " [not a palindrome \n";
  return 0;
}