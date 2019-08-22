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
    void rqEnqueue (T buffer);
    T rqDequeue (T& buffer);
    T rqPeek (T& buffer);
  private:
    Queue<T> theQueue;
};

template<typename T>
inline RegularQueue<T>::RegularQueue ()
{
}

template<typename T>
inline RegularQueue<T>::~RegularQueue ()
{
}

template<typename T>
inline int RegularQueue<T>::rqSize ()
{
  return theQueue.size();
}

template<typename T>
inline bool RegularQueue<T>::rqIsEmpty ()
{
  return theQueue.isEmpty();
}

template<typename T>
inline void RegularQueue<T>::rqEnqueue (T buffer)
{
  theQueue.enqueue (buffer, 0);
}

template<typename T>
inline T RegularQueue<T>::rqDequeue (T& buffer)
{
  int temp;
  theQueue.dequeue (buffer, temp);
  return buffer;
}

template<typename T>
inline T RegularQueue<T>::rqPeek (T& buffer)
{
  int temp;
  theQueue.peek (buffer, temp);
  return buffer;
}
