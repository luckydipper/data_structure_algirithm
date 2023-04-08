#include <bits/stdc++.h>
using namespace std;
// 아니면 돌아가자! (이게 recursion으로 하면 편함.) 
// -> is used로 구현함
// pruning
int N;

bool is_used_col[16];
bool is_used_ascending[32];  // x + y
bool is_used_descending[32]; // x-y + n-1
// index의 합이 0, 정의역 안에 있어야 해서 0-based index 사용?

void update_placeable(int row, int col, bool with){
    is_used_col[col] = with;
    is_used_ascending[row + col] = with;
    is_used_descending[row - col + N -1] =with;
}

int result;
void countNQueen(int row, int col){
    if( row == N-1){
        for(int i = 0; i < N; i++)
            if(!is_used_col[i])
                result++; 
        return;
    }
    if(is_used_col[col]) return;
    if(is_used_ascending[row + col]) return;
    if(is_used_descending[row - col + N -1]) return;
    
    for(int i = 0; i < N;  i++){
        for(int j = 0; j < N; j++){
            update_placeable(i, j, true);
            countNQueen(i,j);
            update_placeable(i, j, false);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    countNQueen(0,0);
    cout << result;

    return 0;
}