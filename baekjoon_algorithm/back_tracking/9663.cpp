#include <bits/stdc++.h>
using namespace std;
// 아니면 돌아가자! (이게 recursion으로 하면 편함.)
// pruning
int N;

bool placeable[16][16];
bool buffer_[16][16];
void fillPlaceable(bool with){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            placeable[i][j] = with;
}

void printPlaceable(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            cout << placeable[i][j] << " ";
    cout << "\n";    
    }
cout << "\n"; 
}

void copyPlaceable(bool from[][16], bool to[][16] ){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            to[i][j] = from[i][j];
}

void update_movable_coordinate(int x, int y, bool with){
    placeable[x][y] = with;
    // right ascending
    int temp_x = x, temp_y = y;
    while( temp_x <= N && temp_y <= N )
        placeable[++temp_x][++temp_y] = with;
    // left ascending 
    temp_x = x, temp_y = y;
    while( temp_x >= 0 && temp_y >= 0)
        placeable[--temp_x][--temp_y] = with;
    // right descending 
    temp_x = x, temp_y = y;
    while( temp_x <= N && temp_y >= 0)
        placeable[++temp_x][--temp_y] = with;
    // left descending 
    temp_x = x, temp_y = y;
    while ( temp_x >= 0 && temp_y <= N)
        placeable[--temp_x][++temp_y] = with;

    // row and col
    for(int i = 1; i <= N; i++){
        placeable[x][i] = with;
        placeable[i][y] = with;
    }
}
int solution = 0;

bool allRowFalse(bool* arr){
    for(int i = 1; i <= N; i++)
        if( arr[i] == true )
            return false;
}

int count_start_with(int row, int col){
    if(row == N){
        for(int i = 1; i <= N; i++)
            if(placeable[row][i])
                solution++;
        return solution;
    }
    if(allRowFalse(placeable[row]))
        return -1;
    
    update_movable_coordinate(row, col,false);
    cout << "row = " << row << "col = " << col << "\n";
    printPlaceable();
    //find next row starting candidate
    for(int i = 1; i <= N; i++){
        if(!placeable[row+1][i]) continue;
        copyPlaceable(placeable, buffer_);
        if(count_start_with(row+1, i) == -1);
        copyPlaceable(buffer_, placeable);
    }
}

int searchPlacable(int row, int col){
    if(allRowFalse(placeable[row]))
        return 0;
    else if(row == N){
        int result = 0;
        for(int i = 1; i <= N; i++)
            if(placeable[row][i])
                result++;
        return result;
    }
    else{
        for(int i = 1; i <= N i++)
            searchPlacable(row+1, i);
    }
    if(searchPlacable(row, col) != 0)
        update_movable_coordinate(row,col);
}

int countNQueen(int start_row, int start_col){
    if(allRowFalse(placeable[start_row]))
        return -1;
    
    update_movable_coordinate(start_row, start_col);

    for(int i = 1; i <= N; i++){
        copyPlaceable(placeable, buffer_);
        if(countNQueen(start_row) == -1)
            copyPlaceable(buffer_, placeable);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    fillPlaceable(true);

    cout << countNQueen(1,1);
    // for(int i = 1; i <= N; i++){
    //     count_start_with(1, i);
    //     fillPlaceable(true);
    //     cout << solution << "\n";
    // }


    return 0;
}