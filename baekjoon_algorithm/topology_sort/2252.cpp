#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

// declare만 했음. 해당 파일에서 전역변수로 쓸 수 있도록.
// vector<vector<int>> adj;
// vector<bool> visited;
// vector<int> order;
int N, M;
vector<vector<int>> adj{};
vector<bool> visited{};
vector<int> order{};
// dfs' input nodes are not visited 
void dfs(int here){
    visited[here] = true; 
    for(int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        if(!visited[there])
            dfs(there);
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

    adj.resize(N+1);
    visited.resize(N+1, false); // 커지는 경우에만 값이 들어가

    make_graph();
    
    for(int i = 1; i < N+1; i++){
        if(!visited[i])
            dfs(i);
    }

    reverse(order.begin(), order.end());
    
    for(int elem: order)
        cout << elem << " ";
}