#include <iostream>
#include "UnsortedType.h"
#include "SortedType.h"
using namespace std;

template <typename ItemType>
void MergeLists( SortedType<ItemType>& l_a,  SortedType<ItemType>& l_b, SortedType<ItemType>& result);
template <typename ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result);


int main()
{
	UnsortedType<int> s1{};
	s1.InsertItem(1);
	s1.InsertItem(2);
	s1.InsertItem(3);
	s1.InsertItem(4);
	s1.InsertItem(810);
	s1.InsertItem(4);
	s1.InsertItem(85);
	
	UnsortedType<int> s2{};
	s2.InsertItem(10);
	s2.InsertItem(20);
	s2.InsertItem(30);
	s2.InsertItem(45);
	s2.InsertItem(8150);
	s2.InsertItem(4652);
	s2.InsertItem(855);

	UnsortedType<int> result{};
	MergeLists<int>(s1, s2, result);
	//s1.MergeLists(s2, result);
	for (int i = 0; i < result.LengthIs(); i++)
	{
		int temp;
		result.GetNextItem(temp);
		cout << temp <<endl;
	}

}

template <typename ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result)
{
	result.MakeEmpty();
	l_a.ResetList();
	l_b.ResetList();


	for (int i = 0; i < l_a.LengthIs(); i++)
	{
		ItemType temp;
		l_a.GetNextItem(temp);
		result.InsertItem(temp);

	}

	for (int i = 0; i < l_b.LengthIs(); i++)
	{
		ItemType temp;
		l_b.GetNextItem(temp);
		result.InsertItem(temp);

	}
}

template <typename ItemType>
void MergeLists( SortedType<ItemType>& l_a,  SortedType<ItemType>& l_b, SortedType<ItemType>& result)
{
	result.MakeEmpty();
	l_a.ResetList();
	l_b.ResetList();

	
	for (int i = 0; i < l_a.LengthIs(); i++)
	{
		ItemType temp;
		l_a.GetNextItem(temp);
		result.InsertItem(temp);

	}

	for (int i = 0; i < l_b.LengthIs(); i++)
	{
		ItemType temp;
		l_b.GetNextItem(temp);
		result.InsertItem(temp);

	}
}


