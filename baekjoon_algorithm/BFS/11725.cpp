#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> graph[100001];

bool is_discovered[100001];
queue<int> q;
void find_bfs_parent(int root, vector<int>& result){
    is_discovered[root] = true;
    q.push(root);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int there : graph[here]){
            if(!is_discovered[there]){
                is_discovered[there] = true;
                q.push(there);
                //cout << "here : " << here << " << there " << there << "\n";
                result[there] = here;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i < N; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2; 
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    vector<int> result(N+1);
    find_bfs_parent(1,result);
    for(int i = 2; i <= N; i++)
        cout << result[i] << "\n";
}