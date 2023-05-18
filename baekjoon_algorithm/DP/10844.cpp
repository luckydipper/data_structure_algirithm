#include <bits/stdc++.h>
using namespace std;
int cache[101][11];
int N;

const int MOD = 1000000000;
//D[i][j] : i번째 원소가 j일때, 0~i-1의 원소로 만들 수 있는 계단수.
int countWhenLastIs(int last_index, int val){
    if(last_index == 1){
        if(val == 0)
            return 0;
        else 
            return 1;
    }
    
    int &ret = cache[last_index][val];
    if(ret != -1)
        return ret;

    //val 0과 9인경우 base case로 처리할 껄..
    if(val == 0)
        return ret = countWhenLastIs(last_index-1, 1) % MOD;
    else if(val == 9)
        return ret = countWhenLastIs(last_index-1, 8) % MOD;
    else
        return ret = countWhenLastIs(last_index-1, val-1) % MOD + countWhenLastIs(last_index-1, val+1) % MOD;
}

int main(){
    memset(cache, -1, sizeof(cache));
    int result = 0;
    cin >> N;
    for(int i = 0; i < 10; i++){
        result += countWhenLastIs(N,i);
        result %= MOD;
    }
    cout << result;
}