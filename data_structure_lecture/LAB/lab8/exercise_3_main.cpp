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
{
	while (fabs(approx * approx - number) > tol)
	{
		approx = (approx * approx + number) / (2 * approx);
	}
	return approx;
}