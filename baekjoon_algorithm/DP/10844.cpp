#include <bits/stdc++.h>
using namespace std;
int cache[101][11];
using ll = long long;
int N;

const int MOD = 1000000000;
//D[i][j] : i번째 원소가 j일때, 0~i-1의 원소로 만들 수 있는 계단수.
int countWhenLastIs(int last_index, int val){
    if(val < 0 || val > 9 )
        return 0;

    if(last_index == 1){
        if(val == 0)
            return 0;
        else 
            return 1;
    }
    
    int &ret = cache[last_index][val];

    if(ret != -1)
        return ret;

    return ret = (countWhenLastIs(last_index-1, val-1)+ countWhenLastIs(last_index-1, val+1 % MOD)) %MOD;
}

int main(){
    memset(cache, -1, sizeof(cache));
    ll result = 0;
    cin >> N;
    for(int i = 0; i < 10; i++){
        result = (result + countWhenLastIs(N, i))%MOD;
    }
    cout << (result%MOD);
}