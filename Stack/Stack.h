#pragma once
#include <iostream>

template <typename T>
class Stack
{
  public:
    static const int MAX_ELEMENTS = 100;
    static const int EMPTY = 0;

    bool isFull ()
	{
		if (size == MAX_ELEMENTS)
			return true;

		return false;
	};
    bool isEmpty ()
	{
		if (size == EMPTY)
			return true;
		return false;
	};
    void push (T* buffer)
	{
		if (isFull())
		{
			std::cout << "The stack is full \n";
			return;
		}
		T* temp = new T;
		*temp = *buffer;
		data[size] = temp;
		size++;
	};
    T* pop (T* buffer)
	{
		if (isEmpty())
		{
			std::cout << "The stack is empty \n";
			return nullptr;
		}
		T* temp = new T;
		*temp = *data[size];
		buffer = temp;
		size--;
		return buffer;
	}
	;
    // T* peek (T* buffer);
    int getSize ()
	{
		return size;
	}
	;

  private:
    T* data[MAX_ELEMENTS];
    int size = EMPTY;
};
