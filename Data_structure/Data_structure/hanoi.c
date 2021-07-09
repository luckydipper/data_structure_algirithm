#include <stdio.h>

void reculsive_example(int called_num)
{
	// end condition 
	if (called_num > 3)
		return;
	called_num++;

	printf("%d \n", called_num);
	reculsive_example(called_num);
	printf("%d end\n", called_num);
}


int factorial(int num)
{
	// end condition
	if( num == 0 )
		return 1;

	// error occur
	if( num < 0 )
		return -1;

	// 
	return num * factorial(num - 1);
}


int fibonacci(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;

	return fibonacci(index - 1) + fibonacci(index - 2);
}



int getMidum(int first_index, int last_index)
{
	int medium = (first_index + last_index) / 2;
	return 0;
}


// range_len은 받을 필요 없다. pointer는 arr의 크기를 갖고 있지 않기 때문에 받음.
// 하지만 마지막 index를 받는 시점에서 last index + 1이 size가 됨.
// int const range_len,
int binarySearch(int* const sorted_range, 
	             int const target,
	             int first_index, int last_index)
{
	// error
	if (first_index > last_index)
		return -1;
	
	int medium_index = (first_index + last_index) / 2;
	int medium_val = sorted_range[medium_index];
	
	if (medium_val == target)
		return medium_index;

	//else를 넣지 않으면 뒤에 것 까지 실행. 아니면, binarySearch 앞에 return을 붙히기!
	else if (medium_val < target)
		return binarySearch(sorted_range, target, /*first_index =*/medium_index + 1, last_index);
	
	else if (medium_val > target)
	    return binarySearch(sorted_range, target, first_index, /*last_index =*/ medium_index - 1);
}


void hanoi(int stack_size, int const from_stack, char const temporal_stack, char const to_stack)
{
	//global variable should be formated constant
	/*int static to_stack_size = 0;
	if (stack_size == to_stack_size)
		return;*/

	//stack size가 1이 될 때까지 반복함.
	if (stack_size == 1)
	{
		printf("%d번째 판을 %c에서 %c로. \n", stack_size, from_stack, to_stack);
	}
	else // 순서도 바꾸면 안됨? 너무 발상적인거 아닌가?
	{// 맨 아래 하노이 타워를 옮기기 위해서는 상위 하노이 타워부터 치워야함. 
	 // stack이 1이 될때까지 상위 타워를 찾음.
		hanoi(stack_size - 1, from_stack, to_stack, temporal_stack);
		printf("%d번째 판을 %c에서 %c로. \n", stack_size, from_stack, to_stack);
		hanoi(stack_size - 1, temporal_stack, from_stack, to_stack);
	}
}
