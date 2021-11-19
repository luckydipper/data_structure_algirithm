#include "TreeType.h"
#include "UnsortedType.h"

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();
	if (list_length != tree_length) //길이를 먼저 비교, 같은지 검사한다.
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;
		list.ResetList(); //list에 iterator를 사용할 준비를 한다
		for (int i = 0; i < list_length; i++) 
		{
			list.GetNextItem(item); // list에서 하나의 아이템을 가져온다
			tree.RetrieveItem(item, found); //트리에 해당 아이템이 있는지 검색. O(logN)이 걸림.
			if (!found)
				return false;
		}
		return true;
	}
}


int main()
{
	UnsortedType<char> abc_list{};
	abc_list.InsertItem('a');
	abc_list.InsertItem('e');
	abc_list.InsertItem('b');
	abc_list.InsertItem('h');
	abc_list.InsertItem('z');
	abc_list.InsertItem('k');
	abc_list.InsertItem('g');

	TreeType BinaraySearchTree{};
	BinaraySearchTree.InsertItem('g');
	BinaraySearchTree.InsertItem('b');
	BinaraySearchTree.InsertItem('k');
	BinaraySearchTree.InsertItem('a');
	BinaraySearchTree.InsertItem('e');
	BinaraySearchTree.InsertItem('h');
	BinaraySearchTree.InsertItem('z');

	bool is_same = MatchingItem_Unsorted(BinaraySearchTree, abc_list);
	return 0;
}