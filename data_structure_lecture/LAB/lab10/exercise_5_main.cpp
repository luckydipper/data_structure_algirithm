#include "TreeType.h"
#include "SortedType.h"

void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int>& list);

void MakeTree(TreeType& tree, SortedType<int>& list)
{
	int length = list.LengthIs(); //����Ʈ ũ�⸦ ��´�
	int* array = new int[length]; //���� �迭 �Ҵ�
	int item_info;
	int i;
	list.ResetList();
	for (i = 0; i < length; i++)
	{
		list.GetNextItem(item_info);
		array[i] = item_info;
	}
	AddElement(tree, array, 0, length - 1);
	delete[] array; // ���� �迭 ����
}
void AddElement(TreeType& tree, int Array[], int front, int rear)
{
	int mid; //�߰� ���� ����ϴ� ����
	if (front <= rear) { //�Լ��� ��������
		mid = (front + rear)/2;
		tree.InsertItem(Array[mid]);
		AddElement(tree, Array, mid+1, rear);
		AddElement(tree, Array, front, mid-1);
	}
}


int main()
{
	SortedType<int> abc_list{};
	abc_list.InsertItem('1');
	abc_list.InsertItem('2');
	abc_list.InsertItem('3');
	abc_list.InsertItem('4');
	abc_list.InsertItem('5');
	abc_list.InsertItem('6');
	abc_list.InsertItem('7');

	TreeType BinaraySearchTree{};
	MakeTree(BinaraySearchTree, abc_list);

	return 0;
}