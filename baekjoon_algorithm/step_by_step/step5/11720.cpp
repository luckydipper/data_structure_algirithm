#include<bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    string st;
    cin >> st;
    
    int result = 0;
    for(int i =0 ;i < N; i++){
        // cout << N << "\n";
        result += int(st[i] - '0'); // (int)
    }
    cout  << result;
}