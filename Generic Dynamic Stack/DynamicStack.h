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
    class Node {
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
  T* temp = new T;
  *temp = buffer;
  if (top == nullptr)
  {
    top = new Node;
    top->data = temp;
  }
  else
  {
    Node* node = top;
    while (node->next)
      node = node->next;
    node->next = new Node;
    node->data = temp;
  }
  size++;
}

template<typename T>
inline T DynamicStack<T>::pop (T buffer)
{
  if (isEmpty ())
    throw "The stack is empty";

  Node* node = top;
  if (size == 1)
  {
    *top->data = buffer;
    delete top;
    top = nullptr;
  }
  else
  {
    Node* node = top;
    while (node->next->next)
      node = node->next;
    *node->next->data = buffer;
    delete node->next->data;
    node->next->data = nullptr;
    delete node->next;
    node->next = nullptr;
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
inline DynamicStack<T>::Node::~Node ()
{
  delete data;
  delete next;
  data = nullptr;
  next = nullptr;
}