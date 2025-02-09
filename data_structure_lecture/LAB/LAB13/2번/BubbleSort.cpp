#include "Student.h"
#include "BubbleSort.h"



void BubbleUp(Student values[], int startIndex, int endIndex)
{
	for (int index = endIndex; index > startIndex; index--)
		if (values[index - 1] > values[index])
			Swap(values[index], values[index - 1]);
}

void BubbleSort(Student values[], int numValues)
{
	int current = 0;
	while (current < numValues - 1)
	{
		BubbleUp(values, current, numValues - 1);
		current++;
	}
}