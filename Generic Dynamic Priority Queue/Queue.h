#include <List.h>
#pragma once

template <typename T>
class Queue
{
  public:
    Queue ();
    ~Queue ();
    int size ();
    bool isEmpty ();
    void enqueue (const T &buffer, int priority);
    T dequeue (T& buffer, int& priority);
    T peek (T& buffer, int& priority);
    void changePriority (const int& change);

    class QueueElement
    {
      public:
        int priority;
        T* data;
    };
  private:
    List<QueueElement> theList;
};

template<typename T>
inline Queue<T>::Queue ()
{

}

template<typename T>
inline Queue<T>::~Queue ()
{
  while (!isEmpty ())
  {
    T temp;
    int priority;
    dequeue (temp, priority);
  }
}

template<typename T>
inline int Queue<T>::size ()
{
  return theList.size();
}

template<typename T>
inline bool Queue<T>::isEmpty ()
{
  return theList.isEmpty();
}

template<typename T>
inline void Queue<T>::enqueue (const T& buffer, int priority)
{
  QueueElement element;
  element.priority = priority;
  element.data = new T;
  *element.data = buffer;
  bool after = false;
  if (!isEmpty ())
  {
    theList.first ();
    QueueElement current;
    theList.peek (current);
    while (priority >= current.priority && theList.hasNext()) 
    {
      theList.next ();
      theList.peek (current);
    }
    if (priority >= current.priority)
      after = true;
  }
  if (after)
    theList.insertAfter (element);
  else
    theList.insertBefore (element);
}

template<typename T>
inline T Queue<T>::dequeue (T& buffer, int& priority)
{
  QueueElement freed;
  theList.first ();
  theList.deleteCurrent (freed);
  buffer = *freed.data;
  priority = freed.priority;
  delete freed.data;
  return buffer;
}

template<typename T>
inline T Queue<T>::peek (T& buffer, int& priority)
{
  QueueElement temp;
  theList.peek (temp);
  buffer = *temp.data;
  priority = temp.priority;
}

template<typename T>
inline void Queue<T>::changePriority (const int& change)
{
  theList.first ();
  while (theList.hasNext ())
  {
    QueueElement current;
    theList.peek (current);
    current.priority += change;
    theList.updateCurrent (current);
  }
}
