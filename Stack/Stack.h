#pragma once
template <typename T>
class Stack
{
  public:
    static const int MAX_ELEMENTS = 100;
    static const int EMPTY = 0;

    Stack ();
    ~Stack ();
    bool isFull ();
    bool isEmpty ();
    void push (T* buffer, int size);
    T* pop (T* buffer, int size);
    T* peek (T* buffer, int size);
    int size ();

  private:
    T* data[MAX_ELEMENTS];
    int size;
};