#include "Student.h"
#include <iostream>
#include "HeapSort.h"

// Heap sort의 첫번째 단계는 주어진 입력 배열을 Heap으로 변경하는 것이다.
// Heap으로 변경하는데 걸리는 시간을 분석한다
// N/2에 reheapdown을 진행한다. Reheapdown의 복잡도는 O(logN)이기 때문에,
// O(NlogN)이 된다.


template <class ItemType >
int GetHeightSum(ItemType values[], int numValues);

template <class ItemType >
int GetHeight(ItemType values[], int start, int numValues);


template <class ItemType >
int GetHeightSum(ItemType values[], int numValues)
{
	int index, sum = 0;
	// non-leaf 노드에 대해 그 노드를 루트로 하는 subtree의 height 계산
	for (index = numValues / 2 - 1; index >= 0; index--)
		sum += GetHeight(values, index, numValues - 1);
	cout << "sum of heights = " << sum << endl;
	return sum;
}

template <class ItemType >
int GetHeight(ItemType values[], int start, int numValues)
{
	if (start > numValues/2)
		return 0; // start가 leaf이거나 tree 밖에 있는 경우
	int l_height = GetHeight(values, 2*start + 1, numValues); // left subtree의 height
	int r_height = GetHeight(values, 2*start + 2, numValues); // right subtree의 height
	return l_height>r_height ? l_height+1:r_height+1; // “subtree height 중 큰 값 + 1” 을 리턴
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