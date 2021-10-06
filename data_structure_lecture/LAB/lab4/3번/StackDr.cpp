// Test driver
#include <iostream>
#include <fstream>

#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& st, int oldItem, int newItem)
{
	StackType dumy{};

	// dumy is Inverse stack.. -> 차라리 변수 이름을 inverse stack으로 지을걸
	while (!st.IsEmpty())
	{
		int top = st.Top();
		if (top == oldItem)
			dumy.Push(newItem);
		else
			dumy.Push(top);
		st.Pop();
	}

	while (!dumy.IsEmpty())
	{
		int top = dumy.Top();
		if (top == oldItem)
			st.Push(newItem);
		else
			st.Push(top);
		dumy.Pop();
	}
	
}

int main()
{
	StackType st{};
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);

	ReplaceItem(st, 3, 0);
	st.ReplaceItem(2, 16);
}


