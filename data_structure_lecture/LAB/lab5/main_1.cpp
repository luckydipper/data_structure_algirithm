#include "QueType.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    
    QueType<int> que(15);

    // Enqueue the random value
    srand(5);
    for (int i = 0; i < 10; i++)
    {
        int random_value = rand();
        que.Enqueue(random_value);
    }
    
    // Dequeue the value
    while (!que.IsEmpty())
    {
        ItemType temp;
        que.Dequeue(temp);
        cout << temp << endl;
    }

    return 0;
}