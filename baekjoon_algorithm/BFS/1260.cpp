#include <bits/stdc++.h>
// adjcent list 쓰는 것이 array 쓰는 것 보다 좋겠다.
// 왜냐면  c++ 11 부터는 range based for
int N, M, V;
using namespace std;
bool graph[1001][1001];

bool is_visited[1001];
void dfs(int from){
    is_visited[from] =true;
    cout << from << " "; 
    for(int to = 0; to < 1001; to++)
        if(graph[from][to] && !is_visited[to])
            dfs(to);
}


bool is_discovered[1001];
queue<int> q;
void bfs(int here){
    cout << here << " ";
    is_discovered[here] = true;
    q.push(here);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int there = 1; there < 1001; there++){
            if(graph[here][there] && !is_discovered[there]){
                cout << there << " ";
                is_discovered[there] = true;
                q.push(there);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from] = true;
    }
    dfs(V);
    cout << "\n";
    bfs(V);

}