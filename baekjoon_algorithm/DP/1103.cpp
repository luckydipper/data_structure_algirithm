#include <bits/stdc++.h>
// is_visited와 cache는 다르게 설정 하자. 방문한 곳 또 방문 한것과, 해당 지점에서 최대한으로 반복할 수 있는 횟수는 따로 저장해야 한다. 

using namespace std;

int size_y, size_x;
int momentum_map[51][51];
int cache[51][51];
int const dy[] = {1, -1,  0, 0};
int const dx[] = {0,  0, -1, 1};

const int INF = 210000000;
bool isSafe(int y, int x){
    //cout << "y :" << y << " x : " << x << " ";
    return  1 <= y && y <= size_y && 1 <= x && x <= size_x && momentum_map[y][x] != ('H'-'0');
}

int countMaxMovable(int y, int x){
    if(!isSafe(y, x))
        return 0;
    //cout << "is safe! \n";

    int &visit_sequence = cache[y][x];
    // 무한 루프이다. 왔던 곳이다.
    if(visit_sequence != -1 && visit_sequence < INF){ 
        cout << -1;  
        exit(0);
    }
    
    int new_y = y + dy[0] * momentum_map[y][x];
    int new_x = x + dx[0] * momentum_map[y][x];
    int current_max_mvabl = countMaxMovable(new_y, new_x);

    for(int direction = 1; direction < 4; direction++){
        new_y = y + dy[direction] * momentum_map[y][x];
        new_x = x + dx[direction] * momentum_map[y][x];
        current_max_mvabl = max(current_max_mvabl, countMaxMovable(new_y, new_x));
    }
    return visit_sequence = current_max_mvabl + 1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    cin >> size_y >> size_x;

    for(int i = 1; i <= size_y; i++){
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= size_x; j++)
            momentum_map[i][j] = tmp[j-1]-'0';
    }

    int result = countMaxMovable(1, 1);

    if(result >= INF)
        cout << -1;
    else
        cout << result;
    return 0;
}