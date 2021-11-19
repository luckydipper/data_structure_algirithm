#include "TreeType.h"
#include "UnsortedType.h"

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();
	if (list_length != tree_length) //���̸� ���� ��, ������ �˻��Ѵ�.
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;
		list.ResetList(); //list�� iterator�� ����� �غ� �Ѵ�
		for (int i = 0; i < list_length; i++) 
		{
			list.GetNextItem(item); // list���� �ϳ��� �������� �����´�
			tree.RetrieveItem(item, found); //Ʈ���� �ش� �������� �ִ��� �˻�. O(logN)�� �ɸ�.
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