#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int count_p[51][51];
int tmp[51][51];


int dy[] = {0,1, 0,-1};
int dx[] = {1,0,-1,0};
bool is_visted[51][51];
int sum_population;
vector<pair<int,int>> history;
void dfs(int y, int x){
    if(y <= 0 || x <= 0 || y > N || x > N)
        return;
    history.push_back({y,x});
    sum_population += count_p[y][x];
    is_visted[y][x] = true;
    for(int i = 0; i < 4; i++){
        int gap = abs(count_p[y+dy[i]][x+dx[i]] - count_p[y][x]);
        //cout << "L R gap : " <<" " << count_p[y][x] << " " << gap << "\n";
        if(!is_visted[y+dy[i]][x+dx[i]] && L <= gap && gap <= R){
            dfs(y+dy[i], x+dx[i]);
        }
    }
}

bool is_same_arr(int arrl[51][51], int arrr[51][51], int sz){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(arrl[i][j] != arrr[i][j])
                return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    cin >> N >> L >> R;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >>count_p[i][j];
        }
    }
    int result = 0;
    while(!is_same_arr(tmp, count_p, N)){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                tmp[i][j] = count_p[i][j];
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(is_visted[i][j])
                    continue;
                dfs(i,j);
                for(const auto& y_x : history)
                    count_p[y_x.first][y_x.second] = sum_population / history.size();
                sum_population = 0;
                history.clear();
            }
        }
    //         cout << result -1 <<"\n";
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //     cout << count_p[i][j] << " ";
    //     }
    //     cout << "\n";
    //     }
    //     cout << "\n";
        memset(is_visted,0,sizeof(is_visted));
        
        result++;
    }

    cout << result -1 <<"\n";
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //     cout << count_p[i][j] << " ";
    //     }
    //     cout << "\n";
    //     }
    //cout << "sum populat : " << sum_population << " num_union : " << history.size();
    
}