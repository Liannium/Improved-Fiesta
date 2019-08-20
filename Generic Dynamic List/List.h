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
    T peekNext (T &buffer);
    void first ();
    void next ();
    void last ();
    void insertAfter (const T &buffer);
    T deleteCurrent (T &buffer);
    void insertBefore (const T &buffer);
    void updateCurrent (T buffer);

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
  while (firstElement)
  {
    currentElement = firstElement->next;
    delete firstElement->data;
    firstElement->data = nullptr;
    delete firstElement;
    firstElement = currentElement;
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
    throw "The list is empty";

  return (currentElement != nullptr);
}

template<typename T>
inline bool List<T>::hasNext ()
{
  if (isEmpty())
    throw "The list is empty";

  return (currentElement->next != nullptr);
}

template<typename T>
inline T List<T>::peek (T& buffer)
{
  if (isEmpty())
    throw "The list is empty";
  if (!hasCurrent())
    throw "The list has no current element";

  buffer = *currentElement->data;
  return buffer;
}

template<typename T>
inline T List<T>::peekNext (T& buffer)
{
  if (isEmpty ())
    throw "The list is empty";
  if (!hasCurrent ())
    throw "The list has no current element";
  if (!hasNext ())
    throw "There is no element after the current element";
  
  buffer = *currentElement->next->data;
  return T ();
}

template<typename T>
inline void List<T>::first ()
{
  if (isEmpty())
    throw "The list is empty";

  currentElement = firstElement;
}

template<typename T>
inline void List<T>::next ()
{
  if (isEmpty ())
    throw "The list is empty";
  if (!hasCurrent())
    throw "The list has no current element";
  if (!hasNext ())
    throw "The list has no next element";

  currentElement = currentElement->next;
}

template<typename T>
inline void List<T>::last ()
{
  if (isEmpty ())
    throw "The list is empty";
  if (!lastElement)
    throw "The last element has not been set";

  currentElement = lastElement;
}

template<typename T>
inline void List<T>::insertAfter (const T& buffer)
{
  if (!isEmpty () && !hasCurrent ())
    throw "The list has no current element";

  if (isEmpty ())
  {
    Element* temp = new Element;
    temp->data = new T;
    *temp->data = buffer;
    firstElement = temp;
    lastElement = temp;
    currentElement = temp;
  }
  else
  {
    Element* temp = currentElement->next;
    currentElement->next = new Element;
    currentElement = currentElement->next;
    currentElement->data = new T;
    *currentElement->data = buffer;
    currentElement->next = temp;
    if (currentElement->next == nullptr)
      lastElement = currentElement;
  }
  numElements++;
}

template<typename T>
inline T List<T>::deleteCurrent (T& buffer)
{
  if (isEmpty ())
    throw "The list is empty";
  if (!hasCurrent ())
    throw "The list has no current element";

  if (currentElement == firstElement)
  {
    buffer = *firstElement->data;
    currentElement = firstElement->next;
    delete firstElement->data;
    firstElement->data = nullptr;
    delete firstElement;
    firstElement = currentElement;
  }
  else {
    Element* temp = firstElement;
    while (temp->next != currentElement)
      temp = temp->next;
    buffer = *currentElement->data;
    temp->next = currentElement->next;
    delete currentElement->data;
    currentElement->data = nullptr;
    delete currentElement;
    currentElement = temp;
  }
  numElements--;
  return buffer;
}

template<typename T>
inline void List<T>::insertBefore (const T& buffer)
{
  if (!isEmpty () && !hasCurrent ())
    throw "The list has no current element";

  if (isEmpty())
    insertAfter (buffer);
  else if (currentElement == firstElement)
  {
    Element* temp = new Element;
    *temp->data = buffer;
    temp->next = firstElement;
    firstElement = temp;
    currentElement = temp;
    numElements++;
  }
  else 
  {
    Element* previous = firstElement;
    while (previous->next != currentElement)
      previous = previous->next;
    Element* element = new Element;
    element->next = currentElement;
    previous->next = element;
    element->data = new T;
    *element->data = buffer;
    numElements++;
  }
}

template<typename T>
inline void List<T>::updateCurrent (T buffer)
{
  if (isEmpty ())
    throw "The list is empty";
  if (!hasCurrent ())
    throw "The list has no current element";

  delete currentElement->data;
  currentElement->data = new T;
  *currentElement->data = buffer;
}
