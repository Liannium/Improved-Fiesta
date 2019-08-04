#pragma once

template <typename T>
class List 
{
  public:
    List ();
    ~List ();
    int size ();
    bool isEmpty ();
    bool hasCurrent ();
    bool hasNext ();
    T peek (T &buffer);
    //T peekNext (T &buffer);
    void first ();
    void next ();
    //void last ();
    void insertAfter (const T &buffer);
    //T deleteCurrent (T &buffer);
    //void insertBefore (const T &buffer);
    //void updateCurrent ();

    class Element {
      public:
        T* data = nullptr;
        Element* next = nullptr;
    };

  private:
    Element* firstElement = nullptr;
    Element* lastElement = nullptr;
    Element* currentElement = nullptr;
    int numElements = 0;
};

template<typename T>
inline List<T>::List ()
{
}

template<typename T>
inline List<T>::~List ()
{
  if (firstElement && lastElement)
  {
    currentElement = nullptr;
    while (firstElement->next)
    {
      Element* temp = firstElement->next;
      delete firstElement->data;
      firstElement->data = nullptr;
      delete firstElement;
      firstElement = temp;
    }
    lastElement = nullptr;
    delete firstElement->data;
    firstElement->data = nullptr;
    delete firstElement;
    firstElement = nullptr;
  }
}

template<typename T>
inline int List<T>::size ()
{
  return numElements;
}

template<typename T>
inline bool List<T>::isEmpty ()
{
  return (numElements == 0);
}

template<typename T>
inline bool List<T>::hasCurrent ()
{
  if (isEmpty())
    throw "The stack is empty";

  return (currentElement);
}

template<typename T>
inline bool List<T>::hasNext ()
{
  if (isEmpty())
    throw "The stack is empty";

  return (currentElement->next);
}

template<typename T>
inline T List<T>::peek (T& buffer)
{
  if (isEmpty())
    throw "The stack is empty";

  buffer = *currentElement->data;
  return buffer;
}

template<typename T>
inline void List<T>::first ()
{
  if (isEmpty())
    throw "The stack is empty";

  currentElement == firstElement;
}

template<typename T>
inline void List<T>::next ()
{
  if (isEmpty ())
    throw "The stack is empty";

  currentElement == currentElement->next;
}

template<typename T>
inline void List<T>::insertAfter (const T& buffer)
{
  if (isEmpty ())
  {
    Element* temp = new Element;
    temp->data = new T;
    *temp->data = buffer;
    firstElement = temp;
    lastElement = temp;
    currentElement = temp;
  }
  else if (lastElement == currentElement)
  {
    currentElement->next = new Element;
    currentElement = currentElement->next;
    currentElement->data = new T;
    *currentElement->data = buffer;
    lastElement = currentElement;
  }
  else
  {
    Element* temp = currentElement->next;
    currentElement->next = new Element;
    currentElement = currentElement->next;
    currentElement->data = new T;
    *currentElement->data = buffer;
    currentElement->next = temp;
  }
  numElements++;
}