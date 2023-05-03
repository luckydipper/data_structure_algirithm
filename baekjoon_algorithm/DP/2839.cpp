#include<bits/stdc++.h>
using namespace std;
int N;
int arr[50001];

const int INF = 987654321;
int main(){
    cin >> N;
    arr[1] = INF;
    arr[2] = INF;
    arr[3] = 1;
    arr[4] = INF;
    arr[5] = 1;
    for(int i = 6; i <= N; i++){
        int a = (arr[i-5] == INF)?  INF : arr[i-5]+1;
        int b = (arr[i-3] == INF)?  INF : arr[i-3]+1;
        arr[i] = min(a, b);
    }
    if(arr[N] == INF){
        cout << -1;
        return 0;
    }
    cout << arr[N];
}
