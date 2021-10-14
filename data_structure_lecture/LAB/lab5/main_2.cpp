#include "QueType.h"
#include <iostream>
using namespace std;

void ReplaceItem(QueType<int>& queue, int oldItem, int newItem);

int main()
{
    QueType<int> que(15);

    // Enqueue the random value
    for (int i = 0; i < 10; ++i)
    {
        que.Enqueue(i);
    }
    que.Enqueue(10);

    ReplaceItem(que, 10, 116551);

    que.ReplaceItem(1, 153);

    while (!que.IsEmpty())
    {
        ItemType temp;
        que.Dequeue(temp);
        cout << temp << endl;
    }
}

void ReplaceItem(QueType<int>& queue, int oldItem, int newItem)
{
    // There are no pointers or references in the Queue member variable.
    // So it's ok to use copy constructor. ie, Shallow copy 
    QueType<int> temp;    
    
    while (!queue.IsEmpty())
    {
        ItemType check_item;
        queue.Dequeue(check_item);

        // Change old item -> new item
        if (check_item != oldItem)
            temp.Enqueue(check_item);
        else
            temp.Enqueue(newItem);
    }

    while (!temp.IsEmpty())
    {
        ItemType check_item;
        temp.Dequeue(check_item);
        queue.Enqueue(check_item);
    }
}