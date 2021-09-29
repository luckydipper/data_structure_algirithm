#include <iostream>
using namespace std;

//return equal or smaller value in the array
int BinarySearch(int array[], int length, int value)
{
	int first_index = 0;
	int last_index = length - 1;
	while (first_index <= last_index)
	{
		int middle_index = (first_index + last_index) / 2;

		if (array[middle_index] == value)
			return middle_index;
		else if (array[middle_index] > value)
			last_index = middle_index - 1;
		else if (array[middle_index] < value)
			first_index = middle_index + 1;
	}
	if (array[last_index] < value && value < array[last_index+1])
		return array[last_index];
	else
		return array[last_index + 1];
}


int main()
{
	int array[] = { 1,3,5,6,8,13,16,28,29,999 };
	for (const int &tem : array)
		cout << tem << ", ";
	int find_value = 30;
	cout << "\nIn that array, find value :" << find_value << endl;
	int value = BinarySearch(array, sizeof(array) / sizeof(array[0]), find_value);
	cout << "Equal or smaller value in the array is " << value <<endl;
}
