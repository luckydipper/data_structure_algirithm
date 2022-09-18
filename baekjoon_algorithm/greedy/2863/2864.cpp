#include <iostream>

int changeNumber(int check_num, int from, int to)
{
	int sixed_num = 0;
	
	for(int pow_num=1; pow_num <= check_num; pow_num *= 10 )
	{
		int coefficient = check_num / pow_num % 10;
		if( coefficient == from)
		{
			coefficient = to;
		}
		sixed_num += coefficient * pow_num;
	}
	return sixed_num;
}

int main()
{
	int A, B;
	std::cin >> A >> B;
	std::cout << changeNumber(A,6,5) + changeNumber(B,6,5) << std::endl;
	std::cout << changeNumber(A,5,6) + changeNumber(B,5,6) << std::endl;
	return 0;
}
