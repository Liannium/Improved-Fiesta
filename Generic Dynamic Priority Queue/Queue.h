#include <List.h>
#pragma once

template <typename T>
class Queue
{
  public:
    Queue ();
    ~Queue ();
    int size ();
    bool isFull ();
    bool isEmpty ();
    void enqueue (const T &buffer, int priority);
    T dequeue (T& buffer, int& priority);
    T peek (T& buffer, int& priority);
    void changePriority (int& change);

    class queueElement
    {
      int priority;
      T* data;
    };
  private:
    List<queueElement> theList;
};