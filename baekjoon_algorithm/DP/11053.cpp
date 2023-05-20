#include<bits/stdc++.h>
using namespace std;
int N;
int cache[1001][1001]; // 0: index 1 : value
int arr[1001];

// 0~i까지 max value의 index가 j 일 때.
// i+1 ~ N까지 남은 lis의 길이
int lis(int i, int j){
    if(i >= N)
        return 0;

    int& ret = cache[i][j];
    if(ret != -1)
        return ret;

    if(arr[i+1] <= arr[j]) // < : monotonously increase.
        return ret = lis(i+1,j);
    else
        return ret = max(lis(i+1,j), lis(i+1, i+1)+1);
}

int main(){
    cin >> N;
    for(int i = 1; i<= N; i++)
        cin >> arr[i];
    memset(cache, -1, sizeof(cache));
    cout << lis(0,arr[0]);
}