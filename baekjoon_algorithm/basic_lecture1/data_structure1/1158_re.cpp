// 규칙성 때문에 modular 연산에 너무 같혀 있었음.
// circular queue를 사용하지 않았던 이유는 중간 중간 erase가 일어나기 때문임.
// STL의 동적 할당된 queue를 사용하면 더 쉽게 표현 가능
// int 2개는 cin으로 한번에
#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;

    vector<int> result;

    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    // 반복 횟수를 주지 않았기 때문에 while 쓸거임.
    // for 2개를 써서도 가능함. 하지만 굳이?
    while(!q.empty())
    {
        for(int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        result.push_back(q.front());
        q.pop();
    }

    
    cout << "<";
    for(int i = 0; i < N-1; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[N-1];
    cout << ">";
    return 0;
}