#include "StackType.h"
#include <iostream>

using namespace std;

int main()
{
	StackType stack;
	stack.Push(3);
	stack.Push(2);
	stack.Push(1);
	stack.Push(62);
	stack.Push(100);
	stack.Push(0);
	StackType stack2;
	stack2.Copy(stack);
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	while (!stack2.IsEmpty())
	{
		cout << stack2.Top() <<endl;
		stack2.Pop();
	}
	return 0;
}