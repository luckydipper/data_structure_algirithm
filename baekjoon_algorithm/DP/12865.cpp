#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 2차원 배열의 2열을 정렬하고 싶으면 cmp 함수를 만들어서 sort에 주면 됨.

int main(){
    int N, K;
    cin >> N >> K;


    map<int,int> weight_to_largest_value;
    
    vector<int> cache_to_value(K+1, 0);
    
    for(int i = 0; i < N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        pair<int,int> p_temp(temp1,temp2); //make pair가 더 좋을 듯
        weight_to_largest_value.insert(p_temp);
    }

    // for(auto a: weight_to_largest_value)
    //     cout << a.first << " " << a.second << "\n";
    
    // k/2랑 j 가 같아서 min(val(2),val(2)) 되는 경우 막아야 함.
    for(int i = 1; i < cache_to_value.size(); i++){
        int largest_value_of_i = weight_to_largest_value[1];
        for(int j = 0; j <= K/2; j++){
            int weight_candidate = weight_to_largest_value[K/2 -j]+weight_to_largest_value[j];
            if( largest_value_of_i < weight_candidate)
                largest_value_of_i = weight_candidate;
        }
        cache_to_value[i] = largest_value_of_i;
    }

    for(auto a: cache_to_value)
        cout << a;
    cout << weight_to_largest_value[K];
}

