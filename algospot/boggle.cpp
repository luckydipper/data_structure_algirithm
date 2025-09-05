#include <iostream>
#include <string>
#include <vector>
#include <cstring>

// substr, splice, clear, string a(1, sentense[0]);
// Out of bound 를 첫 case에 집어넣자. 이후에 index에 대한 reference를 찾는다.
// LIS와 비슷한 구조이다. 
// 답은 없는데 복잡도는 매우 높은 경우 DP를 의심해보자.
// memset은 cstring에들어있다. 

using namespace std;
int C, N;
char board[5][5];
bool bogable[5][5][10];

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1, 1, 0,-1,1,1,0,-1};

bool isBoggable(const string& sentense, int i, int j, int after_idx){
    if(i >=5 || j >= 5 || i < 0 || j < 0 || sentense[after_idx] != board[i][j])
        return false;
    bool& ret = bogable[i][j][after_idx];
    
    if(after_idx == sentense.size()-1) // size 가 aft idx와 같으면 위의 조건에서 펑크남 sentense[after_idx] != board[i][j]
        return ret = true;
    if(ret)
        return ret;
    for(int k = 0; k < 8; k++)
        if(isBoggable(sentense,i+dx[k],j+dy[k],after_idx+1)) 
            return ret = true;
    return ret;
}

bool isBoggablePruned(const string& sentense, int i, int j, int after_idx){

    if(after_idx == sentense.size()-1) 
        return bogable[i][j][after_idx] = true;
    if(board[i][j] != sentense[after_idx])
        return bogable[i][j][after_idx] = false;
    bogable[i][j][after_idx] = true;

    for(int k = 0; k < 8; k++){
        int nxt_x = i+dx[k], nxt_y = j+dy[k];
        if(nxt_x >=5 || nxt_y >= 5 || nxt_x < 0 || nxt_y < 0) continue;
        if(board[nxt_x][nxt_y] != sentense[after_idx+1]) continue;
        if(bogable[nxt_x][nxt_y][after_idx+1]) continue;
        if(isBoggablePruned(sentense, nxt_x, nxt_y, after_idx+1)) return true;
    }
    return false;
}


bool isFindable(char arr[][5], const string& sentense){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(isBoggablePruned(sentense, i, j, 0))
                return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C;
    while(C--){
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cin >> board[i][j];
            }
        }
        cin >> N;
        for(int i = 0; i < N; i++){
            memset(bogable, 0, sizeof(bogable));
            string tmp_str;
            cin >> tmp_str;
            bool is_exist = isFindable(board, tmp_str);
            cout << tmp_str << " ";
            if(is_exist)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
    }
}