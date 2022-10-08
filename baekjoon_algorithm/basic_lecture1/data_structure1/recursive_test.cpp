#include <iostream>
using namespace std;

int foo(int a)
{
	cout << 'b' << a << '\n';
	if(a == 100)
		return a;
	foo(++a);
	cout << 'a' << a << '\n';
	a = -2;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "result : " << foo(0) << '\n';
}