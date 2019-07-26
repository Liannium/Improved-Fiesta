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
    void push (T* buffer);
    T* pop (T* buffer);
    T* peek (T* buffer);
    int getSize ();

  private:
    T* data[MAX_ELEMENTS];
    int size;
};
