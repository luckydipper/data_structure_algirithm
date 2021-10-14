#ifndef __Queue_template_10_12__
#define __Queue_template_10__
#include <cstdlib>
#include <cstring>
class FullQueue
{};  

class EmptyQueue
{};  
typedef int ItemType;

template <typename T>
class QueType
{
public: 
    QueType();
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.
    QueType(int max);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
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
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
    void ReplaceItem(ItemType oldItem, ItemType newItem);
    bool Identical(const QueType& queue) const;
    int Length() const;

    // Linear search algorithm O(N) = N
    const ItemType MinDequeue();
    void copy_element(const QueType<T> &copier); // memcpy (stack이 관리해주도록 메모리 내용만 copy)

private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
};

template <typename T>
QueType<T>::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}

template <typename T>
QueType<T>::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}

template <typename T>
QueType<T>::~QueType()         // Class destructor
{
    delete[] items;
}

template <typename T>
void QueType<T>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

template <typename T>
bool QueType<T>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

template <typename T>
bool QueType<T>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return ((rear + 1) % maxQue == front);
}

template <typename T>
void QueType<T>::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
    if (IsFull())
        throw FullQueue();
    else
    {
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
    }
}

template <typename T>
void QueType<T>::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}

template <typename T>
void QueType<T>::ReplaceItem(ItemType oldItem, ItemType newItem)
{
    for (int i = 0; i < this->Length() -1 ; i++)
    {
        if (items[i] == oldItem)
            items[i] = newItem;
    }
}


// caution queue sequence will be broken
template <typename T>
bool QueType<T>::Identical(const QueType& queue) const
{
    if (queue.Length() != this->Length())
        return false;
    QueType<T> temp_que(maxQue-1);
    temp_que.copy_element(queue);

    int length = queue.Length();
    for (int i = 0; i < length -1; i++)
    {
        int iterator = ((front + 1 + i) % maxQue);

        ItemType temp;
        temp_que.Dequeue(temp);// 왜 API가 이따위지

        if (temp != queue.items[iterator])
        {
            return false;
        }
    }
    return true;
}


// I want to make stack deep copy
template <typename T>
void QueType<T>::copy_element(const QueType<T> & src)
{
    this->front  = src.front;
    this->rear   = src.rear;
    this->maxQue = src.maxQue;
    //memcpy(&items, &src.items, sizeof(T)*Length());
    for (int i = 0; i < src.Length(); i++)
    {
        this->items[i] = src.items[i];
    }
}

template <typename T>
int QueType<T>::Length() const
{
    int length = 0;

    if (front > rear)
        length = maxQue - front + rear;
    else if (front < rear)
        length = rear - front;
    else
        length = 0;

    return length;
}


template <typename T>
const ItemType QueType<T>::MinDequeue()
{
    // Find smallest index
    int* iterator_ptr = items + ((front + 1)%maxQue); // first indicate null
    int smallest_val_index = ((front + 1) % maxQue);   // indicating first value
    int i = 1;
    while (iterator_ptr != items + rear)
    {
        int checking_index = ((front + i++) % maxQue);
        iterator_ptr = items + checking_index;
        if (*iterator_ptr < items[smallest_val_index])
            smallest_val_index = checking_index;
    }
    const int small_val_result = items[smallest_val_index];


    // Remove small value
    iterator_ptr = items + smallest_val_index;
    i = 1;
    while (iterator_ptr != items + rear)
    {
        *iterator_ptr = *(items + ((smallest_val_index + i) % maxQue));
        iterator_ptr = items + ((smallest_val_index + i++) % maxQue);
    }
    rear--;
    return small_val_result;
}

#endif // Queue_template_10_12
