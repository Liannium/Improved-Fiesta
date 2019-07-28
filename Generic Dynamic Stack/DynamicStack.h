#pragma once

template <typename T>
class DynamicStack
{
  public:
    static const int EMPTY = 0;

    DynamicStack ();
    ~DynamicStack ();
    bool isEmpty ();
    void push (T buffer);
    T pop (T buffer);
    T peek (T buffer);
    int getSize ();

  private:
    class Node {
      Node ();
      ~Node ();

      T* data = nullptr;
      Node* next = nullptr;
    };

    Node* top;
    int size;
};