#include "QueType.h"
#include <iostream>
#include <stdbool.h>
using namespace std;

// !!Caution!! queue will be reset
bool Identical(const QueType<int>& queue1, const QueType<int>& queue2);

int main()
{
    QueType<int> que1(15);
    QueType<int> que2(15);
    // Enqueue the random value
    for (int i = 0; i < 10; ++i)
    {
        que1.Enqueue(i);
        que2.Enqueue(i);
    }
    int a;
    que2.Dequeue(a);
    que2.Enqueue(5);
    cout << Identical(que1, que2) <<endl;
    cout << Identical(que1, que2) << endl;
    
    que1.Dequeue(a);
    que1.Enqueue(5);
    //cout << Identical(que1, que2);
    cout << Identical(que1, que2) << endl;
    cout << que2.Identical(que1) << endl;



    return 0;
}

bool Identical(const QueType<int>& queue1,const QueType<int>& queue2)
{
    if (queue1.Length() != queue2.Length())
        return false;

    // While one of the queue is empty
    QueType<int> temp1, temp2;
    temp1.copy_element(queue1);
    temp2.copy_element(queue2);

    while (!temp1.IsEmpty())
    {
        ItemType check1, check2;
        temp1.Dequeue(check1);
        temp2.Dequeue(check2);
        if (check1 != check2)
            return false;
    }
    return true;
}
