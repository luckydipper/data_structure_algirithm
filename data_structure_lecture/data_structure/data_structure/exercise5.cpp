#include "Student.h"
#include <iostream>
#include "HeapSort.h"

using namespace std;

int main(char argc, char* argv[])
{
	int example_arr[] = { 25, 17, 36, 2, 3, 100, 1, 19, 7 };
	int exam_length = sizeof(example_arr) / sizeof(int);
	HeapSort_print(example_arr, exam_length);

	return 0;
}