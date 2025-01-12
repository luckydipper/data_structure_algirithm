// Flood fill 문제 graph 탐색 문제 
// Back Tracking으로 가능할듯 
// DFS BFS 둘다 가능. 넣을 때 조건을 가리면서 넣으면 DFS가 빼서 조건 확인하면 BFS가 더 유리한듯 
// BFS로 queue에 넣을 때 복잡해짐  
// 문제 제대로 읽기 정사각형 아님
// stl 명확히 숙지 queue는 뒤로들어와서 앞으로 나감 push pop시 조심,
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;
//flood fill <- BFS

//Flood fill을 BFS로 구분할 때 대부분 queue에서 뺄 때 조건을 비교했었는데 
// 이중 for문의 continue 때문인가? push 에서 continue 안 넣는 이유가 while for니깐

// dfs + back tracking 으로 푸는게 이상적일 듯 
bool is_visit[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int flood_fill(int i, int j, vector< string > maps){
    if(is_visit[i][j] || maps[i][j] == 'X')
        return 0; 
    
    int result = 0;
    queue< pair<int,int> > q;
    q.push({i,j});
    while(!q.empty()){
        int y_ = q.front().first, x_ = q.front().second;
        q.pop();
        if(is_visit[y_][x_])
            continue;
        is_visit[y_][x_] = true;
        result += (int) maps[y_][x_] - '0';
        
        for(int dir = 0; dir < 4; dir++){
            int y = y_ + dy[dir];
            int x = x_ + dx[dir];
            if( y >= 0 && y < maps.size() && x >= 0 && x < maps[0].size() && !is_visit[y][x] && maps[y][x] != 'X'){
                q.push({y, x});
            }
        }
    }
    return result;
}


int dfsFloodFill(int i, int j, vector<string> maps){
    if(is_visit[i][j] || maps[i][j] == 'X')
        return 0; 
    is_visit[i][j] = true;
    int result = (int) maps[i][j] - '0';
    
    for(int dir = 0; dir < 4; dir++){
        int y = i + dy[dir];
        int x = j + dx[dir];
        int y_end, x_end;
        y_end = maps.size();
        x_end = maps[0].size();
        if( y <0 || y >= y_end || x<0 || x>= x_end)
            continue;
        if(is_visit[y][x] || maps[i][j] == 'X')
            continue;
        result += dfsFloodFill(y,x,maps); 
    }
    return result;
}
vector<int> solution(vector<string> maps) {
    // int length = max(maps.size(), maps[0].size());
    vector<int> tmp, answer;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            tmp.push_back(dfsFloodFill(i, j, maps));
        }
    }
    
    for(int a: tmp)
        if(a != 0)
            answer.push_back(a);
    
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}