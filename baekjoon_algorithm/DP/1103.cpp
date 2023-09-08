#include <bits/stdc++.h>
// 처음에 갈 수 있는 곳이 두곳일 때. 다른 길 하나는 일방 통행일 경우를 고려해야함. 
// ex)
//5 5
//4HHH9
//HHHHH
//HHH12
//HHHHH
//3HH2H
// is_visited와 cache는 다르게 설정 하자. 방문한 곳 또 방문 한것과, 해당 지점에서 최대한으로 반복할 수 있는 횟수는 따로 저장해야 한다. 

using namespace std;

int size_y, size_x;
int momentum_map[51][51];
int cache[51][51];
bool is_visited[51][51]; 
int const dy[] = {1, -1,  0, 0};
int const dx[] = {0,  0, -1, 1};

const int INF = 210000000;
bool isSafe(int y, int x){
    //cout << "y :" << y << " x : " << x << " ";
    //cout << " y: "  << y << " x : " << x << "\n" << momentum_map[y][x] << " " << ('H'-'0') << "\n"; 
    return  1 <= y && y <= size_y && 1 <= x && x <= size_x && momentum_map[y][x] != ('H'-'0');
}

int countMaxMovable(int y, int x){
    if(!isSafe(y, x))
        return 0;
    //cout << y << ", " << x <<  " is safe! \n";

    if(is_visited[y][x]){
        //cout << y << ", " << x << "\n";
        cout << -1;
        exit(0);
    }

    ; //4방위를 다 검사 한 후 visit 도장 찍어줘
  
    int &visit_sequence = cache[y][x];
    // 무한 루프이다. 왔던 곳이다.
    if(visit_sequence != -1)
        return visit_sequence;
    

    int current_max_mvabl = 0;

    is_visited[y][x] = true; //dfs back tracking 와 같이 구현 
    for(int direction = 0; direction < 4; direction++){
        int new_y = y + dy[direction] * momentum_map[y][x];
        int new_x = x + dx[direction] * momentum_map[y][x];
        //cout << y << ", " << x << " call -> " << new_y << ", " << new_x << "\n";
        current_max_mvabl = max(current_max_mvabl, countMaxMovable(new_y, new_x) + 1);
    }
    is_visited[y][x] = false;

    return visit_sequence = current_max_mvabl;
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
    

    cout << countMaxMovable(1, 1);
    return 0;
}