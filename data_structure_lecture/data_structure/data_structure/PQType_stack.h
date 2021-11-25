#pragma once
// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ{};
class EmptyPQ{};
#include "heap.h"
template<class ItemType>
class PQType
{
public:
  PQType();          // parameterized class constructor
  PQType(int);          // parameterized class constructor
  ~PQType();            // class destructor
  
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  
  void Enqueue(ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.
  
  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
  HeapType<ItemType> items;
private:
  int length;
  int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType()
{
    items.elements = new ItemType[1000];
    length = 0;
}
template<class ItemType>
PQType<ItemType>::PQType(int max)
{
  maxItems = max;
  items.elements = new ItemType[max];
  length = 0;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
  delete [] items.elements;
}
template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
    item = items.elements[0];
    items.elements[0] = items.elements[length-1];
    length--;
    items.ReheapDown(0, length-1);
  }
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is in the queue.
{
  if (length == maxItems)
    throw FullPQ();
  else
  {
    length++;
    items.elements[length-1] = newItem;
    items.ReheapUp(0, length-1);
  }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return length == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}



template <typename T>
struct Node
{
	T info;
	int time_priority;
	bool operator<(const Node& node);
	bool operator<=(const Node& node);
};

template <typename T>
bool Node<T>::operator<(const Node& node)
{
	return this->time_priority < node.time_priority;
}
template <typename T>
bool Node<T>::operator<=(const Node& node)
{
	return this->time_priority <= node.time_priority;
}

template <typename T>
class Stack
{
private:
	PQType<Node<T>> priority_queue;
	static int time_stamp;
public:
	Stack();
	void Push(T elem);
	T Top() const;
	void Pop();
};

template <typename T>
int Stack<T>::time_stamp = 0;

template <typename T>
Stack<T>::Stack()
{
	time_stamp = 0;
	PQType<Node<T>> priority_queue(100);
}

template <typename T>
void Stack<T>::Push(T elem)
{
	time_stamp++;
	Node<T> added{};
	added.info = elem;
	added.time_priority = time_stamp;
	priority_queue.Enqueue(added);
}

template <typename T>
void Stack<T>::Pop()
{
	Node<T> del;
	priority_queue.Dequeue(del);
}

template <typename T>
T Stack<T>::Top() const
{
	return priority_queue.items.elements[0].info;
}
