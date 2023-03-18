#include <bits/stdc++.h>
using namespace std;

// 경곗값 주의!!!!
char maze[1001][1001];
int distance_[1001][1001];
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};
queue<pair<int, int>> J_Q;
queue<pair<int, int>> F_Q;
int R, C;

template <typename T>
void print(T mat){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++)
            cout << mat[i][j]<< ", ";
        cout << "\n";
    }
    cout << "\n\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            distance_[i][j]=-1;
            char tmp; 
            cin >> tmp; 
            maze[i][j] = tmp; 
            
            if(tmp == 'J'){
                distance_[i][j] = 0;
                J_Q.push({i,j});}
            if(tmp == 'F')
                F_Q.push({i,j});
        }
    }
    

    while(!F_Q.empty() || !J_Q.empty()){

        auto tmp = F_Q;
        while(!tmp.empty()){
            pair<int, int> F_here = F_Q.front();
            F_Q.pop();
            tmp.pop();
            for(int i=0; i < 4; i++){
                int f_there_x = F_here.first + dx[i];
                int f_there_y = F_here.second + dy[i];
                if(maze[f_there_x][f_there_y] != '.') continue;
                //if(maze[f_there_x][f_there_y] == 'F') continue;
                if(f_there_x >= R || f_there_y >= C || f_there_x < 0 || f_there_y < 0 ) continue;
                maze[f_there_x][f_there_y] = 'F';
                F_Q.push({f_there_x,f_there_y});
            }
        }
        
        tmp = J_Q;
        while(!tmp.empty()){
            pair<int, int> J_here = J_Q.front();
            J_Q.pop();
            tmp.pop();
            for(int i=0; i < 4; i++){
                int j_there_x = J_here.first + dx[i];
                int j_there_y = J_here.second + dy[i];
                //if(maze[j_there_x][j_there_y] == '#' || maze[j_there_x][j_there_y] == 'F') continue;
                //if(j_there_x >= R || j_there_y >= C || j_there_x < 0 || j_there_y < 0 ){
                // 경계에 닿는 순간 fire가 와서 
                if(j_there_x >= R || j_there_y >= C || j_there_x < 0 || j_there_y < 0 ){
                    cout << distance_[J_here.first][J_here.second] + 1;
                    return 0;
                }
                if(maze[j_there_x][j_there_y] != '.') continue;
                if(distance_[j_there_x][j_there_y] != -1) continue;
                distance_[j_there_x][j_there_y] = distance_[J_here.first][J_here.second] + 1;
                J_Q.push({j_there_x, j_there_y});
            }
        }
    }
    cout << "IMPOSSIBLE";
} 
