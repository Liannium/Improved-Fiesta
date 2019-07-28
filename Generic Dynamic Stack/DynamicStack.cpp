#include "DynamicStack.h"

template<typename T>
inline DynamicStack<T>::Node::~Node ()
{
  delete data;
  data = nullptr;
  delete next;
  next = nullptr;
}