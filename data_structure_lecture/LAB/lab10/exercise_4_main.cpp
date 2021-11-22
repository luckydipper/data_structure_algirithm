#include "TreeType.h"


int Smaller(TreeType tree, int value)
{
	ItemType item;
	bool finished = false;
	int count = 0;
	tree.ResetTree(IN_ORDER);
	do {
		tree.GetNextItem(item, IN_ORDER, finished);
		if (item < value)
			count++;
		else
			finished = true;
	} while (!finished);
	return count;
}

int main()
{
	TreeType BinaraySearchTree{};
	BinaraySearchTree.InsertItem('H');
	BinaraySearchTree.InsertItem('Q');
	BinaraySearchTree.InsertItem('D');
	BinaraySearchTree.InsertItem('A');
	BinaraySearchTree.InsertItem('E');
	BinaraySearchTree.InsertItem('P');
	BinaraySearchTree.InsertItem('U');
	BinaraySearchTree.InsertItem('F');
	BinaraySearchTree.InsertItem('T');
	BinaraySearchTree.InsertItem('S');
	int a = Smaller(BinaraySearchTree, 'S');

	return 0;
}