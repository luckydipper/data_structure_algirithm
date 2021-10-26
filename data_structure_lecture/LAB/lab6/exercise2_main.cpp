#include <iostream>
#include "QueType.h"
using namespace std;

void ReplaceItem(QueType<ItemType>& queue, const ItemType& oldItem, const ItemType& newItem);

int main()
{
	QueType<int> que{};
	que.Enqueue(5);
	que.Enqueue(5);
	que.Enqueue(5);
	que.Enqueue(5);
	que.Enqueue(5);
	que.Enqueue(1);
	que.Enqueue(2);
	que.Enqueue(3);
	ReplaceItem(que, 5, 100);
	que.ReplaceItem(3, 9464);
	while (!que.IsEmpty())
	{
		ItemType temp;
		que.Dequeue(temp);
		cout << temp << endl;
	}
	return 0;
}

void ReplaceItem(QueType<ItemType>& queue, const ItemType& oldItem, const ItemType& newItem)
{
	QueType<ItemType> removed_old_item;
	while (!queue.IsEmpty())
	{
		ItemType temp;
		queue.Dequeue(temp);
		if (temp == oldItem)
			removed_old_item.Enqueue(newItem);
		else
			removed_old_item.Enqueue(temp);
	}

	while (!removed_old_item.IsEmpty())
	{
		ItemType temp;
		removed_old_item.Dequeue(temp);
		queue.Enqueue(temp);
	}
}