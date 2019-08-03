#pragma once

template <typename T>
class List 
{
  public:
    List ();
    ~List ();
    int size ();
    bool isFull ();
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
List<T>::List ()
{
}