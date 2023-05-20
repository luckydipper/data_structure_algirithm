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
    
    // i의 크기에 따라서 i를 포함할지 안 안할지 달라짐.
    return ret = arr[i] + max(max_score(i-2), max_score(i-1));
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