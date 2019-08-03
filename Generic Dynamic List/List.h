#pragma once

template <typename T>
class List 
{
  public:
    List ();
    ~List ();
    int size ();
    bool isEmpty ();
    //bool hasCurrent ();
    //bool hasNext ();
    //T peek ();
    //T peekNext ();
    void first ();
    void next ();
    //void last ();
    void insertAfter ();
    //void deleteCurrent ();
    //void insertBefore ();
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
inline void List<T>::first ()
{
  currentElement == firstElement;
}

template<typename T>
inline void List<T>::next ()
{
  currentElement == currentElement->next;
}