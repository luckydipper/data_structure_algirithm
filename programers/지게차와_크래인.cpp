#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
// 예시부터 완전히 이해하고 들어가자. 
// union find인가? -> union find를 하면 삭제할 때마다 다시 union-find 해야 한다.
// 구현인듯 안의 박스 1 밖의 박스 0
// 뽑기전에 후보군 애들 주변을 확인하고 뽑기
// 뽑고나서 주변애들 보기
// dfs bfs 
using namespace std;

int n, m;
int is_touchable[51][51];
int dx[] = {-1, 1,  0, 0};
int dy[] = {0,  0, -1, 1};

void folkLift(const char c, vector<string> &storage){
    vector<pair<int,int>> touchable_buffer; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c == storage[i][j] && is_touchable[i][j]){
                storage[i][j] = ' ';
                touchable_buffer.push_back({i,j});
            }
        }
    }
    for(auto& p: touchable_buffer){
        is_touchable[p.first][p.second] = true;
        for(int k = 0; k < 4; k++){
            is_touchable[p.first + dx[k]][p.second + dy[k]] = true;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        cout <<  is_touchable[i][j];
        }
        cout << "\n";
    }
}

void crain(const char c, vector<string> &storage){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c == storage[i][j]){
                storage[i][j] = ' ';
                is_touchable[i][j] = true;
                
                for(int k = 0; k < 4; k++){
                    is_touchable[i + dx[k]][j + dy[k]] = true;
                }
            }
            cout << is_touchable[i][j];
        }
        cout << "\n";
    }
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1)
                is_touchable[i][j] = 1;
            else
                is_touchable[i][j] = n*i +j;
        }
    }
    for(const string& rqst: requests){
        if(rqst.size() == 1)
            folkLift(rqst[0], storage);
        else
            crain(rqst[0], storage);
    }
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(storage[i][j] != ' '){
                answer++;
                cout << storage[i][j] ;
            }
        }
        cout << "\n";
    }
    
    return answer;
}