#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
vector<pair<int,int>> need_to_find;
//vector<bool> is_founded;
// is found 말고 0의 갯수로 가는 것이 더 효과적임. 
// is found 는 안에 문자열이 적혔는지로 대체.
// D&C나 recursion 할 때, index를 넘기는 것이 효과적임. 
// const vector<pair<int,int>>& need_to_find를 parameter로 넘기면 안될 듯.
int num_zero;

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

// const vector<pair<int,int>>& need_to_find
// found out을 sequential 하게 찾지 않고 앞부터 반복해서 망하는듯.
void solveUnknown(const vector<pair<int,int>>& need_to_find){
    if(num_zero == 0){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j <9; j++)
                cout << arr[i][j] << " ";
        cout << "\n";
        }
        exit(0);
    }

    for(int i = 0; i < need_to_find.size(); i++){
        int y = need_to_find[i].first;
        int x = need_to_find[i].second;
        if(arr[y][x] != 0)
            continue;
        num_zero--;
        for(int trial = 1; trial <= 9; trial++){
            arr[y][x] = trial;
            if(isCompatableSquare(y,x) && isCompatableRow(y,x) && isCompatableCol(y,x))
                solveUnknown(need_to_find); // 에러가 없으면 다음 것도 찾아 
            arr[y][x] = 0;
        }
        num_zero++;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){  
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                need_to_find.push_back({i,j});
                num_zero++;
            }
        }
    }

    int unknown_size = need_to_find.size();
    //is_founded.resize(unknown_size);
    solveUnknown(need_to_find);
    

}