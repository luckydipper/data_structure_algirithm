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
// 4�忡�� ������ Push, Pop ����� ���� �� ������ Big - O �������� ���Ͽ���.
// ���� linked list�� �����ƴ� stack�� Push �� Pop�� log(1)�̾���.
// priority queue�� stack�� �����ϸ� push�� pop�� log(N)�� ���⵵�� �ȴ�. 

