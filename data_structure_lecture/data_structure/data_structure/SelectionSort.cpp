#include "Student.h"
#include <string>

int MinIndex(Student values[], int startIndex, int endIndex)
{
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
	{
		if (values[indexOfMin] > values[index]) // 왼쪽이 크면 1, 오른쪽이 크면 -1 
			indexOfMin = index;
	}
	return indexOfMin;
}

void SelectionSort(Student values[], int numValues)
{
	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
		Swap(values[current], values[MinIndex(values, current, endIndex)]);
}
