
// 문제의 keypoint 2차원 배열의 정렬 sort(pair<int,int>)
// 문자열 처리, split으로, atoi, stoa, stoi

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;

// 3 < 3.0 어떻게 비교하냐? static cast, throw catch type id double
// string -> . 기준으로 자르기 
// pair<int, int>로 하면 될 듯.


pair<int,int> arr[1001];
int main(int argc, char** argv)
{
    cin >> N;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        
        string int_part, float_part; // 이거 대신할 함수 STL에 적기 
        bool is_int_part = true;
        for(auto& digit: tmp){
            if(string{digit} == string{'.'}){
                is_int_part = false;
                continue;
            }
            if(is_int_part)
                int_part.push_back(digit);
            else
                float_part.push_back(digit);
        }
        //cout << int_part <<" " << float_part;
        int iint_part = stoi(string{int_part}), ifloat_part;
        
        if (float_part.empty())
            ifloat_part = -1;
        else
            ifloat_part = stoi(string{float_part});

        //cout << iint_part << " " << ifloat_part;
        arr[i] = {iint_part, ifloat_part};
        is_int_part = false;
        int_part = float_part = "";
    }
    sort(arr, arr+N);

    for(int i = 0; i < N; i++){
        if (arr[i].second == -1){
            cout << arr[i].first <<"\n";
            continue;
        }
        cout << arr[i].first << "." << arr[i].second << "\n";
    }
    return 0;
}