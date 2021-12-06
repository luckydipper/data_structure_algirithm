#include "Student.h"
#include <string>
bool operator> (Student l, Student r)
{
	std::string l_string = l.getName();
	std::string r_string = r.getName();
	if (l_string > r_string)
		return true;
	else
		return false;
}

int MinIndex(Student values[], int startIndex, int endIndex)
{
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
	{
		if (values[indexOfMin] > values[index]) // ������ ũ�� 1, �������� ũ�� -1 
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
