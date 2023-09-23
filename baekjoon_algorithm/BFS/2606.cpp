#include <bits/stdc++.h>
using namespace std;

vector<int> graph[101];
bool is_discovered[101];
int N, M, result;
// union find

// 핵심 : bidirectional graph. 
// DFS : visited 기준으로
// BFS : discovered 기준으로
int main(){
    cin >> N >> M;
    
    while(M--){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    queue<int> q;
    q.push(1);
    is_discovered[1] = true;
    while(!q.empty()){
        result++;
        int here = q.front();
        q.pop();
        for(int there : graph[here])
            if(!is_discovered[there]){
                is_discovered[there] = true;
                q.push(there);
            }
    }
    cout << result-1;
}