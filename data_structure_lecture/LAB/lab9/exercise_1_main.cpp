#include "QueType.h"
#include "TreeType.h"


int main()
{
	TreeType BinaraySearchTree{};
	BinaraySearchTree.InsertItem('H');
	BinaraySearchTree.InsertItem('Q');
	BinaraySearchTree.InsertItem('D');
	BinaraySearchTree.InsertItem('A');
	BinaraySearchTree.InsertItem('E');
	BinaraySearchTree.InsertItem('P');
	BinaraySearchTree.InsertItem('S');
	BinaraySearchTree.InsertItem('F');

	TreeNode* small_node = BinaraySearchTree.PtrToSuccessor();
	delete small_node;
	return 0;
}