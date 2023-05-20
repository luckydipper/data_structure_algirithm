#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10002];
int cache[10002][3];
const int INF = -1e+9; //
// 2579 계단 오르기 문제에서 
//마지막 원소를 포함한다는 제한 조건이 없는 문제

// i를 마셨을 때, i는 j번 연속으로 마셨다.
// 1~i-1까지 마실 수 있는 최대 음료량을 반환한다.
int max_drink(int i, int continous_1){
    if(i <= 0 || continous_1 >= 3) return 0;

    int& ret = cache[i][continous_1];
    if(ret != -1)
        return ret;
    
    int max_before = max_drink(i-1, continous_1+1);
    for(int jump = 2; jump <i; jump++){
        max_before = max(max_before, max_drink(i-jump, 1));
    }
    return ret = arr[i] + max_before;
}

int main(){
    cin >> n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    memset(cache, -1, sizeof(cache));

    cout << max_drink(n+1,0);
}