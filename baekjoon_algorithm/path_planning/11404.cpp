#include <bits/stdc++.h>
using namespace std;
int n, m;
int adj[101][101];
int s_distance[101][101];
int path_history[101][101];

const int INF = 0x3f3f3f3f;

//heap에 경로 저장해 두기
void show_history(int from, int to){
    queue<int> q;
    int count = 0;
    if(from == to){ cout << 0; return;}
    while(from != to){
        count++;
        q.push(from);
        from = path_history[from][to];
        if(from == 0){
            cout << 0; 
            return;
        }
    }
    q.push(to);

    cout << ++count<< " ";
    while(!q.empty()){
        int a = q.front(); q.pop();
        cout << a << " ";
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    
    for(auto line : s_distance)
        fill(line, line+n+1, INF);
    
    while(m--){
        int from, to, cost;
        cin >> from >> to >> cost;
        // 다른 거리의 edge 존재 가능
        adj[from][to] = min(cost, s_distance[from][to]);
        s_distance[from][to] = min(cost, s_distance[from][to]);
        path_history[from][to] = to; //이것이 추가 되어야 해.
    }

    for(int i = 1; i <= n; i++) s_distance[i][i] = 0;
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s_distance[i][j] > s_distance[i][k] + s_distance[k][j]){
                    s_distance[i][j] = s_distance[i][k] + s_distance[k][j];
                    //path_history[i][j] = k;//path_history[i][k]임./
                    path_history[i][j] = path_history[i][k];
                }

            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s_distance[i][j] == INF){
                cout << "0 "; 
                continue;
            }
            cout << s_distance[i][j] << " ";
        }
        cout << "\n";
    }
    // history

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        show_history(i,j);
        cout << " \n";
        }
    }
    

}
