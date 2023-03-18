// STL에 distance library가 존재함. 다른 변수명을 찾아야 할 듯.
// ambiguous error가 뜸.
#include <bits/stdc++.h>
using namespace std;

int box[1001][1001];
int distance_[1001][1001];
int M, N;
// auto 쓸까 말까.
queue<pair<int,int>> Q;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void intialize_local(){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int tmp;
            cin >> tmp;
            box[i][j] = tmp;
            distance_[i][j] = -1;
        }
    }
}

template <typename T>
void print_distance(const T& mat){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cout << mat[i][j]<<", ";
        cout << "\n";
    }
}

int main(){
    intialize_local();
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(box[i][j] == 1){
                Q.push({i,j}); distance_[i][j] = 0;}
    
    pair<int,int> here;
    while(!Q.empty()){
        here = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int there_x = here.first + dx[i];
            int there_y = here.second + dy[i];

            //out of box
            if(there_x < 0 || there_y < 0 || there_x >= N || there_y >= M ) continue;
            if(box[there_x][there_y] == -1 || distance_[there_x][there_y] != -1) continue;
            distance_[there_x][there_y] = distance_[here.first][here.second] + 1;
            Q.push({there_x,there_y});// box [there] =1 하고 53절에 box == 0하면?
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(box[i][j] == 0 && distance_[i][j] == -1){
                cout << -1; return 0;}
    cout << distance_[here.first][here.second];
}