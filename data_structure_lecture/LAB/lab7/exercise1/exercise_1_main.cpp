#include "SortedType.h"
#include <iostream>

using namespace std;

int main()
{
	SortedType<int> sorted_list;
	sorted_list.InsertItem(3);
	sorted_list.InsertItem(2);
	sorted_list.InsertItem(1);
	sorted_list.InsertItem(62);
	sorted_list.InsertItem(100);
	sorted_list.InsertItem(0);

	sorted_list.ResetList();
	
	//int iterator;
	//sorted_list.GetNextItem(iterator);
	//for(int i =0; i<sorted_list.LengthIs();i++)
	//{
	//	sorted_list.GetNextItem(iterator);
	//	cout << iterator <<endl ;
	//}
	sorted_list.PrintReverse();
	return 0;
}