#include "Student.h"
#include <iostream>
#include "HeapSort.h"

// Heap sort�� ù��° �ܰ�� �־��� �Է� �迭�� Heap���� �����ϴ� ���̴�.
// Heap���� �����ϴµ� �ɸ��� �ð��� �м��Ѵ�
// N/2�� reheapdown�� �����Ѵ�. Reheapdown�� ���⵵�� O(logN)�̱� ������,
// O(NlogN)�� �ȴ�.


template <class ItemType >
int GetHeightSum(ItemType values[], int numValues);

template <class ItemType >
int GetHeight(ItemType values[], int start, int numValues);


template <class ItemType >
int GetHeightSum(ItemType values[], int numValues)
{
	int index, sum = 0;
	// non-leaf ��忡 ���� �� ��带 ��Ʈ�� �ϴ� subtree�� height ���
	for (index = numValues / 2 - 1; index >= 0; index--)
		sum += GetHeight(values, index, numValues - 1);
	cout << "sum of heights = " << sum << endl;
	return sum;
}

template <class ItemType >
int GetHeight(ItemType values[], int start, int numValues)
{
	if (start > numValues/2)
		return 0; // start�� leaf�̰ų� tree �ۿ� �ִ� ���
	int l_height = GetHeight(values, 2*start + 1, numValues); // left subtree�� height
	int r_height = GetHeight(values, 2*start + 2, numValues); // right subtree�� height
	return l_height>r_height ? l_height+1:r_height+1; // ��subtree height �� ū �� + 1�� �� ����
}


using namespace std;

int main(char argc, char* argv[])
{
	int example_arr[] = { 25, 17, 36, 2, 3, 100, 1, 19, 7 };
	int exam_length = sizeof(example_arr) / sizeof(int);
	HeapSort_print(example_arr, exam_length);
	GetHeightSum<int>(example_arr, exam_length);
	return 0;
}