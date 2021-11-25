#pragma once
template <class ItemType>
void swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
  ItemType* elements;   // Array to be allocated dynamically
  int numElements;
};

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}  

// Heap을 재구축 하는 두 함수의 시간 복잡도는 O(log_2⁡N)이다. 
// 이유: N개의 data가 있을 때, 탐색 해야하는 최악의 데이터의 수는 log_2 N이기 때문이다.

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
    int parent;
    bool reheaped = false; // bottom이 제 위치를 찾아가서 reheap이 되면 true
    while (bottom > root && !reheaped)
    {
        parent = (bottom - 1) / 2; // bottom 값으로부터 부모 노드의 위치 계산
        if (elements[parent] < elements[bottom])
        {
            Swap(elements[parent], elements[bottom]);// bottom을 부모 노드와 값 교환
            bottom = parent; // bottom이 이제 부모 노드의 위치를 가리킴
        }
        else
            reheaped = true;
    }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
    int maxChild, leftChild, rightChild;
    bool reheaped = false; // root가 제 위치를 찾아가 reheap이 되면 True
    leftChild = 2*root + 1; // root 값으로부터 왼쪽 자식노드의 위치 계산
    while (leftChild <= bottom && !reheaped)
    {
        if (leftChild == bottom) // 왼쪽 자식 노드 하나만 있는 경우
            maxChild = leftChild;
        else {
            rightChild = 2*root + 2;
            maxChild = (elements[leftChild] <= elements[rightChild]) ? rightChild : leftChild;
        }
        if (elements[root] < elements[maxChild]) {
            Swap(elements[root], elements[maxChild]);
            root = maxChild; // maxChild 가 root의 새로운 위치가 됨
            leftChild = 2* maxChild +1;
        }
        else
            reheaped = true;
    }
}

