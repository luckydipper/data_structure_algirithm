#include "PQType_stack.h"
#include <iostream>

int main()
{
	Stack<int> stack{};
	stack.Push(1);
	stack.Push(6);
	stack.Push(7);
	stack.Push(864);
	stack.Push(0);
	
	for (int i = 0; i < 5; i++)
	{
		int item = stack.Top();
		stack.Pop();
		std::cout << item << std::endl;
	}

	return 0;
}
// 4장에서 구현된 Push, Pop 연산과 위의 두 연산을 Big - O 개념으로 비교하여라.
// 원래 linked list로 구현됐던 stack의 Push 와 Pop은 log(1)이었다.
// priority queue로 stack을 구현하면 push와 pop에 log(N)의 복잡도가 된다. 

