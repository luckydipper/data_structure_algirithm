#include "UnsortedType.h"
#include <iostream>
using namespace std;

int main()
{
    UnsortedType<int> students_score;
    students_score.InsertItem(5);
    students_score.InsertItem(2);
    students_score.InsertItem(3);
    students_score.InsertItem(1);
    students_score.Sort(students_score.listData);
    students_score;
	return 0;
}