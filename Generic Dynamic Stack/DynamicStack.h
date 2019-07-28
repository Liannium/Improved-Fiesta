#pragma once

template <typename T>
class DynamicStack
{
  public:
    DynamicStack ();
    ~DynamicStack ();
    void push (T buffer);
    T pop (T buffer);
    T peek (T buffer);
    int getSize ();

  private:
    class Node {
      Node ();
      ~Node ();

      T* data;
      Node* next;
    };

    Node* top;
    int size;
};