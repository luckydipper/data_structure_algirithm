#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
const int MAX_WEIGHT = 100000;
const int MAX_COUNT = 100;
vector<int> weight;
vector<int> value;

vector<vector<int>> cache(MAX_WEIGHT, vector<int> (MAX_COUNT, -1));

// return optimal value, using product after the index.
int pack(int index, int capacity){
    if(index == N)
        return 0;
    else if(cache[index][capacity] != -1) 
        return cache[index][capacity];
    else if(capacity < weight[index])
        return pack(index+1, capacity);
    else
        return max(pack(index+1, capacity), pack(index+1,capacity-weight[index])+value[index]);
}

int main(){
    cin >> N >> K;
    weight.resize(N);
    value.resize(N);
    for(int i=0; i<N; i++){
        int tmp_weight, tmp_val;
        cin >> tmp_weight >> tmp_val;
        weight[i] = tmp_weight;
        value[i] = tmp_val;
    }
    cout << pack(0, K);
}

