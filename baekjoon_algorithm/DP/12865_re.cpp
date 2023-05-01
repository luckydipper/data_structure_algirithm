#include <bits/stdc++.h>
using namespace std;
#define weight first
#define value second

int N, K;
pair<int,int> weight_value[101];
int cache[101][100001];// remain n, remain value;

int max_value(int remain_n, int remain_weight){
    if(remain_n == 1){
        if(remain_weight >= weight_value[1].weight)
            return weight_value[1].value;
        else
            return 0;
    }
    else{
        if(cache[remain_n][remain_weight] != 0)
            return cache[remain_n][remain_weight];
        else if(remain_weight < weight_value[remain_n].weight){
            cache[remain_n][remain_weight] = max_value(remain_n-1, remain_weight);
            return cache[remain_n][remain_weight];
        }
        else{
            cache[remain_n][remain_weight] = max( max_value(remain_n-1, remain_weight), 
                        max_value(remain_n-1, remain_weight - weight_value[remain_n].weight) + weight_value[remain_n].value );
            return cache[remain_n][remain_weight];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> weight_value[i].weight;
        cin >> weight_value[i].value;
    }
    cout << max_value(N,K);
}
