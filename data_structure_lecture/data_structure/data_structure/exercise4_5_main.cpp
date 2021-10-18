#include <iostream>
#include "UnsortedType.h"
#include "SortedType.h"
using namespace std;

int main()
{
	SortedType<int> s1{};
	s1.InsertItem(85);
	s1.InsertItem(85);
	s1.InsertItem(1);
	s1.InsertItem(2);
	s1.InsertItem(3);
	s1.InsertItem(4);
	s1.InsertItem(810);
	s1.InsertItem(4);
	s1.InsertItem(3);
	s1.InsertItem(3);
	s1.InsertItem(85);

	s1.DeleteItem(4);
	s1.DeleteItem(85);
	s1.ResetList();
	for (int i = 0; i < s1.LengthIs(); i++)
	{
		int temp;
		s1.GetNextItem(temp);
		cout << temp << endl;
	}

	//
	UnsortedType<int> s2{};
	s2.InsertItem(85);
	s2.InsertItem(85);
	s2.InsertItem(1);
	s2.InsertItem(2);
	s2.InsertItem(3);
	s2.InsertItem(4);
	s2.InsertItem(810);
	s2.InsertItem(4);
	s2.InsertItem(3);
	s2.InsertItem(3);
	s2.InsertItem(85);

	s2.DeleteItem(4);
	s2.DeleteItem(85);


	for (int i = 0; i < s2.LengthIs(); i++)
	{
		int temp;
		s2.GetNextItem(temp);
		cout << temp << endl;
	}

}



