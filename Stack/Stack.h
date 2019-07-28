#pragma once
#include <iostream>

template <typename T>
class Stack
{
  public:
    static const int MAX_ELEMENTS = 100;
    static const int EMPTY = 0;

    Stack ();
    ~Stack ();
    bool isFull ();
    bool isEmpty ();
    void push (T buffer);
    T pop (T buffer);
    T peek (T buffer);
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
Stack<T>::~Stack ()
{
  do {
    T* temp = new T;
    pop (*temp);
    delete temp;
  } while (!isEmpty ());
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
    throw "The stack is empty";
  T* temp = new T;
  size--;
  buffer = *data[size];
  delete data[size];
  return buffer;
}

template<typename T>
T Stack<T>::peek (T buffer)
{
  if (isEmpty ())
    throw "The stack is empty";
  buffer = *data[size - 1];
  return buffer;
}

template<typename T>
int Stack<T>::getSize ()
{
  return size;
}