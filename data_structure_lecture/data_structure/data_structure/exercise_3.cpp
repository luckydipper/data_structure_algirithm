#include "Student.h"
#include <iostream>
using namespace std;

int SelectMinStudentIndex(Student* values[], const int numValues, const int zero2this_index_sorted)
{
	int min_index = zero2this_index_sorted;
	for (int searching_index = zero2this_index_sorted; searching_index < numValues; searching_index++)
		if (*values[searching_index] < *values[min_index])
			min_index = searching_index;
	return min_index;
}

void SelectionSortPointer(Student* values[], int numValues)
{
	int zero2this_index_sorted = 0;
	for (zero2this_index_sorted; zero2this_index_sorted < numValues; zero2this_index_sorted++)
	{
		int min_index = SelectMinStudentIndex(values, numValues, zero2this_index_sorted);
		Swap(values[min_index], values[zero2this_index_sorted]);
	}
}

int main()
{
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"ÀÌ¿õÀç", 3.0);
	stu[1].InitValue(2004200121, (char*)"±Ç¿ÀÁØ", 3.0);
	stu[2].InitValue(2005200132, (char*)"±èÁøÀÏ", 3.0);

	Student* stuPtrs[3];
	for (int k = 0; k < 3; k++)
		stuPtrs[k] = &stu[k];
	SelectionSortPointer(stuPtrs, 3);
	PrintByPointer(cout, stuPtrs, 3);
	return 0;
}
