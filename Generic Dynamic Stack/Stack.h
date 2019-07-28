#pragma once
#include "Node.h"

template<typename T>
class Stack {
  public:
    Stack ();
    ~Stack ();
    void push (T buffer);
    T pop (T buffer);
    T peek (T buffer);
    int getSize ();

  private:
    Node* top;
    int size;
};