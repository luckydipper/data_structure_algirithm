#include "counted_queue.hpp"
#include <iostream>

using namespace std;

int main()
{
    CountedQueue queue1{ /*max capacity = */15 };
    CountedQueue queue2{ /*max capacity = */15 };
    for (int i = 0; i < 15; i++)
    {
        queue1.Enqueue(i);
        queue2.Enqueue(i);
    }

    for (int i = 0; i < 15; i++)
    {
        cout << queue1.Dequeue() <<endl;
    }

}