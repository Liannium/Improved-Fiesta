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

    class queueElement
    {
      int priority;
      T* data;
    };
  private:
    List<queueElement> theList;
};

template<typename T>
inline Queue<T>::Queue ()
{

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
  queueElement* element = new queueElement;
  *element->priority = priority;
  element->data = new T;
  *element->data = buffer;
  if (theList.isEmpty ())
    theList.insertAfter (element);
  else {
    theList.first ();
    queueElement current = theList.peek ();
    while (priority >= current.priority) 
    {
      theList.next ();
      current = list.peek;
    }
    theList.insertBefore (element);
  }
}
