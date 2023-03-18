#include <bits/stdc++.h>
using namespace std;

int n, m;


const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

//return width
int BFS_(vector<vector<int>>& drawing, vector<vector<int>>& discovered, int init_x, int init_y){
    int width = 0;
    queue<pair<int, int>> Q;
    discovered[init_x][init_y] = 1;
    Q.push(make_pair(init_x,init_y));

    while(!Q.empty()){
        auto x_y = Q.front();
        Q.pop();
        width++;
        for(int i = 0; i <4; i++){
            int there_x = x_y.first + dx[i];
            int there_y = x_y.second + dy[i];
            if(there_x < 0 || there_x >= n || there_y < 0 || there_y >= m) continue;
            if(discovered[there_x][there_y]||!drawing[there_x][there_y]) continue;
            
            discovered[there_x][there_y] = 1;
            Q.push(make_pair(there_x, there_y));
        }
    }

    return width;
}

int main(){

    cin >> n >> m;
    vector<vector<int>> drawing(n, vector<int>(m, 0));
    auto discovered = drawing;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int tmp1;
            cin >> tmp1;
            drawing[i][j] = tmp1;
        }
    }


    //count num of pop
    int num_drawings=0, broadest_width=0;

    for(int i = 0 ; i < n;i++){
        for(int j = 0; j < m; j++){
            if(!discovered[i][j] && drawing[i][j]){
                int width = BFS_(drawing, discovered, i, j);
                if(width > broadest_width)
                    broadest_width = width;
                num_drawings++;
            }
        }
    }
    cout << num_drawings << "\n" << broadest_width;
}


