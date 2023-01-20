#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 2차원 배열의 2열을 정렬하고 싶으면 cmp 함수를 만들어서 sort에 주면 됨.

int main(){
    int N, K;
    cin >> N >> K;


    multimap<int,int> weight_to_value;
    
    for(int i = 0; i < N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        pair<int,int> p_temp(temp1,temp2); //make pair가 더 좋을 듯
        weight_to_value.insert(p_temp);
    }

    // for(auto a: weight_to_value)
    //     cout << a.first << " " << a.second << "\n";
    
    // k/2랑 j 가 같아서 min(val(2),val(2)) 되는 경우 막아야 함.

    vector<int> maximum_values(K+1, 0);
    for(int weight = 1; weight < maximum_values.size(); weight++){
        max_value_of_weight = 0;
        for(int devider = 0; devider < weight/2; devider++){
            if(weight_to_value.upper_bound(devider) == weight_to_value.end())

        }
    }

    for(int i = 1; i < maximum_values.size(); i++){
        int largest_value_of_i = 0;
        for(int j = 1; j <= i/2; j++){
            int weight_candidate = weight_to_value[K/2 -j]+weight_to_value[j];
            if( largest_value_of_i < weight_candidate)
                largest_value_of_i = weight_candidate;
        }
        maximum_values[i] = largest_value_of_i;
    }

    for(auto a: maximum_values)
        cout << a;
    cout << weight_to_value[K];
}

