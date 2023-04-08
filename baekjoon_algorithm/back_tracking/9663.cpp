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

int result=0;
void countNQueen(int row, int col){
    if( row == N ){
        result++;
        return;
    }
    for(int j = 0; j < N; j++){
        if(is_used_col[j]) continue;
        if(is_used_ascending[row + j]) continue;
        if(is_used_descending[row - j + N -1]) continue;
        update_placeable(row, j, true);
        countNQueen(row+1,j);
        update_placeable(row, j, false);
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