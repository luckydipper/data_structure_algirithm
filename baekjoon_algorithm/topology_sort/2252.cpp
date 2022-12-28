#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

//adj list 쓰기로 결정 matrix는 크기가 너무 큰 듯?

// 이건 declare만 한 것이라 전역변수 취급이 안되나?
int N, M;
vector<list<int>> adj;
vector<bool> visited;
vector<int> order;

// dfs' input nodes are not visited 
void dfs(int here){
    visited[here] = true; // 이 부분에서 에러가 발생 
    for(list<int>::iterator i = adj[here].begin(); i != adj[here].end(); i++)
    {
        cout <<"*i : " << *i<< "\n";
        if(visited[*i] == false)
            dfs(*i);
    }
    order.push_back(here);
}

void make_graph() // 이 함수를 main 안에 집어넣어서 동작시키면 잘 동작함.
{
    while(M--){
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }
}

int main()
{
    cin >> N >> M;
    vector<list<int>> adj(N+1);

    make_graph();
    
    vector<bool> visited(N+1, false);
    for(int i = 1; i < N+1; i++)
        dfs(i);

 
    reverse(order.begin(), order.end());
    
    for(int elem: order)
        cout << elem << " ";
}