#pragma once

template <typename T>
class DynamicStack
{
  public:
    static const int EMPTY = 0;

    DynamicStack ();
    //~DynamicStack ();
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

template<typename T>
inline DynamicStack<T>::DynamicStack ()
{
  top = nullptr;
  size = 0;
}

template<typename T>
bool DynamicStack<T>::isEmpty ()
{
  if (size == EMPTY)
    return true;
  return false;
}

template<typename T>
void DynamicStack<T>::push (T buffer)
{
  T* temp = new T;
  *temp = buffer;
}

template<typename T>
int DynamicStack<T>::getSize ()
{
  return size;
}

template<typename T>
inline DynamicStack<T>::Node::~Node ()
{
  delete data;
  delete next;
  data = nullptr;
  next = nullptr;
}