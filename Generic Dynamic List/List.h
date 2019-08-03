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
    bool hasCurrent ();
    bool hasNext ();
    T peek ();
    T peekNext ();
    void first ();
    void next ();
    void last ();
    void insertAfter ();
    void deleteCurrent ();
    void insertBefore ();
    void updateCurrent ();

    class Element {
      public:
        T* data = nullptr;
        Element* next = nullptr;
    };

  private:
    Element* first = nullptr;
    Element* last = nullptr;
    Element* current = nullptr;
    int numElements = 0;
};