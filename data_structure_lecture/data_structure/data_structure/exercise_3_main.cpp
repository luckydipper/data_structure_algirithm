#include <iostream>
#include <cmath>
using namespace std;

float SqrRoot_recursion(float number, float approx, float tol)
{
	bool in_the_tolerance = fabs(approx * approx - number) <= tol;
	if (in_the_tolerance)
		return approx;
	else
		return SqrRoot_recursion(number, (approx * approx + number) / (2 * approx), tol);
		// 여기에 return이 없으면, stack에서 빼는 도중에 approx 값이 바뀜
}

float SqrRoot_non_recursion(float number, float approx, float tol)
{
	while (fabs(approx * approx - number) > tol)
	{
		approx = (approx * approx + number) / (2 * approx);
	}
	return approx;
}

int main()
{
	cout << SqrRoot_recursion(2., 1., 0.1) << endl;
	cout << SqrRoot_non_recursion(2., 1., 0.1) << endl;
	return 0;
}