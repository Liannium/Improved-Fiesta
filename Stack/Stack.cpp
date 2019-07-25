#include "Stack.h"

template<typename T>
Stack<T>::Stack ()
{
  size = EMPTY;
}

template<typename T>
bool Stack<T>::isFull ()
{
  if (size == MAX_ELEMENTS)
    return true;

  return false;
}

template<typename T>
bool Stack<T>::isEmpty ()
{
  if (size == EMPTY)
    return true;
  return false;
}

template<typename T>
void Stack<T>::push (T* buffer, int size)
{
  new T* = buffer;
  data[size] = buffer;
  size++;
}

template<typename T>
int Stack<T>::getSize ()
{
  return size;
}
