#include <bits/stdc++.h>
using namespace std;
// 경우의 수를 세거나 botom up 방식의 문제를 풀 때에는 exponental하게 
// longlong을 쓰는 것이 맞음.
using ll = long long;
ll cache[101];
int T, N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(cache, -1, sizeof(cache));

    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 2;
    cache[4] = 2;
    cache[5] = 3;
    cache[6] = 4;
    cache[7] = 5;

    cin >> T;
    while(T--){
        cin >> N;
        if(cache[N-1] != -1){
            cout << cache[N-1] << "\n";
            continue;
        }
        for(int i = 8; i <= N; i++){
            ll & ret = cache[i];
            // caching은 딱히 필요 없을 듯.
            //if(ret != -1)
            ret = cache[i-1] + cache[i-5];
        }
        cout << cache[N-1] << "\n";
    }
}