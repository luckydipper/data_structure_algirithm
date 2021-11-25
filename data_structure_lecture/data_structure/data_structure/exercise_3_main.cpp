#include "PQType_list.h"
#include "Heap.h"
#include <iostream>
using namespace std;

int main()
{
	PQType<int> priority_queue{};
	priority_queue.Enqueue(56);
	priority_queue.Enqueue(27);
	priority_queue.Enqueue(42);
	priority_queue.Enqueue(26);
	priority_queue.Enqueue(15);
	priority_queue.Enqueue(3);
	priority_queue.Enqueue(19);
	priority_queue.Enqueue(25);
	priority_queue.Enqueue(24);
	priority_queue.Enqueue(5);

	//exercise_2 
	priority_queue.Enqueue(28);
	priority_queue.Enqueue(2);
	priority_queue.Enqueue(40);

	//a. 28,27,19,26,15,3,2,25,24,5
	int x, y, z;			   //b.
	priority_queue.Dequeue(x); //x = 56
	priority_queue.Dequeue(y); //y = 42
	priority_queue.Dequeue(z); //z = 40

	cout << x << " " << y << " " << z << endl;
	return 0;
}