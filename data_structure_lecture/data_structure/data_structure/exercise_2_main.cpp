// 재귀버전은 성능을 향상시키지 않는다. function call overhead가 있기 때문이다.
// 재귀는 stack에 여러번 쌓여서 실행 돼야 하는데, stack overflow가 날 수 도 있다.
// 하지만 코드의 가독성 때문에 recursive를 쓴다.

#include <iostream>
using namespace std;

int Fibonacci_recursive(int n);
int FIbonacci_non_recursive(int n);

//A. 재귀 버전으로
int Fibonacci_recursive(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
}

int FIbonacci_non_recursive(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;

	int before = 1, result = 2;
	for (int i = 3; i < n; i++)
	{
		int temp = result;
		result += before ;
		before = temp;
	}
	return result;
}


int main()
{
	cout << Fibonacci_recursive(10) << endl;
	cout << FIbonacci_non_recursive(10) << endl;
}