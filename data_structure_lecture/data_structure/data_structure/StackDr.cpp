// Test driver

#include "StackType.h"
#include <iostream>
using namespace std;

void ReplaceItem(StackType& stack, const ItemType& oldItem, const ItemType& newItem);

int main()
{
	StackType stack{};
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	
	StackType stack2{};
	stack2.Push(4);
	stack2.Push(3);
	stack2.Push(2);
	stack2.Push(1);

	ReplaceItem(stack, 2, 1);
	
	while (!stack.IsEmpty())
	{
		cout << stack.Top();
		stack.Pop();
	}
}

void ReplaceItem(StackType& stack, const ItemType& oldItem, const ItemType& newItem)
{
	// 
	StackType inversed_stack{};
	while (!stack.IsEmpty())
	{
		inversed_stack.Push(stack.Top());
		stack.Pop();
	}

	// Replace old item
	while (!inversed_stack.IsEmpty())
	{
		if (inversed_stack.Top() == oldItem)
		{
			stack.Push(newItem);
			inversed_stack.Pop();
			continue;
		}
		stack.Push(inversed_stack.Top());
		inversed_stack.Pop();
	}
}
