#pragma once

template <typename T>
class Node {
  Node ();
  ~Node ();

  T* data;
  Node* next;
};

template<typename T>
Node<T>::Node ()
{
  data = nullptr;
  next = nullptr;
}

template<typename T>
inline Node<T>::~Node ()
{
  delete data;
  delete next;
}