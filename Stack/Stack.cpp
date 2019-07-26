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
void Stack<T>::push (T* buffer)
{
  if (isFull ())
  {
    std::cout << "The stack is full \n";
    return;
  }
  T* temp = new T;
  *temp = *buffer;
  data[size] = temp;
  size++;
}

template<typename T>
T* Stack<T>::pop (T* buffer)
{
  if (isEmpty ())
  {
    std::cout << "The stack is empty \n";
    return;
  }
  T* temp = new T;
  *temp = data[size];
  buffer = temp;
  size--;
  return buffer;
}

template<typename T>
int Stack<T>::getSize ()
{
  return size;
}
