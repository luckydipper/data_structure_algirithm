#include "QueType.h"
#include <iostream>
using namespace std;
int Length(const QueType<int> &queue);

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
    //que2.Enqueue(5);
    //cout << Identical(que1, que2);
    cout << Length(que2);

    return 0;

}

int Length(const QueType<int> &queue)
{
    
    int length = 0;
    QueType<int> temp_que;
    temp_que.copy_element(queue);

    while (!temp_que.IsEmpty())
    {
        length++;
        ItemType temp;
        temp_que.Dequeue(temp);
    }

    return length;
}