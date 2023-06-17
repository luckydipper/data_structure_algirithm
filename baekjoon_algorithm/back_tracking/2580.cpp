#include <bits/stdc++.h>
using namespace std;
int board[10][10];

// n번 째 열 행에, 1~9까지 들어갔는가?
bool row_is_used[10][10];
bool col_is_used[10][10];
bool box_is_used[10][10];

int coordinate_to_box(int i, int j){
    return ((i-1)/3)*3 + ((j-1)/3)+1;
}

// bool arr중 1개만 있을 경우 1~9 값
// 모두다 사용중 : 0
// 두개 이상 사용 할 수 있을 때 : -1
int hasOneTBD(bool * is_used){
    int count_useable;
    int val;
    for(int i = 1; i <= 9; i++){
        if(is_used[i]) continue;
        count_useable++;
        val = i;
    }
    if(count_useable >= 2)
        return -1;
    else if(count_useable == 1)
        return val;
    else
        return 0;
}

void start_stoque(int row, int col){
    if(board[row][col] != 0 ) return; // base case 
    // 값이 0이야. 
    // row col box를 보고 없는 숫자를 생각해. 
    int r = hasOneTBD(row_is_used[row]);
    int c = hasOneTBD(col_is_used[col]);
    int b = hasOneTBD(box_is_used[coordinate_to_box(row, col)]);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i <=9; i++){
        for(int j = 1; j <= 9; j++){
            int temp; 
            cin << temp; 
            board[i][j] = temp;
            if(temp != 0){
                row_is_used[i][temp] = true;
                col_is_used[j][temp] = true;
                box_is_used[coordinate_to_box(int i, int j)][temp] = true;
            }
        }
    }

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            start_stoque(i, j);
        }
    }
    return 0;
}