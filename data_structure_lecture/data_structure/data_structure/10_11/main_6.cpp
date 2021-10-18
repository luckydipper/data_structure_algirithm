#include "QueType.h"
#include <iostream>
using namespace std;

int main()
{
    QueType<int> que(15);
    
    que.Enqueue(64);
    que.Enqueue(32);
    que.Enqueue(0);
    que.Enqueue(2);
    que.Enqueue(256);
    que.Enqueue(512);

    for (int i =0; i<6;i++)
        cout << que.MinDequeue() << endl;
}