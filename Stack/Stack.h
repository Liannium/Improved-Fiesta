#pragma once
#include <iostream>

template <typename T>
class Stack
{
  public:
    static const int MAX_ELEMENTS = 100;
    static const int EMPTY = 0;

    Stack ();
    //~Stack ();
    bool isFull ();
    bool isEmpty ();
    void push (T buffer);
    T pop (T buffer);
    //T* peek (T* buffer);
    int getSize ();

  private:
    T* data[MAX_ELEMENTS];
    int size = EMPTY;
};

template<typename T>
Stack<T>::Stack ()
{
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
void Stack<T>::push (T buffer)
{
  if (isFull ())
  {
    std::cout << "The stack is full";
    return;
  }
  T* temp = new T;
  *temp = buffer;
  data[size] = temp;
  size++;
}

template<typename T>
T Stack<T>::pop (T buffer)
{
  if (isEmpty ())
  {
    throw "The stack is empty";
  }
  T* temp = new T;
  size--;
  temp = data[size];
  buffer = *temp;
  delete temp;
  return buffer;
}

template<typename T>
int Stack<T>::getSize ()
{
  return size;
}