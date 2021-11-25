#include "PQType.h"
#include "Heap.h"
#include <iostream>

int main()
{
	PQType<int> priority_queue(100);
	priority_queue.Enqueue(5);
	priority_queue.Enqueue(20);
	priority_queue.Enqueue(10);
	priority_queue.Enqueue(1);
	priority_queue.Enqueue(3);
	priority_queue.Enqueue(7);
	priority_queue.Enqueue(80);
	priority_queue.Enqueue(0);
	
	int val;
	for (int i = 0; i < 8; i++)
	{
		priority_queue.Dequeue(val);
		std::cout << val << ", ";
	}
	return 0;
}