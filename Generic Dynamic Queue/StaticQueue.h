#include "Queue.h"
#pragma once

template <typename T>
class StaticQueue
{
  public:
    StaticQueue ();
    ~StaticQueue ();
    int size ();
    bool isEmpty ();
    void enqueue (const T& buffer);
    T dequeue (T& buffer);
    T peek (T& buffer);
  private:
    Queue<QueueElement> theQueue;
};
