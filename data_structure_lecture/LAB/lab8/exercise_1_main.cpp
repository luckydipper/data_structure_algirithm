#include <iostream>
#include "UnsortedType.h"


int main()
{
    UnsortedType<int> students_score;
    students_score.InsertItem(5);
    students_score.InsertItem(2);
    students_score.InsertItem(3);
    students_score.InsertItem(1);
    students_score.PrintSumSquares();
}