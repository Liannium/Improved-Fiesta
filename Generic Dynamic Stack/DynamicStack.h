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
    T pop (T &buffer);
    T peek (T &buffer);
    int getSize ();
    class Node {
      public:
        Node ();
        ~Node ();

        T* data = nullptr;
        Node* next = nullptr;
    };

  private:
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
  if (size == 0)
  {
    top = new Node;
    top->data = new T;
    *top->data = buffer;
  }
  else
  {
    Node* node = new Node;
    node->data = new T;
    *node->data = buffer;
    node->next = top;
    top = node;
  }
  size++;
}

template<typename T>
T DynamicStack<T>::pop (T &buffer)
{
  if (isEmpty ())
    throw "The stack is empty";

  if (size == 1)
  {
    buffer = *top->data;
    delete top;
    top = nullptr;
  }
  else
  {
    Node* node = top;
    top = top->next;
    buffer = *node->data;
    delete node->data;
    node->data = nullptr;
    delete node;
    node = nullptr;
  }
  size--;
  return buffer;
}

template<typename T>
int DynamicStack<T>::getSize ()
{
  return size;
}

template<typename T>
inline DynamicStack<T>::Node::Node ()
{
}

template<typename T>
inline DynamicStack<T>::Node::~Node ()
{
  delete data;
  data = nullptr;
}