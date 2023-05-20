#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
int arr[301];
ll cache[301];

// i번째 원소를 마지막으로 선택한 score의 최대값.
int max_score(int i){
    if(i <= 1)
        return arr[i];

    ll& ret = cache[i];
    if(ret != -1)  return ret;
    
    // max_score(i-2)과 max_score(i-1) 비교시,
    // -1만 계속 선택할 수 있음.
    return ret = arr[i] + max(max_score(i-2), arr[i-1] + max_score(i-3));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    cin >> N;    
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    cout << max_score(N); //max(max_score(1,1), max_score(2,0));

}