#include <iostream>
#include "sorted.h"
using namespace std;
int MergeList(SortedType list1, SortedType list2, SortedType& result);

int MergeList(SortedType list1, SortedType list2, SortedType& result)
{
	list1.ResetList();
	list2.ResetList();
	if (result.IsFull())
		return -1;
	for (int i = 0; i < list1.LengthIs(); i++)
	{
		ItemType temp;
		list1.GetNextItem(temp);
		result.InsertItem(temp);
	}

	for (int i = 0; i < list2.LengthIs(); i++)
	{
		ItemType temp;
		list2.GetNextItem(temp);
		result.InsertItem(temp);
	}
}

int main()
{
	SortedType sorted_item_a{};
	SortedType sorted_item_b{};
	SortedType sorted_merged{};
	sorted_item_a.ResetList();
	sorted_item_b.ResetList();
	sorted_merged.ResetList();
	
	ItemType item{};
	for (int i = 0; i < 5; i++)
	{
		item.Initialize(i);
		sorted_item_a.InsertItem(item);
	}
	for (int i = 5; i < 10; i++)
	{
		item.Initialize(i);
		sorted_item_b.InsertItem(item);
	}
	MergeList(sorted_item_b, sorted_item_a, sorted_merged);
	for (int i = 0; i < sorted_merged.LengthIs(); i++)
	{
		ItemType temp{};
		sorted_merged.GetNextItem(temp);
		temp.Print(cout);
	}

	// interupt
	int a;
	cin >> a;
}
	
