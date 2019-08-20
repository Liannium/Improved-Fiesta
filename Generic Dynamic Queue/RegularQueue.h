#include "Queue.h"
#pragma once

template <typename T>
class RegularQueue
{
  public:
    RegularQueue ();
    ~RegularQueue ();
    int rqSize ();
    bool rqIsEmpty ();
    void rqEnqueue (const T& buffer);
    T rqEnqueue (T& buffer);
    T rqPeek (T& buffer);
  private:
    Queue<QueueElement> theQueue;
};

template<typename T>
inline StaticQueue<T>::StaticQueue ()
{
}
