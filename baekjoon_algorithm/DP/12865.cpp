#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
const int MAX_WEIGHT = 100001;
const int MAX_COUNT = 100;
vector<int> weight;
vector<int> value;

vector<vector<int>> cache(MAX_COUNT, vector<int> (MAX_WEIGHT, -1));

// return optimal value, using product after the index.
int pack(int index, int capacity){
    if(index == N)
        return 0;
    else if(cache[index][capacity] != -1) 
        return cache[index][capacity];
    else if(capacity < weight[index]){    // 오류를 찾았으나 왜 13이 나오는가?
        int ret = pack(index+1, capacity);
        cache[index][capacity] = ret;
        return ret;
    }
    else{
        int ret = pack(index+1, capacity);
        ret = max(ret, pack(index+1, capacity-weight[index])+value[index]);
        cache[index][capacity] = ret;
        return ret;
    }
}

int main(){
    cin >> N >> K;
    weight.resize(N);
    value.resize(N);
    // 중복된 무게가 있다면?
    for(int i=0; i<N; i++){
        int tmp_weight, tmp_val;
        cin >> tmp_weight >> tmp_val;
        weight[i] = tmp_weight;
        value[i] = tmp_val;
    }

    cout << pack(0, K);
}

