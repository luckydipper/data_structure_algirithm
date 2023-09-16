#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
vector<pair<int,int>> need_to_find;
vector<bool> is_founded;

bool isCompatableSquare(int y, int x){
    int y_ = y/3 * 3, x_ = x/3 * 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(y_ + i == y && x_ + j == x)
                    continue;
            if(arr[y_ + i][x_ + j] == arr[y][x])
                return false;
        }
    }
    return true;
}
bool isCompatableRow(int y, int x){
    for(int i = 0; i < 9; i++){
        if(i == x)
            continue;
        else
            if(arr[y][x] == arr[y][i])
                return false;
    }
    return true;
}
bool isCompatableCol(int y, int x){
    for(int i = 0; i < 9; i++){
        if( i == y )
            continue;
        else
            if(arr[y][x] == arr[i][x])
                return false;
    }
    return true;
}


void solveUnknown(const vector<pair<int,int>>& need_to_find){
    // if 다 found 되면 

    for(int i = 0; i<need_to_find.size(); i++){
        if(is_founded[i])
            continue;
        int y = need_to_find[i].first;
        int x = need_to_find[i].second;
        for(int trial = 1; trial <= 9; trial++){
            is_founded[i] = true;
            arr[y][x] = trial;
            if(!isCompatableSquare(y,x) || !isCompatableRow(y,x) || !isCompatableCol(y,x)){
                is_founded[i] = false;
                arr[y][x] = 0;
                continue;//return; // 넣어봤더니, 잘못 됐네요. continue가 아니라, 다 스택에서 빼. return이나 continue가 아님. 
            }
            solveUnknown(need_to_find); // 맞으면 계속 찾아.
            is_founded[i] = false;
            arr[y][x] = 0;
        }
    }
    // 다 찾아진 경우
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    exit(0);
    return ;
}

int main(){

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){  
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                need_to_find.push_back({i,j});
        }
    }
    // for(const auto& a : need_to_find)
    //     cout << a.first << ", " << a.second << "\n";
    int unknown_size = need_to_find.size();
    is_founded.resize(unknown_size);


    solveUnknown(need_to_find);
    // print arr

}