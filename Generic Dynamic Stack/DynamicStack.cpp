#include "DynamicStack.h"

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