
#include <stdio.h>
void reculsive_example(int called_num);
int factorial(int num);
int fibonacci(int index);

int binarySearch(int* const sorted_range,
	int const target,
	int first_index, int last_index);

// call relation is more important then call sequence





void hanoi(int stack_size, int const from_stack, char const passing_stack, char const to_stack);


enum stack_name {
	A = 1,
	B,
	C
};



int main()
{
	reculsive_example(0); // 0 -> 4
	int factor_result = factorial(5); // 120
	printf("%d\n", factor_result);
	int fibo_result = fibonacci(5); // 5
	printf("%d\n", fibo_result);

	int sorted_arr[] = { 1, 5, 7, 8, 10, 25, 36, 65, 100 };
	int bin_index = binarySearch(sorted_arr, 65, 0, sizeof(sorted_arr) / sizeof(int) - 1 );
	printf("%d\n", bin_index); // 7

	hanoi(3, 'A', 'B', 'C');

 	return 0;
}
