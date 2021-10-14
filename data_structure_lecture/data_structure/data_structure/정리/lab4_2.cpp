#include <iostream>
using namespace std;

const int MAX_ITEMS = 200;

class doublestack
{
private:
	int top_small; //1000보다 작거나 같은 스택의 top
	int top_big; // 1000보다 큰 스택의 top
	int items[MAX_ITEMS];
public:
	doublestack();
	void Push(int item); //C에서 구현할 push 연산
	void Print(); //stack 의 상황을 보여줄 수 있는 함수(채점시)
	bool IsFull()const;
};

doublestack::doublestack()
{
	top_small = -1;
	top_big = -1;
}

void doublestack::Push(int item)
{
	if (IsFull()) //error
	{
		cout << "Stack Overflow" << endl;
		return;
	}

	if (item <= 1000)
		items[++top_small] = item;
	else if (item > 1000)
		items[MAX_ITEMS - 1 - (++top_big)] = item;
}

void doublestack::Print()
{
	cout << "small stack" << endl;
	for (int i = 0; i <= top_small; i++)
		cout << "| " << items[i] << " |";
	//const int MAX_ITEMS = 200;
	cout << " <= push & pop";
	cout << "\n\n";

	cout << "big stack" << endl;
	for (int i = MAX_ITEMS - 1; i >= MAX_ITEMS - 1 - top_big; i--)
		cout << "| " << items[i] << " |";
	cout << " <= push & pop";
	cout << "\n";
}

bool doublestack::IsFull() const
{
	if (top_big + top_small >= 200)
		return true;
	else
		return false;
}

int main()
{
	doublestack a{};
	a.Push(100);
	a.Push(2000);
	a.Push(0);
	a.Push(1001);
	a.Push(1001);
	a.Push(1001);

	a.Print();
	return 0;
}