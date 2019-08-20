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
    void changePriority (int& change);

    class QueueElement
    {
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
    QueueElement temp;
    dequeue (temp);
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
  QueueElement* element = new QueueElement;
  *element->priority = priority;
  element->data = new T;
  *element->data = buffer;
  if (!isEmpty ())
  {
    theList.first ();
    QueueElement current = theList.peek ();
    while (priority >= current.priority) 
    {
      theList.next ();
      current = theList.peek();
    }
  }
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
